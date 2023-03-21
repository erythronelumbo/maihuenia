// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integral.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equals_t<
    typename mhn::mod<mhn::int_<13>, mhn::int_<4>>::type,
    mhn::int_<1>
  >::value,
  "!!!"
);

static_assert(
  mhn::equals_t<
    mhn::mod_t<mhn::uint_<49>, mhn::uint_<7>>,
    mhn::uint_<0>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
