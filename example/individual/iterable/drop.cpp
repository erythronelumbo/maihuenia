// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using vec1 = mhn::vector_c<unsigned, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9>;
using vec2 = mhn::vector_c<unsigned>;

static_assert(
  mhn::equal_types_t<
    mhn::drop_t<vec1, mhn::size_c<0>>,
    vec1
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    mhn::drop_c_t<vec1, 5>,
    mhn::vector_c<unsigned, 1, 3, 5, 7, 9>
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    typename mhn::drop_c<vec1, 1>::type,
    mhn::vector_c<unsigned, 2, 4, 6, 8, 1, 3, 5, 7, 9>
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    typename mhn::drop<vec1, mhn::size_c<10>>::type,
    mhn::vector_c<unsigned>
  >::value,
  "!!!"
);
static_assert(
  mhn::equals_t<
    typename mhn::drop<vec2, mhn::size_c<1>>::type,
    mhn::vector_c<unsigned>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
