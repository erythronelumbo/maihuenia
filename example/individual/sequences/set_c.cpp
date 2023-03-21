// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/set.hpp>


namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::set_c<int, 2, 3, 5, 7, 11, 13, 17, 19>;

using nums1 = mhn::ainsert<mhn::ainsert_t<nums, mhn::int_<1>>, mhn::int_<20>>;

using nums2 = mhn::aerase_t<
  typename nums1::type,
  mhn::int_<2>
>;

static_assert(
  mhn::equal_types_t<
    nums2, mhn::set_c<int, 3, 5, 7, 11, 13, 17, 19, 1, 20>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
