// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file drop_until.hpp
 *
 * @brief `drop_until` metafunction
 *
 * Defines the `drop_until` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DROP_UNTIL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DROP_UNTIL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename It, typename Pred, bool = empty_t<It>::value>
  struct drop_until_helper :
    eval_if<
      typename Pred::template apply<front_t<It>>::type,
      It,
      drop_until_helper<pop_front_t<It>, Pred>
    >
  {};

  template <typename It, typename Pred>
  struct drop_until_helper<It, Pred, true>
  {
    using type = It;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Drops elements satisfying a condition
 *
 * Drops the first elements of an @ref tc_iterable until the condition given in
 * the supplied unary predicate is satisfied.
 *
 * @see @ref drop
 * @see @ref drop_while
 * @see @ref take_until
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/drop_until.cpp
 */
template <typename It, typename Pred>
struct drop_until
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::drop_until_helper<It, Pred> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The @ref tc_iterable without the first elements satisfying `Pred`.
   */
  using type = unspecified;

  #endif //ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::drop_until
 *
 * @invokesmfn{drop_until}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 */
template <typename It, typename Pred>
using drop_until_t = typename drop_until<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DROP_UNTIL_HPP
