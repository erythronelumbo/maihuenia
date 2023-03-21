// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/rational.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equals_t<
    typename mhn::quot<
      mhn::ratio_c<int, -12, 5>,
      mhn::ratio_c<int, 3, 2>
    >::type,
    mhn::ratio_c<int, -8, 5>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
