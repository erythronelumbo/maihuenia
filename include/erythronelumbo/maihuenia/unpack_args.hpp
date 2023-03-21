// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file unpack_args.hpp
 *
 * @brief `unpack_args` metafunction class
 *
 * Defines the `unpack_args` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_UNPACK_ARGS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_UNPACK_ARGS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Fn>
  struct unpack_args_ra_helper
  {
    template <typename, typename>
    struct with_idcs;

    template <typename T, std::size_t... Idcs>
    struct with_idcs<T, detail::varseq_idx_seq<Idcs...>>
    {
      template <typename It>
      struct apply
      {
        using type = typename Fn::template apply<
          at_c_t<It, Idcs>...
        >::type;
      };
    };
  };

  template <typename...> struct unpack_args_sq_args_accum;


  template <typename Fn>
  struct unpack_args_sa_helper
  {
    private:
      template <
        typename It, typename ArgsAcc,
        bool = empty<It>::type::value
      >
      struct apply_impl;

      template <typename It, typename... ArgsAcc, bool IsEmpty>
      struct apply_impl<
        It, unpack_args_sq_args_accum<ArgsAcc...>, IsEmpty
      >
      {
        using type = typename Fn::template apply<ArgsAcc...>::type;
      };

      template <typename It, typename... ArgsAcc>
      struct apply_impl<
        It, unpack_args_sq_args_accum<ArgsAcc...>, false
      >
      {
        using type = typename apply_impl<
          pop_front_t<It>,
          unpack_args_sq_args_accum<ArgsAcc..., front_t<It>>
        >::type;
      };
    public:
      template <typename It>
      struct apply : apply_impl<It, unpack_args_sq_args_accum<>> {};
  };
} // namespace detail

template <typename Fn>
struct unpack_args
{
  private:
    template <
      typename It, bool = iterable_is_random_access<It>::type::value
    >
    struct apply_impl :
      detail::unpack_args_ra_helper<Fn>::template with_idcs<
        void, detail::varseq_make_idx_seq_t<size<It>::type::value>
      >::template apply<It>
    {};

    template <typename It>
    struct apply_impl<It, false> :
      detail::unpack_args_sa_helper<Fn>::template apply<It>
    {};
  public:
    template <typename It> struct apply : apply_impl<It> {};
};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup functional
 * @brief Uses the elements from an iterable as metafunction class arguments
 *
 * Unpacks the arguments of an @ref tc_iterable and applies them to a
 * metafunction class.
 *
 * @tparam Fn
 *   A metafunction class.
 *
 * ## Example
 *
 * @include example/individual/functional/unpack_args.cpp
 */
template <typename Fn>
struct unpack_args
{
  /**
   * @brief Invocation
   *
   * Takes the @ref tc_iterable with the arguments of `Fn`.
   *
   * @tparam It
   *   An @ref tc_iterable.
   */
  template <typename It>
  struct apply
  {
    /**
     * @brief Result
     *
     * The result of `Fn` with the elements from `It` applied to it.
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_UNPACK_ARGS_HPP
