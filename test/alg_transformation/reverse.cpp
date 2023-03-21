// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/reverse.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


using x0 = mhn::char_<'0'>;
using x1 = mhn::char_<'1'>;
using x2 = mhn::char_<'2'>;
using x3 = mhn::char_<'3'>;
using x4 = mhn::char_<'4'>;


template <typename SeqTag>
void test_reverse()
{
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag>>::type,
    mhn::make_seq_t<SeqTag>
  >();
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag, x0>>::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag, x0, x1>>::type,
    mhn::make_seq_t<SeqTag, x1, x0>
  >();
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag, x0, x1, x2>>::type,
    mhn::make_seq_t<SeqTag, x2, x1, x0>
  >();
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag, x0, x1, x2, x3>>::type,
    mhn::make_seq_t<SeqTag, x3, x2, x1, x0>
  >();
  test_eq_types<
    typename mhn::reverse<mhn::make_seq_t<SeqTag, x0, x1, x2, x3, x4>>::type,
    mhn::make_seq_t<SeqTag, x4, x3, x2, x1, x0>
  >();
}


int main()
{
  test_reverse<mhn::linked_list_tag>();
  test_reverse<mhn::vector_tag>();
  test_reverse<mhn::string_tag>();

  return EXIT_SUCCESS;
}
