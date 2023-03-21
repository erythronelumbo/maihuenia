// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::vector_c<int, -9, 8, -7, 6, -5, 4, -3, 2, -1, 0>;

using res1 = mhn::take<nums, mhn::size_c<10>>;
using res2 = mhn::take_c<nums, 5>;
using res3 = mhn::take_t<nums, mhn::size_c<1>>;
using res4 = mhn::take_c_t<nums, 0>;

static_assert(
  mhn::equals_t<
    typename res1::type, nums
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    typename res2::type, mhn::vector_c<int, -9, 8, -7, 6, -5>
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<res3, mhn::vector_c<int, -9>>::value,
  "!!!"
);
static_assert(
  mhn::equals_t<res4, mhn::vector_c<int>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
