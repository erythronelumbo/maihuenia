// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/remove_if.hpp>

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


template <typename SeqTag>
void test_remove_chars()
{
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag>, x5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x1>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x1, x2>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4, x5>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4, x5, x6, x7, x8, x9>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4, x6, x7, x8, x9>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x1, x2, x3, x4, x5, x6, x7, x8, x9>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x1, x2, x3, x4, x6, x7, x8, x9>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x4, x5, x6, x7, x8, x9>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x4, x6, x7, x8, x9>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x5, x6, x7, x8, x9>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x6, x7, x8, x9>
  >();

  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x5>, x5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x5, x5>, x5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x5, x5, x5, x5, x5>, x5
    >::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::remove<
      mhn::make_seq_t<SeqTag, x0, x5, x2, x5, x5, x4, x6, x5, x1, x5, x9>, x5
    >::type,
    mhn::make_seq_t<SeqTag, x0, x2, x4, x6, x1, x9>
  >();
}


int main()
{
  test_remove_chars<mhn::linked_list_tag>();
  test_remove_chars<mhn::vector_tag>();
  test_remove_chars<mhn::string_tag>();

  return EXIT_SUCCESS;
}
