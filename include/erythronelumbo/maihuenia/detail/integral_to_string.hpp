// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file integral_to_string.hpp
 *
 * @brief [...]
 *
 * [...]
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TO_STRING_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TO_STRING_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/enable_if.hpp>
#include <erythronelumbo/maihuenia/detail/integral_traits.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/fwd/string.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename IntType, IntType X, bool = (X == (IntType)0)>
struct integral_to_string_nonzero :
  str_concat_two<
    typename integral_to_string_nonzero<IntType, (X / 10)>::type,
    string<'0' + (char)(X % 10)>
  >
{};

template <typename IntType, IntType X>
struct integral_to_string_nonzero<IntType, X, true> :
  string<>
{};


template <typename, typename = void>
struct integral_to_string_impl;

template <typename IntType>
struct integral_to_string_impl<
  IntType, enable_if_t<is_unsigned<IntType>::value>
>
{
  template <typename X>
  struct apply :
    eval_if_c<
      X::value == (typename X::value_type)0,
      string<'0'>,
      integral_to_string_nonzero<
        typename X::value_type,
        X::value
      >
    >
  {};
};

template <typename IntType>
struct integral_to_string_impl<
  IntType, enable_if_t<is_signed<IntType>::value>
>
{
  template <typename X>
  struct apply :
    str_concat_two<
      if_c_t<(X::value < 0), string<'-'>, string<>>,
      eval_if_c_t<
        X::value == (typename X::value_type)0,
        string<'0'>,
        integral_to_string_nonzero<
          typename X::value_type,
          (X::value < 0) ? -X::value : X::value
        >
      >
    >
  {};
};

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TO_STRING_HPP
