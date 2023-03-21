// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file scan_left.hpp
 *
 * @brief `scan_left` metafunction
 *
 * Defines the `scan_left` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SCAN_LEFT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SCAN_LEFT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  /*
   * scan_left<Fn, [], xI> == [xI]
   * scan_left<Fn, [x0], xI> == [xI, Fn<xI,x0>]
   * scan_left<Fn, [x0,x1], xI>
   * == [xI, Fn<xI,x0>, Fn<Fn<xI,x0>,x1>]
   * == [xI] ++ [Fn<xI,x0>, Fn<Fn<xI,x0>,x1>]
   * == [xI] ++ scan_left<Fn, [x1], Fn<xI,x0>>
   * scan_left<Fn, [x0,x1,x2], xI>
   * == [xI, Fn<xI,x0>, Fn<Fn<xI,x0>,x1>, Fn<Fn<Fn<xI,x0>,x1>,x2>]
   * == [xI] ++ [Fn<xI,x0>, Fn<Fn<xI,x0>,x1>, Fn<Fn<Fn<xI,x0>,x1>,x2>]
   * == [xI] ++ scan_left<Fn, [x1,x2], Fn<xI,x0>>
   *
   * scan_left<Fn, [x1,x2], Fn<xI,x0>>
   * == [Fn<xI,x0>, Fn<Fn<xI,x0>,x1>, Fn<Fn<Fn<xI,x0>,x1>,x2>]
   */

  template <
    typename Fn, typename It, typename ResTag, typename Acc,
    bool = empty<It>::type::value
  >
  struct scan_left_initial_impl :
    push_front<
      typename scan_left_initial_impl<
        Fn,
        pop_front_t<It>,
        ResTag,
        typename Fn::template apply<
          Acc,
          front_t<It>
        >::type
      >::type,
      Acc
    >
  {};

  template <typename Fn, typename It, typename ResTag, typename Acc>
  struct scan_left_initial_impl<Fn, It, ResTag, Acc, true> :
    make_seq<ResTag, Acc>
  {};


  template <
    typename Fn, typename It, typename ResTag,
    bool = empty_t<It>::value
  >
  struct scan_left_impl :
    scan_left_initial_impl<Fn, pop_front_t<It>, ResTag, front_t<It>>
  {};

  template <typename Fn, typename It, typename ResTag>
  struct scan_left_impl<Fn, It, ResTag, true> :
    make_seq<ResTag>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Left-to-right inclusive scan
 *
 * Reduces an @ref tc_iterable starting from its first element by applying a
 * binary metafunction class, creating a @ref tc_sequence with the final result,
 * located at the end of the resulting sequence, and the intermediate results.
 *
 * ```
 * scan_left(f, [x0, x1, x2, ..., x{n-1}, xn])
 * == [
 *   x0,
 *   f(x0, x1),
 *   f(f(x0, x1), x2),
 *   ...,
 *   f(... f(f(x0, x1), x2) ..., x{n-1}),
 *   f(f(... f(f(x0, x1), x2) ..., x{n-1}), xn)
 * ]
 * ```
 *
 * @see @ref fold_left
 * @see @ref fold_left_initial
 * @see @ref scan_left_initial
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam InitialState
 *   The initial state.
 * @tparam ResTag
 *   The tag that represents the output type. It must be a @ref tc_sequence.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/scan_left.cpp
 */
template <typename Fn, typename It, typename ResTag>
struct scan_left
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::scan_left_impl<Fn, It, ResTag> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence with the progressively reduced elements from the iterable given
   * in `It`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @ingroup alg_creation
 * @brief Left-to-right inclusive scan with initial state
 *
 * Reduces an @ref tc_iterable starting from the *initial state* and its first
 * element by applying a binary metafunction class, creating a @ref tc_sequence
 * with the final result, located at the end of the resulting sequence, the
 * intermediate results and the initial state at the beginning.
 *
 * ```
 * scan_left(f, [x0, x1, x2, ..., x{n-1}, xn], xI)
 * == [
 *   xI,
 *   f(xI, x0),
 *   f(f(xI, x0), x1),
 *   f(f(f(xI, x0), x1), x2),
 *   ...,
 *   f(... f(f(f(xI, x0), x1), x2) ..., x{n-1}),
 *   f(f(... f(f(f(xI, x0), x1), x2) ..., x{n-1}), xn)
 * ]
 * ```
 *
 * @see @ref fold_left
 * @see @ref fold_left_initial
 * @see @ref scan_left
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam ResTag
 *   The tag that represents the output type. It must be a @ref tc_sequence.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/scan_left_initial.cpp
 */
template <typename Fn, typename It, typename InitialState, typename ResTag>
struct scan_left_initial
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::scan_left_initial_impl< \
      Fn, It, ResTag, InitialState \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence with the progressively reduced elements from the iterable given
   * in `It`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::scan_left
 *
 * @invokesmfn{scan_left}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam InitialState
 *   The initial state.
 * @tparam ResTag
 *   The tag that represents the output type. It must be a @ref tc_sequence.
 */
template <typename Fn, typename It, typename ResTag>
using scan_left_t = typename scan_left<Fn, It, ResTag>::type;

/**
 * @relates erythronelumbo::maihuenia::scan_left_initial
 *
 * @invokesmfn{scan_left_initial}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam ResTag
 *   The tag that represents the output type. It must be a @ref tc_sequence.
 */
template <typename Fn, typename It, typename InitialState, typename ResTag>
using scan_left_initial_t = typename scan_left_initial<
  Fn, It, InitialState, ResTag
>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SCAN_LEFT_HPP
