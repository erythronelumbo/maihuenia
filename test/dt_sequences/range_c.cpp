// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/range_c.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


int main()
{
  using rg1 = mhn::range_c<int, 0, 10, 1>;
  using rg2 = mhn::range_c<int, 10, 11, -1>;
  using rg3 = mhn::range_c<int, -6, 5, 3>;
  using rg4 = mhn::range_c<int, 0, 0, 1>;

  static_assert(mhn::equals<rg1, rg1>::type::value, "!!!");
  static_assert(!mhn::equals<rg1, rg2>::type::value, "!!!");
  static_assert(!mhn::equals<rg1, rg3>::type::value, "!!!");
  static_assert(!mhn::equals<rg1, rg4>::type::value, "!!!");
  static_assert(mhn::equals<rg2, rg2>::type::value, "!!!");
  static_assert(!mhn::equals<rg2, rg3>::type::value, "!!!");
  static_assert(!mhn::equals<rg2, rg4>::type::value, "!!!");
  static_assert(mhn::equals<rg3, rg3>::type::value, "!!!");
  static_assert(!mhn::equals<rg3, rg4>::type::value, "!!!");
  static_assert(mhn::equals<rg4, rg4>::type::value, "!!!");

  return EXIT_SUCCESS;
}
