// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;


using seq1 = mhn::vector<int, long*, char[4][3]>;
using seq2 = mhn::cons<int, mhn::cons<long*, mhn::cons<char[4][3]>>>;
using seq3 = mhn::vector_c<unsigned short, 0, 1, 1, 2, 3, 5, 8, 13, 21>;
using seq4 = mhn::null_type;


static_assert(
  mhn::equal_types<
    typename mhn::tag<seq1>::type,
    typename mhn::tag<seq3>::type
  >::type::value,
  "!!!"
);

static_assert(
  mhn::equal_types<
    typename seq2::tag, mhn::tag_t<seq2>
  >::type::value,
  "!!!"
);

static_assert(
  mhn::equal_types<
    mhn::tag_t<seq2>, mhn::tag_t<seq4>
  >::type::value,
  "!!!"
);

static_assert(
  !mhn::equal_types<mhn::tag_t<seq1>, mhn::tag_t<seq4>>::type::value,
  "!!!"
);

static_assert(
  !mhn::equal_types<mhn::tag_t<seq3>, mhn::tag_t<seq2>>::type::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
