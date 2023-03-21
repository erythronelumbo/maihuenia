// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/zipped_view.hpp>
#include <erythronelumbo/maihuenia/for_each.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 20)

namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::range_c<unsigned, 1, 20>;

using roman_nums = mhn::vector<
  STR_("I"), STR_("II"), STR_("III"), STR_("IV"), STR_("V"), STR_("VI"),
  STR_("VII"), STR_("VIII"), STR_("IX"), STR_("X"), STR_("XI"), STR_("XII"),
  STR_("XIII"), STR_("XIV"), STR_("XV"), STR_("XVI"), STR_("XVII"),
  STR_("XVIII"), STR_("XIX"), STR_("XX")
>;

using english_num_names = mhn::vector<
  STR_("one"), STR_("two"), STR_("three"), STR_("four"), STR_("five"),
  STR_("six"), STR_("seven"), STR_("eight"), STR_("nine"), STR_("ten"),
  STR_("eleven"), STR_("twelve"), STR_("thirteen"), STR_("fourteen"),
  STR_("fifteen"), STR_("sixteen"), STR_("seventeen"), STR_("eighteen"),
  STR_("nineteen"), STR_("twenty")
>;

using table = mhn::zipped_view<nums, roman_nums, english_num_names>;

#define CHECK_ELEMS(num, rn, enn) \
static_assert( \
  mhn::equal_types_t< \
    mhn::at_c_t<table, (num - 1)>, \
    mhn::vector<mhn::uint_<num>, STR_(rn), STR_(enn)> \
  >::value, \
  "!!!" \
)

CHECK_ELEMS(1, "I", "one");
CHECK_ELEMS(2, "II", "two");
CHECK_ELEMS(3, "III", "three");
CHECK_ELEMS(4, "IV", "four");
CHECK_ELEMS(5, "V", "five");


struct printer
{
  template <typename X>
  inline void operator()(X)
  {
    std::puts(
      mhn::c_str<
        mhn::concat_t<
          STR_("Number: "), mhn::to_string_t<mhn::at_c_t<X, 0>>,
          STR_("; Roman: "), mhn::at_c_t<X, 1>,
          STR_("; English name: "), mhn::at_c_t<X, 2>
        >
      >::value
    );
  }
};


int main()
{
  mhn::for_each<table>(printer{});

  return EXIT_SUCCESS;
}
