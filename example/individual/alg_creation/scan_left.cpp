// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/scan_left.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace mhn = erythronelumbo::maihuenia;

using input_seq = mhn::vector_c<unsigned, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10>;

using arithmetic_seq = typename mhn::scan_left<
  mhn::quote<mhn::add>,
  input_seq,
  mhn::vector_tag
>::type;

static_assert(
  mhn::equals_t<
    arithmetic_seq,
    mhn::vector_c<unsigned, 0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
