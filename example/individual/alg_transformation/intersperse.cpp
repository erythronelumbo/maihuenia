// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/intersperse.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res = mhn::intersperse<
  mhn::vector_c<int, 0, 2, 4, 6, 8, 1, 3, 5, 7, 9>,
  void
>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    mhn::vector<
      mhn::int_<0>, void, mhn::int_<2>, void, mhn::int_<4>, void,
      mhn::int_<6>, void, mhn::int_<8>, void, mhn::int_<1>, void,
      mhn::int_<3>, void, mhn::int_<5>, void, mhn::int_<7>, void,
      mhn::int_<9>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
