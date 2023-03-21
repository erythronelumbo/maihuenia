// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/min_max_element.hpp>

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


template <typename SeqTag>
void test_max_elem()
{
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag>>::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x0>>::type,
    x0
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x1, x0>>::type,
    x1
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x0, x1>>::type,
    x1
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x0, x0>>::type,
    x0
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x3, x2, x4>>::type,
    x4
  >();
  test_eq_types<
    typename mhn::max_element<mhn::make_seq_t<SeqTag, x5, x7, x4, x6>>::type,
    x7
  >();
}


int main()
{
  test_max_elem<mhn::vector_tag>();
  test_max_elem<mhn::string_tag>();
  test_max_elem<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
