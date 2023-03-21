// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/compose.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders; // _1, _2, ...


using cfn = mhn::compose<
  mhn::quote<mhn::incr>,
  mhn::bind<mhn::quote<mhn::mul>, _1, mhn::uint_<3>>,
  mhn::bind<
    mhn::quote<mhn::at>,
    mhn::vector<void, void*, void**, void****, int[3], int[6], int[9]>,
    _1
  >
>;


static_assert(
  mhn::equal_types_t<
    typename cfn::template apply<mhn::uint_<1>>::type,
    int[9]
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
