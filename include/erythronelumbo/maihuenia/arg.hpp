// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file arg.hpp
 *
 * @brief `arg` metafunction class
 *
 * Defines the `arg` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ARG_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ARG_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/variadic_indexers.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <::std::size_t N>
  struct arg
  {
    using type = arg;
    using tag = arg;
    template <typename... Args>
    struct apply :
      detail::variadic_type_indexer<N, Args...>
    {};
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup functional
 * @brief N-th argument
 *
 * A metafunction class that returns its `(N + 1)`-th element.
 *
 * @see @ref placeholders
 * 
 * @tparam N
 *   The position of the argument to get, being `0` the value that corresponds
 *   to the first argument.
 *
 * ## Example
 *
 * @include example/individual/functional/arg.cpp
 */
template <::std::size_t N>
struct arg
{
  /**
   * @brief Reference to itself
   *
   * Calls to itself when treated as a metafunction.
   */
  using type = arg;

  /**
   * @brief Type tag
   *
   * Uses itself as a "type tag". Used for convenience.
   */
  using tag = arg;

  /**
   * @brief Invocation
   *
   * Takes the `N`-th element from a parameter pack.
   *
   * @tparam Args...
   *   The parameter pack.
   */
  template <typename... Args>
  struct apply
  {
    /**
     * @brief Result
     *
     * The `N`-th element of the given parameter pack.
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ARG_HPP
