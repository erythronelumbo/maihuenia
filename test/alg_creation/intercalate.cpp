// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/intercalate.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;



template <typename SeqTag>
void test_intercalate()
{
  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag>,
      STR_("")
    >::type,
    mhn::undefined
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("")>,
      STR_("")
    >::type,
    STR_("")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("a")>,
      STR_("")
    >::type,
    STR_("a")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab")>,
      STR_("")
    >::type,
    STR_("ab")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("c")>,
      STR_("")
    >::type,
    STR_("abc")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cd")>,
      STR_("")
    >::type,
    STR_("abcd")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cd"), STR_("efg")>,
      STR_("")
    >::type,
    STR_("abcdefg")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_(""), STR_("cd"), STR_("efg")>,
      STR_("")
    >::type,
    STR_("cdefg")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cd"), STR_("")>,
      STR_("")
    >::type,
    STR_("abcd")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_(""), STR_("cd"), STR_("")>,
      STR_("")
    >::type,
    STR_("cd")
  >();


  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag>,
      STR_("-")
    >::type,
    mhn::undefined
  >();
  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("")>,
      STR_("-")
    >::type,
    STR_("")
  >();
  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_(""), STR_("")>,
      STR_("-")
    >::type,
    STR_("-")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab")>,
      STR_("-")
    >::type,
    STR_("ab")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde")>,
      STR_("-")
    >::type,
    STR_("ab-cde")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde"), STR_("fghi")>,
      STR_("-")
    >::type,
    STR_("ab-cde-fghi")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde"), STR_("fghi"), STR_("j")>,
      STR_("-")
    >::type,
    STR_("ab-cde-fghi-j")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_(""), STR_("cde"), STR_("fghi"), STR_("j")>,
      STR_("-")
    >::type,
    STR_("-cde-fghi-j")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde"), STR_("fghi"), STR_("")>,
      STR_("-")
    >::type,
    STR_("ab-cde-fghi-")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde"), STR_(""), STR_("j")>,
      STR_("-")
    >::type,
    STR_("ab-cde--j")
  >();


  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_("ab"), STR_("cde"), STR_("fghi"), STR_("j")>,
      STR_("XYZ")
    >::type,
    STR_("abXYZcdeXYZfghiXYZj")
  >();

  test_eq_types<
    typename mhn::intercalate<
      mhn::make_seq_t<SeqTag, STR_(""), STR_("cde"), STR_("fghi"), STR_("")>,
      STR_("XYZ")
    >::type,
    STR_("XYZcdeXYZfghiXYZ")
  >();
}


int main()
{
  test_intercalate<mhn::vector_tag>();
  test_intercalate<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
