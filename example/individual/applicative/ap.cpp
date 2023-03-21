// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace mhn = erythronelumbo::maihuenia;

using incr_ = mhn::quote<mhn::incr>;

static_assert(
  mhn::equal_types_t<
    typename mhn::ap<mhn::some<incr_>, mhn::some<mhn::int_<1>>>::type,
    mhn::some<mhn::int_<2>>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename mhn::ap<mhn::some<incr_>, mhn::none>::type,
    mhn::none
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::ap_t<mhn::none, mhn::some<mhn::int_<1>>>,
    mhn::none
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::ap_t<mhn::none, mhn::none>,
    mhn::none
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
