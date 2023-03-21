// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file drop_while.hpp
 *
 * @brief `drop_while` metafunction
 *
 * Defines the `drop_while` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DROP_WHILE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DROP_WHILE_HPP


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
  struct drop_while_helper :
    eval_if<
      typename Pred::template apply<front_t<It>>::type,
      drop_while_helper<pop_front_t<It>, Pred>,
      It
    >
  {};

  template <typename It, typename Pred>
  struct drop_while_helper<It, Pred, true>
  {
    using type = It;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Drops elements satisfying a condition
 *
 * Drops the first elements of an @ref tc_iterable that satisfy the condition
 * given in the supplied unary predicate.
 *
 * @see @ref drop
 * @see @ref drop_until
 * @see @ref take_while
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/drop_while.cpp
 */
template <typename It, typename Pred>
struct drop_while
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::drop_while_helper<It, Pred> \
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
 * @relates erythronelumbo::maihuenia::drop_while
 *
 * @invokesmfn{drop_while}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 */
template <typename It, typename Pred>
using drop_while_t = typename drop_while<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DROP_WHILE_HPP
