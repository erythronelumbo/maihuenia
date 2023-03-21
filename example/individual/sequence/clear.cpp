// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq1 = mhn::cons<
  mhn::int_<0>,
  mhn::cons<
    mhn::int_<1>,
    mhn::cons<
      mhn::int_<2>
    >
  >
>;
using seq2 = mhn::vector<mhn::int_<3>, mhn::int_<4>, mhn::int_<5>, void>;
using seq3 = mhn::string<'6', '7', '8', '9'>;

static_assert(
  mhn::equal_types_t<typename mhn::clear<seq1>::type, mhn::null_type>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<typename mhn::clear<seq2>::type, mhn::vector<>>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<mhn::clear_t<seq3>, mhn::string<>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
