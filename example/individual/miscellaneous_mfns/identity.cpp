// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>


namespace mhn = erythronelumbo::maihuenia;


using tp = char[3][5][4][2];

using res = typename mhn::identity<tp>::type;


static_assert(mhn::equal_types<res, tp>::type::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
