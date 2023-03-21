// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;


template <typename Placeholder>
using pick_ = mhn::apply_wrap_t<
  Placeholder, double[2], long[3], short[4], bool[4][4], int, void***
>;

using t0 = pick_<_1>;
using t1 = pick_<_2>;
using t2 = pick_<_3>;
using t3 = pick_<_4>;
using t4 = pick_<_5>;
using t5 = pick_<_6>;

static_assert(mhn::equal_types_t<t0, double[2]>::value, "!!!");
static_assert(mhn::equal_types_t<t1, long[3]>::value, "!!!");
static_assert(mhn::equal_types_t<t2, short[4]>::value, "!!!");
static_assert(mhn::equal_types_t<t3, bool[4][4]>::value, "!!!");
static_assert(mhn::equal_types_t<t4, int>::value, "!!!");
static_assert(mhn::equal_types_t<t5, void***>::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
