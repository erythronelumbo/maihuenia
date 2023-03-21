// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/bitwise.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equals_t<
    typename mhn::bit_xor<
      mhn::u32_c<0x5a5aa5a5>, mhn::u32_c<0xf00f8421>
    >::type,
    mhn::u32_c<0x5a5aa5a5 ^ 0xf00f8421>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
