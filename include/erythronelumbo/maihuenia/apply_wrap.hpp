// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file apply_wrap.hpp
 *
 * @brief `apply_wrap` metafunction
 *
 * Contains the `apply_wrap` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_APPLY_WRAP_HPP
#define ERYTHRONELUMBO_MAIHUENIA_APPLY_WRAP_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup functional
 * @brief Metafunction-class-to-metafunction wrapper
 *
 * Allows a metafunction class `Fn` to be treated as a normal metafunction,
 * taking the arguments given in `Args...`.
 *
 * @see @ref quote
 *
 * @tparam Fn
 *   The metafunction class.
 * @tparam Args...
 *   The arguments taken by the wrapped metafunction class.
 *
 * ## Example
 *
 * @include example/individual/functional/apply_wrap.cpp
 */
template <typename Fn, typename... Args>
struct apply_wrap
{
  /**
   * @brief Result
   *
   * The invoked metafunction class.
   */
  using type = typename Fn::template apply<Args...>::type;
};

/**
 * @relates erythronelumbo::maihuenia::apply_wrap
 *
 * @invokesmfn{apply_wrap}
 *
 * @tparam Fn
 *   The metafunction class.
 * @tparam Args...
 *   The arguments taken by the wrapped metafunction class.
 */
template <typename Fn, typename... Args>
using apply_wrap_t = typename apply_wrap<Fn, Args...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_APPLY_WRAP_HPP
