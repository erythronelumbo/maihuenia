// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/fill.hpp>


namespace mhn = erythronelumbo::maihuenia;

using ones = mhn::fill<mhn::vector_tag, mhn::uint_<1>, mhn::size_c<5>>;
using zeros = typename mhn::fill_c<mhn::vector_tag, mhn::uint_<0>, 5>::type;

static_assert(
  mhn::equal_types_t<
    typename ones::type,
    mhn::vector<
      mhn::uint_<1>, mhn::uint_<1>,mhn::uint_<1>, mhn::uint_<1>, mhn::uint_<1>
    >
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    zeros,
    mhn::vector<
      mhn::uint_<0>, mhn::uint_<0>,mhn::uint_<0>, mhn::uint_<0>, mhn::uint_<0>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
