// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/map.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 10)

namespace mhn = erythronelumbo::maihuenia;

using names = mhn::map<
  mhn::pair<mhn::char_<'a'>, STR_("Albert")>,
  mhn::pair<mhn::char_<'b'>, STR_("Edward")>,
  mhn::pair<mhn::char_<'c'>, STR_("Ismael")>,
  mhn::pair<mhn::char_<'?'>, STR_("wtf")>,
  mhn::pair<mhn::char_<'d'>, STR_("Oswald")>,
  mhn::pair<mhn::char_<'e'>, STR_("Ulises")>
>;

using res = mhn::aerase<names, mhn::char_<'?'>>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    mhn::map<
      mhn::pair<mhn::char_<'a'>, STR_("Albert")>,
      mhn::pair<mhn::char_<'b'>, STR_("Edward")>,
      mhn::pair<mhn::char_<'c'>, STR_("Ismael")>,
      mhn::pair<mhn::char_<'d'>, STR_("Oswald")>,
      mhn::pair<mhn::char_<'e'>, STR_("Ulises")>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
