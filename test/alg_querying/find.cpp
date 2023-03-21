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


template <typename SeqTag>
void test_find()
{
  using seq1 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'a'>, mhn::char_<'.'>, mhn::char_<'e'>, mhn::char_<'i'>,
    mhn::char_<'o'>, mhn::char_<'.'>, mhn::char_<'u'>
  >;
  using seq2 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'h'>, mhn::char_<'e'>, mhn::char_<'l'>, mhn::char_<'l'>,
    mhn::char_<'o'>, mhn::char_<'.'>, mhn::char_<'.'>
  >;
  using seq3 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'.'>, mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>,
    mhn::char_<'A'>
  >;
  using seq4 = mhn::make_seq_t<
    SeqTag,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>
  >;

  test_eq_types<
    typename mhn::find<seq1, mhn::char_<'.'>>::type,
    mhn::some<mhn::size_c<1>>
  >();
  test_eq_types<
    typename mhn::find<seq2, mhn::char_<'.'>>::type,
    mhn::some<mhn::size_c<5>>
  >();
  test_eq_types<
    typename mhn::find<seq3, mhn::char_<'.'>>::type,
    mhn::some<mhn::size_c<0>>
  >();
  test_eq_types<
    typename mhn::find<seq4, mhn::char_<'.'>>::type,
    mhn::none
  >();
  test_eq_types<
    typename mhn::find<mhn::make_seq_t<SeqTag>, mhn::char_<'.'>>::type,
    mhn::none
  >();
}


int main()
{
  test_find<mhn::vector_tag>();
  test_find<mhn::linked_list_tag>();
  test_find<mhn::string_tag>();

  return EXIT_SUCCESS;
}
