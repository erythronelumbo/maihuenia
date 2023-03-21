// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq1a = mhn::vector<mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>>;
using seq1b = mhn::vector<mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>>;

using seq2a = mhn::cons<
  mhn::char_<'a'>,
  mhn::cons<
    mhn::char_<'b'>,
    mhn::cons<
      mhn::char_<'c'>
    >
  >
>;
using seq2b = mhn::cons<
  mhn::char_<'x'>,
  mhn::cons<
    mhn::char_<'y'>,
    mhn::cons<
      mhn::char_<'z'>
    >
  >
>;

using seq3a = mhn::string<'a', 'b', 'c'>;
using seq3b = mhn::string<'x', 'y', 'z'>;

static_assert(
  mhn::equal_types_t<
    mhn::concat_t<seq1a, seq1b>,
    mhn::vector<
      mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>,
      mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>
    >
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::concat_t<seq2a, seq2b>,
    mhn::cons<
      mhn::char_<'a'>,
      mhn::cons<
        mhn::char_<'b'>,
        mhn::cons<
          mhn::char_<'c'>,
          mhn::cons<
            mhn::char_<'x'>,
            mhn::cons<
              mhn::char_<'y'>,
              mhn::cons<
                mhn::char_<'z'>
              >
            >
          >
        >
      >
    >
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename mhn::concat<seq3b, seq3a>::type,
    mhn::string<'x', 'y', 'z', 'a', 'b', 'c'>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
