// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/all_of.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using nums1 = mhn::vector_c<std::int8_t, 8, 2, 4, 0, 6, 2, 2, 7, 9, 10>;
using nums2 = mhn::vector_c<std::int8_t, 1, -9, -2, 7, -10, -4, -7, 8, -4, 9>;

// x >= 0
using pred = mhn::lambda<mhn::greater_equal<_1, mhn::i8_c<0>>>;

using res1 = mhn::all_of<nums1, pred>;
using res2 = mhn::all_of_t<nums2, pred>;

static_assert(res1::type::value, "!!!");
static_assert(!res2::value, "!!!");


int main() { return EXIT_SUCCESS; }
