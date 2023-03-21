// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/logical.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res1 = mhn::logical_and<mhn::false_, mhn::false_>;
using res2 = mhn::logical_and<mhn::false_, mhn::true_>;
using res3 = mhn::logical_and<mhn::true_, mhn::false_>;
using res4 = mhn::logical_and<mhn::true_, mhn::true_>;

static_assert(mhn::equals_t<typename res1::type, mhn::false_>::value, "!!!");
static_assert(mhn::equals_t<typename res2::type, mhn::false_>::value, "!!!");
static_assert(mhn::equals_t<typename res3::type, mhn::false_>::value, "!!!");
static_assert(mhn::equals_t<typename res4::type, mhn::true_>::value, "!!!");


int main() { return EXIT_SUCCESS; }
