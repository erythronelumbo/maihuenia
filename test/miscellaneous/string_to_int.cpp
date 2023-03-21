// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/string_to_int.hpp>

#include "../eq_types.hpp"


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 40)

namespace mhn = erythronelumbo::maihuenia;


int main()
{
  test_eq_types<
    typename mhn::string_to_int<STR_(""), long, mhn::int_<0>>::type,
    mhn::invalid_argument
  >();

  test_eq_types<
    typename mhn::string_to_int<STR_("0"), long, mhn::int_<0>>::type,
    mhn::long_<0>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("1"), long, mhn::int_<0>>::type,
    mhn::long_<1>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("12"), long, mhn::int_<0>>::type,
    mhn::long_<12>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("12345"), long, mhn::int_<0>>::type,
    mhn::long_<12345>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("123876345"), long, mhn::int_<0>>::type,
    mhn::long_<123876345>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("-1"), long, mhn::int_<0>>::type,
    mhn::long_<-1>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("-23"), long, mhn::int_<0>>::type,
    mhn::long_<-23>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("-98765"), long, mhn::int_<0>>::type,
    mhn::long_<-98765>
  >();
  test_eq_types<
    typename mhn::string_to_int<STR_("-123876345"), long, mhn::int_<0>>::type,
    mhn::long_<-123876345>
  >();

  test_eq_types<
    typename mhn::string_to_int<
      STR_("0x0"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0x0>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0X0"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0X0>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0x1"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0x1>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0X1"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0X1>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0xabcd0123"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0xabcd0123>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0Xabcd0123"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0Xabcd0123>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0xAbCd0123"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0xabcd0123>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0xABCD0123"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0xabcd0123>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0xac02"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0xac02>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("-0xac02"), long, mhn::int_<0>
    >::type,
    mhn::long_<-0xac02>
  >();

  test_eq_types<
    typename mhn::string_to_int<
      STR_("0b0"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<0>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0b1"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<1>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0B1"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<1>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0b10"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<2>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0B10"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<2>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0b11110001011001001001011001011001"), std::uint32_t, mhn::int_<0>
    >::type,
    mhn::u32_c<4049901145>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("0B11110001011001001001011001011001"), std::uint32_t, mhn::int_<0>
    >::type,
    mhn::u32_c<4049901145>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("-0b1001010"), long, mhn::int_<0>
    >::type,
    mhn::long_<-74>
  >();

  test_eq_types<
    typename mhn::string_to_int<
      STR_("01"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<01>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("010"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<010>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("012743"), unsigned long, mhn::int_<0>
    >::type,
    mhn::ulong_<012743>
  >();
  test_eq_types<
    typename mhn::string_to_int<
      STR_("-012743"), long, mhn::int_<0>
    >::type,
    mhn::long_<-012743>
  >();

  // Strictly decimal
  test_eq_types<
    mhn::string_to_int_t<STR_("0"), long, mhn::int_<10>>,
    mhn::long_<0>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("1"), long, mhn::int_<10>>,
    mhn::long_<1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-1"), long, mhn::int_<10>>,
    mhn::long_<-1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("25"), long, mhn::int_<10>>,
    mhn::long_<25>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("23571113"), long, mhn::int_<10>>,
    mhn::long_<23571113>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-23571113"), long, mhn::int_<10>>,
    mhn::long_<-23571113>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("123abc"), long, mhn::int_<10>>,
    mhn::invalid_argument
  >();

  // Strictly hexadecimal
  test_eq_types<
    mhn::string_to_int_t<STR_("0"), long, mhn::int_<16>>,
    mhn::long_<0>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0x0"), long, mhn::int_<16>>,
    mhn::long_<0x0>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("1"), long, mhn::int_<16>>,
    mhn::long_<1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0x1"), long, mhn::int_<16>>,
    mhn::long_<0x1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("123"), long, mhn::int_<16>>,
    mhn::long_<0x123>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0x123"), long, mhn::int_<16>>,
    mhn::long_<0x0123>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("abcdef1"), long, mhn::int_<16>>,
    mhn::long_<0xabcdef1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("aBCdeF1"), long, mhn::int_<16>>,
    mhn::long_<0xabcdef1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("ABCDEF1"), long, mhn::int_<16>>,
    mhn::long_<0xabcdef1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0XABCDEF1"), long, mhn::int_<16>>,
    mhn::long_<0xabcdef1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-0xabcdef1"), long, mhn::int_<16>>,
    mhn::long_<-0xabcdef1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0xabcdefg1"), long, mhn::int_<16>>,
    mhn::invalid_argument
  >();

  // Strictly binary
  test_eq_types<
    mhn::string_to_int_t<STR_("0"), long, mhn::int_<2>>,
    mhn::long_<0>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b0"), long, mhn::int_<2>>,
    mhn::long_<0>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("1"), long, mhn::int_<2>>,
    mhn::long_<1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b1"), long, mhn::int_<2>>,
    mhn::long_<1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-1"), long, mhn::int_<2>>,
    mhn::long_<-1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-0b1"), long, mhn::int_<2>>,
    mhn::long_<-1>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("101"), long, mhn::int_<2>>,
    mhn::long_<5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b101"), long, mhn::int_<2>>,
    mhn::long_<5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-101"), long, mhn::int_<2>>,
    mhn::long_<-5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-0b101"), long, mhn::int_<2>>,
    mhn::long_<-5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("00101"), long, mhn::int_<2>>,
    mhn::long_<5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b00101"), long, mhn::int_<2>>,
    mhn::long_<5>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b11110000101"), long, mhn::int_<2>>,
    mhn::long_<1925>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-0b11110000101"), long, mhn::int_<2>>,
    mhn::long_<-1925>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("-11110000101"), long, mhn::int_<2>>,
    mhn::long_<-1925>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("11110000101"), long, mhn::int_<2>>,
    mhn::long_<1925>
  >();
  test_eq_types<
    mhn::string_to_int_t<STR_("0b231010"), long, mhn::int_<2>>,
    mhn::invalid_argument
  >();
}
