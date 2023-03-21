// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/logical.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res1 = mhn::logical_not_t<mhn::false_>;
using res2 = mhn::logical_not<mhn::true_>;

static_assert(mhn::equals_t<res1, mhn::true_>::value, "!!!");
static_assert(mhn::equals_t<typename res2::type, mhn::false_>::value, "!!!");


int main() { return EXIT_SUCCESS; }
