// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>


namespace mhn = erythronelumbo::maihuenia;


struct tp1 { char v[2]; };

static_assert(mhn::equal_types<tp1, tp1>::type::value, "!!!");
static_assert(mhn::equal_types<tp1, tp1, tp1>::type::value, "!!!");
static_assert(!mhn::equal_types<long, char, tp1>::type::value, "!!!");
static_assert(!mhn::equal_types<char, float>::type::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
