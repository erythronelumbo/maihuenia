// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>


namespace mhn = erythronelumbo::maihuenia;

using sq1 = mhn::vector_c<int, 10, 3, 5, -1, 34>;
using sq2 = mhn::vector_c<int, 3, 6, 9, 12, 15, 18>;

using res1 = typename mhn::contains<sq1, mhn::int_<-1>>::type;
using res2 = typename mhn::contains<sq2, mhn::int_<-1>>::type;

static_assert(res1::value, "!!!");
static_assert(!res2::value, "!!!");


int main() { return EXIT_SUCCESS; }
