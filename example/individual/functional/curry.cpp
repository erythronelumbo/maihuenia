// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders; // _1, _2, ...

// (a+1)*(b-1)/c
using uncurried = mhn::lambda<
  mhn::quot<
    mhn::mul<
      mhn::add<_1, mhn::ratio_c<int, 1, 1>>,
      mhn::sub<_2, mhn::ratio_c<int, 1, 1>>
    >,
    _3
  >
>;

using curried = mhn::curry<uncurried, 3>;

using called_a1 = typename curried::template apply<
  mhn::ratio_c<int, -5, 4>
>;

using called_a2 = typename called_a1::template apply<
  mhn::ratio_c<int, 21, 34>,
  mhn::ratio_c<int, 3, 4>
>;

static_assert(
  mhn::equals<
    typename called_a2::type,
    mhn::ratio_c<int, 52, 408>
  >::type::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
