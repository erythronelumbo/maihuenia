// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/zipped_view.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct y0 {};

struct a0 {};
struct a1 {};
struct a2 {};
struct a3 {};
struct a4 {};

struct b0 {};
struct b1 {};
struct b2 {};
struct b3 {};
struct b4 {};

struct c0 {};
struct c1 {};
struct c2 {};
struct c3 {};
struct c4 {};

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
  using it1 = mhn::make_seq_t<mhn::linked_list_tag, a0, a1, a2, a3, a4>;
  using it2 = mhn::make_seq_t<mhn::vector_tag, b0, b1, b2, b3, b4>;
  using it3 = mhn::range_c<long, 0, 5>;

  using zpv = mhn::zipped_view<it1, it2, it3>;

  test_eq_types<
    typename mhn::front<zpv>::type,
    mhn::vector<mhn::front_t<it1>, mhn::front_t<it2>, mhn::front_t<it3>>
  >();
  test_eq_types<
    typename mhn::pop_front<zpv>::type,
    mhn::zipped_view<
      mhn::pop_front_t<it1>, mhn::pop_front_t<it2>, mhn::pop_front_t<it3>
    >
  >();
  static_assert(!mhn::empty<zpv>::type::value, "!!!");

  test_eq_types<
    typename mhn::back<zpv>::type,
    mhn::vector<mhn::back_t<it1>, mhn::back_t<it2>, mhn::back_t<it3>>
  >();

  return EXIT_SUCCESS;
}
