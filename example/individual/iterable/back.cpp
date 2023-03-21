// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res1 = mhn::back<mhn::null_type>;
using res2 = mhn::back<mhn::vector<>>;
using res3 = mhn::back<mhn::cons<int, mhn::cons<void, mhn::cons<double>>>>;
using res4 = mhn::back_t<mhn::vector<int, void, double>>;

static_assert(
  mhn::equal_types_t<typename res1::type, mhn::index_out_of_range>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<typename res2::type, mhn::index_out_of_range>::value,
  "!!!"
);
static_assert(mhn::equal_types_t<typename res3::type, double>::value, "!!!");
static_assert(mhn::equal_types_t<res4, double>::value, "!!!");


int main() { return EXIT_SUCCESS; }
