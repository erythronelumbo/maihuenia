// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/split.hpp>


#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


using splitted = mhn::split<
  STR_("... abc; def,,, ,ghi:jkl.:;, mno ..."),
  mhn::string<' ', '.', ':', ',', ';'>,
  mhn::vector_tag
>;

static_assert(
  mhn::equal_types_t<
    typename splitted::type,
    mhn::vector<
      STR_("abc"), STR_("def"), STR_("ghi"), STR_("jkl"), STR_("mno")
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
