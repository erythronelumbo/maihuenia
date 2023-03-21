// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/cartesian_product.hpp>


struct pike;
struct clover;
struct heart;
struct tile;

namespace mhn = erythronelumbo::maihuenia;

using ranks = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("23456789JQKA", 13);
using suits = mhn::vector<pike, clover, heart, tile>;

using deck = typename mhn::cartesian_product<
  mhn::vector_tag, ranks, suits
>::type;

using expected = mhn::vector<
  mhn::vector<mhn::char_<'2'>, pike>, mhn::vector<mhn::char_<'2'>, clover>,
  mhn::vector<mhn::char_<'2'>, heart>, mhn::vector<mhn::char_<'2'>, tile>,
  mhn::vector<mhn::char_<'3'>, pike>, mhn::vector<mhn::char_<'3'>, clover>,
  mhn::vector<mhn::char_<'3'>, heart>, mhn::vector<mhn::char_<'3'>, tile>,
  mhn::vector<mhn::char_<'4'>, pike>, mhn::vector<mhn::char_<'4'>, clover>,
  mhn::vector<mhn::char_<'4'>, heart>, mhn::vector<mhn::char_<'4'>, tile>,
  mhn::vector<mhn::char_<'5'>, pike>, mhn::vector<mhn::char_<'5'>, clover>,
  mhn::vector<mhn::char_<'5'>, heart>, mhn::vector<mhn::char_<'5'>, tile>,
  mhn::vector<mhn::char_<'6'>, pike>, mhn::vector<mhn::char_<'6'>, clover>,
  mhn::vector<mhn::char_<'6'>, heart>, mhn::vector<mhn::char_<'6'>, tile>,
  mhn::vector<mhn::char_<'7'>, pike>, mhn::vector<mhn::char_<'7'>, clover>,
  mhn::vector<mhn::char_<'7'>, heart>, mhn::vector<mhn::char_<'7'>, tile>,
  mhn::vector<mhn::char_<'8'>, pike>, mhn::vector<mhn::char_<'8'>, clover>,
  mhn::vector<mhn::char_<'8'>, heart>, mhn::vector<mhn::char_<'8'>, tile>,
  mhn::vector<mhn::char_<'9'>, pike>, mhn::vector<mhn::char_<'9'>, clover>,
  mhn::vector<mhn::char_<'9'>, heart>, mhn::vector<mhn::char_<'9'>, tile>,
  mhn::vector<mhn::char_<'J'>, pike>, mhn::vector<mhn::char_<'J'>, clover>,
  mhn::vector<mhn::char_<'J'>, heart>, mhn::vector<mhn::char_<'J'>, tile>,
  mhn::vector<mhn::char_<'Q'>, pike>, mhn::vector<mhn::char_<'Q'>, clover>,
  mhn::vector<mhn::char_<'Q'>, heart>, mhn::vector<mhn::char_<'Q'>, tile>,
  mhn::vector<mhn::char_<'K'>, pike>, mhn::vector<mhn::char_<'K'>, clover>,
  mhn::vector<mhn::char_<'K'>, heart>, mhn::vector<mhn::char_<'K'>, tile>,
  mhn::vector<mhn::char_<'A'>, pike>, mhn::vector<mhn::char_<'A'>, clover>,
  mhn::vector<mhn::char_<'A'>, heart>, mhn::vector<mhn::char_<'A'>, tile>
>;

static_assert(mhn::equal_types_t<deck, expected>::value, "!!!");


int main() { return EXIT_SUCCESS; }
