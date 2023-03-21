// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/is_permutation.hpp>

#include "../eq_types.hpp"


#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;


struct x0 {};
struct x1 {};
struct x2 {};
struct x3 {};
struct x4 {};


int main()
{
  using vec1 = mhn::vector<x0, x1, x2, x3, x4>;
  using vec2 = mhn::vector<x0, x1, x2, x1, x4>;
  using vec3 = mhn::vector<x0, x1, x2, x3>;
  using vec4 = mhn::vector<x2, x4, x0, x3, x1>;
  using vec5 = mhn::vector<x0>;
  using vec6 = mhn::vector<>;

  static_assert(mhn::is_permutation<vec1, vec4>::type::value, "!!!");
  static_assert(mhn::is_permutation<vec4, vec1>::type::value, "!!!");
  static_assert(mhn::is_permutation<vec5, vec5>::type::value, "!!!");
  static_assert(!mhn::is_permutation<vec2, vec1>::type::value, "!!!");
  static_assert(!mhn::is_permutation<vec2, vec3>::type::value, "!!!");
  static_assert(!mhn::is_permutation<vec1, vec6>::type::value, "!!!");

  #define PRMT_TEST(a, b) \
  static_assert(mhn::is_permutation<STR_(a), STR_(b)>::type::value, "!!!")

  #define PRMT_TEST_NOT(a, b) \
  static_assert(!mhn::is_permutation<STR_(a), STR_(b)>::type::value, "!!!")

  PRMT_TEST("abc", "abc");
  PRMT_TEST("abc", "acb");
  PRMT_TEST("acb", "abc");
  PRMT_TEST("bca", "acb");
  PRMT_TEST("aab", "aba");
  PRMT_TEST("baa", "aba");
  PRMT_TEST_NOT("bbaa", "abaa");
  PRMT_TEST_NOT("bbcaa", "abaca");
  PRMT_TEST_NOT("yaay", "aaya");
  PRMT_TEST("yaay", "ayay");

  static_assert(
    mhn::is_permutation<
      STR_("abcde"),
      STR_("bacde")
    >::type::value,
    "!!!"
  );

  static_assert(
    !mhn::is_permutation<
      STR_("abcda"),
      STR_("bacde")
    >::type::value,
    "!!!"
  );

  static_assert(
    !mhn::is_permutation<
      STR_("bacde"),
      STR_("abcda")
    >::type::value,
    "!!!"
  );

  static_assert(
    mhn::is_permutation<
      STR_("bacda"),
      STR_("abcda")
    >::type::value,
    "!!!"
  );

  static_assert(
    !mhn::is_permutation<
      STR_(""),
      STR_("abcda")
    >::type::value,
    "!!!"
  );

  static_assert(
    !mhn::is_permutation<
      STR_("xyzxxyz"),
      STR_("abcda")
    >::type::value,
    "!!!"
  );

  static_assert(
    !mhn::is_permutation<
      STR_("bacda"),
      STR_("")
    >::type::value,
    "!!!"
  );

  static_assert(
    mhn::is_permutation<
      STR_("bacda"),
      STR_("abcda")
    >::type::value,
    "!!!"
  );

  return EXIT_SUCCESS;
}
