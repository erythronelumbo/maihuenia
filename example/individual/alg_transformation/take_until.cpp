// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/take_until.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using nums = mhn::vector_c<
  std::int32_t,
  103, 127, 165, 175, 255, 94, 2, 76, 247, 152, 144, 191, 254, 84, 31, -1, 49,
  138, 98, 44, 191, 98, 25, 17, 141, 130, 0, 243, 206, 19, 219, 223
>;

using res = mhn::take_until<
  nums,
  mhn::bind<mhn::quote<mhn::less_equal>, _1, mhn::i32_c<100>>
>;

static_assert(
  mhn::equals_t<
    mhn::vector_c<std::int32_t, 103, 127, 165, 175, 255>,
    typename res::type
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
