// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/split.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


template <typename InStr, typename Delims, typename... ExpectedElems>
constexpr void test_split()
{
  test_eq_types<
    typename mhn::split<InStr, Delims, mhn::linked_list_tag>::type,
    mhn::make_seq_t<mhn::linked_list_tag, ExpectedElems...>
  >();
  test_eq_types<
    typename mhn::split<InStr, Delims, mhn::vector_tag>::type,
    mhn::make_seq_t<mhn::vector_tag, ExpectedElems...>
  >();
}


int main()
{
  using delims = mhn::vector_c<char, '.', ',', ':', ';', '-'>;

  test_split<
    mhn::string<>,
    delims
  >();
  test_split<mhn::string<'.'>, delims>();
  test_split<mhn::string<';'>, delims>();
  test_split<mhn::string<','>, delims>();
  test_split<mhn::string<':'>, delims>();
  test_split<mhn::string<'-'>, delims>();
  test_split<
    STR_(";.:.;-:,::.;.-.::-;,:,:.:.-.,:..-"),
    delims
  >();

  test_split<
    STR_("abc"),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_("a"),
    delims,
    STR_("a")
  >();
  test_split<
    STR_(".abc"),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_("abc."),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_(":abc,"),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_(".--.,abc"),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_("abc-,.;."),
    delims,
    STR_("abc")
  >();
  test_split<
    STR_("::,;-,;abc-:,"),
    delims,
    STR_("abc")
  >();

  test_split<
    STR_("abc,def"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_("-abc,def"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_("abc:def,"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_("-abc.def-"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_("abc.def-,.:;-,.,..,:-;:"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_("abc.-,.:;-,.def,..,:-;:"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_(".-,.abc:def;-,.,..,:-;:"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_(".-,.:;abc-,.,..def,:-;:"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_(".-,.:;-,.,..abc,:-;:def"),
    delims,
    STR_("abc"), STR_("def")
  >();
  test_split<
    STR_(".-,.:;-,.,..,:-;abc:def"),
    delims,
    STR_("abc"), STR_("def")
  >();

  test_split<
    STR_("abc,de.fgh"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("-abc-de:fgh;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("abc.de;fgh."),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("abc:de:fgh,.;.;.:-;.:.;-:,::.;.-.::-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("abc::,.de;fgh.;.:-;.:.;-:,::.;.-.::-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("abc::,.;.;de.:-;.:.;-:,::fgh.;.-.::-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;.;.:-;abc.de:fgh.;-:,::.;.-.::-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;.;.:abc-de;.:.;-:,::.;.-.::-fgh;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;.;abc.:-;.:.;de-:,::.;.-.:fgh:-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;.;.:-;.:.;-:abc,::.;.-.:de:fgh-;,"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;abc.de;.:-;.:.;-:,::.;.-.::-;,fgh"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;abc.;.:-;.:.de;-:,::.;.-.::-;,fgh"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("::,.;.;.:-;.:.;-:,::.;.-.::-abc;de,fgh"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh")
  >();
  test_split<
    STR_("abc:de,fgh;i;,,.:..-,.:;-,.,..,:-;:,;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh"), STR_("i")
  >();
  test_split<
    STR_("abc:de,fgh;;,,.:..i-,.:;-,.,..,:-;:,;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh"), STR_("i")
  >();
  test_split<
    STR_("abc:de,;;,,.:fgh..-,.:;-,.,..,:-i;:,;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh"), STR_("i")
  >();
  test_split<
    STR_("abc:,;;,,de.:..-,.:;fgh-,.,..,i:-;:,;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh"), STR_("i")
  >();
  test_split<
    STR_(":,;;,,abc.def:..-,.:gh;-,.,..,i:-;:,;"),
    delims,
    STR_("abc"), STR_("def"), STR_("gh"), STR_("i")
  >();
  test_split<
    STR_(":,;;abc,,.:..defg-h,.:;-,.,..,:-;:,ii;"),
    delims,
    STR_("abc"), STR_("defg"), STR_("h"), STR_("ii")
  >();
  test_split<
    STR_(":,;abc;,,.:.de.-,.:;-,.,.fgh.i,:-;:,;"),
    delims,
    STR_("abc"), STR_("de"), STR_("fgh"), STR_("i")
  >();
  test_split<
    STR_(":,;;,,.abc:d..-,.:;-,.efgh,i..,:-;:,;"),
    delims,
    STR_("abc"), STR_("d"), STR_("efgh"), STR_("i")
  >();
  test_split<
    STR_(":,;;,,.:..-,.:;-,abc.,..defg,:-;:fgh,;i"),
    delims,
    STR_("abc"), STR_("defg"), STR_("fgh"), STR_("i")
  >();

  return EXIT_SUCCESS;
}
