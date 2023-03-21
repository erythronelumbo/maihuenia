// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/zip_with.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


template <typename X> struct f0 { using type = f0; };
template <typename X> struct f1 { using type = f1; };
template <typename... Xs> struct f2 { using type = f2; };
template <typename... Xs> struct f3 { using type = f3; };
template <typename X0, typename X1> struct f4 { using type = f4; };
template <typename X, typename Y, typename Z> struct f5 { using type = f5; };


struct f0_q { template <typename X> using apply = f0<X>; };
struct f1_q { template <typename X> using apply = f1<X>; };
struct f2_q { template <typename... Xs> using apply = f2<Xs...>; };
struct f3_q { template <typename... Xs> using apply = f3<Xs...>; };
struct f4_q { template <typename X0, typename X1> using apply = f4<X0, X1>; };
struct f5_q
{
  template <typename X, typename Y, typename Z>
  using apply = f5<X, Y, Z>;
};


struct a0 {};
struct a1 {};
struct a2 {};
struct a3 {};
struct a4 {};
struct a5 {};
struct a6 {};
struct a7 {};
struct a8 {};
struct a9 {};

struct b0 {};
struct b1 {};
struct b2 {};
struct b3 {};
struct b4 {};
struct b5 {};
struct b6 {};
struct b7 {};
struct b8 {};
struct b9 {};

struct c0 {};
struct c1 {};
struct c2 {};
struct c3 {};
struct c4 {};
struct c5 {};
struct c6 {};
struct c7 {};
struct c8 {};
struct c9 {};


using it1 = mhn::make_seq_t<mhn::linked_list_tag, a0, a1, a2, a3, a4, a5>;
using it2 = mhn::vector<b0, b1, b2, b3, b4, b5, b6, b7, b8, b9>;
using it3 = mhn::cons<c0, mhn::cons<c1, mhn::cons<c2, mhn::cons<c3>>>>;
using it4 = mhn::vector<char>;
using it5 = mhn::null_type;
using it6 = STR_("abcdefghij");


template <
  typename ZippedMFn,
  typename E0 = mhn::index_out_of_range,
  typename E1 = mhn::index_out_of_range,
  typename E2 = mhn::index_out_of_range,
  typename E3 = mhn::index_out_of_range,
  typename E4 = mhn::index_out_of_range,
  typename E5 = mhn::index_out_of_range,
  typename E6 = mhn::index_out_of_range,
  typename E7 = mhn::index_out_of_range,
  typename E8 = mhn::index_out_of_range,
  typename E9 = mhn::index_out_of_range
>
constexpr void test_zip_elems()
{
  using zipped = typename ZippedMFn::type;

  test_eq_types<mhn::at_c_t<zipped, 0>, E0>();
  test_eq_types<mhn::at_c_t<zipped, 1>, E1>();
  test_eq_types<mhn::at_c_t<zipped, 2>, E2>();
  test_eq_types<mhn::at_c_t<zipped, 3>, E3>();
  test_eq_types<mhn::at_c_t<zipped, 4>, E4>();
  test_eq_types<mhn::at_c_t<zipped, 5>, E5>();
  test_eq_types<mhn::at_c_t<zipped, 6>, E6>();
  test_eq_types<mhn::at_c_t<zipped, 7>, E7>();
  test_eq_types<mhn::at_c_t<zipped, 8>, E8>();
  test_eq_types<mhn::at_c_t<zipped, 9>, E9>();
}


template <typename SeqTag>
constexpr void test_zip()
{
  test_zip_elems<
    mhn::zip_with<f0_q, SeqTag, it1>,
    f0<a0>, f0<a1>, f0<a2>, f0<a3>,
    f0<a4>, f0<a5>
  >();
  test_zip_elems<
    mhn::zip_with<f0_q, SeqTag, it2>,
    f0<b0>, f0<b1>, f0<b2>, f0<b3>,
    f0<b4>, f0<b5>, f0<b6>, f0<b7>,
    f0<b8>, f0<b9>
  >();
  test_zip_elems<
    mhn::zip_with<f1_q, SeqTag, it3>,
    f1<c0>, f1<c1>, f1<c2>, f1<c3>
  >();
  test_zip_elems<
    mhn::zip_with<f2_q, SeqTag, it4>,
    f2<char>
  >();
  test_zip_elems<mhn::zip_with<f2_q, SeqTag, it5>>();

  test_zip_elems<mhn::zip_with<f2_q, SeqTag, it1, it5>>();
  test_zip_elems<mhn::zip_with<f4_q, SeqTag, it5, it2>>();
  test_zip_elems<mhn::zip_with<f4_q, SeqTag, it3, it5>>();
  test_zip_elems<mhn::zip_with<f3_q, SeqTag, it5, it4, it3>>();
  test_zip_elems<mhn::zip_with<f3_q, SeqTag, it6, it5>>();

  test_zip_elems<
    mhn::zip_with<f0_q, SeqTag, it1, it2, it3, it4, it5, it6>
  >();

  test_zip_elems<
    mhn::zip_with<
      f4_q,
      SeqTag,
      it1, it2
    >,
    f4<a0, b0>,
    f4<a1, b1>,
    f4<a2, b2>,
    f4<a3, b3>,
    f4<a4, b4>,
    f4<a5, b5>
  >();
  test_zip_elems<
    mhn::zip_with<
      f4_q,
      SeqTag,
      it2, it1
    >,
    f4<b0, a0>,
    f4<b1, a1>,
    f4<b2, a2>,
    f4<b3, a3>,
    f4<b4, a4>,
    f4<b5, a5>
  >();

  test_zip_elems<
    mhn::zip_with<
      f3_q,
      SeqTag,
      it6, it2
    >,
    f3<mhn::char_<'a'>, b0>,
    f3<mhn::char_<'b'>, b1>,
    f3<mhn::char_<'c'>, b2>,
    f3<mhn::char_<'d'>, b3>,
    f3<mhn::char_<'e'>, b4>,
    f3<mhn::char_<'f'>, b5>,
    f3<mhn::char_<'g'>, b6>,
    f3<mhn::char_<'h'>, b7>,
    f3<mhn::char_<'i'>, b8>,
    f3<mhn::char_<'j'>, b9>
  >();

  test_zip_elems<
    mhn::zip_with<
      f5_q,
      SeqTag,
      it2, it1, it3
    >,
    f5<b0, a0, c0>,
    f5<b1, a1, c1>,
    f5<b2, a2, c2>,
    f5<b3, a3, c3>
  >();

  test_zip_elems<
    mhn::zip_with<
      f2_q,
      SeqTag,
      it2, it6, it6, it2, it6, it2, it2, it6
    >,
    f2<
      b0, mhn::char_<'a'>, mhn::char_<'a'>, b0,
      mhn::char_<'a'>, b0, b0, mhn::char_<'a'>
    >,
    f2<
      b1, mhn::char_<'b'>, mhn::char_<'b'>, b1,
      mhn::char_<'b'>, b1, b1, mhn::char_<'b'>
    >,
    f2<
      b2, mhn::char_<'c'>, mhn::char_<'c'>, b2,
      mhn::char_<'c'>, b2, b2, mhn::char_<'c'>
    >,
    f2<
      b3, mhn::char_<'d'>, mhn::char_<'d'>, b3,
      mhn::char_<'d'>, b3, b3, mhn::char_<'d'>
    >,
    f2<
      b4, mhn::char_<'e'>, mhn::char_<'e'>, b4,
      mhn::char_<'e'>, b4, b4, mhn::char_<'e'>
    >,
    f2<
      b5, mhn::char_<'f'>, mhn::char_<'f'>, b5,
      mhn::char_<'f'>, b5, b5, mhn::char_<'f'>
    >,
    f2<
      b6, mhn::char_<'g'>, mhn::char_<'g'>, b6,
      mhn::char_<'g'>, b6, b6, mhn::char_<'g'>
    >,
    f2<
      b7, mhn::char_<'h'>, mhn::char_<'h'>, b7,
      mhn::char_<'h'>, b7, b7, mhn::char_<'h'>
    >,
    f2<
      b8, mhn::char_<'i'>, mhn::char_<'i'>, b8,
      mhn::char_<'i'>, b8, b8, mhn::char_<'i'>
    >,
    f2<
      b9, mhn::char_<'j'>, mhn::char_<'j'>, b9,
      mhn::char_<'j'>, b9, b9, mhn::char_<'j'>
    >
  >();
}


int main()
{
  test_zip<mhn::linked_list_tag>();
  test_zip<mhn::vector_tag>();

  return EXIT_SUCCESS;
}
