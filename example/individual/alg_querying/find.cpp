// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/find_if.hpp>


#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;

using str1 = STR_("the quick brown fox jumps over the lazy dog");
using str2 = STR_("the quick brown fox jumps over the lazy hog");

using res1 = typename mhn::find<str1, mhn::char_<'d'>>::type;
using res2 = typename mhn::find<str2, mhn::char_<'d'>>::type;

static_assert(
  mhn::equal_types_t<res1, mhn::some<mhn::size_c<40>>>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<res2, mhn::none>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
