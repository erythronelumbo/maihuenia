// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file box.hpp
 *
 * @brief `box` type
 *
 * Defines the `box` type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_BOX_HPP
#define ERYTHRONELUMBO_MAIHUENIA_BOX_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup dt_miscellaneous
 * @brief Box
 *
 * A type that contains a single element.
 *
 * @see @ref identity
 *
 * @tparam T The contained element.
 */
template <typename T>
struct box
{
  /**
   * @mfncalltoitself
   */
  using type = box;

  /**
   * @brief Contained element
   *
   * The contained element.
   */
  using elem = T;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_BOX_HPP
