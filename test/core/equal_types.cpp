// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>


namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};


int main()
{
  static_assert(mhn::equal_types<x0, x0>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1>::type::value, "!!!");

  static_assert(mhn::equal_types<x0, x0, x0>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2>::type::value, "!!!");

  static_assert(mhn::equal_types<x0, x0, x0, x0>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x0, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x1, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2, x3>::type::value, "!!!");

  static_assert(mhn::equal_types<x0, x0, x0, x0, x0>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x0, x0, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x0, x1, x1>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x0, x1, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1, x1, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1, x2, x2>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x0, x1, x2, x3>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x1, x2, x3>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2, x2, x3>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2, x3, x3>::type::value, "!!!");
  static_assert(!mhn::equal_types<x0, x1, x2, x3, x4>::type::value, "!!!");

  return EXIT_SUCCESS;
}
