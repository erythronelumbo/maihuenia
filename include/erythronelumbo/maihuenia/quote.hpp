// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file quote.hpp
 *
 * @brief `quote` metafunction class
 *
 * Defines the `quote` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_QUOTE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_QUOTE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup functional
 * @brief Metafunction-to-metafunction-class wrapper
 * 
 * Wraps an n-ary metafunction so it can be used as a metafunction class.
 *
 * @see @ref apply_wrap
 * @see @ref bind
 * @see @ref lambda
 * @see @ref curry_quote
 * 
 * @tparam MetaFn
 *   The metafunction to be wrapped.
 *
 * ## Example
 *
 * @include example/individual/functional/quote.cpp
 */
template <template <typename...> class MetaFn>
struct quote
{
  /**
   * @brief Reference to itself
   *
   * Calls to itself when treated as a metafunction.
   */
  using type = quote;

  /**
   * @brief Invocation
   *
   * Invokes the metafunction *as is*.
   *
   * @tparam Args...
   *   The metafunction's arguments.
   */
  template <typename... Args>
  struct apply
  {
    /**
     * @brief Result
     *
     * The result of the wrapped metafunction with the given arguments.
     */
    using type = typename MetaFn<Args...>::type;
  };
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_QUOTE_HPP
