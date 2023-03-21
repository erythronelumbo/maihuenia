// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using value1 = mhn::ratio_c<int, 3, 7>;
using value2 = mhn::ratio_c<int, 5, 14>;
using value3 = mhn::ratio_c<int, 3, 28>;

static_assert(mhn::less_equal<value2, value1>::type::value, "!!!");
static_assert(mhn::less_equal_t<value1, value1>::value, "!!!");
static_assert(mhn::less_equal<value2, value2>::type::value, "!!!");
static_assert(!mhn::less_equal<value1, value3>::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
