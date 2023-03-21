// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


struct xt {};
struct xf {};


int main()
{
  test_eq_types<typename mhn::if_c<false, xt, xf>::type, xf>();
  test_eq_types<typename mhn::if_c<true, xt, xf>::type, xt>();

  test_eq_types<typename mhn::if_<mhn::false_, xt, xf>::type, xf>();
  test_eq_types<typename mhn::if_<mhn::true_, xt, xf>::type, xt>();
}
