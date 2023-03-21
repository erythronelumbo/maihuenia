// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file min_max_element.hpp
 *
 * @brief `min_element` and `max_element` metafunctions
 *
 * Defines the `min_element` and `max_element` metafunctions.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_ELEMENT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_ELEMENT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/min_max.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup alg_querying
 * @brief Minimum from an iterable
 *
 * Finds the minimum of all the @ref tc_orderable elements contained in an
 * @ref tc_iterable.
 *
 * @see @ref less
 * @see @ref min
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_orderable s.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/min_element.cpp
 */
template <typename It>
struct min_element
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      typename empty<It>::type, \
      undefined, \
      fold_left<quote<min>, It> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The minimum of the elements in the @ref tc_iterable or @ref undefined if
   * `It` is empty.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::min_element
 *
 * @invokesmfn{min_element}
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_orderable s.
 */
template <typename It>
using min_element_t = typename min_element<It>::type;


/**
 * @ingroup alg_querying
 * @brief Maximum from an iterable
 *
 * Finds the maximum of all the @ref tc_orderable elements contained in an
 * @ref tc_iterable.
 *
 * @see @ref greater
 * @see @ref max
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_orderable s.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/max_element.cpp
 */
template <typename It>
struct max_element
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      typename empty<It>::type, \
      undefined, \
      fold_left<quote<max>, It> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The maximum of the elements in the @ref tc_iterable or @ref undefined if
   * `It` is empty.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::max_element
 *
 * @invokesmfn{max_element}
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_orderable s.
 */
template <typename It>
using max_element_t = typename max_element<It>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_ELEMENT_HPP
