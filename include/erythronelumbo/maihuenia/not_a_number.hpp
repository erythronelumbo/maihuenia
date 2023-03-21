// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file not_a_number.hpp
 *
 * @brief `not_a_nummber` data type
 *
 * Defines the `not_a_nummber` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_NOT_A_NUMBER_HPP
#define ERYTHRONELUMBO_MAIHUENIA_NOT_A_NUMBER_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/string.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup dt_numeric
 * @brief Not a number
 *
 * Represents a "not-a-number" result of numeric operations, for example,
 * divisions by zero.
 *
 * @see @ref undefined
 */
struct not_a_number
{
  /**
   * @mfncalltoitself
   */
  using type = not_a_number;

  /**
   * @brief Type tag
   *
   * Uses itself as its type tag.
   */
  using tag = not_a_number;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <>
struct typeclass<WithStringRepr>::define_for<not_a_number>
{
  template <typename X>
  using to_string_impl = string<'N', 'a', 'N'>; // "NaN"
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_NOT_A_NUMBER_HPP
