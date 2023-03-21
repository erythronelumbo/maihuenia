// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/drop_until.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using str = ERYTHRONELUMBO_MAIHUENIA_STRING("...and they\'re gone.");

using res = mhn::drop_until<
  str,
  mhn::bind<mhn::quote<mhn::not_equals>, _1, mhn::char_<'.'>>
>;

static_assert(
  mhn::equal_types_t<
    ERYTHRONELUMBO_MAIHUENIA_STRING("and they\'re gone."),
    typename res::type
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
