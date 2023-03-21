// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/transformed_view.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct y0 {};

struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};

template <typename T> struct res0 { using type = res0; };
template <typename, typename> struct res1 { using type = res1; };

struct res0_q
{
  template <typename T>
  using apply = res0<T>;
};

struct res1_q
{
  template <typename A, typename B>
  using apply = res1<A, B>;
};


template <
  typename L,
  typename E0 = mhn::index_out_of_range,
  typename E1 = mhn::index_out_of_range,
  typename E2 = mhn::index_out_of_range,
  typename E3 = mhn::index_out_of_range,
  typename E4 = mhn::index_out_of_range
>
constexpr void test_at()
{
  test_eq_types<typename mhn::at<L, mhn::int_<0>>::type, E0>();
  test_eq_types<typename mhn::at<L, mhn::int_<1>>::type, E1>();
  test_eq_types<typename mhn::at<L, mhn::int_<2>>::type, E2>();
  test_eq_types<typename mhn::at<L, mhn::int_<3>>::type, E3>();
  test_eq_types<typename mhn::at<L, mhn::int_<4>>::type, E4>();
}

template <typename L>
constexpr void test_drop()
{
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<0>>::type,
    L
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<1>>::type,
    mhn::pop_front_t<L>
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<2>>::type,
    mhn::pop_front_t<mhn::pop_front_t<L>>
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<3>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<L>>>
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<4>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<L>>>>
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<5>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<
      mhn::pop_front_t<L>
    >>>>
  >();
  test_eq_types<
    typename mhn::drop<L, mhn::size_c<6>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<
      mhn::pop_front_t<mhn::pop_front_t<L>>
    >>>>
  >();
}


int main()
{
  using lst1 = mhn::null_type;
  using lst2 = mhn::cons<x0>;
  using lst3 = mhn::cons<x0, mhn::cons<x1>>;
  using lst4 = mhn::cons<
    x0, mhn::cons<x1, mhn::cons<x2, mhn::cons<x3, mhn::cons<x4>>>>
  >;

  using vec1 = mhn::vector<>;
  using vec2 = mhn::vector<x0>;
  using vec3 = mhn::vector<x0, x1>;
  using vec4 = mhn::vector<x0, x1, x2, x3, x4>;

  using tv1l = mhn::transformed_view<lst1, res0_q>;
  using tv2l = mhn::transformed_view<lst2, res0_q>;
  using tv3l = mhn::transformed_view<lst3, res0_q>;
  using tv4l = mhn::transformed_view<lst4, res0_q>;
  using tv1v = mhn::transformed_view<vec1, res0_q>;
  using tv2v = mhn::transformed_view<vec2, res0_q>;
  using tv3v = mhn::transformed_view<vec3, res0_q>;
  using tv4v = mhn::transformed_view<vec4, res0_q>;


  static_assert(mhn::empty<tv1l>::type::value, "!!!");
  static_assert(!mhn::empty<tv2l>::type::value, "!!!");
  static_assert(!mhn::empty<tv3l>::type::value, "!!!");
  static_assert(!mhn::empty<tv4l>::type::value, "!!!");
  static_assert(mhn::empty<tv1v>::type::value, "!!!");
  static_assert(!mhn::empty<tv2v>::type::value, "!!!");
  static_assert(!mhn::empty<tv3v>::type::value, "!!!");
  static_assert(!mhn::empty<tv4v>::type::value, "!!!");

  test_eq_types<typename mhn::front<tv1l>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<tv2l>::type, res0<x0>>();
  test_eq_types<typename mhn::front<tv3l>::type, res0<x0>>();
  test_eq_types<typename mhn::front<tv4l>::type, res0<x0>>();
  test_eq_types<typename mhn::front<tv1v>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<tv2v>::type, res0<x0>>();
  test_eq_types<typename mhn::front<tv3v>::type, res0<x0>>();
  test_eq_types<typename mhn::front<tv4v>::type, res0<x0>>();

  test_eq_types<
    typename mhn::pop_front<tv1l>::type,
    mhn::transformed_view<mhn::pop_front_t<lst1>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv2l>::type,
    mhn::transformed_view<mhn::pop_front_t<lst2>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv3l>::type,
    mhn::transformed_view<mhn::pop_front_t<lst3>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv4l>::type,
    mhn::transformed_view<mhn::pop_front_t<lst4>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv1v>::type,
    mhn::transformed_view<mhn::pop_front_t<vec1>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv2v>::type,
    mhn::transformed_view<mhn::pop_front_t<vec2>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv3v>::type,
    mhn::transformed_view<mhn::pop_front_t<vec3>, res0_q>
  >();
  test_eq_types<
    typename mhn::pop_front<tv4v>::type,
    mhn::transformed_view<mhn::pop_front_t<vec4>, res0_q>
  >();

  test_eq_types<typename mhn::back<tv1l>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<tv2l>::type, res0<x0>>();
  test_eq_types<typename mhn::back<tv3l>::type, res0<x1>>();
  test_eq_types<typename mhn::back<tv4l>::type, res0<x4>>();
  test_eq_types<typename mhn::back<tv1v>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<tv2v>::type, res0<x0>>();
  test_eq_types<typename mhn::back<tv3v>::type, res0<x1>>();
  test_eq_types<typename mhn::back<tv4v>::type, res0<x4>>();

  test_at<tv1l>();
  test_at<tv2l, res0<x0>>();
  test_at<tv3l, res0<x0>, res0<x1>>();
  test_at<tv4l, res0<x0>, res0<x1>, res0<x2>, res0<x3>, res0<x4>>();
  test_at<tv1v>();
  test_at<tv2v, res0<x0>>();
  test_at<tv3v, res0<x0>, res0<x1>>();
  test_at<tv4v, res0<x0>, res0<x1>, res0<x2>, res0<x3>, res0<x4>>();

  static_assert(mhn::size<tv1l>::type::value == 0, "!!!");
  static_assert(mhn::size<tv2l>::type::value == 1, "!!!");
  static_assert(mhn::size<tv3l>::type::value == 2, "!!!");
  static_assert(mhn::size<tv4l>::type::value == 5, "!!!");
  static_assert(mhn::size<tv1v>::type::value == 0, "!!!");
  static_assert(mhn::size<tv2v>::type::value == 1, "!!!");
  static_assert(mhn::size<tv3v>::type::value == 2, "!!!");
  static_assert(mhn::size<tv4v>::type::value == 5, "!!!");

  test_drop<tv1l>();
  test_drop<tv2l>();
  test_drop<tv3l>();
  test_drop<tv4l>();
  test_drop<tv1v>();
  test_drop<tv2v>();
  test_drop<tv3v>();
  test_drop<tv4v>();


  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv1l, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv2l, y0>::type,
    res1<y0, res0<x0>>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv3l, y0>::type,
    res1<res1<y0, res0<x0>>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv4l, y0>::type,
    res1<
      res1<res1<res1<res1<y0, res0<x0>>, res0<x1>>, res0<x2>>, res0<x3>>,
      res0<x4>
    >
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv1v, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv2v, y0>::type,
    res1<y0, res0<x0>>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv3v, y0>::type,
    res1<res1<y0, res0<x0>>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, tv4v, y0>::type,
    res1<
      res1<res1<res1<res1<y0, res0<x0>>, res0<x1>>, res0<x2>>, res0<x3>>,
      res0<x4>
    >
  >();

  test_eq_types<
    typename mhn::fold_left<res1_q, tv1l>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv2l>::type,
    res0<x0>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv3l>::type,
    res1<res0<x0>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv4l>::type,
    res1<res1<res1<res1<res0<x0>, res0<x1>>, res0<x2>>, res0<x3>>, res0<x4>>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv1v>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv2v>::type,
    res0<x0>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv3v>::type,
    res1<res0<x0>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, tv4v>::type,
    res1<res1<res1<res1<res0<x0>, res0<x1>>, res0<x2>>, res0<x3>>, res0<x4>>
  >();

  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv1l, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv2l, y0>::type,
    res1<res0<x0>, y0>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv3l, y0>::type,
    res1<res0<x0>, res1<res0<x1>, y0>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv4l, y0>::type,
    res1<
      res0<x0>,
      res1<res0<x1>, res1<res0<x2>, res1<res0<x3>, res1<res0<x4>, y0>>>>
    >
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv1v, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv2v, y0>::type,
    res1<res0<x0>, y0>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv3v, y0>::type,
    res1<res0<x0>, res1<res0<x1>, y0>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, tv4v, y0>::type,
    res1<
      res0<x0>,
      res1<res0<x1>, res1<res0<x2>, res1<res0<x3>, res1<res0<x4>, y0>>>>
    >
  >();

  test_eq_types<
    typename mhn::fold_right<res1_q, tv1l>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv2l>::type,
    res0<x0>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv3l>::type,
    res1<res0<x0>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv4l>::type,
    res1<res0<x0>, res1<res0<x1>, res1<res0<x2>, res1<res0<x3>, res0<x4>>>>>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv1v>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv2v>::type,
    res0<x0>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv3v>::type,
    res1<res0<x0>, res0<x1>>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, tv4v>::type,
    res1<res0<x0>, res1<res0<x1>, res1<res0<x2>, res1<res0<x3>, res0<x4>>>>>
  >();

  return EXIT_SUCCESS;
}
