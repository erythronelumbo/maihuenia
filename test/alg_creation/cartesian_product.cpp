// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/cartesian_product.hpp>

#include "../eq_types.hpp"

#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 5)

namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};

struct y0 {};
struct y1 {};
struct y2 {};
struct y3 {};
struct y4 {};


template <typename SeqTag>
constexpr void test_cprod()
{
  using it1 = mhn::cons<x0, mhn::cons<x1>>;
  using it2 = mhn::vector<x0, x1, x2, x3>;

  using res = typename mhn::cartesian_product<SeqTag, it1, it2>::type;

  test_eq_types<
    res,
    mhn::make_seq_t<
      SeqTag,
      mhn::vector<x0, x0>,
      mhn::vector<x0, x1>,
      mhn::vector<x0, x2>,
      mhn::vector<x0, x3>,
      mhn::vector<x1, x0>,
      mhn::vector<x1, x1>,
      mhn::vector<x1, x2>,
      mhn::vector<x1, x3>
    >
  >();
}

template <typename SeqTag>
constexpr void test_cprod_1()
{
  using it1 = mhn::range_c<short, 10, 5, -5>;
  using it2 = STR_("aeiou");
  using it3 = mhn::cons<x0, mhn::cons<x1, mhn::cons<x2>>>;
  using it4 = mhn::vector<y0, y1>;

  using res = typename mhn::cartesian_product<
    SeqTag,
    it1, it2, it3, it4
  >::type;

  using expected = mhn::make_seq_t<
    SeqTag,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x0, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x0, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x1, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x1, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x2, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'a'>, x2, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x0, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x0, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x1, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x1, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x2, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'e'>, x2, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x0, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x0, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x1, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x1, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x2, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'i'>, x2, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x0, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x0, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x1, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x1, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x2, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'o'>, x2, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x0, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x0, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x1, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x1, y1>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x2, y0>,
    mhn::vector<mhn::short_< 10>, mhn::char_<'u'>, x2, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x0, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x0, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x1, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x1, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x2, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'a'>, x2, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x0, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x0, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x1, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x1, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x2, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'e'>, x2, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x0, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x0, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x1, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x1, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x2, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'i'>, x2, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x0, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x0, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x1, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x1, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x2, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'o'>, x2, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x0, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x0, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x1, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x1, y1>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x2, y0>,
    mhn::vector<mhn::short_<  5>, mhn::char_<'u'>, x2, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x0, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x0, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x1, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x1, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x2, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'a'>, x2, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x0, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x0, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x1, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x1, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x2, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'e'>, x2, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x0, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x0, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x1, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x1, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x2, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'i'>, x2, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x0, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x0, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x1, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x1, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x2, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'o'>, x2, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x0, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x0, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x1, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x1, y1>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x2, y0>,
    mhn::vector<mhn::short_<  0>, mhn::char_<'u'>, x2, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x0, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x0, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x1, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x1, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x2, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'a'>, x2, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x0, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x0, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x1, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x1, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x2, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'e'>, x2, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x0, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x0, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x1, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x1, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x2, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'i'>, x2, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x0, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x0, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x1, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x1, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x2, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'o'>, x2, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x0, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x0, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x1, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x1, y1>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x2, y0>,
    mhn::vector<mhn::short_< -5>, mhn::char_<'u'>, x2, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x0, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x0, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x1, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x1, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x2, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'a'>, x2, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x0, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x0, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x1, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x1, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x2, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'e'>, x2, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x0, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x0, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x1, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x1, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x2, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'i'>, x2, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x0, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x0, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x1, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x1, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x2, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'o'>, x2, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x0, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x0, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x1, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x1, y1>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x2, y0>,
    mhn::vector<mhn::short_<-10>, mhn::char_<'u'>, x2, y1>
  >;

  test_eq_types<res, expected>();
}


int main()
{
  test_cprod<mhn::linked_list_tag>();
  test_cprod<mhn::vector_tag>();
  test_cprod_1<mhn::linked_list_tag>();
  test_cprod_1<mhn::vector_tag>();

  return EXIT_SUCCESS;
}
