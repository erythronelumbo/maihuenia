// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equals_t<mhn::short_<123>, mhn::longlong_<123>>::value,
  "!!!"
);

static_assert(
  !mhn::equals<mhn::short_<123>, mhn::uchar_<122>>::type::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
