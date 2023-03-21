// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file while.hpp
 *
 * @brief `while_` metafunction
 *
 * Defines the `while_` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_WHILE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_WHILE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename C, typename F>
  struct while_helper
  {
    template <typename St, bool = C::template apply<St>::type::value>
    struct result_ : result_<typename F::template apply<St>::type> {};

    template <typename St>
    struct result_<St, false>
    {
      using type = St;
    };
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup control
 * @brief *While* loop
 *
 * Transforms a *state* repeatedly with a metafunction class until said state
 * stops satisfying a condition.
 *
 * @see @ref until
 *
 * @tparam Cond
 *   The condition that the state needs to satisfy for keeping the *loop*
 *   running. It must be an unary predicate (a metafunction class).
 * @tparam Fn
 *   The unary metafunction class that transforms the state.
 * @tparam State
 *   The *state* of the loop.
 *
 * ## Example
 *
 * @include example/individual/control/while.cpp
 */
template <typename Cond, typename Fn, typename State>
struct while_
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::while_helper<Cond, Fn>::template result_<State> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The state after being transformed many times as much as `Cond` was
   * satisfied.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::while_
 *
 * @invokesmfn{while_}
 *
 * @tparam Cond
 *   The condition that the *state* needs to satisfy for keeping the *loop*
 *   running. It must be an unary predicate (a metafunction class).
 * @tparam Fn
 *   The unary metafunction class that transforms the state.
 * @tparam State
 *   The *state* of the loop.
 */
template <typename Cond, typename Fn, typename State>
using while_t = typename while_<Cond, Fn, State>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_WHILE_HPP
