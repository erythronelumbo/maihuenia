// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/scan_left.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;

template <typename A, typename B>
struct fn { using type = fn; };

struct fn_q { template <typename A, typename B> using apply = fn<A, B>; };

struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};
struct x5 {};
struct x6 {};
struct x7 {};
struct x8 {};
struct x9 {};

template <typename SeqTagI, typename SeqTagO>
void test_scan_left_initial_tls()
{
  using tl1 = mhn::make_seq_t<SeqTagI>;
  using tl2 = mhn::make_seq_t<SeqTagI, x0>;
  using tl3 = mhn::make_seq_t<SeqTagI, x0, x1>;
  using tl4 = mhn::make_seq_t<SeqTagI, x0, x1, x2>;
  using tl5 = mhn::make_seq_t<SeqTagI, x0, x1, x2, x3, x4, x5>;


  test_eq_types<
    typename mhn::scan_left_initial<fn_q, tl1, void, SeqTagO>::type,
    mhn::make_seq_t<
      SeqTagO,
      void
    >
  >();

  test_eq_types<
    typename mhn::scan_left_initial<fn_q, tl2, void, SeqTagO>::type,
    mhn::make_seq_t<
      SeqTagO,
      void,
      fn<void, x0>
    >
  >();

  test_eq_types<
    typename mhn::scan_left_initial<fn_q, tl3, void, SeqTagO>::type,
    mhn::make_seq_t<
      SeqTagO,
      void,
      fn<void, x0>,
      fn<fn<void, x0>, x1>
    >
  >();

  test_eq_types<
    typename mhn::scan_left_initial<fn_q, tl4, void, SeqTagO>::type,
    mhn::make_seq_t<
      SeqTagO,
      void,
      fn<void, x0>,
      fn<fn<void, x0>, x1>,
      fn<fn<fn<void, x0>, x1>, x2>
    >
  >();

  test_eq_types<
    typename mhn::scan_left_initial<fn_q, tl5, void, SeqTagO>::type,
    mhn::make_seq_t<
      SeqTagO,
      void,
      fn<void, x0>,
      fn<fn<void, x0>, x1>,
      fn<fn<fn<void, x0>, x1>, x2>,
      fn<fn<fn<fn<void, x0>, x1>, x2>, x3>,
      fn<fn<fn<fn<fn<void, x0>, x1>, x2>, x3>, x4>,
      fn<fn<fn<fn<fn<fn<void, x0>, x1>, x2>, x3>, x4>, x5>
    >
  >();
}


int main()
{
  test_scan_left_initial_tls<mhn::linked_list_tag, mhn::linked_list_tag>();
  test_scan_left_initial_tls<mhn::linked_list_tag, mhn::vector_tag>();
  test_scan_left_initial_tls<mhn::vector_tag, mhn::linked_list_tag>();
  test_scan_left_initial_tls<mhn::vector_tag, mhn::vector_tag>();

  return EXIT_SUCCESS;
}
