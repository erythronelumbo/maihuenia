// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `integer_c` data type
 *
 * Defines the `integer_c` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INTEGER_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INTEGER_C_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/enumerable.hpp>
#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/logical.hpp>
#include <erythronelumbo/maihuenia/bitwise.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>
#include <erythronelumbo/maihuenia/integral.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>
#include <erythronelumbo/maihuenia/detail/integral_to_string.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <typename IntType>
struct typeclass<Enumerable>::define_for<integer_c_tag<IntType>> : true_
{
  template <typename X>
  struct incr_impl : integer_c<typename X::value_type, X::value + 1> {};

  template <typename X>
  struct decr_impl : integer_c<typename X::value_type, X::value - 1> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Comparable>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct equals_impl : bool_<(X1::value == X2::value)> {};

  template <typename X1, typename X2>
  struct not_equals_impl : bool_<(X1::value != X2::value)> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Orderable>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct less_impl : bool_<(X1::value < X2::value)> {};

  template <typename X1, typename X2>
  struct less_equal_impl : bool_<(X1::value <= X2::value)> {};

  template <typename X1, typename X2>
  struct greater_impl : bool_<(X1::value > X2::value)> {};

  template <typename X1, typename X2>
  struct greater_equal_impl : bool_<(X1::value >= X2::value)> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Logical>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct logical_and_impl : bool_<X1::value && X2::value> {};

  template <typename X1, typename X2>
  struct logical_or_impl : bool_<X1::value || X2::value> {};

  template <typename X>
  struct logical_not_impl : bool_<!X::value> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Bitwise>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct bit_and_impl :
    integer_c<decltype(X1::value & X2::value), X1::value & X2::value>
  {};

  template <typename X1, typename X2>
  struct bit_or_impl :
    integer_c<decltype(X1::value | X2::value), X1::value | X2::value>
  {};

  template <typename X1, typename X2>
  struct bit_xor_impl :
    integer_c<decltype(X1::value ^ X2::value), X1::value ^ X2::value>
  {};

  template <typename X>
  struct bit_not_impl :
    integer_c<typename X::value_type, ~X::value>
  {};

  template <typename X, typename S>
  struct shift_left_impl :
    integer_c<typename X::value_type, (X::value << S::value)>
  {};

  template <typename X, typename S>
  struct shift_right_impl :
    integer_c<typename X::value_type, (X::value >> S::value)>
  {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Numeric>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct add_impl :
    integer_c<decltype(X1::value + X2::value), X1::value + X2::value>
  {};

  template <typename X1, typename X2>
  struct sub_impl :
    integer_c<decltype(X1::value - X2::value), X1::value - X2::value>
  {};

  template <typename X1, typename X2>
  struct mul_impl :
    integer_c<decltype(X1::value * X2::value), X1::value * X2::value>
  {};

  template <typename X>
  struct negate_impl :
    integer_c<IntType1, (IntType1)(-X::value)>
  {};

  template <typename X>
  struct abs_impl :
    integer_c<IntType1, (X::value > 0) ? X::value : -X::value>
  {};

  template <typename X>
  struct sign_impl :
    integer_c<
      IntType1,
      X::value == 0 ? 0 : (X::value > 0 ? 1 : -1)
    >
  {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Integral>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct div_impl :
    integer_c<decltype(X1::value / X2::value), X1::value / X2::value>
  {};

  template <typename X1, typename X2>
  struct mod_impl :
    integer_c<decltype(X1::value % X2::value), X1::value % X2::value>
  {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Monoid>::define_for<
  integer_c_tag<IntType1>, integer_c_tag<IntType2>
> :
  true_
{
  struct mident_impl : integer_c<IntType1, (IntType1)0> {};

  template <typename X1, typename X2>
  struct mappend_impl :
    integer_c<decltype(X1::value + X2::value), X1::value + X2::value>
  {};
};


template <typename IntType>
struct typeclass<WithStringRepr>::define_for<integer_c_tag<IntType>> : true_
{
  template <typename X>
  struct to_string_impl :
    detail::integral_to_string_impl<
      typename X::value_type
    >::template apply<X>
  {};
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_INTEGER_C_HPP
