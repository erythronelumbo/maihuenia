// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>
#include <erythronelumbo/maihuenia/set.hpp>
#include <erythronelumbo/maihuenia/map.hpp>


namespace mhn = erythronelumbo::maihuenia;

using assoc_seq1 = mhn::set<int, void, float, double>;

template <char C, typename T>
using map_item_ = mhn::pair<mhn::char_<C>, T>;

using assoc_seq2 = mhn::map<
  map_item_<'x', void*>,
  map_item_<'y', void**>,
  map_item_<'z', void***>,
  map_item_<'w', void****>
>;

using res1 = mhn::aclear<assoc_seq1>;
using res2 = mhn::aclear<assoc_seq2>;

static_assert(mhn::equal_types_t<typename res1::type, mhn::set<>>::value, "!");
static_assert(mhn::equal_types_t<typename res2::type, mhn::map<>>::value, "!");


int main() { return EXIT_SUCCESS; }
