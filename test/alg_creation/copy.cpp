// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/copy.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


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


int main()
{
  using mhn::cons;

  using src1 = mhn::vector_c<int, -9, 2, -5, 8, -1, 4, -7, 0, -3, 6>;
  using src2 = STR_("abcxyz123");
  using src3 = cons<a0, cons<a1, cons<a2, cons<a3, cons<a4, cons<a5>>>>>>;
  using src4 = mhn::vector<a6, a7, a8, a9>;
  using src6 = mhn::vector<
    mhn::char_<'h'>, mhn::char_<'e'>, mhn::char_<'l'>, mhn::char_<'l'>,
    mhn::char_<'o'>
  >;

  test_eq_types<
    typename mhn::copy<mhn::vector_tag, src1>::type,
    mhn::vector<
      mhn::int_<-9>, mhn::int_<2>, mhn::int_<-5>, mhn::int_<8>, mhn::int_<-1>,
      mhn::int_<4>, mhn::int_<-7>, mhn::int_<0>, mhn::int_<-3>, mhn::int_<6>
    >
  >();
  test_eq_types<
    typename mhn::copy<mhn::linked_list_tag, src1>::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      mhn::int_<-9>, mhn::int_<2>, mhn::int_<-5>, mhn::int_<8>, mhn::int_<-1>,
      mhn::int_<4>, mhn::int_<-7>, mhn::int_<0>, mhn::int_<-3>, mhn::int_<6>
    >
  >();

  test_eq_types<
    typename mhn::copy<mhn::vector_tag, src2>::type,
    mhn::vector<
      mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>, mhn::char_<'x'>,
      mhn::char_<'y'>, mhn::char_<'z'>, mhn::char_<'1'>, mhn::char_<'2'>,
      mhn::char_<'3'>
    >
  >();
  test_eq_types<
    typename mhn::copy<mhn::string_tag, src2>::type,
    mhn::string<'a', 'b', 'c', 'x', 'y', 'z', '1', '2', '3'>
  >();
  test_eq_types<
    typename mhn::copy<mhn::linked_list_tag, src2>::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>, mhn::char_<'x'>,
      mhn::char_<'y'>, mhn::char_<'z'>, mhn::char_<'1'>, mhn::char_<'2'>,
      mhn::char_<'3'>
    >
  >();

  test_eq_types<
    mhn::copy_t<mhn::linked_list_tag, src3>,
    src3
  >();
  test_eq_types<
    mhn::copy_t<mhn::vector_tag, src3>,
    mhn::vector<a0, a1, a2, a3, a4, a5>
  >();

  test_eq_types<
    mhn::copy_t<mhn::linked_list_tag, src4>,
    cons<a6, cons<a7, cons<a8, cons<a9>>>>
  >();
  test_eq_types<
    mhn::copy_t<mhn::vector_tag, src4>,
    src4
  >();

  test_eq_types<
    mhn::copy_t<mhn::string_tag, src6>,
    STR_("hello")
  >();

  return EXIT_SUCCESS;
}
