// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/any_of.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using nums1 = mhn::vector_c<
  std::uint8_t, 7, 9, 9, 5, 7, 9, 1, 1, 7, 9, 7, 5, 9, 5, 9, 9, 9, 3, 5, 3
>;
using nums2 = mhn::vector_c<
  std::uint8_t, 2, 1, 4, 2, 7, 2, 5, 8, 2, 6, 2, 1, 8, 1, 8, 2, 3, 9, 8, 6
>;

// (x % 2) == 0
using pred = mhn::lambda<
  mhn::equals<mhn::mod<_1, mhn::u8_c<2>>, mhn::u8_c<0>>
>;

using res1 = typename mhn::any_of<nums1, pred>::type;
using res2 = mhn::any_of_t<nums2, pred>;

static_assert(!res1::value, "!!!");
static_assert(res2::value, "!!!");


int main() { return EXIT_SUCCESS; }
