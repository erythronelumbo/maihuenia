// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/partition.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using numbers = mhn::vector_c<unsigned, 2, 5, 9, 4, 8, 0, 3, 7, 6, 1>;

using even_odd = typename mhn::partition<
  numbers,
  mhn::lambda<
    mhn::equals<
      mhn::bit_and<_1, mhn::uint_<0x1>>,
      mhn::uint_<0>
    >
  >,
  mhn::vector_tag
>::type;

using even = typename even_odd::first;
using odd = typename even_odd::second;

static_assert(
  mhn::equal_types_t<
    even,
    mhn::vector<
      mhn::uint_<2>,
      mhn::uint_<4>,
      mhn::uint_<8>,
      mhn::uint_<0>,
      mhn::uint_<6>
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    odd,
    mhn::vector<
      mhn::uint_<5>,
      mhn::uint_<9>,
      mhn::uint_<3>,
      mhn::uint_<7>,
      mhn::uint_<1>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
