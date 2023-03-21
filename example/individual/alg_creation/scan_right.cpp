// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/scan_right.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 5)

namespace mhn = erythronelumbo::maihuenia;

using vowels = mhn::vector<
  mhn::string<'a'>,
  mhn::string<'e'>,
  mhn::string<'i'>,
  mhn::string<'o'>,
  mhn::string<'u'>
>;

using result = typename mhn::scan_right<
  mhn::quote<mhn::concat>,
  vowels,
  mhn::vector_tag
>::type;

static_assert(
  mhn::equal_types_t<
    result,
    mhn::vector<
      STR_("aeiou"),
      STR_("eiou"),
      STR_("iou"),
      STR_("ou"),
      STR_("u")
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
