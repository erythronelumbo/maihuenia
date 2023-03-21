// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/has_repeated.hpp>


namespace mhn = erythronelumbo::maihuenia;

using types1 = mhn::make_seq_t<
  mhn::linked_list_tag,
  int(*)(int, int),
  void(*)(int),
  double*,
  int(*)(char*, char*, bool(*)(char))
>;

using types2 = mhn::make_seq_t<
  mhn::linked_list_tag,
  void*,
  void(*)(int),
  double*,
  void*
>;

using res1 = typename mhn::has_repeated<types1>::type;
using res2 = mhn::has_repeated_t<types2>;

static_assert(!res1::value, "!!!");
static_assert(res2::value, "!!!");


int main() { return EXIT_SUCCESS; }
