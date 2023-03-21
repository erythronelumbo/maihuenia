// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file always.hpp
 *
 * @brief `always` metafunction class
 *
 * Defines the `always` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ALWAYS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ALWAYS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_miscellaneous
 * @brief Identity-like metafunction class
 *
 * A metafunction class that always results in a given type `T`, regardless of
 * the arguments passed in its `apply` member.
 *
 * @see @ref identity
 *
 * @tparam T
 *   The type that will be returned.
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/always.cpp
 */
template <typename T>
struct always
{
  /**
   * @brief Reference to itself
   *
   * Calls to itself when treated as a metafunction.
   */
  using type = always;

  /**
   * @brief Invocation
   *
   * Takes any number of parameters, which are ignored.
   *
   * @tparam Args...
   *   The arguments.
   */
  template <typename... Args>
  struct apply
  {
    /**
     * @brief Result
     *
     * The type specified in `T`.
     */
    using type = T;
  };
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ALWAYS_HPP
