// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/replace_if.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 40)

namespace mhn = erythronelumbo::maihuenia;

using input_str = STR_("The five boxing wizards jump quickly");

using res = mhn::replace<input_str, mhn::char_<' '>, mhn::char_<'-'>>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    STR_("The-five-boxing-wizards-jump-quickly")
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
