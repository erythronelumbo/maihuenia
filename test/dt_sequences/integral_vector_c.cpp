// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/integral_vector_c.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


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


template <
  typename V1, typename V2, typename V3, typename V4, typename V5,
  typename W1, typename W2, typename W3, typename W4, typename W5
>
constexpr void test_equality()
{
  static_assert(mhn::equals<V1, V1>::type::value, "!!!");
  static_assert(!mhn::equals<V1, V2>::type::value, "!!!");
  static_assert(!mhn::equals<V1, V3>::type::value, "!!!");
  static_assert(!mhn::equals<V1, V4>::type::value, "!!!");
  static_assert(!mhn::equals<V1, V5>::type::value, "!!!");
  static_assert(mhn::equals<V2, V2>::type::value, "!!!");
  static_assert(!mhn::equals<V2, V3>::type::value, "!!!");
  static_assert(!mhn::equals<V2, V4>::type::value, "!!!");
  static_assert(!mhn::equals<V2, V5>::type::value, "!!!");
  static_assert(mhn::equals<V3, V3>::type::value, "!!!");
  static_assert(!mhn::equals<V3, V4>::type::value, "!!!");
  static_assert(!mhn::equals<V3, V5>::type::value, "!!!");
  static_assert(mhn::equals<V4, V4>::type::value, "!!!");
  static_assert(!mhn::equals<V4, V5>::type::value, "!!!");
  static_assert(mhn::equals<V5, V5>::type::value, "!!!");

  static_assert(mhn::equals<V1, W1>::type::value, "!!!");
  static_assert(!mhn::equals<V1, W2>::type::value, "!!!");
  static_assert(!mhn::equals<V1, W3>::type::value, "!!!");
  static_assert(!mhn::equals<V1, W4>::type::value, "!!!");
  static_assert(!mhn::equals<V1, W5>::type::value, "!!!");
  static_assert(mhn::equals<V2, W2>::type::value, "!!!");
  static_assert(!mhn::equals<V2, W3>::type::value, "!!!");
  static_assert(!mhn::equals<V2, W4>::type::value, "!!!");
  static_assert(!mhn::equals<V2, W5>::type::value, "!!!");
  static_assert(mhn::equals<V3, W3>::type::value, "!!!");
  static_assert(!mhn::equals<V3, W4>::type::value, "!!!");
  static_assert(!mhn::equals<V3, W5>::type::value, "!!!");
  static_assert(mhn::equals<V4, W4>::type::value, "!!!");
  static_assert(!mhn::equals<V4, W5>::type::value, "!!!");
  static_assert(mhn::equals<V5, W5>::type::value, "!!!");

  static_assert(mhn::equals<W1, V1>::type::value, "!!!");
  static_assert(!mhn::equals<W1, V2>::type::value, "!!!");
  static_assert(!mhn::equals<W1, V3>::type::value, "!!!");
  static_assert(!mhn::equals<W1, V4>::type::value, "!!!");
  static_assert(!mhn::equals<W1, V5>::type::value, "!!!");
  static_assert(mhn::equals<W2, V2>::type::value, "!!!");
  static_assert(!mhn::equals<W2, V3>::type::value, "!!!");
  static_assert(!mhn::equals<W2, V4>::type::value, "!!!");
  static_assert(!mhn::equals<W2, V5>::type::value, "!!!");
  static_assert(mhn::equals<W3, V3>::type::value, "!!!");
  static_assert(!mhn::equals<W3, V4>::type::value, "!!!");
  static_assert(!mhn::equals<W3, V5>::type::value, "!!!");
  static_assert(mhn::equals<W4, V4>::type::value, "!!!");
  static_assert(!mhn::equals<W4, V5>::type::value, "!!!");
  static_assert(mhn::equals<W5, V5>::type::value, "!!!");

  static_assert(mhn::equals<W1, W1>::type::value, "!!!");
  static_assert(!mhn::equals<W1, W2>::type::value, "!!!");
  static_assert(!mhn::equals<W1, W3>::type::value, "!!!");
  static_assert(!mhn::equals<W1, W4>::type::value, "!!!");
  static_assert(!mhn::equals<W1, W5>::type::value, "!!!");
  static_assert(mhn::equals<W2, W2>::type::value, "!!!");
  static_assert(!mhn::equals<W2, W3>::type::value, "!!!");
  static_assert(!mhn::equals<W2, W4>::type::value, "!!!");
  static_assert(!mhn::equals<W2, W5>::type::value, "!!!");
  static_assert(mhn::equals<W3, W3>::type::value, "!!!");
  static_assert(!mhn::equals<W3, W4>::type::value, "!!!");
  static_assert(!mhn::equals<W3, W5>::type::value, "!!!");
  static_assert(mhn::equals<W4, W4>::type::value, "!!!");
  static_assert(!mhn::equals<W4, W5>::type::value, "!!!");
  static_assert(mhn::equals<W5, W5>::type::value, "!!!");
}


template <typename T, typename U = T>
constexpr void test_vector_c()
{
  using ivec1 = mhn::integral_vector_c<T>;
  using ivec2 = mhn::integral_vector_c<T, 0>;
  using ivec3 = mhn::integral_vector_c<T, 0, 1>;
  using ivec4 = mhn::integral_vector_c<T, 0, 1, 2, 3, 4>;
  using ivec5 = mhn::integral_vector_c<T, 100, 99, 98>;

  using ivec1a = mhn::integral_vector_c<U>;
  using ivec2a = mhn::integral_vector_c<U, 0>;
  using ivec3a = mhn::integral_vector_c<U, 0, 1>;
  using ivec4a = mhn::integral_vector_c<U, 0, 1, 2, 3, 4>;
  using ivec5a = mhn::integral_vector_c<U, 100, 99, 98>;

  test_equality<
    ivec1, ivec2, ivec3, ivec4, ivec5,
    ivec1a, ivec2a, ivec3a, ivec4a, ivec5a
  >();

  static_assert(mhn::empty<ivec1>::type::value, "!!!");
  static_assert(!mhn::empty<ivec2>::type::value, "!!!");
  static_assert(!mhn::empty<ivec3>::type::value, "!!!");
  static_assert(!mhn::empty<ivec4>::type::value, "!!!");
  static_assert(!mhn::empty<ivec5>::type::value, "!!!");

  test_eq_types<typename mhn::front<ivec1>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<ivec2>::type, mhn::integer_c<T, 0>>();
  test_eq_types<typename mhn::front<ivec3>::type, mhn::integer_c<T, 0>>();
  test_eq_types<typename mhn::front<ivec4>::type, mhn::integer_c<T, 0>>();
  test_eq_types<typename mhn::front<ivec5>::type, mhn::integer_c<T, 100>>();

  test_eq_types<
    typename mhn::pop_front<ivec1>::type, mhn::integral_vector_c<T>
  >();
  test_eq_types<
    typename mhn::pop_front<ivec2>::type, mhn::integral_vector_c<T>
  >();
  test_eq_types<
    typename mhn::pop_front<ivec3>::type, mhn::integral_vector_c<T, 1>
  >();
  test_eq_types<
    typename mhn::pop_front<ivec4>::type, mhn::integral_vector_c<T, 1, 2, 3, 4>
  >();


  test_eq_types<typename mhn::back<ivec1>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<ivec2>::type, mhn::integer_c<T, 0>>();
  test_eq_types<typename mhn::back<ivec3>::type, mhn::integer_c<T, 1>>();
  test_eq_types<typename mhn::back<ivec4>::type, mhn::integer_c<T, 4>>();
  test_eq_types<typename mhn::back<ivec5>::type, mhn::integer_c<T, 98>>();

  test_at<ivec1>();
  test_at<ivec2, mhn::integer_c<T, 0>>();
  test_at<ivec3, mhn::integer_c<T, 0>, mhn::integer_c<T, 1>>();

  static_assert(mhn::size<ivec1>::type::value == 0, "!!!");
  static_assert(mhn::size<ivec2>::type::value == 1, "!!!");
  static_assert(mhn::size<ivec3>::type::value == 2, "!!!");
  static_assert(mhn::size<ivec4>::type::value == 5, "!!!");
  static_assert(mhn::size<ivec5>::type::value == 3, "!!!");

  test_drop<ivec1>();
  test_drop<ivec2>();
  test_drop<ivec3>();
  test_drop<ivec4>();
  test_drop<ivec5>();

  test_eq_types<
    typename mhn::fold_left_initial<
      res1_q, ivec1, mhn::integer_c<T, 234>
    >::type,
    mhn::integer_c<T, 234>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<
      res1_q, ivec2, mhn::integer_c<T, 234>
    >::type,
    res1<mhn::integer_c<T, 234>, mhn::integer_c<T, 0>>
  >();
  test_eq_types<
    typename mhn::fold_left_initial<
      res1_q, ivec3, mhn::integer_c<T, 234>
    >::type,
    res1<
      res1<
        mhn::integer_c<T, 234>,
        mhn::integer_c<T, 0>
      >,
      mhn::integer_c<T, 1>
    >
  >();
  test_eq_types<
    typename mhn::fold_left_initial<
      res1_q, ivec4, mhn::integer_c<T, 234>
    >::type,
    res1<
      res1<
        res1<
          res1<
            res1<
              mhn::integer_c<T, 234>,
              mhn::integer_c<T, 0>
            >,
            mhn::integer_c<T, 1>
          >,
          mhn::integer_c<T, 2>
        >,
        mhn::integer_c<T, 3>
      >,
      mhn::integer_c<T, 4>
    >
  >();

  test_eq_types<
    typename mhn::fold_left<res1_q, ivec1>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, ivec2>::type,
    mhn::integer_c<T, 0>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, ivec3>::type,
    res1<mhn::integer_c<T, 0>, mhn::integer_c<T, 1>>
  >();
  test_eq_types<
    typename mhn::fold_left<res1_q, ivec4>::type,
    res1<
      res1<
        res1<
          res1<
            mhn::integer_c<T, 0>,
            mhn::integer_c<T, 1>
          >,
          mhn::integer_c<T, 2>
        >,
        mhn::integer_c<T, 3>
      >,
      mhn::integer_c<T, 4>
    >
  >();


  test_eq_types<
    typename mhn::fold_right_initial<
      res1_q, ivec1, mhn::integer_c<T, 234>
    >::type,
    mhn::integer_c<T, 234>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<
      res1_q, ivec2, mhn::integer_c<T, 234>
    >::type,
    res1<mhn::integer_c<T, 0>, mhn::integer_c<T, 234>>
  >();
  test_eq_types<
    typename mhn::fold_right_initial<
      res1_q, ivec3, mhn::integer_c<T, 234>
    >::type,
    res1<
      mhn::integer_c<T, 0>,
      res1<
        mhn::integer_c<T, 1>,
        mhn::integer_c<T, 234>
      >
    >
  >();
  test_eq_types<
    typename mhn::fold_right_initial<
      res1_q, ivec4, mhn::integer_c<T, 234>
    >::type,
    res1<
      mhn::integer_c<T, 0>,
      res1<
        mhn::integer_c<T, 1>,
        res1<
          mhn::integer_c<T, 2>,
          res1<
            mhn::integer_c<T, 3>,
            res1<
              mhn::integer_c<T, 4>,
              mhn::integer_c<T, 234>
            >
          >
        >
      >
    >
  >();

  test_eq_types<
    typename mhn::fold_right<res1_q, ivec1>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, ivec2>::type,
    mhn::integer_c<T, 0>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, ivec3>::type,
    res1<mhn::integer_c<T, 0>, mhn::integer_c<T, 1>>
  >();
  test_eq_types<
    typename mhn::fold_right<res1_q, ivec4>::type,
    res1<
      mhn::integer_c<T, 0>,
      res1<
        mhn::integer_c<T, 1>,
        res1<
          mhn::integer_c<T, 2>,
          res1<
            mhn::integer_c<T, 3>,
            mhn::integer_c<T, 4>
          >
        >
      >
    >
  >();


  test_eq_types<typename mhn::clear<ivec1>::type, ivec1>();
  test_eq_types<typename mhn::clear<ivec2>::type, ivec1>();
  test_eq_types<typename mhn::clear<ivec3>::type, ivec1>();
  test_eq_types<typename mhn::clear<ivec4>::type, ivec1>();
  test_eq_types<typename mhn::clear<ivec5>::type, ivec1>();

  test_eq_types<
    typename mhn::concat<ivec1, ivec1>::type, ivec1
  >();
  test_eq_types<
    typename mhn::concat<ivec1, ivec3>::type, ivec3
  >();
  test_eq_types<
    typename mhn::concat<ivec3, ivec1>::type, ivec3
  >();
  test_eq_types<
    typename mhn::concat<ivec3, ivec5>::type,
    mhn::integral_vector_c<T, 0, 1, 100, 99, 98>
  >();
  test_eq_types<
    typename mhn::concat<ivec3, ivec5, ivec4>::type,
    mhn::integral_vector_c<T, 0, 1, 100, 99, 98, 0, 1, 2, 3, 4>
  >();
}


int main()
{
  test_vector_c<int, short>();
  test_vector_c<unsigned int, unsigned char>();

  return EXIT_SUCCESS;
}
