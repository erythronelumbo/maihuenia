// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `integral_vector_c` data type
 *
 * Defines the `integral_vector_c` data type.
 */

/**
 * @defgroup dt_seq_integral_vector_c integral_vector_c
 * @ingroup dt_sequences
 *
 * @brief Vector of integers
 *
 * Defines a *random-access* sequence of only integers.
 *
 * ### Models
 *
 * @ref tc_iterable, @ref tc_foldable, @ref tc_sequence, @ref tc_monoid
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGRAL_VECTOR_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGRAL_VECTOR_C_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_integral_vector_c}
 */
template <typename IntType>
struct integral_vector_c_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

/**
 * @ingroup dt_seq_integral_vector_c
 * @brief Vector of integers
 *
 * A *random-access* varidic sequence of only integers.
 *
 * @see @ref vector_c, a similar data type, but with different semantics.
 * @see @ref range_c
 *
 * @tparam IntType
 *   The type of the contained integral values.
 * @tparam Xs...
 *   The contained elements.
 *
 * ## Example
 *
 * TBD
 */
template <typename IntType, IntType... Xs>
struct integral_vector_c
{
  /**
   * @mfncalltoitself
   */
  using type = integral_vector_c;

  /**
   * @memtypetag
   */
  using tag = integral_vector_c_tag<IntType>;

  /**
   * @brief Value type
   *
   * The type of the contained elements.
   */
  using value_type = IntType;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGRAL_VECTOR_C_HPP
