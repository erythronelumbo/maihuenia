// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/map.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};

struct y0 {};
struct y1 {};
struct y2 {};
struct y3 {};
struct y4 {};
struct y5 {};


template <
  typename M,
  typename E0 = mhn::index_out_of_range,
  typename E1 = mhn::index_out_of_range,
  typename E2 = mhn::index_out_of_range,
  typename E3 = mhn::index_out_of_range,
  typename E4 = mhn::index_out_of_range,
  typename E5 = mhn::index_out_of_range
>
constexpr void test_at_key()
{
  test_eq_types<typename mhn::at_key<M, x0>::type, E0>();
  test_eq_types<typename mhn::at_key<M, x1>::type, E1>();
  test_eq_types<typename mhn::at_key<M, x2>::type, E2>();
  test_eq_types<typename mhn::at_key<M, x3>::type, E3>();
  test_eq_types<typename mhn::at_key<M, x4>::type, E4>();
  test_eq_types<typename mhn::at_key<M, x5>::type, E5>();
}


int main()
{
  using map1 = mhn::map<>;
  using map2 = mhn::map<
    mhn::pair<x0, y0>
  >;
  using map3 = mhn::map<
    mhn::pair<x0, y0>,
    mhn::pair<x1, y1>
  >;
  using map4 = mhn::map<
    mhn::pair<x0, y0>,
    mhn::pair<x1, y1>,
    mhn::pair<x2, y2>,
    mhn::pair<x3, y3>,
    mhn::pair<x4, y4>
  >;

  static_assert(mhn::aempty<map1>::type::value, "!!!");
  static_assert(!mhn::aempty<map2>::type::value, "!!!");
  static_assert(!mhn::aempty<map3>::type::value, "!!!");
  static_assert(!mhn::aempty<map4>::type::value, "!!!");

  static_assert(!mhn::has_key<map1, x0>::type::value, "!!!");
  static_assert(mhn::has_key<map2, x0>::type::value, "!!!");
  static_assert(!mhn::has_key<map2, x1>::type::value, "!!!");
  static_assert(mhn::has_key<map3, x0>::type::value, "!!!");
  static_assert(mhn::has_key<map3, x1>::type::value, "!!!");
  static_assert(!mhn::has_key<map3, x2>::type::value, "!!!");
  static_assert(mhn::has_key<map4, x0>::type::value, "!!!");
  static_assert(mhn::has_key<map4, x1>::type::value, "!!!");
  static_assert(mhn::has_key<map4, x2>::type::value, "!!!");
  static_assert(mhn::has_key<map4, x3>::type::value, "!!!");
  static_assert(mhn::has_key<map4, x4>::type::value, "!!!");
  static_assert(!mhn::has_key<map4, x5>::type::value, "!!!");

  test_at_key<map1>();
  test_at_key<map2, y0>();
  test_at_key<map3, y0, y1>();
  test_at_key<map4, y0, y1, y2, y3, y4>();

  using new_elem1 = mhn::pair<x5, y5>;
  using new_elem2 = mhn::pair<x0, void>;

  test_eq_types<
    typename mhn::ainsert<map1, new_elem1>::type,
    mhn::map<new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<map2, new_elem1>::type,
    mhn::map<mhn::pair<x0, y0>, new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<map2, new_elem2>::type,
    mhn::map<mhn::pair<x0, y0>>
  >();
  test_eq_types<
    typename mhn::ainsert<map3, new_elem1>::type,
    mhn::map<mhn::pair<x0, y0>, mhn::pair<x1, y1>, new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<map3, new_elem2>::type,
    mhn::map<mhn::pair<x0, y0>, mhn::pair<x1, y1>>
  >();
  test_eq_types<
    typename mhn::ainsert<map4, new_elem1>::type,
    mhn::map<
      mhn::pair<x0, y0>,
      mhn::pair<x1, y1>,
      mhn::pair<x2, y2>,
      mhn::pair<x3, y3>,
      mhn::pair<x4, y4>,
      new_elem1
    >
  >();
  test_eq_types<
    typename mhn::ainsert<map4, new_elem2>::type,
    mhn::map<
      mhn::pair<x0, y0>,
      mhn::pair<x1, y1>,
      mhn::pair<x2, y2>,
      mhn::pair<x3, y3>,
      mhn::pair<x4, y4>
    >
  >();

  test_eq_types<
    typename mhn::aerase<map1, x0>::type,
    map1
  >();
  test_eq_types<
    typename mhn::aerase<map1, x1>::type,
    map1
  >();
  test_eq_types<
    typename mhn::aerase<map2, x0>::type,
    mhn::map<>
  >();
  test_eq_types<
    typename mhn::aerase<map2, x1>::type,
    map2
  >();
  test_eq_types<
    typename mhn::aerase<map3, x0>::type,
    mhn::map<mhn::pair<x1, y1>>
  >();
  test_eq_types<
    typename mhn::aerase<map3, x1>::type,
    mhn::map<mhn::pair<x0, y0>>
  >();
  test_eq_types<
    typename mhn::aerase<map3, x5>::type,
    map3
  >();

  return EXIT_SUCCESS;
}
