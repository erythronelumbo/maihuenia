// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file zip_with.hpp
 *
 * @brief `zip_with` metafunction
 *
 * Defines the `zip_with` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ZIP_WITH_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ZIP_WITH_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Fn, typename ResTag, typename... Its>
  struct zip_with_impl
  {
    template <
      typename X, bool = logical_or<typename empty<Its>::type...>::type::value
    >
    struct result_ : make_seq<ResTag> {};

    template <typename X>
    struct result_<X, false> :
      push_front<
        typename zip_with_impl<
          Fn, ResTag, pop_front_t<Its>...
        >::template result_<X>::type,
        typename Fn::template apply<front_t<Its>...>::type
      >
    {};
  };

  template <typename Fn, typename ResTag, typename It>
  struct zip_with_impl<Fn, ResTag, It>
  {
    template <
      typename X, bool = empty<It>::type::value
    >
    struct result_ : make_seq<ResTag> {};

    template <typename X>
    struct result_<X, false> :
      push_front<
        typename zip_with_impl<
          Fn, ResTag, pop_front_t<It>
        >::template result_<X>::type,
        typename Fn::template apply<front_t<It>>::type
      >
    {};
  };
} // namespace detail


template <typename Fn, typename ResTag, typename... Its>
struct zip_with :
  detail::zip_with_impl<Fn, ResTag, Its...>::template result_<void>
{};

template <typename Fn, typename ResTag>
struct zip_with<Fn, ResTag> : make_seq<ResTag> {};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Transforms in parallel the elements of iterables
 *
 * Creates a @ref tc_sequence where each `I`-th element is the result of
 * applying, in a parallel manner, a metafunction class to the `I`-th elements
 * of the supplied @ref tc_iterable s.
 *
 * If the supplied iterables have different sizes, the resulting sequence will
 * have the same size as the shortest iterable (it can also be empty).
 *
 * @see @ref zip
 * @see @ref transform
 *
 * @tparam Fn
 *   The metafunction class to be applied.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 * @tparam Its...
 *   The @ref tc_iterable s.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/zip_with.cpp
 */
template <typename Fn, typename ResTag, typename... Its>
struct zip_with
{
  /**
   * @brief Result
   *
   * A @ref tc_sequence with the results of applying `Fn` to each element from
   * `Its...` or, if no @ref tc_iterable s are provided and/or at least one
   * iterable is empty, an empty sequence.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @relates erythronelumbo::maihuenia::zip_with
 *
 * @invokesmfn{zip_with}
 *
 * @tparam Fn
 *   The metafunction class to be applied.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 * @tparam Its...
 *   The @ref tc_iterable s.
 */
template <typename Fn, typename ResTag, typename... Its>
using zip_with_t = typename zip_with<Fn, ResTag, Its...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ZIP_WITH_HPP
