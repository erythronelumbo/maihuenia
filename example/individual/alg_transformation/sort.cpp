// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/size_of.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/sort.hpp>


namespace mhn = erythronelumbo::maihuenia;

// 4 bytes
struct aaa { std::uint16_t x; std::uint8_t y; std::int8_t z; };

// 2 bytes
struct bbb { std::uint8_t x[2]; };

// 12 bytes
struct ccc { std::uint64_t x; std::int16_t y[2]; };

// ~23 bytes
struct ddd { std::int32_t x[5]; std::int8_t y[3]; };

// ~5 bytes
struct eee { std::uint16_t w; std::uint8_t x; std::int8_t y; std::uint8_t z; };

struct lesser_size
{
  template <typename A, typename B>
  using apply = mhn::less<
    typename mhn::size_of<A>::type,
    typename mhn::size_of<B>::type
  >;
};

using res = typename mhn::sort<
  mhn::vector<aaa, bbb, ccc, ddd, eee>,
  lesser_size
>::type;

static_assert(
  mhn::equal_types_t<res, mhn::vector<bbb, aaa, eee, ccc, ddd>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
