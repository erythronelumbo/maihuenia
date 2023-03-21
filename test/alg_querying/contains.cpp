// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


template <typename SeqTag>
void test_contains_chars()
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
  using seq5 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>, mhn::char_<'0'>,
    mhn::char_<'1'>, mhn::char_<'2'>, mhn::char_<'3'>, mhn::char_<'4'>
  >;
  using seq6 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>, mhn::char_<'x'>, mhn::char_<'x'>, mhn::char_<'x'>,
    mhn::char_<'x'>, mhn::char_<'x'>, mhn::char_<'a'>, mhn::char_<'a'>
  >;

  static_assert(!mhn::contains<seq1, mhn::char_<'a'>>::type::value, "!!!");
  static_assert(mhn::contains<seq2, mhn::char_<'a'>>::type::value, "!!!");
  static_assert(!mhn::contains<seq3, mhn::char_<'a'>>::type::value, "!!!");
  static_assert(mhn::contains<seq4, mhn::char_<'a'>>::type::value, "!!!");
  static_assert(!mhn::contains<seq5, mhn::char_<'a'>>::type::value, "!!!");
  static_assert(mhn::contains<seq6, mhn::char_<'a'>>::type::value, "!!!");
}


template <typename SeqTag>
void test_contains_types()
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
  using seq5 = mhn::make_seq_t<
    SeqTag,
    int[3], double, float, double*, char, short, unsigned, double[2][2], bool
  >;
  using seq6 = mhn::make_seq_t<
    SeqTag,
    int[3], double, float, double*, char, short, unsigned, double[2][2], void
  >;
  using seq7 = mhn::make_seq_t<
    SeqTag,
    void, void, void, void, void, void, void, void, void, void
  >;

  static_assert(!mhn::contains<seq1, void>::type::value, "!!!");
  static_assert(mhn::contains<seq2, void>::type::value, "!!!");
  static_assert(!mhn::contains<seq3, void>::type::value, "!!!");
  static_assert(mhn::contains<seq4, void>::type::value, "!!!");
  static_assert(!mhn::contains<seq5, void>::type::value, "!!!");
  static_assert(mhn::contains<seq6, void>::type::value, "!!!");
  static_assert(mhn::contains<seq7, void>::type::value, "!!!");
}


int main()
{
  test_contains_chars<mhn::vector_tag>();
  test_contains_chars<mhn::linked_list_tag>();
  test_contains_chars<mhn::string_tag>();

  test_contains_types<mhn::vector_tag>();
  test_contains_types<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
