// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/ratio_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


template <typename IntType>
constexpr void test_ratio_signed()
{
  using x1 = mhn::ratio_c<IntType, 0, 1>;
  using x2 = mhn::ratio_c<IntType, 1, 1>;
  using x3 = mhn::ratio_c<IntType, 1, 2>;
  using x4 = mhn::ratio_c<IntType, 3, 5>;
  using x5 = mhn::ratio_c<IntType, -3, 2>;
  using x6 = mhn::ratio_c<IntType, -1, 7>;
  using x7 = mhn::ratio_c<IntType, -7, 13>;

  static_assert(
    mhn::equals<x1, mhn::ratio_c<int, 0, 1>>::type::value, "!!!"
  );
  static_assert(
    mhn::not_equals<x7, mhn::ratio_c<int, 0, 1>>::type::value, "!!!"
  );
  static_assert(
    mhn::equals<x7, mhn::ratio_c<int, -21, 39>>::type::value, "!!!"
  );

  static_assert(
    mhn::equals<
      typename mhn::add<x3, x4>::type,
      mhn::ratio_c<
        IntType,
        (x3::num*x4::den + x4::num*x3::den),
        (x3::den*x4::den)
      >
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::equals<
      typename mhn::sub<x3, x4>::type,
      mhn::ratio_c<
        IntType,
        (x3::num*x4::den - x4::num*x3::den),
        (x3::den*x4::den)
      >
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::equals<
      typename mhn::mul<x3, x4>::type,
      mhn::ratio_c<
        IntType,
        x3::num*x4::num,
        x3::den*x4::den
      >
    >::type::value,
    "!!!"
  );

  test_eq_types<
    typename mhn::quot<x3, mhn::ratio_c<IntType, 0, 1>>::type,
    mhn::not_a_number
  >();
}


int main()
{
  test_ratio_signed<int>();
}
