// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/iota.hpp>


namespace mhn = erythronelumbo::maihuenia;

using alphabet = typename mhn::iota<
  mhn::string_tag,
  char,
  mhn::char_<'a'>,
  mhn::size_c<26>
>::type;

using countdown = typename mhn::iota_c<
  mhn::vector_tag, std::uint16_t, 10, 11, -1
>::type;

static_assert(
  mhn::equal_types_t<
    alphabet,
    ERYTHRONELUMBO_MAIHUENIA_STRING("abcdefghijklmnopqrstuvwxyz")
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    countdown,
    mhn::vector<
      mhn::u16_c<10>, mhn::u16_c< 9>, mhn::u16_c< 8>, mhn::u16_c< 7>,
      mhn::u16_c< 6>, mhn::u16_c< 5>, mhn::u16_c< 4>, mhn::u16_c< 3>,
      mhn::u16_c< 2>, mhn::u16_c< 1>, mhn::u16_c< 0>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
