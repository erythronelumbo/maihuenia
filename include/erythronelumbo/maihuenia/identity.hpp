// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file identity.hpp
 *
 * @brief `identity` metafunction
 *
 * Defines the `identity` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_IDENTITY_HPP
#define ERYTHRONELUMBO_MAIHUENIA_IDENTITY_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_miscellaneous
 * @brief Identity metafunction
 *
 * A metafunction that returns its argument, without any modifications.
 *
 * @see @ref box
 * @see @ref always
 *
 * @tparam T The argument and result.
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/identity.cpp
 */
template <typename T>
struct identity
{
  /**
   * @brief Result
   *
   * The metafunction's argument, with no changes.
   */
  using type = T;
};


/**
 * @relates erythronelumbo::maihuenia::identity
 *
 * @invokesmfn{identity}
 *
 * @note This alias is pointless, but it is left for convenience.
 *
 * @tparam T The argument and result.
 */
template <typename T>
using identity_t = typename identity<T>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_IDENTITY_HPP
