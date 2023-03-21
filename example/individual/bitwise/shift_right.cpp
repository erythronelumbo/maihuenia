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
    typename mhn::shift_right<mhn::u32_c<0x80800101>, mhn::uint_<9>>::type,
    mhn::u32_c<0x00404000>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
