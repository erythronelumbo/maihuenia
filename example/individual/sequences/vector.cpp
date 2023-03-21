// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using vec1 = mhn::vector<long>;
using vec2 = mhn::push_front_t<vec1, bool>;
using vec3 = mhn::push_back_t<vec2, void>;
using vec4 = mhn::concat_t<mhn::vector<mhn::int_<1>, mhn::int_<2>>, vec3>;

static_assert(
  mhn::equal_types_t<
    vec4,
    mhn::vector<mhn::int_<1>, mhn::int_<2>, bool, long, void>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<mhn::at_c_t<vec4, 2>, bool>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
