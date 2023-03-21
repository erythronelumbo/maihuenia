// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/vector.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;

struct y0 {};

struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};
struct x6 {};
struct x7 {};

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


struct monadic_fn_1
{
  template <typename X>
  using apply = mhn::vector<X, X>;
};

struct monadic_fn_2
{
  template <typename X>
  using apply = mhn::vector<>;
};


using lst1 = mhn::vector<>;
using lst2 = mhn::vector<x0>;
using lst3 = mhn::vector<x0, x1>;
using lst4 = mhn::vector<x0, x1, x2, x3, x4>;
using lst5 = mhn::vector<x5, x6>;

template <
  typename L,
  typename E0,
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
  static_assert(mhn::empty<lst1>::type::value, "!!!");
  static_assert(!mhn::empty<lst2>::type::value, "!!!");
  static_assert(!mhn::empty<lst3>::type::value, "!!!");
  static_assert(!mhn::empty<lst4>::type::value, "!!!");

  test_eq_types<typename mhn::front<lst1>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<lst2>::type, x0>();
  test_eq_types<typename mhn::front<lst3>::type, x0>();
  test_eq_types<typename mhn::front<lst4>::type, x0>();

  test_eq_types<typename mhn::pop_front<lst1>::type, mhn::vector<>>();
  test_eq_types<typename mhn::pop_front<lst2>::type, mhn::vector<>>();
  test_eq_types<
    typename mhn::pop_front<lst3>::type,
    mhn::vector<x1>
  >();
  test_eq_types<
    typename mhn::pop_front<lst4>::type,
    mhn::vector<x1, x2, x3, x4>
  >();

  test_eq_types<typename mhn::back<lst1>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<lst2>::type, x0>();
  test_eq_types<typename mhn::back<lst3>::type, x1>();
  test_eq_types<typename mhn::back<lst4>::type, x4>();

  test_at<lst1, mhn::index_out_of_range>();
  test_at<lst2, x0>();
  test_at<lst3, x0, x1>();
  test_at<lst4, x0, x1, x2, x3, x4>();

  static_assert(mhn::size<lst1>::type::value == 0, "!!!");
  static_assert(mhn::size<lst2>::type::value == 1, "!!!");
  static_assert(mhn::size<lst3>::type::value == 2, "!!!");
  static_assert(mhn::size<lst4>::type::value == 5, "!!!");

  test_drop<lst1>();
  test_drop<lst2>();
  test_drop<lst3>();
  test_drop<lst4>();

  test_eq_types<
    typename mhn::fold_left_initial<res1_q, lst1, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, lst2, y0>::type,
    res1<y0, x0>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, lst3, y0>::type,
    res1<res1<y0, x0>, x1>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<res1_q, lst4, y0>::type,
    res1<res1<res1<res1<res1<y0, x0>, x1>, x2>, x3>, x4>
  >();

  test_eq_types<
    typename mhn::fold_left<res1_q, lst1>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, lst2>::type,
    x0
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, lst3>::type,
    res1<x0, x1>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, lst4>::type,
    res1<res1<res1<res1<x0, x1>, x2>, x3>, x4>
  >();

  test_eq_types<
    typename mhn::fold_right_initial<res1_q, lst1, y0>::type,
    y0
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, lst2, y0>::type,
    res1<x0, y0>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, lst3, y0>::type,
    res1<x0, res1<x1, y0>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<res1_q, lst4, y0>::type,
    res1<x0, res1<x1, res1<x2, res1<x3, res1<x4, y0>>>>>
  >();

  test_eq_types<
    typename mhn::fold_right<res1_q, lst1>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, lst2>::type,
    x0
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, lst3>::type,
    res1<x0, x1>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, lst4>::type,
    res1<x0, res1<x1, res1<x2, res1<x3, x4>>>>
  >();



  test_eq_types<
    typename mhn::make_seq<mhn::vector_tag>::type,
    lst1
  >();
  test_eq_types<
    typename mhn::make_seq<mhn::vector_tag, x0>::type,
    lst2
  >();
  test_eq_types<
    typename mhn::make_seq<mhn::vector_tag, x0, x1>::type,
    lst3
  >();
  test_eq_types<
    typename mhn::make_seq<mhn::vector_tag, x0, x1, x2, x3, x4>::type,
    lst4
  >();

  test_eq_types<typename mhn::clear<lst1>::type, lst1>();
  test_eq_types<typename mhn::clear<lst2>::type, lst1>();
  test_eq_types<typename mhn::clear<lst3>::type, lst1>();
  test_eq_types<typename mhn::clear<lst4>::type, lst1>();
  test_eq_types<typename mhn::clear<lst5>::type, lst1>();

  test_eq_types<
    typename mhn::concat<lst1, lst1>::type, lst1
  >();
  test_eq_types<
    typename mhn::concat<lst1, lst3>::type, lst3
  >();
  test_eq_types<
    typename mhn::concat<lst3, lst1>::type, lst3
  >();
  test_eq_types<
    typename mhn::concat<lst3, lst5>::type,
    mhn::vector<x0, x1, x5, x6>
  >();
  test_eq_types<
    typename mhn::concat<lst3, lst5, lst4>::type,
    mhn::vector<x0, x1, x5, x6, x0, x1, x2, x3, x4>
  >();

  test_eq_types<typename mhn::push_front<lst1, x7>::type, mhn::vector<x7>>();
  test_eq_types<
    typename mhn::push_front<lst3, x7>::type,
    mhn::vector<x7, x0, x1>
  >();

  test_eq_types<typename mhn::push_back<lst1, x7>::type, mhn::vector<x7>>();
  test_eq_types<
    typename mhn::push_back<lst3, x7>::type,
    mhn::vector<x0, x1, x7>
  >();

  test_eq_types<
    typename mhn::pop_back<lst1>::type,
    mhn::vector<>
  >();
  test_eq_types<
    typename mhn::pop_back<lst2>::type,
    mhn::vector<>
  >();
  test_eq_types<
    typename mhn::pop_back<lst5>::type,
    mhn::vector<x5>
  >();

  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<5>>::type, lst4
  >();
  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<4>>::type,
    mhn::pop_back_t<lst4>
  >();
  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<3>>::type,
    mhn::pop_back_t<mhn::pop_back_t<lst4>>
  >();
  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<2>>::type,
    mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<lst4>>>
  >();
  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<1>>::type,
    mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<lst4>>>>
  >();
  test_eq_types<
    typename mhn::take<lst4, mhn::size_c<0>>::type,
    mhn::clear_t<lst4>
  >();

  test_eq_types<
    typename mhn::insert<lst1, mhn::size_c<0>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x7>
  >();
  test_eq_types<
    typename mhn::insert<lst1, mhn::size_c<1>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x7>
  >();
  test_eq_types<
    typename mhn::insert<lst2, mhn::size_c<0>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x7, x0>
  >();
  test_eq_types<
    typename mhn::insert<lst2, mhn::size_c<1>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x0, x7>
  >();
  test_eq_types<
    typename mhn::insert<lst3, mhn::size_c<0>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x7, x0, x1>
  >();
  test_eq_types<
    typename mhn::insert<lst3, mhn::size_c<1>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x0, x7, x1>
  >();
  test_eq_types<
    typename mhn::insert<lst3, mhn::size_c<2>, x7>::type,
    mhn::make_seq_t<mhn::vector_tag, x0, x1, x7>
  >();

  test_eq_types<
    typename mhn::erase<lst1, mhn::size_c<0>>::type, lst1
  >();
  test_eq_types<
    typename mhn::erase<lst1, mhn::size_c<1>>::type, lst1
  >();
  test_eq_types<
    typename mhn::erase<lst2, mhn::size_c<0>>::type,
    mhn::make_seq_t<mhn::vector_tag>
  >();
  test_eq_types<
    typename mhn::erase<lst3, mhn::size_c<0>>::type,
    mhn::make_seq_t<mhn::vector_tag, x1>
  >();
  test_eq_types<
    typename mhn::erase<lst3, mhn::size_c<1>>::type,
    mhn::make_seq_t<mhn::vector_tag, x0>
  >();


  test_eq_types<
    typename mhn::mident<mhn::vector_tag>::type, mhn::vector<>
  >();

  test_eq_types<
    typename mhn::mappend<lst1, lst1>::type, lst1
  >();
  test_eq_types<
    typename mhn::mappend<lst1, lst3>::type, lst3
  >();
  test_eq_types<
    typename mhn::mappend<lst3, lst1>::type, lst3
  >();
  test_eq_types<
    typename mhn::mappend<lst3, lst5>::type,
    mhn::vector<x0, x1, x5, x6>
  >();
  test_eq_types<
    typename mhn::mappend<lst3, lst5, lst4>::type,
    mhn::vector<x0, x1, x5, x6, x0, x1, x2, x3, x4>
  >();


  test_eq_types<
    typename mhn::transform<res0_q, lst1>::type,
    lst1
  >();
  test_eq_types<
    typename mhn::transform<res0_q, lst2>::type,
    mhn::make_seq_t<mhn::vector_tag, res0<x0>>
  >();
  test_eq_types<
    typename mhn::transform<res0_q, lst3>::type,
    mhn::make_seq_t<mhn::vector_tag, res0<x0>, res0<x1>>
  >();

  test_eq_types<
    typename mhn::mbind<
      mhn::vector<>,
      monadic_fn_1
    >::type,
    mhn::vector<>
  >();
  test_eq_types<
    typename mhn::mbind<
      mhn::vector<x0>,
      monadic_fn_1
    >::type,
    mhn::vector<x0, x0>
  >();
  test_eq_types<
    typename mhn::mbind<
      mhn::vector<x0, x1>,
      monadic_fn_1
    >::type,
    mhn::vector<x0, x0, x1, x1>
  >();
  test_eq_types<
    typename mhn::mbind<
      mhn::vector<x2>,
      monadic_fn_1,
      monadic_fn_1
    >::type,
    mhn::vector<x2, x2, x2, x2>
  >();
  test_eq_types<
    typename mhn::mbind<
      mhn::vector<x3, x4>,
      monadic_fn_1,
      monadic_fn_1
    >::type,
    mhn::vector<x3, x3, x3, x3, x4, x4, x4, x4>
  >();
  test_eq_types<
    typename mhn::mbind<
      mhn::vector<x5, x5>,
      monadic_fn_1,
      monadic_fn_2
    >::type,
    mhn::vector<>
  >();

  return EXIT_SUCCESS;
}
