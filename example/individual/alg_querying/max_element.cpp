// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/min_max_element.hpp>


namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::vector_c<
  int,
  -12, -17, 21, 31, 31, -11, 6, 46,  15, 18,
    5, -17, 13, 19,  0,   6, 2, 16, -30,-10
>;

using res = typename mhn::max_element<nums>::type;

static_assert(mhn::equal_types_t<res, mhn::int_<46>>::value, "!!!");


int main() { return EXIT_SUCCESS; }
