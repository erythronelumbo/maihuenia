// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/zip.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 20)

namespace mhn = erythronelumbo::maihuenia;

using animals = mhn::make_seq<
  mhn::linked_list_tag,
  STR_("fox"),
  STR_("wolf"),
  STR_("cat"),
  STR_("dog"),
  STR_("skunk"),
  STR_("tiger"),
  STR_("ignored")
>;

using are_domestic = mhn::make_seq<
  mhn::vector_tag,
  mhn::false_,
  mhn::false_,
  mhn::true_,
  mhn::true_,
  mhn::false_,
  mhn::false_
>;

using zipped = typename mhn::zip<
  mhn::vector_tag,
  mhn::range_c<char, 'a', 6>,
  typename animals::type,
  typename are_domestic::type
>::type;

static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 0>,
    mhn::vector<mhn::char_<'a'>, STR_("fox"), mhn::false_>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 1>,
    mhn::vector<mhn::char_<'b'>, STR_("wolf"), mhn::false_>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 2>,
    mhn::vector<mhn::char_<'c'>, STR_("cat"), mhn::true_>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 3>,
    mhn::vector<mhn::char_<'d'>, STR_("dog"), mhn::true_>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 4>,
    mhn::vector<mhn::char_<'e'>, STR_("skunk"), mhn::false_>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<zipped, 5>,
    mhn::vector<mhn::char_<'f'>, STR_("tiger"), mhn::false_>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
