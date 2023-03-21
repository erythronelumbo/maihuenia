// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/set.hpp>


namespace mhn = erythronelumbo::maihuenia;

template <typename T> struct rgb_t { T r{0}, g{0}, b{0}; };
template <typename T> struct rgba_t { T r{0}, g{0}, b{0}, a{0}; };
template <typename T> struct cmyk_t { T c{0}, m{0}, y{0}, k{0}; };

using pixel_types = mhn::set<
  rgb_t<std::uint8_t>,
  rgba_t<std::uint8_t>,
  cmyk_t<std::uint8_t>,
  int[3]
>;

using pixel_types1 = mhn::ainsert_t<
  mhn::ainsert_t<
    mhn::ainsert_t<
      pixel_types,
      rgb_t<float>
    >,
    rgba_t<float>
  >,
  cmyk_t<float>
>;

static_assert(
  mhn::equal_types_t<
    mhn::set<
      rgb_t<std::uint8_t>,
      rgba_t<std::uint8_t>,
      cmyk_t<std::uint8_t>,
      int[3],
      rgb_t<float>,
      rgba_t<float>,
      cmyk_t<float>
    >,
    pixel_types1
  >::value,
  "!!!"
);

using pixel_types2 = mhn::ainsert_t<pixel_types1, rgb_t<std::uint8_t>>;

static_assert(
  mhn::equal_types_t<
    mhn::set<
      rgb_t<std::uint8_t>,
      rgba_t<std::uint8_t>,
      cmyk_t<std::uint8_t>,
      int[3],
      rgb_t<float>,
      rgba_t<float>,
      cmyk_t<float>
    >,
    pixel_types2
  >::value,
  "!!!"
);

using pixel_types3 = mhn::aerase_t<pixel_types2, int[3]>;

static_assert(
  mhn::equal_types_t<
    mhn::set<
      rgb_t<std::uint8_t>,
      rgba_t<std::uint8_t>,
      cmyk_t<std::uint8_t>,
      rgb_t<float>,
      rgba_t<float>,
      cmyk_t<float>
    >,
    pixel_types3
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
