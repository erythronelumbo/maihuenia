// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/iota.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


template <
  std::size_t N, std::ptrdiff_t Step,
  typename IntType, IntType Start, IntType... Values
>
struct int_seq_iota_test
{
  template <typename SeqTag>
  static constexpr void call()
  {
    using expected = mhn::make_seq_t<
      SeqTag,
      mhn::integer_c<IntType, Values>...
    >;

    using res_a = typename mhn::iota<
      SeqTag,
      IntType,
      mhn::integer_c<IntType, Start>,
      mhn::size_c<(sizeof...(Values))>,
      mhn::ptrdiff_c<Step>
    >::type;
    using res_b = typename mhn::iota_c<
      SeqTag,
      IntType,
      Start,
      sizeof...(Values),
      Step
    >::type;

    test_eq_types<res_a, res_b>();
    test_eq_types<res_a, expected>();
    test_eq_types<res_b, expected>();
  }
};


int main()
{
  using iota_test_1 = int_seq_iota_test<
    0, 1,
    int, 0
  >;
  using iota_test_2 = int_seq_iota_test<
    1, 1,
    int, 0,
    0
  >;
  using iota_test_3 = int_seq_iota_test<
    2, 1,
    int, 0,
    0, 1
  >;
  using iota_test_4 = int_seq_iota_test<
    5, 1,
    int, 0,
    0, 1, 2, 3, 4
  >;
  using iota_test_5 = int_seq_iota_test<
    21, -1,
    int, 10,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10
  >;
  using iota_test_6 = int_seq_iota_test<
    10, 7,
    unsigned, 2,
    2, 9, 16, 23, 30, 37, 44, 51, 58, 65
  >;
  using iota_test_7 = int_seq_iota_test<
    10, 1,
    char, 'a',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'
  >;
  using iota_test_8 = int_seq_iota_test<
    9, -3,
    char, 'z',
    'z', 'w', 't', 'q', 'n', 'k', 'h', 'e', 'b'
  >;

  iota_test_1::template call<mhn::linked_list_tag>();
  iota_test_1::template call<mhn::vector_tag>();

  iota_test_2::template call<mhn::linked_list_tag>();
  iota_test_2::template call<mhn::vector_tag>();

  iota_test_3::template call<mhn::linked_list_tag>();
  iota_test_3::template call<mhn::vector_tag>();

  iota_test_4::template call<mhn::linked_list_tag>();
  iota_test_4::template call<mhn::vector_tag>();

  iota_test_5::template call<mhn::linked_list_tag>();
  iota_test_5::template call<mhn::vector_tag>();

  iota_test_6::template call<mhn::linked_list_tag>();
  iota_test_6::template call<mhn::vector_tag>();

  iota_test_7::template call<mhn::linked_list_tag>();
  iota_test_7::template call<mhn::vector_tag>();
  iota_test_7::template call<mhn::string_tag>();

  iota_test_8::template call<mhn::linked_list_tag>();
  iota_test_8::template call<mhn::vector_tag>();
  iota_test_8::template call<mhn::string_tag>();

  return EXIT_SUCCESS;
}
