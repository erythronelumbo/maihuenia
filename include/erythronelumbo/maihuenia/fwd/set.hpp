// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `set` data type
 *
 * Defines the `set` data type.
 */

/**
 * @defgroup dt_seq_set Set
 * @ingroup dt_sequences
 *
 * @brief Set
 *
 * Defines a container where only a single instance of a contained element is
 * allowed.
 *
 * ### Models
 *
 * @ref tc_mapping, @ref tc_extensiblemapping
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_SET_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_SET_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_set}
 */
struct set_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename X> struct set_box {};
} // namespace detail


template <typename... Elems>
struct set : detail::set_box<Elems>...
{
  using type = set;
  using tag = set_tag;
};

template <>
struct set<>
{
  using type = set;
  using tag = set_tag;
};


template <typename IntType, IntType... Elems>
struct set_c : detail::set_box<integer_c<IntType, Elems>>...
{
  using type = set_c;
  using tag = set_tag;
  using value_type = IntType;
};

template <typename IntType>
struct set_c<IntType>
{
  using type = set_c;
  using tag = set_tag;
  using value_type = IntType;
};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup dt_seq_set
 * @brief Set
 *
 * A container where there can be only one instance of each contained element.
 * 
 * @warning
 *   This is intentionally supposed to fail when there are two or more instances
 *   of an element.
 *
 * @tparam Elems...
 *   The contained elements.
 *
 * ## Example
 *
 * @include example/individual/sequences/set.cpp
 */
template <typename... Elems>
struct set
{
  /**
   * @mfncalltoitself
   */
  using type = set;

  /**
   * @memtypetag
   */
  using tag = set_tag;
};

/**
 * @ingroup dt_seq_set
 * @brief Set with integers
 *
 * A container where there can be only one instance of each contained element.
 * 
 * @warning
 *   This is intentionally supposed to fail when there are two or more instances
 *   of an element.
 *
 * @tparam IntType
 *   The type of the contained elements. It must be integral.
 * @tparam Elems...
 *   The contained elements.
 *
 * ## Example
 *
 * @include example/individual/sequences/set_c.cpp
 */
template <typename IntType, IntType... Elems>
struct set_c
{
  /**
   * @mfncalltoitself
   */
  using type = set_c;

  /**
   * @memtypetag
   */
  using tag = set_tag;

  /**
   * @brief Value type
   *
   * The type of the contained elements.
   */
  using value_type = IntType;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_SET_HPP
