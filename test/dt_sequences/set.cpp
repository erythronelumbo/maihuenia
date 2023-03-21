// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/set.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};


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
  using set1 = mhn::set<>;
  using set2 = mhn::set<x0>;
  using set3 = mhn::set<x0, x1>;
  using set4 = mhn::set<x0, x1, x2, x3, x4>;

  static_assert(mhn::aempty<set1>::type::value, "!!!");
  static_assert(!mhn::aempty<set2>::type::value, "!!!");
  static_assert(!mhn::aempty<set3>::type::value, "!!!");
  static_assert(!mhn::aempty<set4>::type::value, "!!!");

  static_assert(!mhn::has_key<set1, x0>::type::value, "!!!");
  static_assert(mhn::has_key<set2, x0>::type::value, "!!!");
  static_assert(!mhn::has_key<set2, x1>::type::value, "!!!");
  static_assert(mhn::has_key<set3, x0>::type::value, "!!!");
  static_assert(mhn::has_key<set3, x1>::type::value, "!!!");
  static_assert(!mhn::has_key<set3, x2>::type::value, "!!!");
  static_assert(mhn::has_key<set4, x0>::type::value, "!!!");
  static_assert(mhn::has_key<set4, x1>::type::value, "!!!");
  static_assert(mhn::has_key<set4, x2>::type::value, "!!!");
  static_assert(mhn::has_key<set4, x3>::type::value, "!!!");
  static_assert(mhn::has_key<set4, x4>::type::value, "!!!");
  static_assert(!mhn::has_key<set4, x5>::type::value, "!!!");

  test_at_key<set1>();
  test_at_key<set2, x0>();
  test_at_key<set3, x0, x1>();
  test_at_key<set4, x0, x1, x2, x3, x4>();

  using new_elem1 = x5;
  using new_elem2 = x0;

  test_eq_types<
    typename mhn::ainsert<set1, new_elem1>::type,
    mhn::set<new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<set2, new_elem1>::type,
    mhn::set<x0, new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<set2, new_elem2>::type,
    mhn::set<x0>
  >();
  test_eq_types<
    typename mhn::ainsert<set3, new_elem1>::type,
    mhn::set<x0, x1, new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<set3, new_elem2>::type,
    mhn::set<x0, x1>
  >();
  test_eq_types<
    typename mhn::ainsert<set4, new_elem1>::type,
    mhn::set<x0, x1, x2, x3, x4, new_elem1>
  >();
  test_eq_types<
    typename mhn::ainsert<set4, new_elem2>::type,
    mhn::set<x0, x1, x2, x3, x4>
  >();

  test_eq_types<
    typename mhn::aerase<set1, x0>::type,
    set1
  >();
  test_eq_types<
    typename mhn::aerase<set1, x1>::type,
    set1
  >();
  test_eq_types<
    typename mhn::aerase<set2, x0>::type,
    mhn::set<>
  >();
  test_eq_types<
    typename mhn::aerase<set2, x1>::type,
    set2
  >();
  test_eq_types<
    typename mhn::aerase<set3, x0>::type,
    mhn::set<x1>
  >();
  test_eq_types<
    typename mhn::aerase<set3, x1>::type,
    mhn::set<x0>
  >();
  test_eq_types<
    typename mhn::aerase<set3, x5>::type,
    set3
  >();

  return EXIT_SUCCESS;
}
