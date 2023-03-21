// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file protect.hpp
 *
 * @brief `protect` type
 *
 * Defines the `protect` utility type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_PROTECT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_PROTECT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup functional
 * @brief *Protects* a bind expression
 *
 * Encapsulates a @ref bind when it needs to be used as the argument of another
 * bind expression, preventing it from being treated as such. This also applies
 * with @ref lambda.
 *
 * @see @ref bind
 * @see @ref lambda
 *
 * @tparam T
 *   A bind or lambda expression.
 *
 * ## Example
 *
 * @include example/individual/functional/protect.cpp
 */
template <typename T>
struct protect
{
  /**
   * @mfncalltoitself
   */
  using type = protect;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_PROTECT_HPP
