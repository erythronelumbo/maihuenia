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


struct is_ptr
{
  template <typename T> struct apply : mhn::false_ {};
  template <typename T> struct apply<T*> : mhn::true_ {};
  template <typename T> struct apply<const T*> : mhn::true_ {};
};


template <typename SeqTag>
void test_count_if_chars()
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
  // "The five boxing wizards jump quickly"
  using seq4 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'T'>, mhn::char_<'h'>, mhn::char_<'e'>, mhn::char_<' '>,
    mhn::char_<'f'>, mhn::char_<'i'>, mhn::char_<'v'>, mhn::char_<'e'>,
    mhn::char_<' '>, mhn::char_<'b'>, mhn::char_<'o'>, mhn::char_<'x'>,
    mhn::char_<'i'>, mhn::char_<'n'>, mhn::char_<'g'>, mhn::char_<' '>,
    mhn::char_<'w'>, mhn::char_<'i'>, mhn::char_<'z'>, mhn::char_<'a'>,
    mhn::char_<'r'>, mhn::char_<'d'>, mhn::char_<'s'>, mhn::char_<' '>,
    mhn::char_<'j'>, mhn::char_<'u'>, mhn::char_<'m'>, mhn::char_<'p'>,
    mhn::char_<' '>, mhn::char_<'q'>, mhn::char_<'u'>, mhn::char_<'i'>,
    mhn::char_<'c'>, mhn::char_<'k'>, mhn::char_<'l'>, mhn::char_<'y'>
  >;

  test_eq_types<typename mhn::count_if<seq1, is_vowel>::type, mhn::size_c<0>>();
  test_eq_types<typename mhn::count_if<seq2, is_vowel>::type, mhn::size_c<1>>();
  test_eq_types<typename mhn::count_if<seq3, is_vowel>::type, mhn::size_c<0>>();
  test_eq_types<
    typename mhn::count_if<seq4, is_vowel>::type, mhn::size_c<10>
  >();
}


template <typename SeqTag>
void test_count_if_types()
{
  using seq1 = mhn::make_seq_t<
    SeqTag
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    int*
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    float
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    int**, void, float, double*, char, void***
  >;

  test_eq_types<typename mhn::count_if<seq1, is_ptr>::type, mhn::size_c<0>>();
  test_eq_types<typename mhn::count_if<seq2, is_ptr>::type, mhn::size_c<1>>();
  test_eq_types<typename mhn::count_if<seq3, is_ptr>::type, mhn::size_c<0>>();
  test_eq_types<typename mhn::count_if<seq4, is_ptr>::type, mhn::size_c<3>>();
}


int main()
{
  test_count_if_chars<mhn::vector_tag>();
  test_count_if_chars<mhn::linked_list_tag>();
  test_count_if_chars<mhn::string_tag>();

  test_count_if_types<mhn::vector_tag>();
  test_count_if_types<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
