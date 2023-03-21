// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file take_while.hpp
 *
 * @brief `take_while` metafunction
 *
 * Defines the `take_while` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_TAKE_WHILE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_TAKE_WHILE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename Seq, typename Pred, typename Result,
    bool = empty<Seq>::type::value
  >
  struct take_while_helper :
    eval_if<
      typename Pred::template apply<front_t<Seq>>::type,
      take_while_helper<
        pop_front_t<Seq>, Pred,
        push_back_t<Result, front_t<Seq>>
      >,
      Result
    >
  {};

  template <typename Seq, typename Pred, typename Result>
  struct take_while_helper<Seq, Pred, Result, true> :
    Result
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Takes elements satisfying a condition
 *
 * Takes the first elements of a @ref tc_sequence that satisfy the condition
 * given in the supplied unary predicate.
 *
 * @see @ref take
 * @see @ref take_until
 * @see @ref drop_while
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/take_while.cpp
 */
template <typename Seq, typename Pred>
struct take_while
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::take_while_helper<Seq, Pred, clear_t<Seq>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The @ref tc_sequence with only the first elements satisfying `Pred`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::take_while
 *
 * @invokesmfn{take_while}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   An unary predicate (a metafunction class).
 */
template <typename It, typename Pred>
using take_while_t = typename take_while<It, Pred>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_TAKE_WHILE_HPP
