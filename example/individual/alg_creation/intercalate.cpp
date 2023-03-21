// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/intercalate.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>


#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;

using things = mhn::cons<
  STR_("apples"),
  mhn::cons<
    STR_("oranges"),
    mhn::cons<
      STR_("pears"),
      mhn::cons<
        STR_("bananas"),
        mhn::cons<
          STR_("grapes")
        >
      >
    >
  >
>;

using sep = STR_(" and ");

using res = mhn::intercalate<things, sep>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    STR_("apples and oranges and pears and bananas and grapes")
  >::value,
  "!!!"
);


int main()
{
  std::printf("Result: %s\n", mhn::c_str<typename res::type>::value);
}
