// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file count_while.hpp
 *
 * @brief `count_while` metafunction
 *
 * Defines the `count_while` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_COUNT_WHILE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_COUNT_WHILE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename It, typename Pred, typename Result,
    bool = empty_t<It>::value
  >
  struct count_while_helper :
    eval_if<
      typename Pred::template apply<front_t<It>>::type,
      count_while_helper<pop_front_t<It>, Pred, incr_t<Result>>,
      Result
    >
  {};

  template <typename It, typename Pred, typename Result>
  struct count_while_helper<It, Pred, Result, true>
  {
    using type = Result;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Counts the first elements that satisfy a condition
 *
 * Counts the first elements of an @ref tc_iterable that satisfy the condition
 * given by an unary predicate. It stops counting when the element does not
 * satisfy said condition.
 *
 * @see @ref count
 * @see @ref count_if
 * @see @ref count_until
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 *
 * ## Example
 *
 * @include example/individual/alg_querying/count_while.cpp
 */
template <typename It, typename Pred>
struct count_while
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::count_while_helper<It, Pred, size_c<0>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `size_c` with the counted elements.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::count_while
 *
 * @invokesmfn{count_while}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 */
template <typename It, typename Pred>
using count_while_t = typename count_while<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_COUNT_WHILE_HPP
