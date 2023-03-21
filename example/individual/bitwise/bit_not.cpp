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
    typename mhn::bit_not<mhn::u64_c<0x0123456789abcdefull>>::type,
    mhn::u64_c<0xfedcba9876543210ull>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
