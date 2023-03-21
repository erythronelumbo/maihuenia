// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/undefined.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};


int main()
{
  test_eq_types<
    typename mhn::unless_undefined<x0, x1>::type,
    x0
  >();
  test_eq_types<
    typename mhn::unless_undefined<mhn::undefined, x1>::type,
    x1
  >();

  return EXIT_SUCCESS;
}
