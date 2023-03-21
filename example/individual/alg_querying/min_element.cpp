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
  -32, 36,   4, -8, 5, -13, 34, 11, -17, -12,
   17,  1, -12,  2, 4,  20, 13, 13,  25, -25
>;

using res = typename mhn::min_element<nums>::type;

static_assert(mhn::equal_types_t<res, mhn::int_<-32>>::value, "!!!");


int main() { return EXIT_SUCCESS; }
