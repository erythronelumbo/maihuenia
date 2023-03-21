// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>
#include <erythronelumbo/maihuenia/set.hpp>


namespace mhn = erythronelumbo::maihuenia;

using letters = mhn::set<
  mhn::char_<'a'>,
  mhn::char_<'e'>,
  mhn::char_<'i'>,
  mhn::char_<'o'>,
  mhn::char_<'u'>
>;

using res1 = mhn::ainsert<letters, mhn::char_<'y'>>;
using res2 = mhn::ainsert<letters, mhn::char_<'o'>>;

static_assert(
  mhn::equal_types_t<
    typename res1::type,
    mhn::set<
      mhn::char_<'a'>,
      mhn::char_<'e'>,
      mhn::char_<'i'>,
      mhn::char_<'o'>,
      mhn::char_<'u'>,
      mhn::char_<'y'>
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<typename res2::type, letters>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
