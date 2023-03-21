// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file until.hpp
 *
 * @brief `until` metafunction
 *
 * Defines the `until` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_UNTIL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_UNTIL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename C, typename F>
  struct until_helper
  {
    template <typename St, bool = !C::template apply<St>::type::value>
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
 * @brief *Until* loop
 *
 * Transforms a *state* repeatedly with a metafunction class until said state
 * satisfies a condition.
 *
 * @see @ref while_
 *
 * @tparam Cond
 *   The condition that the state needs to satisfy for the *loop* to be stopped.
 *   It must be an unary predicate (a metafunction class).
 * @tparam Fn
 *   The unary metafunction class that transforms the state.
 * @tparam State
 *   The *state* of the loop.
 *
 * ## Example
 *
 * @include example/individual/control/until.cpp
 */
template <typename Cond, typename Fn, typename State>
struct until
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::until_helper<Cond, Fn>::template result_<State> \
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
 * @relates erythronelumbo::maihuenia::until
 *
 * @invokesmfn{until}
 *
 * @tparam Cond
 *   The condition that the state needs to satisfy for the *loop* to be stopped.
 *   It must be an unary predicate (a metafunction class).
 * @tparam Fn
 *   The unary metafunction class that transforms the state.
 * @tparam State
 *   The *state* of the loop.
 */
template <typename Cond, typename Fn, typename State>
using until_t = typename until<Cond, Fn, State>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_UNTIL_HPP
