// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/empty_base.hpp>
#include <erythronelumbo/maihuenia/inherit.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


struct vl0_ { enum { value = 0 }; };
struct vl1_ { enum { value = 1 }; };

template <typename Base>
constexpr vl1_ test_inheritance_(Base*);

template <typename Base>
constexpr vl0_ test_inheritance_(...);

template <typename Derived, typename Base>
struct inherits_from :
  decltype(test_inheritance_<Base>((Derived*)nullptr))
{};


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};

template <typename InheritMfn, typename Derived>
constexpr void test_inherits_from()
{
  static_assert(
    inherits_from<typename InheritMfn::type, Derived>::value,
    "!!!"
  );
}


int main()
{
  using eb = mhn::empty_base;


  test_inherits_from<mhn::inherit<>, eb>();

  test_inherits_from<mhn::inherit<eb>, eb>();
  test_inherits_from<mhn::inherit<x0>, x0>();


  test_inherits_from<mhn::inherit<eb, eb>, eb>();

  test_inherits_from<mhn::inherit<x0, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, x0>, x0>();

  test_inherits_from<mhn::inherit<x0, x1>, x0>();
  test_inherits_from<mhn::inherit<x0, x1>, x1>();


  test_inherits_from<mhn::inherit<eb, eb, eb>, eb>();

  test_inherits_from<mhn::inherit<x0, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0>, x0>();

  test_inherits_from<mhn::inherit<x0, x1, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, x1>, x1>();

  test_inherits_from<mhn::inherit<x0, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2>, x2>();


  test_inherits_from<mhn::inherit<eb, eb, eb, eb>, eb>();

  test_inherits_from<mhn::inherit<x0, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0>, x0>();

  test_inherits_from<mhn::inherit<x0, x1, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1>, x1>();

  test_inherits_from<mhn::inherit<x0, x1, x2, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2>, x2>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3>, x3>();


  test_inherits_from<mhn::inherit<eb, eb, eb, eb, eb>, eb>();

  test_inherits_from<mhn::inherit<x0, eb, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, eb, x0>, x0>();

  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, x1>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, x1>, x1>();

  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2>, x2>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3>, x3>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4>, x4>();


  test_inherits_from<mhn::inherit<eb, eb, eb, eb, eb, eb>, eb>();

  test_inherits_from<mhn::inherit<x0, eb, eb, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, eb, x0, eb>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, eb, eb, x0>, x0>();

  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, eb, x1>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, eb, x0, x1>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, eb, x1>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, eb, eb, x0, x1>, x1>();

  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, x1, x2>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, x1, x2>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, eb, x2>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, eb, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, eb, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, eb, x0, eb, x1, x2>, x2>();
  test_inherits_from<mhn::inherit<eb, eb, eb, x0, x1, x2>, x2>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2, x3>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2, x3>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2, x3>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, eb>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, eb>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, eb, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, eb, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, eb, eb, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, eb, x1, eb, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<x0, eb, eb, x1, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<eb, x0, eb, x1, x2, x3>, x3>();
  test_inherits_from<mhn::inherit<eb, eb, x0, x1, x2, x3>, x3>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, eb>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, x4>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, x4>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3, x4>, x0>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3, x4>, x0>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3, x4>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, eb>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, x4>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, x4>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3, x4>, x1>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3, x4>, x1>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3, x4>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, eb>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, x4>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, x4>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3, x4>, x2>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3, x4>, x2>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3, x4>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, eb>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, x4>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, x4>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3, x4>, x3>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3, x4>, x3>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3, x4>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, eb>, x4>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, eb, x4>, x4>();
  test_inherits_from<mhn::inherit<x0, x1, x2, eb, x3, x4>, x4>();
  test_inherits_from<mhn::inherit<x0, x1, eb, x2, x3, x4>, x4>();
  test_inherits_from<mhn::inherit<x0, eb, x1, x2, x3, x4>, x4>();
  test_inherits_from<mhn::inherit<eb, x0, x1, x2, x3, x4>, x4>();

  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x0>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x1>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x2>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x3>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x4>();
  test_inherits_from<mhn::inherit<x0, x1, x2, x3, x4, x5>, x5>();
}
