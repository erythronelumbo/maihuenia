// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file is_permutation.hpp
 *
 * @brief `is_permutation` metafunction
 *
 * Defines the `is_permutation` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_IS_PERMUTATION_HPP
#define ERYTHRONELUMBO_MAIHUENIA_IS_PERMUTATION_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/count_if.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  /*
   * With strings "bacd" and "aabc":
   * count("bacd", "aabc"[0]) == 1; count("aabc", "aabc"[0]) == 2
   * count("bacd", "abc"[0])  == 1; count("aabc", "abc"[0])  == 2
   * count("bacd", "bc"[0])   == 1; count("aabc", "bc"[0])   == 1
   * count("bacd", "c"[0])    == 1; count("aabc", "c"[0])    == 1
   * count("aabc", "bacd"[0]) == 1; count("bacd", "bacd"[0]) == 1
   * count("aabc", "acd"[0])  == 2; count("bacd", "acd"[0])  == 1
   * count("aabc", "cd"[0])   == 1; count("bacd", "cd"[0])   == 1
   * count("aabc", "d"[0])    == 0; count("bacd", "d"[0])    == 1
   *
   * With strings "abcd" and "bdca":
   * count("abcd", "bcda"[0]) == 1
   * count("abcd", "cda"[0]) == 1
   * count("abcd", "da"[0]) == 1
   * count("abcd", "a"[0]) == 1
   * count("bcda", "abcd"[0]) == 1
   * count("bcda", "bcd"[0]) == 1
   * count("bcda", "cd"[0]) == 1
   * count("bcda", "d"[0]) == 1
   *
   * With strings "bacad" and "acbad":
   * count("bacad", "acbad"[0]) == 2
   * count("bacad", "cbad"[0]) == 1
   * count("bacad", "bad"[0]) == 1
   * count("bacad", "ad"[0]) == 2
   * count("bacad", "d"[0]) == 1
   * count("acbad", "bacad"[0]) == 1
   * count("acbad", "acad"[0]) == 2
   * count("acbad", "cad"[0]) == 1
   * count("acbad", "ad"[0]) == 2
   * count("acbad", "d"[0]) == 1
   *
   * With strings "bacay" and "dabca":
   * count("bacay", "dabca"[0]) == 0; count("dabca", "dabca"[0]) == 1
   * count("bacay", "abca"[0])  == 2; count("dabca", "abca"[0])  == 2
   * count("bacay", "bca"[0])   == 1; count("dabca", "bca"[0])   == 1
   * count("bacay", "ca"[0])    == 1; count("dabca", "ca"[0])    == 1
   * count("bacay", "a"[0])     == 2; count("dabca", "a"[0])     == 2
   * ---
   * count("dabca", "bacay"[0]) == 1; count("bacay", "bacay"[0]) == 1
   * count("dabca", "acay"[0])  == 2; count("bacay", "acay"[0])  == 2
   * count("dabca", "cay"[0])   == 1; count("bacay", "cay"[0])   == 1
   * count("dabca", "ay"[0])    == 2; count("bacay", "ay"[0])    == 2
   * count("dabca", "y"[0])     == 0; count("bacay", "y"[0])     == 2
   *
   * With strings "babb" and "aaab":
   * count("babb", "aaab"[0]) == 1; count("aaab", "aaab"[0]) == 3
   * count("babb", "aab"[0])  == 1; count("aaab", "aab"[0])  == 3
   * count("babb", "ab"[0])   == 1; count("aaab", "ab"[0])   == 3
   * count("babb", "b"[0])    == 3; count("aaab", "b"[0])    == 1
   * ---
   * count("aaab", "babb"[0]) == 1; count("babb", "babb"[0]) == 3
   * count("aaab", "abb"[0])  == 3; count("babb", "abb"[0])  == 1
   * count("aaab", "bb"[0])   == 1; count("babb", "bb"[0])   == 3
   * count("aaab", "b"[0])    == 1; count("babb", "b"[0])    == 3
   *
   * With strings "aab" and "baa":
   * count("aab", "baa"[0]) == 1; count("baa", "baa"[0]) == 1
   * count("aab", "aa"[0])  == 2; count("baa", "aa"[0])  == 2
   * count("aab", "a"[0])   == 2; count("baa", "a"[0])   == 2
   * ---
   * count("baa", "aab"[0]) == 2; count("aab", "aab"[0]) == 2
   * count("baa", "ab"[0])  == 2; count("aab", "ab"[0])  == 2
   * count("baa", "b"[0])   == 1; count("aab", "b"[0])   == 1
   *
   * With strings "acba" and "bcaa":
   * count("acba", "bcaa"[0]) == 1; count("bcaa", "bcaa"[0]) == 1
   * count("acba", "caa"[0])  == 1; count("bcaa", "caa"[0])  == 1
   * count("acba", "aa"[0])   == 2; count("bcaa", "aa"[0])   == 2
   * count("acba", "a"[0])    == 2; count("bcaa", "a"[0])    == 2
   * ---
   * count("bcaa", "acba"[0]) == 2; count("acba", "acba"[0]) == 2
   * count("bcaa", "cba"[0])  == 1; count("acba", "cba"[0])  == 1
   * count("bcaa", "ba"[0])   == 1; count("acba", "ba"[0])   == 1
   * count("bcaa", "a"[0])    == 2; count("acba", "a"[0])    == 2
   */

  template <typename It1, typename It2>
  struct is_prmt_chk_sszs_nonempty
  {
    template <typename Res, typename It2Elem>
    using apply = logical_and<
      Res,
      equals_t<count_t<It1, It2Elem>, count_t<It2, It2Elem>>
    >;
  };


  template <typename It1, typename It2>
  struct is_prmt_same_sizes :
    fold_left_initial<
      is_prmt_chk_sszs_nonempty<It1, It2>, It2, true_
    >
  {};



  template <typename It1, typename It2, bool = empty_t<It1>::value>
  struct is_prmt_discard_equal_fronts :
    eval_if<
      equals_t<front_t<It1>, front_t<It2>>,
      is_prmt_discard_equal_fronts<
        pop_front_t<It1>, pop_front_t<It2>
      >,
      is_prmt_same_sizes<It1, It2>
    >
  {};

  template <typename It1, typename It2>
  struct is_prmt_discard_equal_fronts<It1, It2, true> :
    true_
  {};


  template <
    typename It1, typename It2,
    bool = empty_t<It1>::value,
    bool = empty_t<It2>::value
  >
  struct is_permutation_initial :
    eval_if_c<
      size<It1>::type::value == size<It2>::type::value,
      is_prmt_discard_equal_fronts<It1, It2>,
      false_
    >
  {};

  template <typename It1, typename It2>
  struct is_permutation_initial<It1, It2, false, true> : false_ {};

  template <typename It1, typename It2>
  struct is_permutation_initial<It1, It2, true, false> : false_ {};

  template <typename It1, typename It2>
  struct is_permutation_initial<It1, It2, true, true> : true_ {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks if an iterable is a permutation of another one
 *
 * Checks if an @ref tc_iterable is a permutation of another one.
 *
 * @tparam It1
 *   The @ref tc_iterable to analyze.
 * @tparam It2
 *   The @ref tc_iterable to analyze.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/is_permutation.cpp
 */
template <typename It1, typename It2>
struct is_permutation
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::is_permutation_initial<It1, It2> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_`: `true_` if both are permutations, `false_` otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::is_permutation
 *
 * @invokesmfn{is_permutation}
 *
 * @tparam It1
 *   The @ref tc_iterable to analyze.
 * @tparam It2
 *   The @ref tc_iterable to analyze.
 */
template <typename It1, typename It2>
using is_permutation_t = typename is_permutation<It1, It2>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_IS_PERMUTATION_HPP
