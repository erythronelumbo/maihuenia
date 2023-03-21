// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/count_until.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using numbers = mhn::vector_c<
  short, 4, 2, -1, 6, 10, 3, 8, 6, 4, 9, 7, 8, 1, 0, -3, -6, -10, -8, 10, 3
>;

using res = typename mhn::count_until<
  numbers,
  mhn::bind<mhn::quote<mhn::equals>, mhn::short_<0>, _1>
>::type;

static_assert(res::value == 13, "!!!");


int main() { return EXIT_SUCCESS; }
