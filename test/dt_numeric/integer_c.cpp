// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


template <typename IntType>
constexpr void integer_c_test_signed()
{
  using xa = mhn::integer_c<IntType, 0>;
  using xb = mhn::integer_c<IntType, 1>;
  using xc = mhn::integer_c<IntType, 2>;
  using xd = mhn::integer_c<IntType, 5>;
  using xe = mhn::integer_c<IntType, 10>;
  using xf = mhn::integer_c<IntType, -1>;
  using xg = mhn::integer_c<IntType, -2>;
  using xh = mhn::integer_c<IntType, -5>;
  using xi = mhn::integer_c<IntType, -10>;

  static_assert(
    mhn::equals<xa, mhn::integer_c<int, 0>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xb, mhn::integer_c<int, 1>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xd, mhn::integer_c<int, 5>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xf, mhn::integer_c<int, -1>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xh, mhn::integer_c<int, -5>>::type::value, "!!!"
  );
  static_assert(
    !mhn::equals<xh, mhn::integer_c<int, -23>>::type::value, "!!!"
  );

  static_assert(mhn::not_equals<xa, xc>::type::value, "!!!");
  static_assert(mhn::not_equals<xc, xg>::type::value, "!!!");
  static_assert(!mhn::not_equals<xg, xg>::type::value, "!!!");

  static_assert(!mhn::logical_and<xa, xa>::type::value, "!!!");
  static_assert(!mhn::logical_and<xa, xb>::type::value, "!!!");
  static_assert(!mhn::logical_and<xc, xa>::type::value, "!!!");
  static_assert(mhn::logical_and<xd, xe>::type::value, "!!!");

  static_assert(!mhn::logical_or<xa, xa>::type::value, "!!!");
  static_assert(mhn::logical_or<xa, xb>::type::value, "!!!");
  static_assert(mhn::logical_or<xc, xa>::type::value, "!!!");
  static_assert(mhn::logical_or<xd, xe>::type::value, "!!!");

  static_assert(mhn::logical_not<xa>::type::value, "!!!");
  static_assert(!mhn::logical_not<xb>::type::value, "!!!");
  static_assert(!mhn::logical_not<xc>::type::value, "!!!");

  static_assert(mhn::less<xa, xd>::type::value, "!!!");
  static_assert(mhn::less<xb, xe>::type::value, "!!!");
  static_assert(mhn::less<xg, xc>::type::value, "!!!");
  static_assert(!mhn::less<xg, xg>::type::value, "!!!");
  static_assert(!mhn::less<xd, xa>::type::value, "!!!");
  static_assert(!mhn::less<xe, xb>::type::value, "!!!");
  static_assert(!mhn::less<xc, xg>::type::value, "!!!");

  static_assert(mhn::less_equal<xf, xf>::type::value, "!!!");
  static_assert(mhn::less_equal<xf, xe>::type::value, "!!!");
  static_assert(!mhn::less_equal<xe, xf>::type::value, "!!!");

  static_assert(mhn::greater<xd, xa>::type::value, "!!!");
  static_assert(mhn::greater<xe, xb>::type::value, "!!!");
  static_assert(mhn::greater<xc, xg>::type::value, "!!!");
  static_assert(!mhn::greater<xg, xg>::type::value, "!!!");
  static_assert(!mhn::greater<xa, xd>::type::value, "!!!");
  static_assert(!mhn::greater<xb, xe>::type::value, "!!!");
  static_assert(!mhn::greater<xg, xc>::type::value, "!!!");

  static_assert(mhn::greater_equal<xd, xa>::type::value, "!!!");
  static_assert(mhn::greater_equal<xd, xd>::type::value, "!!!");
  static_assert(!mhn::greater_equal<xa, xd>::type::value, "!!!");

  static_assert(mhn::incr<xa>::type::value == 1, "!!!");
  static_assert(mhn::decr<xa>::type::value == -1, "!!!");
  static_assert(mhn::incr<xb>::type::value == 2, "!!!");
  static_assert(mhn::decr<xb>::type::value == 0, "!!!");
  static_assert(mhn::incr<xh>::type::value == -4, "!!!");
  static_assert(mhn::decr<xh>::type::value == -6, "!!!");

  static_assert(mhn::add<xa, xb>::type::value == 1, "!!!");
  static_assert(mhn::add<xb, xa>::type::value == 1, "!!!");
  static_assert(mhn::add<xb, xc>::type::value == 3, "!!!");
  static_assert(mhn::add<xc, xb>::type::value == 3, "!!!");
  static_assert(mhn::add<xi, xc>::type::value == -8, "!!!");
  static_assert(mhn::add<xc, xi>::type::value == -8, "!!!");
  static_assert(mhn::add<xe, xg, xb, xa>::type::value == 9, "!!!");

  static_assert(mhn::sub<xc, xd>::type::value == -3, "!!!");
  static_assert(mhn::sub<xd, xc>::type::value == 3, "!!!");
  static_assert(mhn::sub<xc, xh>::type::value == 7, "!!!");
  static_assert(mhn::sub<xh, xc>::type::value == -7, "!!!");

  static_assert(mhn::mul<xe, xa>::type::value == 0, "!!!");
  static_assert(mhn::mul<xa, xe>::type::value == 0, "!!!");
  static_assert(mhn::mul<xe, xd>::type::value == 50, "!!!");
  static_assert(mhn::mul<xd, xe>::type::value == 50, "!!!");
  static_assert(mhn::mul<xe, xh>::type::value == -50, "!!!");
  static_assert(mhn::mul<xd, xi>::type::value == -50, "!!!");
  static_assert(mhn::mul<xh, xi>::type::value == 50, "!!!");
  static_assert(mhn::mul<xi, xh>::type::value == 50, "!!!");

  static_assert(mhn::abs<xa>::type::value == 0, "!!!");
  static_assert(mhn::abs<xb>::type::value == 1, "!!!");
  static_assert(mhn::abs<xh>::type::value == 5, "!!!");

  static_assert(mhn::sign<xa>::type::value == 0, "!!!");
  static_assert(mhn::sign<xc>::type::value == 1, "!!!");
  static_assert(mhn::sign<xi>::type::value == -1, "!!!");

  static_assert(mhn::negate<xa>::type::value == 0, "!!!");
  static_assert(mhn::negate<xd>::type::value == -5, "!!!");
  static_assert(mhn::negate<xf>::type::value == 1, "!!!");

  static_assert(mhn::div<xa, xb>::type::value == 0, "!!!");
  static_assert(mhn::div<xa, xd>::type::value == 0, "!!!");
  static_assert(mhn::div<xa, xg>::type::value == 0, "!!!");

  static_assert(
    mhn::div<mhn::integer_c<IntType, 3>, xc>::type::value == 1, "!!!"
  );
  static_assert(
    mhn::mod<mhn::integer_c<IntType, 3>, xc>::type::value == 1, "!!!"
  );

  static_assert(
    mhn::mod<mhn::integer_c<IntType, 7>, xd>::type::value == 2, "!!!"
  );

  test_eq_types<
    typename mhn::mident<mhn::integer_c_tag<IntType>>::type,
    mhn::integer_c<IntType, 0>
  >();

  static_assert(mhn::mappend<xa, xa>::type::value == 0, "!!!");
  static_assert(mhn::mappend<xa, xd>::type::value == 5, "!!!");
  static_assert(mhn::mappend<xe, xd>::type::value == 15, "!!!");
  static_assert(mhn::mappend<xe, xf>::type::value == 9, "!!!");

  test_eq_types<
    typename mhn::to_string<xa>::type,
    mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::to_string<xb>::type,
    mhn::string<'1'>
  >();
  test_eq_types<
    typename mhn::to_string<xc>::type,
    mhn::string<'2'>
  >();
  test_eq_types<
    typename mhn::to_string<xd>::type,
    mhn::string<'5'>
  >();
  test_eq_types<
    typename mhn::to_string<xe>::type,
    mhn::string<'1', '0'>
  >();
  test_eq_types<
    typename mhn::to_string<xf>::type,
    mhn::string<'-', '1'>
  >();
  test_eq_types<
    typename mhn::to_string<xg>::type,
    mhn::string<'-', '2'>
  >();
  test_eq_types<
    typename mhn::to_string<xh>::type,
    mhn::string<'-', '5'>
  >();
  test_eq_types<
    typename mhn::to_string<xi>::type,
    mhn::string<'-', '1', '0'>
  >();
  test_eq_types<
    typename mhn::to_string<mhn::integer_c<IntType, -125>>::type,
    mhn::string<'-', '1', '2', '5'>
  >();
}


template <typename UIntType>
constexpr void integer_c_test_unsigned()
{
  using xa = mhn::integer_c<UIntType, 0>;
  using xb = mhn::integer_c<UIntType, 1>;
  using xc = mhn::integer_c<UIntType, 2>;
  using xd = mhn::integer_c<UIntType, 3>;
  using xe = mhn::integer_c<UIntType, 7>;
  using xf = mhn::integer_c<UIntType, 15>;
  using xg = mhn::integer_c<UIntType, 0xff>; // == 255
  using xh = mhn::integer_c<UIntType, 0x96>;
  using xi = mhn::integer_c<UIntType, 128>;

  static_assert(
    mhn::equals<xa, mhn::integer_c<unsigned, 0>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xc, mhn::integer_c<unsigned, 2>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<xf, mhn::integer_c<unsigned, 15>>::type::value, "!!!"
  );
  static_assert(
    !mhn::equals<xe, mhn::integer_c<unsigned, 15>>::type::value, "!!!"
  );

  static_assert(mhn::not_equals<xb, xe>::type::value, "!!!");
  static_assert(mhn::not_equals<xe, xb>::type::value, "!!!");
  static_assert(!mhn::not_equals<xe, xe>::type::value, "!!!");

  static_assert(!mhn::logical_and<xa, xa>::type::value, "!!!");
  static_assert(!mhn::logical_and<xa, xb>::type::value, "!!!");
  static_assert(!mhn::logical_and<xc, xa>::type::value, "!!!");
  static_assert(mhn::logical_and<xd, xe>::type::value, "!!!");

  static_assert(!mhn::logical_or<xa, xa>::type::value, "!!!");
  static_assert(mhn::logical_or<xa, xb>::type::value, "!!!");
  static_assert(mhn::logical_or<xc, xa>::type::value, "!!!");
  static_assert(mhn::logical_or<xd, xe>::type::value, "!!!");

  static_assert(mhn::logical_not<xa>::type::value, "!!!");
  static_assert(!mhn::logical_not<xb>::type::value, "!!!");
  static_assert(!mhn::logical_not<xc>::type::value, "!!!");

  static_assert(mhn::bit_and<xa, xa>::type::value == 0x00, "!!!");
  static_assert(mhn::bit_and<xa, xg>::type::value == 0x00, "!!!");
  static_assert(mhn::bit_and<xh, xg>::type::value == 0x96, "!!!");
  static_assert(mhn::bit_and<xg, xg>::type::value == 0xff, "!!!");

  static_assert(mhn::bit_or<xa, xa>::type::value == 0x00, "!!!");
  static_assert(mhn::bit_or<xh, xa>::type::value == 0x96, "!!!");
  static_assert(mhn::bit_or<xa, xg>::type::value == 0xff, "!!!");
  static_assert(mhn::bit_or<xh, xg>::type::value == 0xff, "!!!");
  static_assert(mhn::bit_or<xg, xg>::type::value == 0xff, "!!!");

  static_assert(mhn::bit_xor<xa, xa>::type::value == 0x00, "!!!");
  static_assert(mhn::bit_xor<xh, xa>::type::value == 0x96, "!!!");
  static_assert(mhn::bit_xor<xg, xa>::type::value == 0xff, "!!!");
  static_assert(mhn::bit_xor<xh, xg>::type::value == 0x69, "!!!");
  static_assert(mhn::bit_xor<xg, xg>::type::value == 0x00, "!!!");
  static_assert(mhn::bit_xor<xh, xh>::type::value == 0x00, "!!!");

  static_assert(mhn::shift_left<xb, xd>::type::value == 0x08, "!!!");
  static_assert(mhn::shift_right<xi, xd>::type::value == 0x10, "!!!");

  static_assert(mhn::less<xa, xc>::type::value, "!!!");
  static_assert(mhn::less<xc, xd>::type::value, "!!!");
  static_assert(!mhn::less<xd, xd>::type::value, "!!!");
  static_assert(!mhn::less<xf, xd>::type::value, "!!!");
  static_assert(!mhn::less<xc, xa>::type::value, "!!!");
  static_assert(!mhn::less<xd, xc>::type::value, "!!!");

  static_assert(mhn::less_equal<xc, xe>::type::value, "!!!");
  static_assert(mhn::less_equal<xe, xe>::type::value, "!!!");
  static_assert(!mhn::less_equal<xe, xc>::type::value, "!!!");

  static_assert(mhn::greater<xc, xa>::type::value, "!!!");
  static_assert(mhn::greater<xd, xc>::type::value, "!!!");
  static_assert(!mhn::greater<xd, xd>::type::value, "!!!");
  static_assert(!mhn::greater<xd, xf>::type::value, "!!!");
  static_assert(!mhn::greater<xa, xc>::type::value, "!!!");
  static_assert(!mhn::greater<xc, xd>::type::value, "!!!");

  static_assert(mhn::greater_equal<xf, xe>::type::value, "!!!");
  static_assert(mhn::greater_equal<xe, xe>::type::value, "!!!");
  static_assert(!mhn::greater_equal<xe, xf>::type::value, "!!!");

  static_assert(mhn::incr<xa>::type::value == 1, "!!!");
  static_assert(mhn::incr<xe>::type::value == 8, "!!!");

  static_assert(mhn::decr<xe>::type::value == 6, "!!!");

  static_assert(mhn::add<xa, xa>::type::value == 0, "!!!");
  static_assert(mhn::add<xa, xc>::type::value == 2, "!!!");
  static_assert(mhn::add<xc, xa>::type::value == 2, "!!!");
  static_assert(mhn::add<xd, xe>::type::value == 10, "!!!");
  static_assert(mhn::add<xe, xd>::type::value == 10, "!!!");

  static_assert(mhn::sub<xa, xa>::type::value == 0, "!!!");
  static_assert(mhn::sub<xf, xf>::type::value == 0, "!!!");
  static_assert(mhn::sub<xf, xa>::type::value == 15, "!!!");
  static_assert(mhn::sub<xf, xd>::type::value == 12, "!!!");

  static_assert(mhn::mul<xa, xa>::type::value == 0, "!!!");
  static_assert(mhn::mul<xe, xa>::type::value == 0, "!!!");
  static_assert(mhn::mul<xa, xe>::type::value == 0, "!!!");
  static_assert(mhn::mul<xd, xe>::type::value == 21, "!!!");
  static_assert(mhn::mul<xe, xd>::type::value == 21, "!!!");
  static_assert(mhn::mul<xe, xd, xc>::type::value == 42, "!!!");

  static_assert(mhn::abs<xa>::type::value == 0, "!!!");
  static_assert(mhn::abs<xd>::type::value == 3, "!!!");

  static_assert(mhn::sign<xa>::type::value == 0, "!!!");
  static_assert(mhn::sign<xb>::type::value == 1, "!!!");
  static_assert(mhn::sign<xd>::type::value == 1, "!!!");

  static_assert(mhn::negate<xa>::type::value == 0, "!!!");
  static_assert(mhn::negate<xb>::type::value == (UIntType)-1, "!!!");
  static_assert(mhn::negate<xd>::type::value == (UIntType)-3, "!!!");

  static_assert(mhn::div<xa, xd>::type::value == 0, "!!!");
  static_assert(mhn::div<xf, xd>::type::value == 5, "!!!");
  static_assert(mhn::div<xe, xd>::type::value == 2, "!!!");

  static_assert(mhn::mod<xf, xd>::type::value == 0, "!!!");
  static_assert(mhn::mod<xe, xd>::type::value == 1, "!!!");

  test_eq_types<
    typename mhn::mident<mhn::integer_c_tag<UIntType>>::type,
    mhn::integer_c<UIntType, 0>
  >();

  static_assert(mhn::mappend<xa, xa>::type::value == 0, "!!!");
  static_assert(mhn::mappend<xa, xc>::type::value == 2, "!!!");
  static_assert(mhn::mappend<xd, xe>::type::value == 10, "!!!");

  test_eq_types<
    typename mhn::to_string<xa>::type,
    mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::to_string<xb>::type,
    mhn::string<'1'>
  >();
  test_eq_types<
    typename mhn::to_string<xc>::type,
    mhn::string<'2'>
  >();
  test_eq_types<
    typename mhn::to_string<xd>::type,
    mhn::string<'3'>
  >();
  test_eq_types<
    typename mhn::to_string<xe>::type,
    mhn::string<'7'>
  >();
  test_eq_types<
    typename mhn::to_string<xf>::type,
    mhn::string<'1', '5'>
  >();
  test_eq_types<
    typename mhn::to_string<mhn::integer_c<UIntType, 245>>::type,
    mhn::string<'2', '4', '5'>
  >();
};

int main()
{
  static_assert(
    !mhn::logical_and<mhn::false_, mhn::false_>::type::value, "!!!"
  );
  static_assert(
    !mhn::logical_and<mhn::false_, mhn::true_>::type::value, "!!!"
  );
  static_assert(
    !mhn::logical_and<mhn::true_, mhn::false_>::type::value, "!!!"
  );
  static_assert(
    mhn::logical_and<mhn::true_, mhn::true_>::type::value, "!!!"
  );

  static_assert(
    !mhn::logical_or<mhn::false_, mhn::false_>::type::value, "!!!"
  );
  static_assert(
    mhn::logical_or<mhn::bool_<false>, mhn::true_>::type::value, "!!!"
  );
  static_assert(
    mhn::logical_or<mhn::bool_<true>, mhn::false_>::type::value, "!!!"
  );
  static_assert(
    mhn::logical_or<mhn::true_, mhn::true_>::type::value, "!!!"
  );

  static_assert(mhn::logical_not<mhn::false_>::type::value, "!!!");
  static_assert(!mhn::logical_not<mhn::true_>::type::value, "!!!");
  static_assert(!mhn::logical_not<mhn::true_>::type::value, "!!!");

  integer_c_test_signed<char>();
  integer_c_test_signed<short>();
  integer_c_test_signed<int>();
  integer_c_test_signed<long>();
  integer_c_test_signed<long long>();

  integer_c_test_unsigned<unsigned char>();
  integer_c_test_unsigned<unsigned short>();
  integer_c_test_unsigned<unsigned int>();
  integer_c_test_unsigned<unsigned long>();
  integer_c_test_unsigned<unsigned long long>();

  test_eq_types<
    typename mhn::to_string<mhn::int_<-93827352>>::type,
    mhn::string<'-', '9', '3', '8', '2', '7', '3', '5', '2'>
  >();
}
