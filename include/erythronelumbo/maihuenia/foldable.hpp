// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file foldable.hpp
 *
 * @brief `Foldable` typeclass
 *
 * Defines the `Foldable` typeclass.
 */

/**
 * @defgroup tc_foldable Foldable
 * @ingroup typeclasses
 *
 * @brief Data types that can be reduced to a single *value*
 *
 * Indicates that a data type can be reduced, by using a binary metafunction,
 * to a single value type, begining from the leftmost or the rightmost element
 * contained in said data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FOLDABLE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FOLDABLE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_foldable}
 */
struct Foldable ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Foldable, \
    1, \
    (), \
    ( \
      (fold_left, 0, 2, 0, 0, (1)), (fold_right, 0, 2, 0, 0, (1)), \
      (fold_left_initial, 0, 3, 0, 0, (1)), \
      (fold_right_initial, 0, 3, 0, 0, (1)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_foldable
 * @brief Left folding of a data structure
 *
 * Applies a binary transformation to all the elements contained in a data type,
 * starting from the *leftmost* element, and reduces it into a single value in
 * the following manner:
 * 
 * ```
 * f(... f(f(f(x1, x2), x3) ...), xn)
 * 
 * - f(a, b):     binary metafunction
 * - x1, x2, ..., xn: elements of a type
 * ```
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 *
 * ## Example
 *
 * @include example/individual/foldable/fold_left.cpp
 */
template <typename Fn, typename T>
struct fold_left
{
  /**
   * @brief Result
   *
   * The result of applying the binary metafunction class `Fn` to the elements
   * of `T`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_foldable
 * @brief Right folding of a data structure
 *
 * Applies a binary transformation to all the elements contained in a data type,
 * starting from the *rightmost* element, and reduces it into a single value in
 * the following manner:
 * 
 * ```
 * f(x1, f(x2, ... f(xn-1, xn) ...))
 * 
 * - f(a, b):     binary metafunction
 * - x1, x2, ..., xn: elements of a type
 * ```
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 *
 * ## Example
 *
 * @include example/individual/foldable/fold_right.cpp
 */
template <typename Fn, typename T>
struct fold_right
{
  /**
   * @brief Result
   *
   * The result of applying the binary metafunction class `Fn` to the elements
   * of `T`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_foldable
 * @brief Left folding of a data structure, with initial state
 *
 * Applies a binary transformation to all the elements contained in a data type,
 * starting from the *leftmost* element and an initial value, and reduces it
 * into a single value in the following manner:
 * 
 * ```
 * f(f(... f(f(f(x1, x2), x3) ...), xn), InitSt)
 * 
 * - f(a, b):     binary metafunction
 * - x1, x2, ..., xn: elements of a type
 * ```
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 * @tparam InitSt
 *   The initial state (or initial value).
 *
 * ## Example
 *
 * @include example/individual/foldable/fold_left_initial.cpp
 */
template <typename Fn, typename T, typename InitSt>
struct fold_left_initial
{
  /**
   * @brief Result
   *
   * The result of applying the binary metafunction class `Fn` to the elements
   * of `T`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_foldable
 * @brief Right folding of a data structure, with initial state
 *
 * Applies a binary transformation to all the elements contained in a data type,
 * starting from the *rightmost* element and an initial value, and reduces it
 * into a single value in the following manner:
 * 
 * ```
 * f(x1, f(x2, ... f(xn-1, f(xn, InitSt)) ...))
 * 
 * - f(a, b):     binary metafunction
 * - x1, x2, ..., xn: elements of a type
 * ```
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 * @tparam InitSt
 *   The initial state (or initial value).
 *
 * ## Example
 *
 * @include example/individual/foldable/fold_right_initial.cpp
 */
template <typename Fn, typename T, typename InitSt>
struct fold_right_initial
{
  /**
   * @brief Result
   *
   * The result of applying the binary metafunction class `Fn` to the elements
   * of `T`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::fold_left
 *
 * @invokesmfn{fold_left}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 */
template <typename Fn, typename T>
using fold_left_t = typename fold_left<Fn, T>::type;


/**
 * @relates erythronelumbo::maihuenia::fold_right
 *
 * @invokesmfn{fold_right}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 */
template <typename Fn, typename T>
using fold_right_t = typename fold_right<Fn, T>::type;


/**
 * @relates erythronelumbo::maihuenia::fold_left_initial
 *
 * @invokesmfn{fold_left_initial}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 * @tparam InitSt
 *   The initial state (or initial value).
 */
template <typename Fn, typename T, typename InitSt>
using fold_left_initial_t = typename fold_left_initial<Fn, T, InitSt>::type;


/**
 * @relates erythronelumbo::maihuenia::fold_right_initial
 *
 * @invokesmfn{fold_right_initial}
 *
 * @tparam Fn
 *   A binary metafunction class.
 * @tparam T
 *   The type to reduce.
 * @tparam InitSt
 *   The initial state (or initial value).
 */
template <typename Fn, typename T, typename InitSt>
using fold_right_initial_t = typename fold_right_initial<Fn, T, InitSt>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FOLDABLE_HPP
