// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file integral.hpp
 *
 * @brief `Integral` typeclass
 *
 * Defines the `Integral` typeclass.
 */

/**
 * @defgroup tc_integral Integral
 * @ingroup typeclasses
 *
 * @brief Integral numbers that support integral division
 *
 * Numeric data types that correspond to an *Euclidean domain*, where division
 * between integers with remainder (also known as *Euclidean division*) is
 * defined and the results of this operation are both integral.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_integral}
 */
struct Integral ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (erythronelumbo, maihuenia), \
  ::erythronelumbo::maihuenia::Integral, \
  2, \
  (::erythronelumbo::maihuenia::Numeric), \
  ((div, 1, (0, 1)), (mod, 1, (0, 1))), () \
)


namespace erythronelumbo { namespace maihuenia
{

template <typename OtherTag>
struct typeclass<Integral>::define_for<OtherTag, not_a_number> : true_
{
  template <typename X0, typename X1>
  using div_impl = not_a_number;

  template <typename X0, typename X1>
  using mod_impl = not_a_number;
};

template <typename OtherTag>
struct typeclass<Integral>::define_for<not_a_number, OtherTag> : true_
{
  template <typename X0, typename X1>
  using div_impl = not_a_number;

  template <typename X0, typename X1>
  using mod_impl = not_a_number;
};

template <>
struct typeclass<Integral>::define_for<not_a_number, not_a_number> : true_
{
  template <typename X0, typename X1>
  using div_impl = not_a_number;

  template <typename X0, typename X1>
  using mod_impl = not_a_number;
};

}} // namespace erythronelumbo::maihuenia

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_integral
 * @brief Integral division
 *
 * Performs the division between integrals. Equivalent to `X0 / X1 / ...` for
 * integers.
 *
 * @tparam X1
 *   An integral value.
 * @tparam X2
 *   An integral value.
 * @tparam Xs...
 *   Integral values.
 *
 * ## Example
 *
 * @include example/individual/integral/div.cpp
 */
template <typename X1, typename X2, typename... Xs>
struct div
{
  /**
   * @brief Result
   *
   * The result of dividing several integral values.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_integral
 * @brief Integral modulus
 *
 * Calculates the remainders of integral division (or moduli) between integral
 * values. Equivalent to `X0 % X1 % ...`.
 *
 * @tparam X1
 *   An integral value.
 * @tparam X2
 *   An integral value.
 * @tparam Xs...
 *   Integral values.
 *
 * ## Example
 *
 * @include example/individual/integral/mod.cpp
 */
template <typename X1, typename X2, typename... Xs>
struct mod
{
  /**
   * @brief Result
   *
   * The modulus obtained from several integral values.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::div
 *
 * @invokesmfn{div}
 *
 * @tparam X1
 *   An integral value.
 * @tparam X2
 *   An integral value.
 * @tparam Xs...
 *   Integral values.
 */
template <typename X1, typename X2, typename... Xs>
using div_t = typename div<X1, X2, Xs...>::type;

/**
 * @relates erythronelumbo::maihuenia::mod
 *
 * @invokesmfn{mod}
 *
 * @tparam X1
 *   An integral value.
 * @tparam X2
 *   An integral value.
 * @tparam Xs...
 *   Integral values.
 */
template <typename X1, typename X2, typename... Xs>
using mod_t = typename mod<X1, X2, Xs...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_HPP
