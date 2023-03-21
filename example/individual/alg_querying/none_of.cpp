// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/none_of.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using nums1 = mhn::vector_c<
  short,
  11, 11, 4, -20, 1, -16, 0, 5, 9, -8, 5, 7, -11, -2, -5, 7, -5, -20, 8, 14
>;
using nums2 = mhn::vector_c<
  short,
  -1, -2, -5, 2, -1, 2, 1, 2, 1, 1, -3, 1, -4, -1, -1, 1, -2, -3, -1, 4
>;

// abs(x) >= 10
using pred = mhn::lambda<
  mhn::greater_equal<mhn::abs<_1>, mhn::short_<10>>
>;

using res1 = typename mhn::none_of<nums1, pred>::type;
using res2 = mhn::none_of<nums2, pred>;

static_assert(!res1::value, "!!!");
static_assert(res2::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
