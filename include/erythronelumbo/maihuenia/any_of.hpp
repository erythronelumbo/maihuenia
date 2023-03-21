// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file any_of.hpp
 *
 * @brief `any_of` metafunction
 *
 * Defines the `any_of` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ANY_OF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ANY_OF_HPP


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
  struct any_of_fn
  {
    template <typename Xa, typename Xb>
    using apply = logical_or<Xa, typename Pred::template apply<Xb>::type>;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks if some elements in an iterable satisfy a condition
 *
 * Checks if at least one of the elements contained in an @ref tc_iterable
 * satisfy the condition given by an unary predicate.
 *
 * @see @ref find_if
 * @see @ref count_if
 * @see @ref all_of
 * @see @ref none_of
 * @see @ref logical_or
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/any_of.cpp
 */
template <typename It, typename Pred>
struct any_of
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial<detail::any_of_fn<Pred>, It, false_> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_` indicating if some elements of `It` satisfy `Pred` or not.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::any_of
 *
 * @invokesmfn{any_of}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 */
template <typename It, typename Pred>
using any_of_t = typename any_of<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ANY_OF_HPP
