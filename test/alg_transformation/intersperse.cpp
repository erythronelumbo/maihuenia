// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/intersperse.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct yy {};

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


using n0 = mhn::int_<0>;
using n1 = mhn::int_<1>;
using n2 = mhn::int_<2>;
using n3 = mhn::int_<3>;
using n4 = mhn::int_<4>;
using n5 = mhn::int_<5>;
using n6 = mhn::int_<6>;
using n7 = mhn::int_<7>;
using n8 = mhn::int_<8>;
using n9 = mhn::int_<9>;


int main()
{
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<>,
      yy
    >::type,
    mhn::vector<>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<x0>,
      yy
    >::type,
    mhn::vector<x0>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<x0, x1>,
      yy
    >::type,
    mhn::vector<x0, yy, x1>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<x0, x1, x2>,
      yy
    >::type,
    mhn::vector<x0, yy, x1, yy, x2>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<x0, x1, x2, x3>,
      yy
    >::type,
    mhn::vector<x0, yy, x1, yy, x2, yy, x3>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector<x0, x1, x2, x3, x4, x5, x6, x7>,
      yy
    >::type,
    mhn::vector<x0, yy, x1, yy, x2, yy, x3, yy, x4, yy, x5, yy, x6, yy, x7>
  >();

  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int, 0>,
      yy
    >::type,
    mhn::vector<n0>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int>,
      yy
    >::type,
    mhn::vector_c<int>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int, 0, 1>,
      yy
    >::type,
    mhn::vector<n0, yy, n1>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int, 0, 1, 2>,
      yy
    >::type,
    mhn::vector<n0, yy, n1, yy, n2>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int, 0, 1, 2, 3>,
      yy
    >::type,
    mhn::vector<n0, yy, n1, yy, n2, yy, n3>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::vector_c<int, 0, 1, 2, 3, 4, 5, 6, 7>,
      yy
    >::type,
    mhn::vector<n0, yy, n1, yy, n2, yy, n3, yy, n4, yy, n5, yy, n6, yy, n7>
  >();

  test_eq_types<
    typename mhn::intersperse<
      mhn::null_type,
      yy
    >::type,
    mhn::null_type
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::cons<x0>,
      yy
    >::type,
    mhn::cons<x0>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::cons<x0, mhn::cons<x1>>,
      yy
    >::type,
    mhn::cons<x0, mhn::cons<yy, mhn::cons<x1>>>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::cons<x0, mhn::cons<x1, mhn::cons<x2>>>,
      yy
    >::type,
    mhn::cons<x0, mhn::cons<yy, mhn::cons<x1, mhn::cons<yy, mhn::cons<x2>>>>>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::cons<x0, mhn::cons<x1, mhn::cons<x2, mhn::cons<x3>>>>,
      yy
    >::type,
    mhn::make_seq_t<mhn::linked_list_tag, x0, yy, x1, yy, x2, yy, x3>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::make_seq_t<mhn::linked_list_tag, x0, x1, x2, x3, x4, x5, x6, x7>,
      yy
    >::type,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      x0, yy, x1, yy, x2, yy, x3, yy, x4, yy, x5, yy, x6, yy, x7
    >
  >();

  test_eq_types<
    typename mhn::intersperse<
      mhn::string<>,
      mhn::char_<'-'>
    >::type,
    mhn::string<>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::string<'a'>,
      mhn::char_<'-'>
    >::type,
    mhn::string<'a'>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::string<'a', 'b'>,
      mhn::char_<'-'>
    >::type,
    mhn::string<'a', '-', 'b'>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::string<'a', 'b', 'c'>,
      mhn::char_<'-'>
    >::type,
    mhn::string<'a', '-', 'b', '-', 'c'>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::string<'a', 'b', 'c', 'd'>,
      mhn::char_<'-'>
    >::type,
    mhn::string<'a', '-', 'b', '-', 'c', '-', 'd'>
  >();
  test_eq_types<
    typename mhn::intersperse<
      mhn::string<'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'>,
      mhn::char_<'-'>
    >::type,
    mhn::string<
      'a', '-', 'b', '-', 'c', '-', 'd', '-', 'e', '-', 'f', '-', 'g', '-', 'h'
    >
  >();

  return EXIT_SUCCESS;
}
