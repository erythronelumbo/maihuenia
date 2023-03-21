// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/split_sd.hpp>

#include "../eq_types.hpp"

#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 60)

namespace mhn = erythronelumbo::maihuenia;


using delims = mhn::string<'.', ',', ':', ';', '-'>;


template <typename SeqTag>
void test_split_sd()
{
  test_eq_types<
    typename mhn::split_sd<
      mhn::string<>,
      delims, SeqTag
    >::type,
    mhn::make_seq_t<SeqTag>
  >();

  test_eq_types<
    typename mhn::split_sd<
      STR_("."),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""),
      STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_("-"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""),
      STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(",."),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_(""), STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":-;"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_(""), STR_(""), STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_("-.--.;,,:,"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_(""), STR_(""), STR_(""), STR_(""), STR_(""), STR_(""),
      STR_(""), STR_(""), STR_(""), STR_("")
    >
  >();

  test_eq_types<
    typename mhn::split_sd<
      STR_("-a"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("a")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(";-a"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_(""), STR_("a")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":abc"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("abc")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(",:abc"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_(""), STR_("abc")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_("a."),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_("a"), STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_("a::"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_("a"), STR_(""), STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_("abc:,"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_("abc"), STR_(""), STR_("")
    >
  >();

  test_eq_types<
    typename mhn::split_sd<
      STR_("abc,def"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_("abc"), STR_("def")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":ab,cdef"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("ab"), STR_("cdef")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":abc:,cdef"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("abc"), STR_(""), STR_("cdef")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":abcd:,ef;"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("abcd"), STR_(""), STR_("ef"), STR_("")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(":abcd:,ef;"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("abcd"), STR_(""), STR_("ef"), STR_("")
    >
  >();

  test_eq_types<
    typename mhn::split_sd<
      STR_("abc,def;gh.ij-k"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_("abc"), STR_("def"), STR_("gh"), STR_("ij"), STR_("k")
    >
  >();
  test_eq_types<
    typename mhn::split_sd<
      STR_(";a,-,bc;--:;d.efghi,;-:jkl:.;m:n-o..-,;.;"),
      delims, SeqTag
    >::type,
    mhn::make_seq_t<
      SeqTag,
      STR_(""), STR_("a"), STR_(""), STR_(""), STR_("bc"), STR_(""), STR_(""),
      STR_(""), STR_(""), STR_("d"), STR_("efghi"), STR_(""), STR_(""),
      STR_(""), STR_("jkl"), STR_(""), STR_(""), STR_("m"), STR_("n"),
      STR_("o"), STR_(""), STR_(""), STR_(""), STR_(""), STR_(""), STR_(""),
      STR_("")
    >
  >();
}



int main()
{
  test_split_sd<mhn::vector_tag>();
  test_split_sd<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
