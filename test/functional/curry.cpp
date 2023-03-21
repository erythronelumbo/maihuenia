// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/curry.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};

template <typename...> struct dummy { using type = dummy; };


struct make_dummy
{
  template <typename... Xs>
  using apply = dummy<Xs...>;
};


using curried1a = typename mhn::curry<
  make_dummy, 1
>::template apply<
  x0
>::type;

using curried2a = typename mhn::curry<
  make_dummy, 2
>::template apply<
  x0, x1
>::type;

using curried2b = typename mhn::curry<
  make_dummy, 2
>::template apply<
  x0
>::template apply<
  x1
>::type;

using curried3a = typename mhn::curry<
  make_dummy, 3
>::template apply<
  x0, x1, x2
>::type;

using curried3b = typename mhn::curry<
  make_dummy, 3
>::template apply<
  x0
>::template apply<
  x1, x2
>::type;

using curried3c = typename mhn::curry<
  make_dummy, 3
>::template apply<
  x0, x1
>::template apply<
  x2
>::type;

using curried3d = typename mhn::curry<
  make_dummy, 3
>::template apply<
  x0
>::template apply<
  x1
>::template apply<
  x2
>::type;

using curried4a = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0, x1, x2, x3
>::type;

using curried4b = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0
>::template apply<
  x1, x2, x3
>::type;

using curried4c = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0, x1, x2
>::template apply<
  x3
>::type;

using curried4d = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0, x1
>::template apply<
  x2, x3
>::type;

using curried4e = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0
>::template apply<
  x1, x2
>::template apply<
  x3
>::type;

using curried4f = typename mhn::curry<
  make_dummy, 4
>::template apply<
  x0
>::template apply<
  x1
>::template apply<
  x2
>::template apply<
  x3
>::type;


int main()
{
  test_eq_types<curried1a, dummy<x0>>();

  test_eq_types<curried2a, dummy<x0, x1>>();
  test_eq_types<curried2b, dummy<x0, x1>>();

  test_eq_types<curried3a, dummy<x0, x1, x2>>();
  test_eq_types<curried3b, dummy<x0, x1, x2>>();
  test_eq_types<curried3c, dummy<x0, x1, x2>>();
  test_eq_types<curried3d, dummy<x0, x1, x2>>();

  test_eq_types<curried4a, dummy<x0, x1, x2, x3>>();
  test_eq_types<curried4b, dummy<x0, x1, x2, x3>>();
  test_eq_types<curried4c, dummy<x0, x1, x2, x3>>();
  test_eq_types<curried4d, dummy<x0, x1, x2, x3>>();
  test_eq_types<curried4e, dummy<x0, x1, x2, x3>>();
  test_eq_types<curried4f, dummy<x0, x1, x2, x3>>();

  return EXIT_SUCCESS;
}
