// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `range_c` data type
 *
 * Defines the `range_c` data type.
 */

/**
 * @defgroup dt_seq_range_c range_c
 * @ingroup dt_sequences
 *
 * @brief Numeric range
 *
 * A sequence that represents sequentially increasing or decreasing integral
 * values.
 *
 * ### Models
 *
 * @ref tc_foldable, @ref tc_iterable
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_RANGE_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_RANGE_C_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_range_c}
 */
struct range_c_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_range_c
 * @brief Numeric range
 *
 * A sequence of integral values.
 *
 * @see @ref vector_c
 * @see @ref iota
 * @see @ref iota_c
 *
 * @tparam IntType
 *   The type of the underlying integral values.
 * @tparam Start
 *   The start.
 * @tparam Num
 *   The length of the sequence.
 * @tparam Step
 *   The *step* of the sequence. Determines how much it increases or decreases.
 *
 * ## Example
 *
 * @include example/individual/sequences/range_c.cpp
 */
template <
  typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step = 1
>
struct range_c
{
  /**
   * @mfncalltoitself
   */
  using type = range_c;

  /**
   * @memtypetag
   */
  using tag = range_c_tag;

  /**
   * @brief Value type
   *
   * The type of the contained elements.
   */
  using value_type = IntType;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_RANGE_C_HPP
