// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/iota.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/zip_with.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;


using seqs = mhn::zip_with_t<
  mhn::lambda<mhn::iota<mhn::vector_tag, int, _1, _2, mhn::int_<1>>>,
  mhn::linked_list_tag,
  mhn::vector_c<int, 0, 1, 3, 6>,
  mhn::range_c<int, 1, 4>
>;

static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<seqs, 0>,
    mhn::vector<mhn::int_<0>>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<seqs, 1>,
    mhn::vector<mhn::int_<1>, mhn::int_<2>>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<seqs, 2>,
    mhn::vector<mhn::int_<3>, mhn::int_<4>, mhn::int_<5>>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<seqs, 3>,
    mhn::vector<mhn::int_<6>, mhn::int_<7>, mhn::int_<8>, mhn::int_<9>>
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
