// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;


using type1 = char;
using type2 = long;

using res1 = mhn::if_t<mhn::true_, type1, type2>;
using res2 = mhn::if_c_t<false, type1, type2>;

static_assert(mhn::equal_types<res1, type1>::type::value, "!!!");
static_assert(mhn::equal_types<res2, type2>::type::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
