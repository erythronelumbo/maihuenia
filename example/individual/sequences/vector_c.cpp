// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using vec1 = mhn::vector_c<unsigned short, 0, 1, 3, 6, 10, 15, 21, 28, 36>;
using vec2 = mhn::vector_c<unsigned short, 0, 1, 1, 2, 3, 5, 8, 13, 21>;

using vec3 = mhn::concat<mhn::drop_c_t<vec2, 7>, mhn::drop_c_t<vec1, 7>>;

using vec4 = mhn::insert_c<typename vec3::type, 2, mhn::ushort_<0>>;

static_assert(
  mhn::equals_t<
    typename vec4::type,
    mhn::vector<
      mhn::ushort_<13>,
      mhn::ushort_<21>,
      mhn::ushort_< 0>,
      mhn::ushort_<28>,
      mhn::ushort_<36>
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
