// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file all_of.hpp
 *
 * @brief `all_of` metafunction
 *
 * Defines the `all_of` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ALL_OF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ALL_OF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Pred>
  struct all_of_fn
  {
    template <typename Xa, typename Xb>
    using apply = logical_and<Xa, typename Pred::template apply<Xb>::type>;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks if all the elements in an iterable satisfy a condition
 *
 * Checks if all the elements contained in an @ref tc_iterable satisfy the
 * condition given by an unary predicate.
 *
 * @see @ref find_if
 * @see @ref count_if
 * @see @ref any_of
 * @see @ref none_of
 * @see @ref logical_and
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/all_of.cpp
 */
template <typename It, typename Pred>
struct all_of
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial<detail::all_of_fn<Pred>, It, true_> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_` indicating if all the elements of `It` satisfy `Pred` or not.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::all_of
 *
 * @invokesmfn{all_of}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 */
template <typename It, typename Pred>
using all_of_t = typename all_of<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ALL_OF_HPP
