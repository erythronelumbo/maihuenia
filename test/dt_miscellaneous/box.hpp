// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/box.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct x0;
struct x1 {};
struct x2 : x1 {};

int main()
{
  using box1 = mhn::box<x0>;
  using box2 = mhn::box<x1>;
  using box3 = mhn::box<x2>;
  using box4 = mhn::box<void>;
  using box5 = mhn::box<int>;

  test_eq_types<typename box1::type, box1>();
  test_eq_types<typename box2::type, box2>();
  test_eq_types<typename box3::type, box3>();
  test_eq_types<typename box4::type, box4>();
  test_eq_types<typename box5::type, box5>();

  test_eq_types<typename box1::elem, x0>();
  test_eq_types<typename box2::elem, x1>();
  test_eq_types<typename box3::elem, x2>();
  test_eq_types<typename box4::elem, void>();
  test_eq_types<typename box5::elem, int>();

  return EXIT_SUCCESS;
}
