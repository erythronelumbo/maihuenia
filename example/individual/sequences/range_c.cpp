// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using rng1 = mhn::range_c<unsigned, 10, 11, -1>;
using rng2 = mhn::range_c<unsigned, 0, 10, 2>;

static_assert(mhn::not_equals_t<rng1, rng2>::value, "!!!");

#define CHECK_ELEM(seq_, idx_, value_) \
static_assert( \
  mhn::equals_t<mhn::at_c_t<seq_, idx_>, mhn::uint_<value_>>::value, "!!!" \
)

CHECK_ELEM(rng1,  0, 10);
CHECK_ELEM(rng1,  1,  9);
CHECK_ELEM(rng1,  2,  8);
CHECK_ELEM(rng1,  3,  7);
CHECK_ELEM(rng1,  4,  6);
CHECK_ELEM(rng1,  5,  5);
CHECK_ELEM(rng1,  6,  4);
CHECK_ELEM(rng1,  7,  3);
CHECK_ELEM(rng1,  8,  2);
CHECK_ELEM(rng1,  9,  1);
CHECK_ELEM(rng1, 10,  0);

CHECK_ELEM(rng2, 0,  0);
CHECK_ELEM(rng2, 1,  2);
CHECK_ELEM(rng2, 2,  4);
CHECK_ELEM(rng2, 3,  6);
CHECK_ELEM(rng2, 4,  8);
CHECK_ELEM(rng2, 5, 10);
CHECK_ELEM(rng2, 6, 12);
CHECK_ELEM(rng2, 7, 14);
CHECK_ELEM(rng2, 8, 16);
CHECK_ELEM(rng2, 9, 18);


int main() { return EXIT_SUCCESS; }
