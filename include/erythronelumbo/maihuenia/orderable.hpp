// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file orderable.hpp
 *
 * @brief `Orderable` typeclass
 *
 * Defines the `Orderable` typeclass.
 */

/**
 * @defgroup tc_orderable Orderable
 * @ingroup typeclasses
 *
 * @brief Defines data types that can be ordered
 *
 * Indicates that two instances of a data type can be compared based on if
 * the value of one of them is lesser or greater than the other. It refines
 * @ref tc_comparable.
 *
 * ### Minimal complete definition
 *
 * `less<X0, X1>`.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ORDERABLE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ORDERABLE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_orderable}
 */
struct Orderable ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Orderable, \
    2, \
    (::erythronelumbo::maihuenia::Comparable), \
    ((less, 0, 2, 0, 0, (0, 1))), \
    ( \
      (less_equal, 0, 2, 0, 0, (0, 1)), \
      (greater, 0, 2, 0, 0, (0, 1)), \
      (greater_equal, 0, 2, 0, 0, (0, 1)) \
    ) \
  )

  namespace erythronelumbo { namespace maihuenia { namespace detail
  {
    template <typename X1, typename X2>
    using less_equal_ = bool_<
      less<X1, X2>::type::value || equals<X1, X2>::type::value
    >;
  }}} // namespace erythronelumbo::maihuenia::detail

  ERYTHRONELUMBO_MAIHUENIA_DEFINE_DERIVED_TYPECLASS_OPS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Orderable, \
    2, \
    ( \
      ( \
        less_equal, 0, 2, 0, 0, (0, 1), \
        (::erythronelumbo::maihuenia::detail::less_equal_<X0, X1>) \
      ), \
      ( \
        greater, 0, 2, 0, 0, (0, 1), \
        (::erythronelumbo::maihuenia::less<X1, X0>) \
      ), \
      ( \
        greater_equal, 0, 2, 0, 0, (0, 1), \
        (::erythronelumbo::maihuenia::detail::less_equal_<X1, X0>) \
      ) \
    ) \
  )
#else //ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_orderable
 * @brief *Less-than* comparator
 *
 * Checks if the value of a type is lesser than another one.
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 *
 * ## Example
 *
 * @include example/individual/orderable/less.cpp
 */
template <typename X1, typename X2>
struct less
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if `X1 < X2`, `false_` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_orderable
 * @brief *Less-than or equals* comparator
 *
 * Checks if the value of a type is lesser than or is equal to another one.
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 *
 * ## Example
 *
 * @include example/individual/orderable/less_equal.cpp
 */
template <typename X1, typename X2>
struct less_equal
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if `X1 <= X2`, `false_` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_orderable
 * @brief *Greater-than* comparator
 *
 * Checks if the value of a type is greater than another one.
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 *
 * ## Example
 *
 * @include example/individual/orderable/greater.cpp
 */
template <typename X1, typename X2>
struct greater
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if `X1 > X2`, `false_` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_orderable
 * @brief *Greater-than or equals* comparator
 *
 * Checks if the value of a type is greater than or is equal to another one.
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 *
 * ## Example
 *
 * @include example/individual/orderable/greater_equal.cpp
 */
template <typename X1, typename X2>
struct greater_equal
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if `X1 >= X2`, `false_` otherwise.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::less
 *
 * @invokesmfn{less}
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 */
template <typename X1, typename X2>
using less_t = typename less<X1, X2>::type;

/**
 * @relates erythronelumbo::maihuenia::less_equal
 *
 * @invokesmfn{less_equal}
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 */
template <typename X1, typename X2>
using less_equal_t = typename less_equal<X1, X2>::type;

/**
 * @relates erythronelumbo::maihuenia::greater
 *
 * @invokesmfn{greater}
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 */
template <typename X1, typename X2>
using greater_t = typename greater<X1, X2>::type;

/**
 * @relates erythronelumbo::maihuenia::greater_equal
 *
 * @invokesmfn{greater_equal}
 *
 * @tparam X1
 *   Value type to check.
 * @tparam X2
 *   Value type to check.
 */
template <typename X1, typename X2>
using greater_equal_t = typename greater_equal<X1, X2>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ORDERABLE_HPP
