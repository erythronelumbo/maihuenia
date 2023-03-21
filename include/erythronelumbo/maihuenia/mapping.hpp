// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file mapping.hpp
 *
 * @brief `Mapping` typeclass
 *
 * Defines the `Mapping` typeclass.
 */

/**
 * @defgroup tc_mapping Mapping
 * @ingroup typeclasses
 *
 * @brief Associative sequences
 *
 * Sequences where their elements are usually stored in *key-value* pairs and
 * each element is accessed with its associated key, rather that its *physical*
 * position.
 *
 * ### Minimal complete definition
 *
 * `at_key<AssocSeq, Key>`, `has_key<AssocSeq, Key>`
 *
 * @see @ref tc_sequence
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MAPPING_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MAPPING_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_mapping}
 */
struct Mapping ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Mapping, \
    1, \
    (), \
    ( \
      (aempty, 0, 1, 0, 0, (0)), \
      (at_key, 0, 2, 0, 0, (0)), \
      (has_key, 0, 2, 0, 0, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_mapping
 * @brief Checks if a mapping is empty
 *
 * Checks if an associative sequence has no elements.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 *
 * ## Example
 *
 * @include example/individual/mapping/at_key.cpp
 */
template <typename AssocSeq>
struct aempty
{
  /**
   * @brief Result
   *
   * `true_` if `AssocSeq` is empty, `false_` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_mapping
 * @brief Element of an associative sequence
 *
 * Retrieves the element of an associative sequence by means of its associated
 * key.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key associated to the element.
 *
 * ## Example
 *
 * @include example/individual/mapping/at_key.cpp
 */
template <typename AssocSeq, typename Key>
struct at_key
{
  /**
   * @brief Result
   *
   * The value (or element) associated to the key or @ref undefined if not
   * present.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_mapping
 * @brief Checks if an associative sequence has a key
 *
 * Checks if an associative sequence contains the given key and, therefore, the
 * associated value.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key to find.
 *
 * ## Example
 *
 * @include example/individual/mapping/has_key.cpp
 */
template <typename AssocSeq, typename Key>
struct has_key
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if the key is in the sequence, `false_` otherwise.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::aempty
 *
 * @invokesmfn{aempty}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 */
template <typename AssocSeq>
using aempty_t = typename aempty<AssocSeq>::type;

/**
 * @relates erythronelumbo::maihuenia::at_key
 *
 * @invokesmfn{at_key}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key associated to the element.
 */
template <typename AssocSeq, typename Key>
using at_key_t = typename at_key<AssocSeq, Key>::type;

/**
 * @relates erythronelumbo::maihuenia::has_key
 *
 * @invokesmfn{has_key}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key to find.
 */
template <typename AssocSeq, typename Key>
using has_key_t = typename has_key<AssocSeq, Key>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MAPPING_HPP
