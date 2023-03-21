// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/find_if.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct is_vowel
{
  template <typename X>
  struct apply :
    mhn::bool_<
      X::value == 'A' ||
      X::value == 'E' ||
      X::value == 'I' ||
      X::value == 'O' ||
      X::value == 'U' ||
      X::value == 'a' ||
      X::value == 'e' ||
      X::value == 'i' ||
      X::value == 'o' ||
      X::value == 'u'
    >
  {};
};


template <typename SeqTag>
void test_find_if()
{
  using seq1 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'a'>, mhn::char_<'e'>, mhn::char_<'i'>, mhn::char_<'o'>,
    mhn::char_<'u'>
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'h'>, mhn::char_<'e'>, mhn::char_<'l'>, mhn::char_<'l'>,
    mhn::char_<'o'>
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>, mhn::char_<'A'>
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>
  >;

  test_eq_types<
    typename mhn::find_if<seq1, is_vowel>::type,
    mhn::some<mhn::size_c<0>>
  >();
  test_eq_types<
    typename mhn::find_if<seq2, is_vowel>::type,
    mhn::some<mhn::size_c<1>>
  >();
  test_eq_types<
    typename mhn::find_if<seq3, is_vowel>::type,
    mhn::some<mhn::size_c<3>>
  >();
  test_eq_types<
    typename mhn::find_if<seq4, is_vowel>::type,
    mhn::none
  >();
  test_eq_types<
    typename mhn::find_if<mhn::make_seq_t<SeqTag>, is_vowel>::type,
    mhn::none
  >();
}


int main()
{
  test_find_if<mhn::vector_tag>();
  test_find_if<mhn::linked_list_tag>();
  test_find_if<mhn::string_tag>();

  return EXIT_SUCCESS;
}
