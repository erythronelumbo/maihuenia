// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/size_of.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/scan_left.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using input_types = mhn::vector<
  std::uint32_t,
  std::uint32_t,
  std::int8_t[20],
  std::int16_t, std::int16_t, std::int16_t
>;

using offsets = typename mhn::scan_left_initial<
  mhn::lambda<mhn::add<_1, mhn::size_of<_2>>>,
  input_types,
  mhn::size_c<0>,
  mhn::vector_tag
>::type;

static_assert(
  mhn::equals_t<
    offsets,
    mhn::vector_c<std::size_t, 0, 4, 8, 28, 30, 32, 34>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
