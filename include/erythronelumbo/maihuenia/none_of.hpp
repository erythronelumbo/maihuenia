// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file none_of.hpp
 *
 * @brief `none_of` metafunction
 *
 * Defines the `none_of` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_NONE_OF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_NONE_OF_HPP


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
  struct none_of_fn
  {
    template <typename Xa, typename Xb>
    using apply = logical_and<
      Xa, logical_not_t<typename Pred::template apply<Xb>::type>
    >;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks if all elements in an iterable cannot satisfy a condition
 *
 * Checks if all the elements contained in an @ref tc_iterable cannot satisfy
 * the condition given by an unary predicate.
 *
 * @see @ref find_if
 * @see @ref count_if
 * @see @ref all_of
 * @see @ref any_of
 * @see @ref logical_or
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/none_of.cpp
 */
template <typename It, typename Pred>
struct none_of
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial<detail::none_of_fn<Pred>, It, true_> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_` indicating if all the elements of `It` are unable to satisfy
   * `Pred` or not.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::none_of
 *
 * @invokesmfn{none_of}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate.
 */
template <typename It, typename Pred>
using none_of_t = typename none_of<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_NONE_OF_HPP
