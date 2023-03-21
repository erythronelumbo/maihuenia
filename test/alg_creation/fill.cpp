// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/fill.hpp>

#include "../eq_types.hpp"

#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


template <typename IntType, IntType InputValue, IntType... Values>
struct int_seq_fill_test
{
  template <typename SeqTag>
  static constexpr void call()
  {
    using expected = mhn::make_seq_t<
      SeqTag,
      mhn::integer_c<IntType, Values>...
    >;

    using res_a = typename mhn::fill<
      SeqTag,
      mhn::integer_c<IntType, InputValue>,
      mhn::size_c<(sizeof...(Values))>
    >::type;
    using res_b = typename mhn::fill_c<
      SeqTag,
      mhn::integer_c<IntType, InputValue>,
      sizeof...(Values)
    >::type;

    test_eq_types<res_a, res_b>();
    test_eq_types<res_a, expected>();
    test_eq_types<res_b, expected>();
  }
};


int main()
{
  using isq_fill_test_1 = int_seq_fill_test<
    int, 1
  >;
  isq_fill_test_1::template call<mhn::vector_tag>();
  isq_fill_test_1::template call<mhn::linked_list_tag>();

  using isq_fill_test_2 = int_seq_fill_test<
    int, 2,
    2
  >;
  isq_fill_test_2::template call<mhn::vector_tag>();
  isq_fill_test_2::template call<mhn::linked_list_tag>();

  using isq_fill_test_3 = int_seq_fill_test<
    int, -3,
    -3, -3
  >;
  isq_fill_test_3::template call<mhn::vector_tag>();
  isq_fill_test_3::template call<mhn::linked_list_tag>();

  using isq_fill_test_4 = int_seq_fill_test<
    unsigned, 123,
    123, 123, 123, 123, 123
  >;
  isq_fill_test_4::template call<mhn::vector_tag>();
  isq_fill_test_4::template call<mhn::linked_list_tag>();

  using isq_fill_test_5 = int_seq_fill_test<
    unsigned, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680,
    24680, 24680, 24680, 24680, 24680
  >;
  isq_fill_test_5::template call<mhn::vector_tag>();
  isq_fill_test_5::template call<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
