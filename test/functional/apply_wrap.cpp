// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/apply_wrap.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};


struct get_first
{
  template <typename X0, typename... Xs>
  struct apply { using type = X0; };
};

struct get_second
{
  template <typename X0, typename X1, typename... Xs>
  struct apply { using type = X1; };
};

struct get_third
{
  template <typename X0, typename X1, typename X2, typename... Xs>
  struct apply { using type = X2; };
};


int main()
{
  test_eq_types<
    typename mhn::apply_wrap<get_first, x0, x1, x2, x3, x4>::type,
    x0
  >();
  test_eq_types<
    typename mhn::apply_wrap<get_second, x0, x1, x2, x3, x4>::type,
    x1
  >();
  test_eq_types<
    typename mhn::apply_wrap<get_third, x0, x1, x2, x3, x4>::type,
    x2
  >();
}
