// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/take_while.hpp>

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


struct is_above_char5
{
  template <typename C> struct apply : mhn::bool_<(C::value > '5')> {};
};

template <typename SeqTag>
void test_take_while_ints()
{
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x9>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag, x9>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x9, x8>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag, x9, x8>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x7, x8, x9>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag, x7, x8, x9>
  >();

  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x5>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x6, x4>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag, x6>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x7, x6, x3>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag, x7, x6>
  >();

  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x0>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x1, x2>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x3, x4, x5>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::take_while<
      mhn::make_seq_t<SeqTag, x4, x5, x7, x9>,
      is_above_char5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
}


int main()
{
  test_take_while_ints<mhn::vector_tag>();
  test_take_while_ints<mhn::string_tag>();
  test_take_while_ints<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
