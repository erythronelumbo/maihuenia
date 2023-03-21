// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file rational.hpp
 *
 * @brief `Rational` typeclass
 *
 * Defines the `Rational` typeclass.
 */

/**
 * @defgroup tc_rational Rational
 * @ingroup typeclasses
 *
 * @brief Rational numbers
 *
 * Numeric data types that correspond to fractions, which are defined in terms
 * of a *numerator* and a *denominator*, being both of them integers. This
 * typeclass provides a division operation between such data types, as well as
 * another operation for obtaining the *reciprocal* or *inverse* of a rational
 * value type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_RATIONAL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_RATIONAL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_rational}
 */
struct Rational ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (erythronelumbo, maihuenia), \
  ::erythronelumbo::maihuenia::Rational, \
  2, \
  (::erythronelumbo::maihuenia::Numeric), \
  ((quot, 1, (0, 1)), (recip, 0, 1, 0, 0, (0))), \
  () \
)


namespace erythronelumbo { namespace maihuenia
{

template <typename OtherTag>
struct typeclass<Rational>::define_for<OtherTag, not_a_number> : true_
{
  template <typename X0, typename X1>
  using quot_impl = not_a_number;

  template <typename X>
  using recip_impl = not_a_number;
};

template <typename OtherTag>
struct typeclass<Rational>::define_for<not_a_number, OtherTag> : true_
{
  template <typename X0, typename X1>
  using quot_impl = not_a_number;

  template <typename X>
  using recip_impl = not_a_number;
};

template <>
struct typeclass<Rational>::define_for<not_a_number, not_a_number> : true_
{
  template <typename X0, typename X1>
  using quot_impl = not_a_number;

  template <typename X>
  using recip_impl = not_a_number;
};

}} // namespace erythronelumbo::maihuenia

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_rational
 * @brief Rational division
 *
 * Performs the division of several rational *values*, without having a
 * remainder (compare with @ref tc_integral), and, also, resulting in another
 * rational *value*. It is worth mentioning that this operation, applied to
 * rational numbers, is the inverse of their multiplication.
 *
 * @tparam Q0
 *   A rational *value*.
 * @tparam Q1
 *   A rational *value*.
 * @tparam Qs...
 *   Rational *values*.
 *
 * ## Example
 *
 * @include example/individual/rational/quot.cpp
 */
template <typename Q0, typename Q1, typename... Qs>
struct quot
{
  /**
   * @brief Result
   *
   * The result of dividing several rational *values*.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_rational
 * @brief Reciprocal
 *
 * Obtains the reciprocal or inverse value of a rational *value*. Equivalent to
 * `1/X` or `Den/Num` for fractions of the form `Num/Den`.
 *
 * @tparam Q
 *   A rational *value*.
 *
 * ## Example
 *
 * @include example/individual/rational/recip.cpp
 */
template <typename Q>
struct recip
{
  /**
   * @brief Result
   *
   * The reciprocal or inverse of the given *value*.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::quot
 *
 * @invokesmfn{quot}
 *
 * @tparam Q0
 *   A rational *value*.
 * @tparam Q1
 *   A rational *value*.
 * @tparam Qs...
 *   Rational *values*.
 */
template <typename Q0, typename Q1, typename... Qs>
using quot_t = typename quot<Q0, Q1, Qs...>::type;

/**
 * @relates erythronelumbo::maihuenia::recip
 *
 * @invokesmfn{recip}
 *
 * @tparam Q
 *   A rational *value*.
 */
template <typename Q>
using recip_t = typename recip<Q>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_RATIONAL_HPP
