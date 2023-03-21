// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>


namespace mhn = erythronelumbo::maihuenia;

template <typename SeqTag>
using mkseq1 = typename mhn::make_seq<SeqTag, char[2], char[4], char[6]>::type;

template <typename SeqTag>
using mkseq2 = mhn::make_seq_t<SeqTag>;

static_assert(
  mhn::equal_types_t<
    mkseq1<mhn::vector_tag>,
    mhn::vector<char[2], char[4], char[6]>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mkseq1<mhn::linked_list_tag>,
    mhn::cons<char[2], mhn::cons<char[4], mhn::cons<char[6]>>>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    mhn::make_seq_t<
      mhn::string_tag,
      mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>
    >,
    mhn::string<'a', 'b', 'c'>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<mkseq2<mhn::vector_tag>, mhn::vector<>>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<mkseq2<mhn::linked_list_tag>, mhn::null_type>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename mhn::make_seq<mhn::string_tag>::type,
    mhn::string<>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
