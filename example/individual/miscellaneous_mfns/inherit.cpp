// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/empty_base.hpp>
#include <erythronelumbo/maihuenia/inherit.hpp>


namespace mhn = erythronelumbo::maihuenia;


struct char_box { char v; };
struct int_box { int v; };
struct double_box { double v; };
struct vec3d { double x, y, z; };

using res1 = typename mhn::inherit<>::type;
using res2 = typename mhn::inherit<int_box>::type;
using res3 = mhn::inherit_t<mhn::empty_base>;
using res4 = mhn::inherit_t<mhn::empty_base, mhn::empty_base>;
using res5 = mhn::inherit_t<mhn::empty_base, mhn::empty_base, mhn::empty_base>;
using res6 = typename mhn::inherit<double_box, mhn::empty_base>::type;
using res7 = typename mhn::inherit<mhn::empty_base, char_box>::type;
using res8 = typename mhn::inherit<double_box, char_box, int_box>::type;
using res9 = typename mhn::inherit<
  double_box, char_box, int_box, vec3d
>::type;


int main()
{
  return EXIT_SUCCESS;
}
