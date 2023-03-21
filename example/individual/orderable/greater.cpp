// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using value1 = mhn::ratio_c<int, 1, 20>;
using value2 = mhn::ratio_c<int, 2, 5>;
using value3 = mhn::ratio_c<int, 59, 60>;

static_assert(mhn::greater<value3, value1>::type::value, "!!!");
static_assert(!mhn::greater_t<value1, value2>::value, "!!!");
static_assert(mhn::greater_t<value3, value2>::value, "!!!");


int main() { return EXIT_SUCCESS; }
