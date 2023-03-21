// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/filled_view.hpp>


namespace mhn = erythronelumbo::maihuenia;

using fv1 = mhn::filled_view<void*, mhn::size_c<5>>;
using fv2 = mhn::filled_view_c<float, 3>;

static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<fv1, 0>,
    mhn::at_c_t<fv1, 1>,
    mhn::at_c_t<fv1, 2>,
    mhn::at_c_t<fv1, 3>,
    mhn::at_c_t<fv1, 4>,
    void*
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::front_t<fv2>, float
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::pop_front_t<fv2>, mhn::filled_view_c<float, 2>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
