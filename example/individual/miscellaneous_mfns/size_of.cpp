// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/size_of.hpp>

namespace mhn = erythronelumbo::maihuenia;

struct tp1 { std::uint32_t x[13]; };
struct tp2 { std::uint8_t x[5]; };


static_assert(
  mhn::size_of<std::int8_t>::type::value == sizeof(std::int8_t),
  "!!!"
);

static_assert(
  mhn::size_of<std::int16_t>::type::value == sizeof(std::int16_t),
  "!!!"
);

static_assert(
  mhn::size_of<std::int32_t>::type::value == sizeof(std::int32_t),
  "!!!"
);

static_assert(
  mhn::size_of<std::int64_t>::type::value == sizeof(std::int64_t),
  "!!!"
);

static_assert(
  mhn::size_of<std::size_t>::type::value == sizeof(std::size_t),
  "!!!"
);

static_assert(
  mhn::size_of<tp1>::type::value == sizeof(tp1),
  "!!!"
);

static_assert(
  mhn::size_of<tp2>::type::value == sizeof(tp2),
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
