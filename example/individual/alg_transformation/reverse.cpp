// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/reverse.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq1 = mhn::make_seq_t<
  mhn::linked_list_tag, char[2], char[3], char[5], char[7], char[11], char[13]
>;

using seq2 = mhn::vector<
  unsigned[2], unsigned[3], unsigned[5],
  unsigned[7], unsigned[11], unsigned[13]
>;

using res1 = mhn::reverse_t<seq1>;
using res2 = typename mhn::reverse_t<seq2>::type;

using expected1 = mhn::make_seq_t<
  mhn::linked_list_tag, char[13], char[11], char[7], char[5], char[3], char[2]
>;

using expected2 = mhn::vector<
  unsigned[13], unsigned[11], unsigned[7],
  unsigned[5], unsigned[3], unsigned[2]
>;

static_assert(mhn::equal_types_t<res1, expected1>::value, "!!!");
static_assert(mhn::equal_types_t<res2, expected2>::value, "!!!");


int main() { return EXIT_SUCCESS; }
