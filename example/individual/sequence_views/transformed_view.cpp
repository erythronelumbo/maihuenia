// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/transformed_view.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct tms_fn
{
  template <typename T>
  struct apply :
    mhn::u32_c<
      (
        (T::value >> 7) ^
        (T::value >> 6) ^
        (T::value >> 5) ^
        (T::value >> 4) ^
        (T::value >> 3) ^
        (T::value >> 2) ^
        (T::value >> 1) ^
        (T::value)
      ) &
      0x1
    >
  {};
};

// Thue-Morse seq.: 0, 1, 1, 0, 1, 0, 0, 1, ...
using thue_morse_seq = mhn::transformed_view<
  mhn::range_c<std::uint8_t, 0, 16>,
  tms_fn
>;

using res = mhn::logical_and<
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 0>, mhn::u32_c<0>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 1>, mhn::u32_c<1>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 2>, mhn::u32_c<1>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 3>, mhn::u32_c<0>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 4>, mhn::u32_c<1>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 5>, mhn::u32_c<0>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 6>, mhn::u32_c<0>>,
  mhn::equal_types_t<mhn::at_c_t<thue_morse_seq, 7>, mhn::u32_c<1>>
>;

static_assert(res::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
