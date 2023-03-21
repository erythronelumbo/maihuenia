// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>

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
struct x5 {};
struct x6 {};
struct x7 {};
struct x8 {};
struct x9 {};

template <typename...> struct expr0 { using type = expr0; };
template <typename...> struct expr1 { using type = expr1; };
template <typename...> struct expr2 { using type = expr2; };
template <typename...> struct expr3 { using type = expr3; };
template <typename...> struct expr4 { using type = expr4; };


int main()
{
  test_eq_types<ivkr<mhn::lambda<_1>, x0>, x0>();
  test_eq_types<ivkr<mhn::lambda<_1>, x0, x1>, x0>();
  test_eq_types<ivkr<mhn::lambda<_1>, x0, x1, x2>, x0>();
  test_eq_types<ivkr<mhn::lambda<_1>, x0, x1, x2, x3>, x0>();
  test_eq_types<ivkr<mhn::lambda<_1>, x0, x1, x2, x3, x4>, x0>();

  test_eq_types<ivkr<mhn::lambda<_2>, x0, x1>, x1>();
  test_eq_types<ivkr<mhn::lambda<_2>, x0, x1, x2>, x1>();
  test_eq_types<ivkr<mhn::lambda<_2>, x0, x1, x2, x3>, x1>();
  test_eq_types<ivkr<mhn::lambda<_2>, x0, x1, x2, x3, x4>, x1>();

  test_eq_types<ivkr<mhn::lambda<_3>, x0, x1, x2>, x2>();
  test_eq_types<ivkr<mhn::lambda<_3>, x0, x1, x2, x3>, x2>();
  test_eq_types<ivkr<mhn::lambda<_3>, x0, x1, x2, x3, x4>, x2>();

  test_eq_types<ivkr<mhn::lambda<_4>, x0, x1, x2, x3>, x3>();
  test_eq_types<ivkr<mhn::lambda<_4>, x0, x1, x2, x3, x4>, x3>();

  test_eq_types<ivkr<mhn::lambda<_5>, x0, x1, x2, x3, x4>, x4>();

  test_eq_types<ivkr<mhn::lambda<expr0<_1>>, x0>                , expr0<x0>>();
  test_eq_types<ivkr<mhn::lambda<expr0<_2>>, x0, x1>            , expr0<x1>>();
  test_eq_types<ivkr<mhn::lambda<expr0<_3>>, x0, x1, x2>        , expr0<x2>>();
  test_eq_types<ivkr<mhn::lambda<expr0<_4>>, x0, x1, x2, x3>    , expr0<x3>>();
  test_eq_types<ivkr<mhn::lambda<expr0<_5>>, x0, x1, x2, x3, x4>, expr0<x4>>();
  test_eq_types<
    ivkr<mhn::lambda<expr0<_1, _1>>, x0>,
    expr0<x0, x0>
  >();
  test_eq_types<
    ivkr<mhn::lambda<expr0<_1, x4>>, x0>,
    expr0<x0, x4>
  >();
  test_eq_types<
    ivkr<mhn::lambda<expr0<x4, _1>>, x0>,
    expr0<x4, x0>
  >();
  test_eq_types<
    ivkr<mhn::lambda<expr0<_1, _2>>, x0, x1>,
    expr0<x0, x1>
  >();

  test_eq_types<
    ivkr<
      mhn::lambda<expr0<_1>>,
      x0
    >,
    expr0<x0>
  >();
  test_eq_types<
    ivkr<
      mhn::lambda<expr0<expr0<_1>>>,
      x0
    >,
    expr0<expr0<x0>>
  >();
  test_eq_types<
    ivkr<
      mhn::lambda<expr0<expr0<expr0<_1>>>>,
      x0
    >,
    expr0<expr0<expr0<x0>>>
  >();
  test_eq_types<
    ivkr<
      mhn::lambda<expr0<expr0<expr0<expr0<_1>>>>>,
      x0
    >,
    expr0<expr0<expr0<expr0<x0>>>>
  >();
  test_eq_types<
    ivkr<
      mhn::lambda<expr0<expr0<expr0<expr0<expr0<_1>>>>>>,
      x0
    >,
    expr0<expr0<expr0<expr0<expr0<x0>>>>>
  >();

  test_eq_types<
    ivkr<
      mhn::lambda<
        expr0<
          expr1<_1, _2>, int, _7, expr2<_3, _2>, expr3<_4, expr4<_5, _6, _1>>
        >
      >,
      x0, x1, x2, x3, x4, x5, x6
    >,
    expr0<expr1<x0, x1>, int, x6, expr2<x2, x1>, expr3<x3, expr4<x4, x5, x0>>>
  >();
  test_eq_types<
    ivkr<
      mhn::lambda<
        expr0<
          _10,
          expr4<
            _11,
            expr3<_1, _2, _3>,
            expr1<_4, _5, _6>,
            expr2<_7, _8, _9>
          >,
          _12,
          _13,
          expr4<
            expr3<_2, _9, _3>,
            expr1<_6, _5, _4>,
            expr2<_7, _1, _8>
          >,
          _14
        >
      >,
      x1, x2, x3, x4, x5, x6, x7, x8, x9, x0, void, x0, x0, int
    >,
    expr0<
      x0,
      expr4<
        void,
        expr3<x1, x2, x3>,
        expr1<x4, x5, x6>,
        expr2<x7, x8, x9>        
      >,
      x0,
      x0,
      expr4<
        expr3<x2, x9, x3>,
        expr1<x6, x5, x4>,
        expr2<x7, x1, x8>        
      >,
      int
    >
  >();

  test_eq_types<
    ivkr<
      mhn::lambda<
        expr0<
          _3, _2, _1, x9,
          mhn::protect<mhn::lambda<expr1<_1, _2, x8, expr1<_4, _3, x7>, _5>>>,
          float, _4, _5, _6
        >
      >,
      x0, x1, x2, x3, x4, x5
    >,
    expr0<
      x2, x1, x0, x9,
      mhn::lambda<expr1<_1, _2, x8, expr1<_4, _3, x7>, _5>>,
      float, x3, x4, x5
    >
  >();

  test_eq_types<
    ivkr<
      mhn::lambda<
        expr0<mhn::protect<mhn::lambda<_4>>, _3, _2, mhn::protect<_1>>
      >,
      x0, x1, x2, x3
    >,
    expr0<mhn::lambda<_4>, x2, x1, _1>
  >();

  return EXIT_SUCCESS;
}
