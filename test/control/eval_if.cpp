// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};

struct fn0 { using type = x0; };
struct fn1 { using type = x1; };


int main()
{
  test_eq_types<typename mhn::eval_if_c<false, fn0, fn1>::type, x1>();
  test_eq_types<typename mhn::eval_if_c<true , fn0, fn1>::type, x0>();

  test_eq_types<typename mhn::eval_if<mhn::false_, fn0, fn1>::type, x1>();
  test_eq_types<typename mhn::eval_if<mhn::true_ , fn0, fn1>::type, x0>();
}
