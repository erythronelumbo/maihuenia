// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/count_until.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct pred_
{
  template <typename C> struct apply : mhn::bool_<(C::value > 'e')> {};
};

struct is_not_ptr
{
  template <typename T> struct apply : mhn::true_ {};
  template <typename T> struct apply<T*> : mhn::false_ {};
  template <typename T> struct apply<const T*> : mhn::false_ {};
};


template <typename SeqTag>
void test_count_until_chars()
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
    mhn::char_<'z'>
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'a'>, mhn::char_<'e'>, mhn::char_<'c'>, mhn::char_<'d'>,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'b'>, mhn::char_<'1'>
  >;
  using seq5 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'h'>, mhn::char_<'e'>, mhn::char_<'l'>, mhn::char_<'l'>,
    mhn::char_<'o'>
  >;

  test_eq_types<
    typename mhn::count_until<seq1, pred_>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count_until<seq2, pred_>::type, mhn::size_c<1>
  >();
  test_eq_types<
    typename mhn::count_until<seq3, pred_>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count_until<seq4, pred_>::type, mhn::size_c<4>
  >();
  test_eq_types<
    typename mhn::count_until<seq5, pred_>::type, mhn::size_c<0>
  >();
}


template <typename SeqTag>
void test_count_until_types()
{
  using seq1 = mhn::make_seq_t<
    SeqTag
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    char*
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    float
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    char*, void*, const int*, unsigned*, unsigned short*, float*, float
  >;
  using seq5 = mhn::make_seq_t<
    SeqTag,
    char, void, int, unsigned, unsigned short, float, float
  >;

  test_eq_types<
    typename mhn::count_until<seq1, is_not_ptr>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count_until<seq2, is_not_ptr>::type, mhn::size_c<1>
  >();
  test_eq_types<
    typename mhn::count_until<seq3, is_not_ptr>::type, mhn::size_c<0>
  >();
  test_eq_types<
    typename mhn::count_until<seq4, is_not_ptr>::type, mhn::size_c<6>
  >();
  test_eq_types<
    typename mhn::count_until<seq5, is_not_ptr>::type, mhn::size_c<0>
  >();
}


int main()
{
  test_count_until_chars<mhn::vector_tag>();
  test_count_until_chars<mhn::linked_list_tag>();
  test_count_until_chars<mhn::string_tag>();

  test_count_until_types<mhn::vector_tag>();
  test_count_until_types<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
