// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `map` data type
 *
 * Defines the `map` data type.
 */

/**
 * @defgroup dt_seq_map Map
 * @ingroup dt_sequences
 *
 * @brief Map
 *
 * Defines an associative container, where the contained elements are associated
 * to *keys*.
 *
 * ### Models
 *
 * @ref tc_mapping, @ref tc_extensiblemapping
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_MAP_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_MAP_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_map}
 */
struct map_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_map
 * @brief Map
 *
 * An associative container where the elements are key-value pairs. Each key
 * cannot represent more than one value.
 *
 * @tparam Pairs...
 *   Instances of @ref pair containing the key and the value.
 *
 * ## Example
 *
 * @include example/individual/sequences/map.cpp
 */
template <typename... Pairs>
struct map
{
  /**
   * @mfncalltoitself
   */
  using type = map;

  /**
   * @memtypetag
   */
  using tag = map_tag;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_MAP_HPP
