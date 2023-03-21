// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/always.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


template <typename MFnC, typename... Args>
using ivkr = typename MFnC::template apply<Args...>::type;

struct z0 {};

struct y0;
struct y1 {};
struct y2 : z0 {};

struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};
struct x6 {};
struct x7 {};
struct x8 {};
struct x9 {};


template <typename T>
constexpr void test_always()
{
  test_eq_types<
    ivkr<mhn::always<T>>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4, x5>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4, x5, x6>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4, x5, x6, x7>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4, x5, x6, x7, x8>, T
  >();
  test_eq_types<
    ivkr<mhn::always<T>, x0, x1, x2, x3, x4, x5, x6, x7, x8, x9>, T
  >();
}


int main()
{
  test_always<void>();
  test_always<y0>();
  test_always<y1>();
  test_always<y2>();
}
