// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file scan_right.hpp
 *
 * @brief `scan_right` metafunction
 *
 * Defines the `scan_right` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SCAN_RIGHT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SCAN_RIGHT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  /*
   * scan_right<Fn, [], xI> == [xI]
   * scan_right<Fn, [x0], xI> == [Fn<x0, xI>, xI]
   * scan_right<Fn, [x0, x1], xI>
   * == [Fn<x0, Fn<x1, xI>>, Fn<x1, xI>, xI]
   * == [Fn<x0, Fn<x1, xI>>, Fn<x1, xI>] ++ [xI]
   * == scan_right<Fn, [x0], Fn<x1, xI>> ++ [xI]
   * scan_right<Fn, [x0, x1, x2], xI>
   * == [Fn<x0, Fn<x1, Fn<x2, xI>>>, Fn<x1, Fn<x2, xI>>, Fn<x2, xI>, xI]
   * == [Fn<x0, Fn<x1, Fn<x2, xI>>>, Fn<x1, Fn<x2, xI>>, Fn<x2, xI>] ++ [xI]
   * == scan_right<Fn, [x0, x1], Fn<x2, xI>> ++ [xI]
   * 
   * scan_right<Fn, [x0, x1], Fn<x2, xI>>
   * == [Fn<x0, Fn<x1, Fn<x2, xI>>>, Fn<x1, Fn<x2, xI>>, Fn<x2, xI>]
   *
   * [] ++ [xI]
   * -> [xI]
   *
   * [x0] ++ [xI]
   * -> [x0@xI, xI]
   *
   * [x0, x1] ++ [xI]
   * -> [x0, x1@xI, xI]
   * -> [x0@(x1@xI), (x1@xI), xI]
   *
   * [x0, x1, x2] ++ [xI]
   * -> [x0, x1, x2@xI, xI]
   * -> [x0, x1@x2@xI, x2@xI, xI]
   * -> [x0@(x1@(x2@xI)), x1@(x2@xI), (x2@xI), xI]
   */
  template <
    typename Fn, typename It, typename Res,
    bool = empty<It>::type::value
  >
  struct scan_right_impl :
    push_front<
      typename scan_right_impl<
        Fn,
        pop_front_t<It>,
        Res
      >::type,
      fold_right_t<Fn, It>
    >
  {};

  template <typename Fn, typename It, typename Res>
  struct scan_right_impl<Fn, It, Res, true> :
    Res
  {};


  template <
    typename Fn, typename It, typename Res, typename Head,
    bool = empty<It>::type::value
  >
  struct scan_right_initial_impl :
    push_front<
      typename scan_right_initial_impl<
        Fn,
        pop_front_t<It>,
        Res,
        Head
      >::type,
      fold_right_initial_t<Fn, It, Head>
    >
  {};

  template <typename Fn, typename It, typename Res, typename Head>
  struct scan_right_initial_impl<Fn, It, Res, Head, true> :
    push_back<Res, Head>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Right-to-left inclusive scan
 *
 * Reduces an @ref tc_iterable starting from its last element by applying a
 * binary metafunction class, creating a @ref tc_sequence with the final result,
 * located at the beginning of the resulting sequence, and the intermediate
 * results.
 *
 * ```
 * scan_right(f, [x0, x1, ..., x{n-2}, x{n-1}, xn])
 * == [
 *   f(x0, f(x1, ... f(x{n-1}, xn) ...)),
 *   f(x1, ... f(x{n-1}, xn) ...),
 *   ...,
 *   f(x{n-2}, f(x{n-1}, xn)),
 *   f(x{n-1}, xn),
 *   xn
 * ]
 * ```
 *
 * @see @ref fold_right
 * @see @ref fold_right_initial
 * @see @ref scan_right_initial
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
 * @include example/individual/alg_creation/scan_right.cpp
 */
template <typename Fn, typename It, typename ResTag>
struct scan_right
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::scan_right_impl<Fn, It, make_seq_t<ResTag>> \
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
 * @brief Right-to-left inclusive scan with initial state
 *
 * Reduces an @ref tc_iterable starting from the *initial state* and its last
 * element by applying a binary metafunction class, creating a @ref tc_sequence
 * with the final result, located at the beginning of the resulting sequence,
 * the intermediate results and the initial state at the end.
 *
 * ```
 * scan_right_initial(f, [x0, x1, ..., x{n-2}, x{n-1}, xn], xI)
 * == [
 *   f(x0, f(x1, ... f(x{n-1}, f(xn, xI)) ...)),
 *   f(x1, ... f(x{n-1}, f(xn, xI)) ...),
 *   ...,
 *   f(x{n-2}, f(x{n-1}, f(xn, xI))),
 *   f(x{n-1}, f(xn, xI)),
 *   f(xn, xI),
 *   xI
 * ]
 * ```
 *
 * @see @ref fold_right
 * @see @ref fold_right_initial
 * @see @ref scan_right
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
 * @include example/individual/alg_creation/scan_right_initial.cpp
 */
template <typename Fn, typename It, typename InitialState, typename ResTag>
struct scan_right_initial
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::scan_right_initial_impl< \
      Fn, It, make_seq_t<ResTag>, InitialState \
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
 * @relates erythronelumbo::maihuenia::scan_right
 *
 * @invokesmfn{scan_right}
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
using scan_right_t = typename scan_right<Fn, It, ResTag>::type;

/**
 * @relates erythronelumbo::maihuenia::scan_right_initial
 *
 * @invokesmfn{scan_right_initial}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam ResTag
 *   The tag that represents the output type. It must be a @ref tc_sequence.
 */
template <typename Fn, typename It, typename InitialState, typename ResTag>
using scan_right_initial_t = typename scan_right_initial<
  Fn, It, InitialState, ResTag
>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SCAN_RIGHT_HPP
