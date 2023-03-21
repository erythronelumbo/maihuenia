// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq1 = mhn::cons<long>;
using seq2 = mhn::push_front_t<seq1, bool>;
using seq3 = mhn::push_back_t<seq2, void>;
using seq4 = mhn::concat_t<
  mhn::cons<mhn::int_<1>, mhn::cons<mhn::int_<2>>>,
  seq3,
  mhn::null_type
>;

static_assert(
  mhn::equal_types_t<
    seq4,
    mhn::make_seq_t<
      mhn::linked_list_tag, mhn::int_<1>, mhn::int_<2>, bool, long, void
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<mhn::at_c_t<seq4, 2>, bool>::value,
  "!!!"
);


// ", world!"
using common_tail = mhn::make_seq_t<
  mhn::linked_list_tag,
  mhn::char_<','>, mhn::char_<' '>, mhn::char_<'w'>, mhn::char_<'o'>,
  mhn::char_<'r'>, mhn::char_<'l'>, mhn::char_<'d'>, mhn::char_<'!'>
>;

// `lst1` and `ls2` share the same "tail".

// "Hello, world!"
using lst1 = mhn::cons<
  mhn::char_<'H'>,
  mhn::cons<
    mhn::char_<'e'>,
    mhn::cons<
      mhn::char_<'l'>,
      mhn::cons<
        mhn::char_<'l'>,
        mhn::cons<
          mhn::char_<'o'>,
          common_tail
        >
      >
    >
  >
>;

// "Bye, world!"
using lst2 = mhn::cons<
  mhn::char_<'B'>,
  mhn::cons<
    mhn::char_<'y'>,
    mhn::cons<
      mhn::char_<'e'>,
      common_tail
    >
  >
>;

static_assert(
  mhn::equals_t<
    lst1,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      mhn::char_<'H'>, mhn::char_<'e'>, mhn::char_<'l'>, mhn::char_<'l'>,
      mhn::char_<'o'>, mhn::char_<','>, mhn::char_<' '>, mhn::char_<'w'>,
      mhn::char_<'o'>, mhn::char_<'r'>, mhn::char_<'l'>, mhn::char_<'d'>,
      mhn::char_<'!'>
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equals_t<
    lst2,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      mhn::char_<'B'>, mhn::char_<'y'>, mhn::char_<'e'>, mhn::char_<','>,
      mhn::char_<' '>, mhn::char_<'w'>, mhn::char_<'o'>, mhn::char_<'r'>,
      mhn::char_<'l'>, mhn::char_<'d'>, mhn::char_<'!'>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
