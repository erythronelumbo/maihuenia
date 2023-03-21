// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>


namespace mhn = erythronelumbo::maihuenia;

using my_str_1 = mhn::string<'M', 'a', 'i', 'h', 'u', 'e', 'n', 'i', 'a'>;
using my_str_2 = ERYTHRONELUMBO_MAIHUENIA_STRING("Maihuenia");

using my_str_3 = mhn::string<'H', 'e', 'l', 'l', 'o'>;
using my_str_4 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("Hello", 5);
using my_str_5 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("Hello", 4);

static_assert(mhn::equal_types_t<my_str_1, my_str_2>::value, "!!!");
static_assert(mhn::equal_types_t<my_str_3, my_str_4>::value, "!!!");
static_assert(!mhn::equal_types_t<my_str_4, my_str_5>::value, "!!!");
static_assert(
  mhn::equal_types_t<
    my_str_5,
    ERYTHRONELUMBO_MAIHUENIA_STRING("Hell")
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
