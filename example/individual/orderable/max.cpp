// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>
#include <erythronelumbo/maihuenia/min_max.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res = mhn::max<
  mhn::ratio_c<int, 51, 70>,
  mhn::ratio_c<int, 40, 39>,
  mhn::ratio_c<int,  2,  5>
>;

static_assert(
  mhn::equals_t<
    typename res::type,
    mhn::ratio_c<int, 40, 39>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
