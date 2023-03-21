// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>


namespace mhn = erythronelumbo::maihuenia;

using curried_add = mhn::curry_quote<mhn::add, 5>;

using call_1 = typename curried_add::template apply<mhn::int_<31>>;
using call_2 = typename call_1::template apply<mhn::int_<14>, mhn::int_<62>>;
using call_3 = typename call_2::template apply<>;
using call_4 = typename call_3::template apply<mhn::int_<183>>;
using call_5 = typename call_4::template apply<mhn::int_<70>>;


static_assert(
  mhn::equals_t<
    typename call_5::type, mhn::int_<31 + 14 + 62 + 183 + 70>
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
