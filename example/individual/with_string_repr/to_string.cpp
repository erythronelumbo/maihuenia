// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 10)

namespace mhn = erythronelumbo::maihuenia;

using res1 = typename mhn::to_string<mhn::int_<-14337>>::type;
using res2 = typename mhn::to_string<mhn::ratio_c<unsigned, 39, 60>>::type;
using res3 = typename mhn::to_string<mhn::string<'a', 'b', 'c', 'd'>>::type;

static_assert(mhn::equal_types_t<res1, STR_("-14337")>::value, "!!!");
static_assert(mhn::equal_types_t<res2, STR_("13/20")>::value, "!!!");
static_assert(mhn::equal_types_t<res3, STR_("abcd")>::value, "!!!");


int main()
{
  std::printf(
    "Generated strings:\n"
    "(1) \"%s\"\n"
    "(2) \"%s\"\n"
    "(3) \"%s\"\n",
    mhn::c_str<res1>::value,
    mhn::c_str<res2>::value,
    mhn::c_str<res3>::value
  );
}
