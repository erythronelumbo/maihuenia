// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/scan_right.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::vector_c<unsigned short, 2, 10, 15, 9, 9, 6, 2>;

/*
1
2 / 1 = 2
6 / 2 = 3
9 / 3 = 3
9 / 3 = 3
15 / 3 = 5
10 / 5 = 2
2 / 2 = 1
*/

using res = typename mhn::scan_right_initial<
  mhn::quote<mhn::div>,
  nums,
  mhn::ushort_<1>,
  mhn::vector_tag
>::type;

static_assert(
  mhn::equals_t<
    res,
    mhn::vector_c<unsigned short, 1, 2, 5, 3, 3, 3, 2, 1>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
