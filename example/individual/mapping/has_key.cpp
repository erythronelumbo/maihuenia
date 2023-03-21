// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/mapping.hpp>
#include <erythronelumbo/maihuenia/map.hpp>
#include <erythronelumbo/maihuenia/set.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 10)

namespace mhn = erythronelumbo::maihuenia;

using my_map = mhn::map<
  mhn::pair<mhn::char_<'A'>, STR_("Alpha")>,
  mhn::pair<mhn::char_<'B'>, STR_("Bravo")>,
  mhn::pair<mhn::char_<'C'>, STR_("Charlie")>,
  mhn::pair<mhn::char_<'D'>, STR_("Delta")>,
  mhn::pair<mhn::char_<'E'>, STR_("Echo")>
>;

using my_set = mhn::set<
  mhn::char_<'a'>,
  mhn::char_<'e'>,
  mhn::char_<'i'>,
  mhn::char_<'o'>,
  mhn::char_<'u'>
>;

static_assert(mhn::has_key<my_map, mhn::char_<'A'>>::type::value, "!!!");
static_assert(!mhn::has_key<my_map, mhn::char_<'f'>>::type::value, "!!!");
static_assert(mhn::has_key_t<my_set, mhn::char_<'i'>>::value, "!!!");
static_assert(!mhn::has_key<my_set, mhn::char_<'w'>>::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
