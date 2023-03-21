// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file numeric.hpp
 *
 * @brief `Numeric` typeclass
 *
 * Defines the `Numeric` typeclass.
 */

/**
 * @defgroup tc_numeric Numeric
 * @ingroup typeclasses
 *
 * @brief Basic numeric types
 *
 * Corresponds to data types that hold numerical values, where basic arithmetic
 * operations (addition, multiplication, negation, etc.) can be done with them.
 *
 * This typeclass can also be valid to compound types, like complex numbers,
 * vectors or matrices.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_NUMERIC_HPP
#define ERYTHRONELUMBO_MAIHUENIA_NUMERIC_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_numeric}
 */
struct Numeric ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (erythronelumbo, maihuenia), \
  ::erythronelumbo::maihuenia::Numeric, \
  2, \
  (), \
  ( \
    (add, 1, (0, 1)), \
    (sub, 1, (0, 1)), \
    (mul, 1, (0, 1)), \
    (negate, 0, 1, 0, 0, (0)), \
    (abs, 0, 1, 0, 0, (0)), \
    (sign, 0, 1, 0, 0, (0)) \
  ), \
  () \
)


namespace erythronelumbo { namespace maihuenia
{

template <typename OtherTag>
struct typeclass<Numeric>::define_for<OtherTag, not_a_number> : true_
{
  template <typename X0, typename X1>
  using add_impl = not_a_number;

  template <typename X0, typename X1>
  using sub_impl = not_a_number;

  template <typename X0, typename X1>
  using mul_impl = not_a_number;

  template <typename X>
  using negate_impl = not_a_number;

  template <typename X>
  using abs_impl = not_a_number;

  template <typename X>
  using sign_impl = not_a_number;
};

template <typename OtherTag>
struct typeclass<Numeric>::define_for<not_a_number, OtherTag> : true_
{
  template <typename X0, typename X1>
  using add_impl = not_a_number;

  template <typename X0, typename X1>
  using sub_impl = not_a_number;

  template <typename X0, typename X1>
  using mul_impl = not_a_number;

  template <typename X>
  using negate_impl = not_a_number;

  template <typename X>
  using abs_impl = not_a_number;

  template <typename X>
  using sign_impl = not_a_number;
};

template <>
struct typeclass<Numeric>::define_for<not_a_number, not_a_number> : true_
{
  template <typename X0, typename X1>
  using add_impl = not_a_number;

  template <typename X0, typename X1>
  using sub_impl = not_a_number;

  template <typename X0, typename X1>
  using mul_impl = not_a_number;

  template <typename X>
  using negate_impl = not_a_number;

  template <typename X>
  using abs_impl = not_a_number;

  template <typename X>
  using sign_impl = not_a_number;
};

}} // namespace erythronelumbo::maihuenia

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_numeric
 * @brief Addition
 *
 * Adds several numerical *values*. Equivalent to `X0 + X1 + ...`.
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 *
 * ## Example
 *
 * @include example/individual/numeric/add.cpp
 */
template <typename X0, typename X1, typename... Xs>
struct add
{
  /**
   * @brief Result
   *
   * The result of adding several *values*.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_numeric
 * @brief Subtraction
 *
 * Subtracts several numerical *values*. Equivalent to `X0 - X1 - ...`.
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 *
 * ## Example
 *
 * @include example/individual/numeric/sub.cpp
 */
template <typename X0, typename X1, typename... Xs>
struct sub
{
  /**
   * @brief Result
   *
   * The result of subtracting several *values*.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_numeric
 * @brief Multiplication
 *
 * Multiplies several numerical *values*. Equivalent to `X0 * X1 * ...`.
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 *
 * ## Example
 *
 * @include example/individual/numeric/mul.cpp
 */
template <typename X0, typename X1, typename... Xs>
struct mul
{
  /**
   * @brief Result
   *
   * The result of multiplying several *values*.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_numeric
 * @brief Negation
 *
 * Obtains the negative counterpart of a numerical value type. Equivalent to
 * `-X`.
 *
 * @tparam X
 *   A numeric value type
 *
 * ## Example
 *
 * @include example/individual/numeric/negate.cpp
 */
template <typename X>
struct negate
{
  /**
   * @brief Result
   *
   * The *value* of `X` but with the opposite sign: the result is positive for
   * a negative *value* and viceversa.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_numeric
 * @brief Absolute value
 *
 * Calculates the absolute value, which is the *distance* of a value (positive
 * or negative) from zero, of a numerical *value*.
 *
 * @tparam X
 *   A numeric value type
 *
 * ## Example
 *
 * @include example/individual/numeric/abs.cpp
 */
template <typename X>
struct abs
{
  /**
   * @brief Result
   *
   * The positive counterpart of `X`, regardless of its sign.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_numeric
 * @brief Sign of a numerical *value*
 *
 * Results in an unitary *value* with the same sign of the supplied *value* or
 * zero for zero *values*
 *
 * @tparam X
 *   A numeric value type
 *
 * ## Example
 *
 * @include example/individual/numeric/sign.cpp
 */
template <typename X>
struct sign
{
  /**
   * @brief Result
   *
   * Equivalent to `1` for positive values, `-1` for negative values and `0` for
   * zero *values*.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::add
 *
 * @invokesmfn{add}
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 */
template <typename X0, typename X1, typename... Xs>
using add_t = typename add<X0, X1, Xs...>::type;

/**
 * @relates erythronelumbo::maihuenia::sub
 *
 * @invokesmfn{sub}
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 */
template <typename X0, typename X1, typename... Xs>
using sub_t = typename sub<X0, X1, Xs...>::type;

/**
 * @relates erythronelumbo::maihuenia::mul
 *
 * @invokesmfn{mul}
 *
 * @tparam X0
 *   A numeric value type.
 * @tparam X1
 *   A numeric value type.
 * @tparam Xs...
 *   Numeric value types.
 */
template <typename X0, typename X1, typename... Xs>
using mul_t = typename mul<X0, X1, Xs...>::type;

/**
 * @relates erythronelumbo::maihuenia::negate
 *
 * @invokesmfn{negate}
 *
 * @tparam X
 *   A numeric value type
 */
template <typename X>
using negate_t = typename negate<X>::type;

/**
 * @relates erythronelumbo::maihuenia::abs
 *
 * @invokesmfn{abs}
 *
 * @tparam X
 *   A numeric value type
 */
template <typename X>
using abs_t = typename abs<X>::type;

/**
 * @relates erythronelumbo::maihuenia::sign
 *
 * @invokesmfn{sign}
 *
 * @tparam X
 *   A numeric value type
 */
template <typename X>
using sign_t = typename sign<X>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_NUMERIC_HPP
