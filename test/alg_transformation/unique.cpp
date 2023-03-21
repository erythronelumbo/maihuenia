// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/unique.hpp>

#include "../eq_types.hpp"


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 20)

namespace mhn = erythronelumbo::maihuenia;


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


template <typename SeqTag>
void test_unique_types()
{
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0>>::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x1, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x1, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x1, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x2>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x0, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x1, x0, x0, x0>>::type,
    mhn::make_seq_t<SeqTag, x1, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x1, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x1, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x1, x1, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x1, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x0, x1>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x0, x1, x2>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x1, x2>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x2, x2>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x2, x1>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x1, x2, x1, x0>>::type,
    mhn::make_seq_t<SeqTag, x1, x2, x0>
  >();
  test_eq_types<
    typename mhn::unique<mhn::make_seq_t<SeqTag, x0, x1, x2, x3>>::type,
    mhn::make_seq_t<SeqTag, x0, x1, x2, x3>
  >();
}


void test_unique_vector_c()
{
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0>>::type,
    mhn::vector<mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0>>::type,
    mhn::vector<mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 1, 0>>::type,
    mhn::vector<mhn::int_<1>, mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 0>>::type,
    mhn::vector<mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 0>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 1, 0, 0>>::type,
    mhn::vector<mhn::int_<1>, mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 2>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 0, 0>>::type,
    mhn::vector<mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 0, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 1, 0>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 0, 0>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 1, 0, 0, 0>>::type,
    mhn::vector<mhn::int_<1>, mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 1, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 1, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 1, 0>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 1, 1, 1, 0>>::type,
    mhn::vector<mhn::int_<1>, mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 1, 0>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 0, 1, 2>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 1, 2>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 2, 2>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 2, 1>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 1, 2, 1, 0>>::type,
    mhn::vector<mhn::int_<1>, mhn::int_<2>, mhn::int_<0>>
  >();
  test_eq_types<
    typename mhn::unique<mhn::vector_c<int, 0, 1, 2, 3>>::type,
    mhn::vector<mhn::int_<0>, mhn::int_<1>, mhn::int_<2>, mhn::int_<3>>
  >();
}


void test_unique_string()
{
  test_eq_types<typename mhn::unique<STR_("")>::type, STR_("")>();
  test_eq_types<typename mhn::unique<STR_("a")>::type, STR_("a")>();
  test_eq_types<typename mhn::unique<STR_("aa")>::type, STR_("a")>();
  test_eq_types<typename mhn::unique<STR_("ab")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("ba")>::type, STR_("ba")>();
  test_eq_types<typename mhn::unique<STR_("aaa")>::type, STR_("a")>();
  test_eq_types<typename mhn::unique<STR_("aab")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("abb")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("aba")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("baa")>::type, STR_("ba")>();
  test_eq_types<typename mhn::unique<STR_("abc")>::type, STR_("abc")>();
  test_eq_types<typename mhn::unique<STR_("aaaa")>::type, STR_("a")>();
  test_eq_types<typename mhn::unique<STR_("aaab")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("aabb")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("abab")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("abbb")>::type, STR_("ab")>();
  test_eq_types<typename mhn::unique<STR_("abbc")>::type, STR_("abc")>();
  test_eq_types<typename mhn::unique<STR_("abcc")>::type, STR_("abc")>();
  test_eq_types<typename mhn::unique<STR_("abcb")>::type, STR_("abc")>();
  test_eq_types<typename mhn::unique<STR_("bcba")>::type, STR_("bca")>();
  test_eq_types<typename mhn::unique<STR_("abcd")>::type, STR_("abcd")>();
  test_eq_types<typename mhn::unique<STR_("aaabbccdd")>::type, STR_("abcd")>();
}


int main()
{
  test_unique_types<mhn::linked_list_tag>();
  test_unique_types<mhn::vector_tag>();
  test_unique_vector_c();
  test_unique_string();

  return EXIT_SUCCESS;
}
