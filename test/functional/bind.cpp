// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;


template <typename MFnC, typename... Args>
using ivkr = typename MFnC::template apply<Args...>::type;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};

template <typename...> struct res { using type = res; };


struct make_res_1
{
  template <typename T0>
  struct apply : res<T0> {};
};

struct make_res_2
{
  template <typename T0, typename T1>
  struct apply : res<T0, T1> {};
};

struct make_res_3
{
  template <typename T0, typename T1, typename T2>
  struct apply : res<T0, T1, T2> {};
};

struct make_res
{
  template <typename... Ts>
  struct apply : res<Ts...> {};
};


using bres1f_a = mhn::bind<make_res_1, x0>;
using bres1f_b = mhn::bind<make_res_1, _1>;
using bres1f_c = mhn::bind<make_res_1, _2>;

using bres2f_a = mhn::bind<make_res_2, x0, x1>;
using bres2f_b = mhn::bind<make_res_2, x0, _1>;
using bres2f_c = mhn::bind<make_res_2, x0, _2>;
using bres2f_d = mhn::bind<make_res_2, _1, x1>;
using bres2f_e = mhn::bind<make_res_2, _2, x1>;
using bres2f_f = mhn::bind<make_res_2, _1, _1>;
using bres2f_g = mhn::bind<make_res_2, _1, _2>;
using bres2f_h = mhn::bind<make_res_2, _2, _1>;
using bres2f_i = mhn::bind<make_res_2, _2, _2>;

using bres3f_a = mhn::bind<make_res_3, x0, x1, x2>;
using bres3f_b = mhn::bind<make_res_3, x0, x1, _1>;
using bres3f_c = mhn::bind<make_res_3, x0, x1, _2>;
using bres3f_d = mhn::bind<make_res_3, x0, x1, _3>;
using bres3f_e = mhn::bind<make_res_3, x0, _1, x2>;
using bres3f_f = mhn::bind<make_res_3, x0, _2, x2>;
using bres3f_g = mhn::bind<make_res_3, x0, _3, x2>;
using bres3f_h = mhn::bind<make_res_3, _1, x1, x2>;
using bres3f_i = mhn::bind<make_res_3, _2, x1, x2>;
using bres3f_j = mhn::bind<make_res_3, _3, x1, x2>;
using bres3f_k = mhn::bind<make_res_3, _1, _2, _3>;


int main()
{
  test_eq_types<ivkr<bres1f_a>        , res<x0>>();
  test_eq_types<ivkr<bres1f_a, x1>    , res<x0>>();
  test_eq_types<ivkr<bres1f_a, x1, x2>, res<x0>>();

  test_eq_types<ivkr<bres2f_a>        , res<x0, x1>>();
  test_eq_types<ivkr<bres2f_a, x1>    , res<x0, x1>>();
  test_eq_types<ivkr<bres2f_a, x1, x2>, res<x0, x1>>();

  test_eq_types<ivkr<bres2f_a, x1>    , res<x0, x1>>();
  test_eq_types<ivkr<bres2f_a, x2>    , res<x0, x1>>();
  test_eq_types<ivkr<bres2f_a, x1, x2>, res<x0, x1>>();

  test_eq_types<ivkr<bres2f_b, x2, x1>, res<x0, x2>>();
  test_eq_types<ivkr<bres2f_b, x3, x1>, res<x0, x3>>();
  test_eq_types<ivkr<bres2f_b, x3, x3>, res<x0, x3>>();


  test_eq_types<
    ivkr<
      mhn::bind<
        make_res,
        _1,
        mhn::bind<make_res, mhn::bind<make_res, _2>, _4, _5>,
        _3
      >,
      x0, x1, x2, x3, x4
    >,
    res<x0, res<res<x1>, x3, x4>, x2>
  >();

  test_eq_types<
    ivkr<
      mhn::bind<
        make_res,
        _2, _3, _1,
        mhn::protect<mhn::bind<make_res, x0, _2, _1>>,
        mhn::protect<_1>,
        mhn::bind<make_res, _5, _4>
      >,
      x0, x1, x2, x3, x4
    >,
    res<x1, x2, x0, mhn::bind<make_res, x0, _2, _1>, _1, res<x4, x3>>
  >();


  return EXIT_SUCCESS;
}
