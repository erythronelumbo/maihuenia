// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using elems = mhn::vector_c<int, 1, 2, 6, 24, 120>;
using empty_vec = mhn::vector_c<int>;

static_assert(
  mhn::equal_types_t<
    typename mhn::at<elems, mhn::size_c<0>>::type,
    mhn::int_<1>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename mhn::at_c<elems, 1>::type,
    mhn::int_<2>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_t<elems, mhn::size_c<2>>,
    mhn::int_<6>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<elems, 3>,
    mhn::int_<24>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename mhn::at<elems, mhn::size_c<4>>::type,
    mhn::int_<120>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename mhn::at<empty_vec, mhn::size_c<0>>::type,
    mhn::index_out_of_range
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
