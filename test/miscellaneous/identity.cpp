// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/identity.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


struct z0 {};

struct y0;
struct y1 {};
struct y2 : z0 {};


int main()
{
  test_eq_types<typename mhn::identity<void>::type, void>();
  test_eq_types<typename mhn::identity<void*>::type, void*>();
  test_eq_types<typename mhn::identity<bool>::type, bool>();
  test_eq_types<typename mhn::identity<char>::type, char>();
  test_eq_types<typename mhn::identity<short>::type, short>();
  test_eq_types<typename mhn::identity<int>::type, int>();
  test_eq_types<typename mhn::identity<long>::type, long>();
  test_eq_types<typename mhn::identity<long long>::type, long long>();
  test_eq_types<typename mhn::identity<y0>::type, y0>();
  test_eq_types<typename mhn::identity<y1>::type, y1>();
  test_eq_types<typename mhn::identity<y2>::type, y2>();
}
