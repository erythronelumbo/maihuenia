// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file lexicographical_compare.hpp
 *
 * @brief `lexicographical_compare` metafunction
 *
 * Defines the `lexicographical_compare` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_LEXICOGRAPHICAL_COMPARE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_LEXICOGRAPHICAL_COMPARE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename Cmp, typename It1, typename It2,
    bool = empty_t<It1>::value,
    bool = empty_t<It2>::value
  >
  struct lcmp_impl :
    eval_if<
      typename equals<front_t<It1>, front_t<It2>>::type,
      lcmp_impl<Cmp, pop_front_t<It1>, pop_front_t<It2>>,
      typename Cmp::template apply<front_t<It1>, front_t<It2>>
    >
  {};

  template <typename Cmp, typename It1, typename It2>
  struct lcmp_impl<Cmp, It1, It2, true, true> :
    false_
  {};

  template <typename Cmp, typename It1, typename It2>
  struct lcmp_impl<Cmp, It1, It2, false, true> :
    Cmp::template apply<typename size<It1>::type, typename size<It2>::type>
  {};

  template <typename Cmp, typename It1, typename It2>
  struct lcmp_impl<Cmp, It1, It2, true, false> :
    Cmp::template apply<typename size<It1>::type, typename size<It2>::type>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Lexicographical comparator
 *
 * Compares lexicographically two iterables, which contain @ref tc_comparable s,
 * according to a binary predicate.
 *
 * @see @ref tc_comparable
 *
 * @tparam It1
 *   An @ref tc_iterable containing elements that implement @ref tc_comparable.
 * @tparam It2
 *   An @ref tc_iterable containing elements that implement @ref tc_comparable.
 * @tparam Cmp
 *   The comparator (a binary metafunction class). It also compares the sizes
 *   of `It1` and `It2`.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/lexicographical_compare.cpp
 */
template <typename It1, typename It2, typename Cmp>
struct lexicographical_compare
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN(: detail::lcmp_impl<Cmp, It1, It2>)
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @c bool_ : @c true_ if the comparison applies lexicographically,
   * @c false_ otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::lexicographical_compare
 *
 * @invokesmfn{lexicographical_compare}
 *
 * @tparam It1
 *   An @ref tc_iterable containing elements that implement @ref tc_comparable.
 * @tparam It2
 *   An @ref tc_iterable containing elements that implement @ref tc_comparable.
 * @tparam Cmp
 *   The comparator (a binary metafunction class). It also compares the sizes
 *   of `It1` and `It2`.
 */
template <typename It1, typename It2, typename Cmp>
using lexicographical_compare_t = typename lexicographical_compare<
  It1, It2, Cmp
>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_LEXICOGRAPHICAL_COMPARE_HPP
