// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::not_equals<mhn::long_<123>, mhn::long_<-5391>>::type::value,
  "!!!"
);

static_assert(
  !mhn::not_equals_t<mhn::uint_<123>, mhn::uint_<123>>::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
