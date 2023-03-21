// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>


namespace mhn = erythronelumbo::maihuenia;


using x1 = mhn::ratio_c<int, 1, 2>;
using x2 = mhn::ratio_c<int, 3, 4>;


static_assert(
  mhn::equals_t<mhn::add_t<x1, x2>, mhn::ratio_c<int, 5, 4>>::value,
  "!!!"
);
static_assert(
  mhn::equals_t<mhn::sub_t<x1, x2>, mhn::ratio_c<int, -1, 4>>::value,
  "!!!"
);
static_assert(
  mhn::equals_t<mhn::mul_t<x1, x2>, mhn::ratio_c<int, 3, 8>>::value,
  "!!!"
);
static_assert(
  mhn::equals_t<mhn::quot_t<x1, x2>, mhn::ratio_c<int, 2, 3>>::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    mhn::recip_t<mhn::ratio_c<int, 23, 12>>,
    mhn::ratio_c<int, 12, 23>
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
