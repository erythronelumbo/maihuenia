// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;


template <typename A, typename B>
using safe_div = mhn::eval_if<
  mhn::equals_t<B, mhn::int_<0>>,
  mhn::undefined,
  mhn::div<A, B>
>;

using res1 = typename safe_div<mhn::int_<12>, mhn::int_<4>>::type;
using res2 = typename safe_div<mhn::int_<13>, mhn::int_<0>>::type;

static_assert(mhn::equals<res1, mhn::int_<3>>::type::value, "!!!");
static_assert(mhn::equals<res2, mhn::undefined>::type::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
