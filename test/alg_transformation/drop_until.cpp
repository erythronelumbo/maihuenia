// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/drop_until.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


using x0 = mhn::char_<'0'>;
using x1 = mhn::char_<'1'>;
using x2 = mhn::char_<'2'>;
using x3 = mhn::char_<'3'>;
using x4 = mhn::char_<'4'>;
using x5 = mhn::char_<'5'>;
using x6 = mhn::char_<'6'>;
using x7 = mhn::char_<'7'>;
using x8 = mhn::char_<'8'>;
using x9 = mhn::char_<'9'>;


struct equals_zero
{
  template <typename C> using apply = mhn::equals<C, mhn::char_<'0'>>;
};

template <typename SeqTag>
void test_drop_until()
{
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x0, x1>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x0, x2, x3>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x2, x3>
  >();

  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x4, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x6, x5, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x7, x9, x8, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();

  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x4, x0, x7, x3, x2, x1, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x7, x3, x2, x1, x0>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x6, x5, x0, x6>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x6>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x7, x9, x8, x0, x5>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x5>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x7, x9, x8, x0, x5, x0>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x5, x0>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x7, x9, x8, x0, x5, x0, x1>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x5, x0, x1>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x7, x9, x8, x0, x5, x0, x0, x1>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag, x0, x5, x0, x0, x1>
  >();

  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x1>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x1, x2>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x9, x8, x7>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::drop_until<
      mhn::make_seq_t<SeqTag, x3, x6, x9, x1, x2, x3, x4, x5, x6>,
      equals_zero
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
}


int main()
{
  test_drop_until<mhn::vector_tag>();
  test_drop_until<mhn::string_tag>();
  test_drop_until<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
