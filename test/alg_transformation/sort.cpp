// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/sort.hpp>

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

using pred = mhn::quote<mhn::less>;


template <typename SeqTag>
void test_replace_chars()
{
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x0>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x0, x0>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x0>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x0, x0, x0, x0, x0>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x0, x0, x0, x0>
  >();

  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x0, x1>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x1, x0>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x1, x2, x0>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::sort<
      mhn::make_seq_t<SeqTag, x1, x3, x0, x4, x2>,
      pred
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4>
  >();
}


int main()
{
  test_replace_chars<mhn::linked_list_tag>();
  test_replace_chars<mhn::vector_tag>();
  test_replace_chars<mhn::string_tag>();

  return EXIT_SUCCESS;
}
