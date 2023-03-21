// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/size_of.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct trfm
{
  template <typename T>
  using apply = mhn::size_of<T>;
};

static_assert(
  mhn::equal_types_t<
    typename mhn::transform<trfm, mhn::some<std::uint32_t>>::type,
    mhn::some<mhn::size_c<4>>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename mhn::transform<trfm, mhn::none>::type,
    mhn::none
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::transform_t<
      trfm,
      mhn::vector<std::uint32_t, std::uint16_t, std::uint64_t, std::uint8_t>
    >,
    mhn::vector<mhn::size_c<4>, mhn::size_c<2>, mhn::size_c<8>, mhn::size_c<1>>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
