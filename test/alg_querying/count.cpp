// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/count_if.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;



template <typename SeqTag>
void test_count_chars()
{
  using seq1 = mhn::make_seq_t<
    SeqTag
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'a'>
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'a'>, mhn::char_<'a'>, mhn::char_<'a'>, mhn::char_<'x'>,
    mhn::char_<'a'>, mhn::char_<'x'>, mhn::char_<'a'>, mhn::char_<'a'>
  >;

  test_eq_types<
    typename mhn::count<seq1, mhn::char_<'a'>>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count<seq2, mhn::char_<'a'>>::type, mhn::size_c<1>
  >();
  test_eq_types<
    typename mhn::count<seq3, mhn::char_<'a'>>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count<seq4, mhn::char_<'a'>>::type, mhn::size_c<6>
  >();
}


template <typename SeqTag>
void test_count_types()
{
  using seq1 = mhn::make_seq_t<
    SeqTag
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    void
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    float
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    int[3], void, float, double*, char, void, void, double[2][2], bool, void
  >;

  test_eq_types<typename mhn::count<seq1, void>::type, mhn::size_c<0>>();
  test_eq_types<typename mhn::count<seq2, void>::type, mhn::size_c<1>>();
  test_eq_types<typename mhn::count<seq3, void>::type, mhn::size_c<0>>();
  test_eq_types<typename mhn::count<seq4, void>::type, mhn::size_c<4>>();
}


int main()
{
  test_count_chars<mhn::vector_tag>();
  test_count_chars<mhn::linked_list_tag>();
  test_count_chars<mhn::string_tag>();

  test_count_types<mhn::vector_tag>();
  test_count_types<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
