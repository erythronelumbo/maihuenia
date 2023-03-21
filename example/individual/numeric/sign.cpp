// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equal_types_t<
    typename mhn::sign<mhn::short_<-15>>::type, mhn::short_<-1>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename mhn::sign<mhn::short_<0>>::type, mhn::short_<0>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::sign_t<mhn::short_<31>>, mhn::short_<1>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
