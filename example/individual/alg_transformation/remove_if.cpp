// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/remove_if.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using input_vec = mhn::vector_c<
  int,
  23, 29, 1, 30, 17, 0, 24, 20, 16, 29, 6, 14, 29, 14, 2, 11, 22, 26, 0, -6, 5,
  3, 29, 27, 28, 20, 30, 27, 12, 5, -6, 27, 1, 7, 18, -5, 19, 10, -4, 8
>;

using res = typename mhn::remove_if<
  input_vec,
  mhn::lambda<
    /* x < 0 || x > 20 */
    mhn::logical_or<
      mhn::greater<_1, mhn::int_<20>>,
      mhn::less<_1, mhn::int_<0>>
    >
  >
>::type;

static_assert(
  mhn::equals_t<
    res,
    mhn::vector_c<
      int,
      1, 17, 0, 20, 16, 6, 14, 14, 2, 11, 0, 5, 3, 20, 12, 5, 1, 7, 18, 19, 10,
      8
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
