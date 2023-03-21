// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>
#include <erythronelumbo/maihuenia/for_each.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 10)

namespace mhn = erythronelumbo::maihuenia;

using strings = mhn::make_seq_t<
  mhn::linked_list_tag,
  STR_("zero"),
  STR_("one"),
  STR_("two"),
  STR_("three"),
  STR_("four"),
  STR_("five"),
  STR_("six"),
  STR_("seven"),
  STR_("eight"),
  STR_("nine"),
  STR_("ten")
>;

struct print_string_with_length
{
  template <typename T>
  void operator()(T)
  {
    std::printf(
      "String: \"%s\", length: %llu\n",
      mhn::c_str<T>::value,
      mhn::size<T>::type::value
    );
  }
};


int main()
{
  mhn::for_each<strings>(print_string_with_length{});
}
