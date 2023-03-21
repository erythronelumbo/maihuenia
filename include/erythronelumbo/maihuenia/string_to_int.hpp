// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file string_to_int.hpp
 *
 * @brief `string_to_int` metafunction
 *
 * Defines the `string_to_int` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_STRING_TO_INT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_STRING_TO_INT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <char Ch, int Base>
  struct strtoi_is_valid_digit :
    bool_<
      (
        (
          Ch +
          10*((Ch >= 'A' && Ch <= 'Z') || (Ch >= 'a' && Ch <= 'z')) -
          (
            '0' +
            ('a' - '0')*(Ch >= 'a' && Ch <= 'z') +
            ('A' - '0')*(Ch >= 'A' && Ch <= 'Z')
          )
        ) <
        Base
      ) 
    >
  {};


  template <typename UIntType, UIntType Base>
  struct strtoi_parse_digits_pos
  {
    template <typename Acc, typename CurrChar>
    struct apply :
      eval_if_c<
        strtoi_is_valid_digit<CurrChar::value, Base>::type::value,
        integer_c<
          UIntType,
          Base*Acc::value +
          (UIntType)(
            CurrChar::value +
            10*(
              (CurrChar::value >= 'A' && CurrChar::value <= 'Z') ||
              (CurrChar::value >= 'a' && CurrChar::value <= 'z')
            ) -
            (
              '0' +
              ('a' - '0')*(CurrChar::value >= 'a' && CurrChar::value <= 'z') +
              ('A' - '0')*(CurrChar::value >= 'A' && CurrChar::value <= 'Z')
            )
          )
        >,
        identity<invalid_argument>
      >
    {};

    template <typename CurrChar>
    struct apply<invalid_argument, CurrChar> :
      identity<invalid_argument>
    {};
  };

  template <typename IntType, IntType Base>
  struct strtoi_parse_digits_neg
  {
    template <typename Acc, typename CurrChar>
    struct apply :
      eval_if_c<
        strtoi_is_valid_digit<CurrChar::value, Base>::type::value,
        integer_c<
          IntType,
          Base*Acc::value -
          (IntType)(
            CurrChar::value +
            10*(
              (CurrChar::value >= 'A' && CurrChar::value <= 'Z') ||
              (CurrChar::value >= 'a' && CurrChar::value <= 'z')
            ) -
            (
              '0' +
              ('a' - '0')*(CurrChar::value >= 'a' && CurrChar::value <= 'z') +
              ('A' - '0')*(CurrChar::value >= 'A' && CurrChar::value <= 'Z')
            )
          )
        >,
        identity<invalid_argument>
      >
    {};

    template <typename CurrChar>
    struct apply<invalid_argument, CurrChar> :
      identity<invalid_argument>
    {};
  };


  template <typename Str, typename IntType, int Base, bool IsNegative>
  struct str_to_int_do_parsing :
    fold_left_initial<
      if_c_t<
        IsNegative,
        strtoi_parse_digits_neg<IntType, Base>,
        strtoi_parse_digits_pos<IntType, Base>
      >,
      Str,
      integer_c<IntType, 0>
    >
  {};


  template <
    typename Str,
    bool = empty_t<Str>::value,
    bool = empty_t<pop_front_t<Str>>::value
  >
  struct strtoi_prefix_to_base :
    int_<
      (front_t<Str>::value == '0') ?
      (
        (
          front_t<pop_front_t<Str>>::value == 'X' ||
          front_t<pop_front_t<Str>>::value == 'x'
        ) ?
        16 :
        (
          (
            front_t<pop_front_t<Str>>::value == 'B' ||
            front_t<pop_front_t<Str>>::value == 'b'
          ) ?
          2 :
          8
        )
      ) :
      10
    >
  {};

  template <typename Str>
  struct strtoi_prefix_to_base<Str, false, true> :
    int_<(front_t<Str>::value == '0') ? 8 : 10>
  {};

  template <typename Str>
  struct strtoi_prefix_to_base<Str, true, true> : int_<10>
  {};

  template <typename Str, int Base>
  struct strtoi_discard_bprfx_best :
    Str
  {};

  template <typename Str>
  struct strtoi_discard_bprfx_best<Str, 0> :
    drop_c<
      Str,
      (::std::size_t)(front_t<Str>::value == '0') +
      (::std::size_t)(
        front_t<pop_front_t<Str>>::value == 'X' ||
        front_t<pop_front_t<Str>>::value == 'x' ||
        front_t<pop_front_t<Str>>::value == 'B' ||
        front_t<pop_front_t<Str>>::value == 'b'
      )
    >
  {};

  template <typename Str>
  struct strtoi_discard_bprfx_best<Str, 16> :
    drop_c<
      Str,
      (::std::size_t)(front_t<Str>::value == '0') +
      (::std::size_t)(
        front_t<pop_front_t<Str>>::value == 'X' ||
        front_t<pop_front_t<Str>>::value == 'x'
      )
    >
  {};

  template <typename Str>
  struct strtoi_discard_bprfx_best<Str, 2> :
    drop_c<
      Str,
      (::std::size_t)(front_t<Str>::value == '0') +
      (::std::size_t)(
        front_t<pop_front_t<Str>>::value == 'B' ||
        front_t<pop_front_t<Str>>::value == 'b'
      )
    >
  {};

  template <
    typename Str, int Base,
    bool = empty_t<pop_front_t<Str>>::value
  >
  struct strtoi_discard_bprfx :
    strtoi_discard_bprfx_best<Str, Base>
  {};

  template <typename Str, int Base>
  struct strtoi_discard_bprfx<Str, Base, true> :
    Str
  {};


  template <typename Str, typename IntType, int Base, bool IsNegative>
  struct str_to_int_auto_base :
    str_to_int_do_parsing<
      typename strtoi_discard_bprfx<Str, Base>::type,
      IntType,
      Base == 0 ? (strtoi_prefix_to_base<Str>::value) : Base,
      IsNegative
    >
  {};


  template <typename Str, typename IntType, int Base>
  struct str_to_int_non_empty :
    str_to_int_auto_base<
      eval_if_c_t<
        front_t<Str>::value == '-' || front_t<Str>::value == '+',
        pop_front<Str>,
        Str
      >,
      IntType,
      Base,
      front_t<Str>::value == '-'
    >
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup mfn_miscellaneous
 * @brief String to integer
 *
 * Parses a string for obtaining an integral value. The string to be interpreted
 * is asumed to be composed of a sequence of characters corresponding to base-n
 * digits of the number to obtain. Said string can optionally begin with the
 * following prefixes:
 * - A plus or minus sign,
 * - `0x` or `0X` for hexadecimal (base-16) representations (only if the base is
 *    set to 0 or 16,
 * - `0b` or `0B` for binary representations (only if the base is set to 0 or 2,
 * - `0` for octal (base-8) representations (only if the base is set to 0 or 8.
 *
 * Therefore, said string should have the following structure:
 * ```
 * [+/-][0/0x/0X/0b/0B][digits...]
 * ```
 *
 * The valid values for the bases are between `2` and `36` inclusive, as well as
 * `0`. For base-2 numbers, the digits are `{0, 1}`; for base-3 numbers,
 * `{0, 1, 2}` and so on. For bases higher that 10, besides the digits
 * `{0, 1, ..., 9}`, it takes alphabetic characters (lowercase or uppercase):
 * `{0, ..., 9, a}` for base-11 numbers, `{0, ..., 9, a, b}` for base-12 numbers
 * and so on.
 *
 * If the value of the base is set as `0`, the base of the number will be
 * automatically detected: hexadecimal if the prefix is `0x`/`0X`; binary if the
 * prefix is `0b`/`0B`; octal if the prefix is just `0` or decimal otherwise.
 *
 * The resulting integral value will also take the sign at the beginning of the
 * string.
 *
 * @tparam Str
 *   A string type.
 * @tparam IntType
 *   The underlying type (integer) of the resulting value.
 * @tparam Base
 *   An integral constant with the base of the number to parse (0 or between 2
 *   and 36; default: 0).
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/string_to_int.cpp
 */
template <typename Str, typename IntType, typename Base = int_<0>>
struct string_to_int
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      logical_or_t< \
        empty_t<Str>, \
        logical_and_t< \
          not_equals_t<Base, int_<0>>, \
          logical_or_t<less_t<Base, int_<2>>, greater_t<Base, int_<36>>> \
        > \
      >, \
      identity<invalid_argument>, \
      detail::str_to_int_non_empty<Str, IntType, Base::value> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * An @ref integer_c which value was parsed from a given string or
   * @ref invalid_argument if the input string is empty or not parsed properly
   * or the value of the base is invalid.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::string_to_int
 *
 * @invokesmfn{string_to_int}
 *
 * @tparam Str
 *   A string type.
 * @tparam IntType
 *   The underlying type (integer) of the resulting value.
 * @tparam Base
 *   An integral constant with the base of the number to parse (0 or between 2
 *   and 36; default: 0).
 */
template <typename Str, typename IntType, typename Base = int_<0>>
using string_to_int_t = typename string_to_int<Str, IntType, Base>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_STRING_TO_INT_HPP
