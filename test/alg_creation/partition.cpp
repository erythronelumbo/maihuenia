// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/partition.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


struct a0 {};
struct a1 {};
struct a2 {};
struct a3 {};
struct a4 {};
struct a5 {};
struct a6 {};
struct a7 {};
struct a8 {};
struct a9 {};

using b0 = mhn::char_<'A'>;
using b1 = mhn::char_<'E'>;
using b2 = mhn::char_<'I'>;
using b3 = mhn::char_<'O'>;
using b4 = mhn::char_<'U'>;
using b5 = mhn::char_<'a'>;
using b6 = mhn::char_<'e'>;
using b7 = mhn::char_<'i'>;
using b8 = mhn::char_<'o'>;
using b9 = mhn::char_<'u'>;

template <typename T> struct pick_axs_helper : mhn::false_ {};

template <> struct pick_axs_helper<a1> : mhn::true_ {};
template <> struct pick_axs_helper<a3> : mhn::true_ {};
template <> struct pick_axs_helper<a4> : mhn::true_ {};
template <> struct pick_axs_helper<a8> : mhn::true_ {};

struct pick_axs
{
  template <typename X>
  using apply = pick_axs_helper<X>;
};

template <typename T> struct pick_bxs_helper : mhn::false_ {};

template <> struct pick_bxs_helper<b0> : mhn::true_ {};
template <> struct pick_bxs_helper<b2> : mhn::true_ {};
template <> struct pick_bxs_helper<b4> : mhn::true_ {};
template <> struct pick_bxs_helper<b5> : mhn::true_ {};
template <> struct pick_bxs_helper<b9> : mhn::true_ {};

struct pick_bxs
{
  template <typename X>
  using apply = pick_bxs_helper<X>;
};


template <typename SeqTag>
void test_partition_typeseq()
{
  using sq1 = mhn::make_seq_t<
    SeqTag,
    a0, a1, a2, a3, a4, a5, a6, a7, a8, a9
  >;
  using sq2 = mhn::make_seq_t<SeqTag, a0>;
  using sq3 = mhn::make_seq_t<SeqTag, a1>;
  using sq4 = mhn::make_seq_t<SeqTag, a7, a4>;
  using sq5 = mhn::make_seq_t<SeqTag>;
  using sq6 = mhn::make_seq_t<SeqTag, a2, a8, a5, a7, a0>;
  using sq7 = mhn::make_seq_t<SeqTag, a8, a3, a1, a9, a3>;

  test_eq_types<
    typename mhn::partition<sq1, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, a1, a3, a4, a8>,
      mhn::make_seq_t<SeqTag, a0, a2, a5, a6, a7, a9>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq2, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag>,
      mhn::make_seq_t<SeqTag, a0>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq3, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, a1>,
      mhn::make_seq_t<SeqTag>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq4, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, a4>,
      mhn::make_seq_t<SeqTag, a7>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq5, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag>,
      mhn::make_seq_t<SeqTag>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq6, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, a8>,
      mhn::make_seq_t<SeqTag, a2, a5, a7, a0>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq7, pick_axs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, a8, a3, a1, a3>,
      mhn::make_seq_t<SeqTag, a9>
    >
  >();
}


template <typename SeqTag>
void test_partition_intseq()
{
  using sq1 = mhn::make_seq_t<
    SeqTag,
    b0, b1, b2, b3, b4, b5, b6, b7, b8, b9
  >;
  using sq2 = mhn::make_seq_t<SeqTag, b0>;
  using sq3 = mhn::make_seq_t<SeqTag, b1>;
  using sq4 = mhn::make_seq_t<SeqTag, b9, b3>;

  test_eq_types<
    typename mhn::partition<sq1, pick_bxs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, b0, b2, b4, b5, b9>,
      mhn::make_seq_t<SeqTag, b1, b3, b6, b7, b8>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq2, pick_bxs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, b0>,
      mhn::make_seq_t<SeqTag>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq3, pick_bxs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag>,
      mhn::make_seq_t<SeqTag, b1>
    >
  >();
  test_eq_types<
    typename mhn::partition<sq4, pick_bxs, SeqTag>::type,
    mhn::pair<
      mhn::make_seq_t<SeqTag, b9>,
      mhn::make_seq_t<SeqTag, b3>
    >
  >();
}


int main()
{
  test_partition_typeseq<mhn::linked_list_tag>();
  test_partition_typeseq<mhn::vector_tag>();

  test_partition_intseq<mhn::linked_list_tag>();
  test_partition_intseq<mhn::vector_tag>();
  test_partition_intseq<mhn::string_tag>();

  return EXIT_SUCCESS;
}
