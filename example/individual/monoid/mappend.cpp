// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res1 = mhn::mappend_t<
  mhn::long_<12>, mhn::long_<34>
>;
using res2 = mhn::mappend<
  mhn::string<'H', 'e', 'l'>, mhn::string<'l', 'o', '!'>
>;
using res3 = mhn::mappend<
  mhn::cons<char[2], mhn::cons<char[3]>>,
  mhn::cons<char[4], mhn::cons<char[5]>>
>;
using res4 = mhn::mappend<
  mhn::vector<int*, int**>, mhn::vector<int***, int****>
>;


static_assert(
  mhn::equal_types_t<
    res1, mhn::long_<46>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename res2::type, mhn::string<'H', 'e', 'l', 'l', 'o', '!'>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename res3::type,
    mhn::cons<
      char[2],
      mhn::cons<
        char[3],
        mhn::cons<
          char[4],
          mhn::cons<
            char[5]
          >
        >
      >
    >
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename res4::type, mhn::vector<int*, int**, int***, int****>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
