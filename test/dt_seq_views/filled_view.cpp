// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/filled_view.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct y0 {};

struct x0;
struct x1 {};
struct x2 : x1 {};

template <typename...> struct res0 { using type = res0; };
template <typename, typename> struct res1 { using type = res1; };

struct res0_q
{
  template <typename... Ts>
  using apply = res0<Ts...>;
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
  test_eq_types<typename mhn::at<L, mhn::size_c<0>>::type, E0>();
  test_eq_types<typename mhn::at<L, mhn::size_c<1>>::type, E1>();
  test_eq_types<typename mhn::at<L, mhn::size_c<2>>::type, E2>();
  test_eq_types<typename mhn::at<L, mhn::size_c<3>>::type, E3>();
  test_eq_types<typename mhn::at<L, mhn::size_c<4>>::type, E4>();
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

template <typename T>
constexpr void test_filled_view()
{
  using fv1a = mhn::filled_view<T, mhn::size_c<0>>;
  using fv2a = mhn::filled_view<T, mhn::size_c<1>>;
  using fv3a = mhn::filled_view<T, mhn::size_c<2>>;
  using fv4a = mhn::filled_view<T, mhn::size_c<5>>;
  using fv1b = mhn::filled_view_c<T, 0>;
  using fv2b = mhn::filled_view_c<T, 1>;
  using fv3b = mhn::filled_view_c<T, 2>;
  using fv4b = mhn::filled_view_c<T, 5>;

  static_assert(mhn::equals<fv1a, fv1a>::type::value, "!!!");
  static_assert(mhn::equals<fv1a, fv1b>::type::value, "!!!");
  static_assert(mhn::equals<fv1b, fv1a>::type::value, "!!!");
  static_assert(mhn::equals<fv1b, fv1b>::type::value, "!!!");
  static_assert(mhn::equals<fv3a, fv3a>::type::value, "!!!");
  static_assert(mhn::equals<fv3a, fv3b>::type::value, "!!!");
  static_assert(mhn::equals<fv3b, fv3a>::type::value, "!!!");
  static_assert(mhn::equals<fv3b, fv3b>::type::value, "!!!");

  static_assert(mhn::empty<fv1a>::type::value, "!!!");
  static_assert(!mhn::empty<fv2a>::type::value, "!!!");
  static_assert(!mhn::empty<fv3a>::type::value, "!!!");
  static_assert(!mhn::empty<fv4a>::type::value, "!!!");
  static_assert(mhn::empty<fv1b>::type::value, "!!!");
  static_assert(!mhn::empty<fv2b>::type::value, "!!!");
  static_assert(!mhn::empty<fv3b>::type::value, "!!!");
  static_assert(!mhn::empty<fv4b>::type::value, "!!!");

  test_eq_types<typename mhn::front<fv1a>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<fv2a>::type, T>();
  test_eq_types<typename mhn::front<fv3a>::type, T>();
  test_eq_types<typename mhn::front<fv4a>::type, T>();
  test_eq_types<typename mhn::front<fv1b>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<fv2b>::type, T>();
  test_eq_types<typename mhn::front<fv3b>::type, T>();
  test_eq_types<typename mhn::front<fv4b>::type, T>();

  test_eq_types<
    typename mhn::pop_front<fv1a>::type, mhn::filled_view<T, mhn::size_c<0>>
  >();
  test_eq_types<
    typename mhn::pop_front<fv2a>::type, mhn::filled_view<T, mhn::size_c<0>>
  >();
  test_eq_types<
    typename mhn::pop_front<fv3a>::type, mhn::filled_view<T, mhn::size_c<1>>
  >();
  test_eq_types<
    typename mhn::pop_front<fv4a>::type, mhn::filled_view<T, mhn::size_c<4>>
  >();
  test_eq_types<
    typename mhn::pop_front<fv1b>::type, mhn::filled_view_c<T, 0>
  >();
  test_eq_types<
    typename mhn::pop_front<fv2b>::type, mhn::filled_view_c<T, 0>
  >();
  test_eq_types<
    typename mhn::pop_front<fv3b>::type, mhn::filled_view_c<T, 1>
  >();
  test_eq_types<
    typename mhn::pop_front<fv4b>::type, mhn::filled_view_c<T, 4>
  >();

  test_eq_types<typename mhn::back<fv1a>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<fv2a>::type, T>();
  test_eq_types<typename mhn::back<fv3a>::type, T>();
  test_eq_types<typename mhn::back<fv4a>::type, T>();
  test_eq_types<typename mhn::back<fv1b>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<fv2b>::type, T>();
  test_eq_types<typename mhn::back<fv3b>::type, T>();
  test_eq_types<typename mhn::back<fv4b>::type, T>();

  test_at<fv1a>();
  test_at<fv2a, T>();
  test_at<fv3a, T, T>();
  test_at<fv4a, T, T, T, T, T>();
  test_at<fv1b>();
  test_at<fv2b, T>();
  test_at<fv3b, T, T>();
  test_at<fv4b, T, T, T, T, T>();

  static_assert(mhn::size<fv1a>::type::value == 0, "!!!");
  static_assert(mhn::size<fv2a>::type::value == 1, "!!!");
  static_assert(mhn::size<fv3a>::type::value == 2, "!!!");
  static_assert(mhn::size<fv4a>::type::value == 5, "!!!");
  static_assert(mhn::size<fv1b>::type::value == 0, "!!!");
  static_assert(mhn::size<fv2b>::type::value == 1, "!!!");
  static_assert(mhn::size<fv3b>::type::value == 2, "!!!");
  static_assert(mhn::size<fv4b>::type::value == 5, "!!!");

  test_drop<fv1a>();
  test_drop<fv2a>();
  test_drop<fv3a>();
  test_drop<fv4a>();
  test_drop<fv1b>();
  test_drop<fv2b>();
  test_drop<fv3b>();
  test_drop<fv4b>();


  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv1a, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv2a, y0>::type,
    res0<y0, T>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv3a, y0>::type,
    res0<res0<y0, T>, T>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv4a, y0>::type,
    res0<res0<res0<res0<res0<y0, T>, T>, T>, T>, T>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv1b, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv2b, y0>::type,
    res0<y0, T>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv3b, y0>::type,
    res0<res0<y0, T>, T>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res0_q, fv4b, y0>::type,
    res0<res0<res0<res0<res0<y0, T>, T>, T>, T>, T>
  >();

  test_eq_types<
    typename mhn::fold_left<res0_q, fv1a>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv2a>::type,
    T
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv3a>::type,
    res0<T, T>
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv4a>::type,
    res0<res0<res0<res0<T, T>, T>, T>, T>
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv1b>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv2b>::type,
    T
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv3b>::type,
    res0<T, T>
  >();
  test_eq_types<
    typename mhn::fold_left<res0_q, fv4b>::type,
    res0<res0<res0<res0<T, T>, T>, T>, T>
  >();

  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv1a, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv2a, y0>::type,
    res0<T, y0>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv3a, y0>::type,
    res0<T, res0<T, y0>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv4a, y0>::type,
    res0<T, res0<T, res0<T, res0<T, res0<T, y0>>>>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv1b, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv2b, y0>::type,
    res0<T, y0>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv3b, y0>::type,
    res0<T, res0<T, y0>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res0_q, fv4b, y0>::type,
    res0<T, res0<T, res0<T, res0<T, res0<T, y0>>>>>
  >();

  test_eq_types<
    typename mhn::fold_right<res0_q, fv1a>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv2a>::type,
    T
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv3a>::type,
    res0<T, T>
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv4a>::type,
    res0<T, res0<T, res0<T, res0<T, T>>>>
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv1b>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv2b>::type,
    T
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv3b>::type,
    res0<T, T>
  >();
  test_eq_types<
    typename mhn::fold_right<res0_q, fv4b>::type,
    res0<T, res0<T, res0<T, res0<T, T>>>>
  >();
}


int main()
{
  test_filled_view<x0>();
  test_filled_view<x1>();
  test_filled_view<x2>();
  test_filled_view<void>();
  test_filled_view<int>();

  return EXIT_SUCCESS;
}
