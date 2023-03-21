// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>


namespace mhn = erythronelumbo::maihuenia;

using lifted = typename mhn::lift<mhn::optional_tag, float>::type;

static_assert(mhn::equal_types_t<lifted, mhn::some<float>>::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
