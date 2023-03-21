// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file for_each.hpp
 *
 * @brief `for_each` function
 *
 * Defines the `for_each` runtime function.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FOR_EACH_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FOR_EACH_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <bool IsRandomAccess>
  struct for_each_helper
  {
    private:
      template <
        typename It,
        typename = varseq_make_idx_seq_t<size<It>::type::value>
      >
      struct result_impl;

      template <typename It, ::std::size_t... Idcs>
      struct result_impl<It, varseq_idx_seq<Idcs...>>
      {
        template <typename Fn>
        inline static void call(Fn f)
        {
          int sink_[] = {0, (f(at_c_t<It, Idcs>{}), 0)...};
          (void)sink_;
        }
      };

      template <typename It>
      struct result_impl<It, varseq_idx_seq<>>
      {
        template <typename Fn>
        inline static void call(Fn)
        {
          return;
        }
      };
    public:
      template <typename It>
      struct result_ : result_impl<It> {};
  };

  template <>
  struct for_each_helper<false>
  {
    private:
      template <typename It, bool = empty_t<It>::value>
      struct result_impl
      {
        template <typename Fn>
        inline static void call(Fn f)
        {
          f(front_t<It>{});
          result_impl<pop_front_t<It>>::call(f);
        }
      };

      template <typename It>
      struct result_impl<It, true>
      {
        template <typename Fn>
        inline static void call(Fn /*f*/)
        {
          return;
        }
      };
    public:
      template <typename It>
      struct result_ : result_impl<It> {};
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_runtime
 * @brief Applies a runtime function object for each element
 *
 * Appliies a function object to each element in an @ref tc_iterable, which can
 * do an operation at runtime based on such elements.
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @param f
 *   The function object to be applied.
 *
 * ## Example
 *
 * @include example/individual/alg_runtime/for_each.cpp
 */
template <typename It, typename Fn>
inline void for_each(Fn f)
{
  detail::for_each_helper<
    iterable_is_random_access<It>::type::value
  >::template result_<It>::call(f);
}

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FOR_EACH_HPP
