// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/arg.hpp>


namespace mhn = erythronelumbo::maihuenia;

using t0 = typename mhn::arg<0>::template apply<char, double, void, bool>::type;
using t1 = typename mhn::arg<1>::template apply<char, double, void, bool>::type;
using t2 = typename mhn::arg<2>::template apply<char, double, void, bool>::type;
using t3 = typename mhn::arg<3>::template apply<char, double, void, bool>::type;

static_assert(mhn::equal_types_t<t0, char>::value, "!!!");
static_assert(mhn::equal_types_t<t1, double>::value, "!!!");
static_assert(mhn::equal_types_t<t2, void>::value, "!!!");
static_assert(mhn::equal_types_t<t3, bool>::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
