// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/pair.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct x0;
struct x1 {};
struct x2 : x1 {};

int main()
{
  using p1 = mhn::pair<x0, x1>;
  using p2 = mhn::pair<x2, int>;
  using p3 = mhn::pair<void, int*>;

  test_eq_types<typename p1::type, p1>();
  test_eq_types<typename p2::type, p2>();
  test_eq_types<typename p3::type, p3>();

  test_eq_types<typename p1::first, x0>();
  test_eq_types<typename p1::second, x1>();
  test_eq_types<typename p2::first, x2>();
  test_eq_types<typename p2::second, int>();
  test_eq_types<typename p3::first, void>();
  test_eq_types<typename p3::second, int*>();

  return EXIT_SUCCESS;
}
