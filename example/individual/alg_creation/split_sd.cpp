// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/split_sd.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 24)

namespace mhn = erythronelumbo::maihuenia;

using delims = STR_(".,:;");

using str1 = STR_("abc,def;ghi");
using str2 = STR_(",,abc,;def,;:ghi,.jkl,,");
using str3 = STR_(",abc.def.ghi,");

using res1 = mhn::split_sd<str1, delims, mhn::linked_list_tag>;
using res2 = mhn::split_sd<str2, delims, mhn::linked_list_tag>;
using res3 = mhn::split_sd<str3, delims, mhn::linked_list_tag>;

static_assert(
  mhn::equal_types_t<
    typename res1::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      STR_("abc"), STR_("def"), STR_("ghi")
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename res2::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      STR_(""), STR_(""), STR_("abc"), STR_(""), STR_("def"), STR_(""),
      STR_(""), STR_("ghi"), STR_(""), STR_("jkl"), STR_(""), STR_("")
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename res3::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      STR_(""), STR_("abc"), STR_("def"), STR_("ghi"), STR_("")
    >
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
