// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file extensible_mapping.hpp
 *
 * @brief `ExtensibleMapping` typeclass
 *
 * Defines the `ExtensibleMapping` typeclass.
 */

/**
 * @defgroup tc_extensiblemapping ExtensibleMapping
 * @ingroup typeclasses
 *
 * @brief Extensible associative sequences
 *
 * An extension of @ref tc_mapping where insertion and deletion of elements are
 * allowed.
 *
 * ### Minimal complete definition
 *
 * `ainsert<AssocSeq, Key>`, `aerase<AssocSeq, Elem>`, `aclear<AssocSeq>`.
 *
 * @see @ref tc_sequence
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_EXTENSIBLE_MAPPING_HPP
#define ERYTHRONELUMBO_MAIHUENIA_EXTENSIBLE_MAPPING_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/mapping.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_extensiblemapping}
 */
struct ExtensibleMapping ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::ExtensibleMapping, \
    1, \
    (::erythronelumbo::maihuenia::Mapping), \
    ( \
      (ainsert, 0, 2, 0, 0, (0)), \
      (aerase, 0, 2, 0, 0, (0)), \
      (aclear, 0, 1, 0, 0, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_extensiblemapping
 * @brief Inserts an element into an associative sequence
 *
 * Inserts an element into an associative sequence. If the new element (or its
 * key) was already contained, nothing will be done.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Elem
 *   The element to insert. It might be a key-value pair or a plain element,
 *   depending of the kind of sequence.
 *
 * ## Example
 *
 * @include example/individual/extensible_mapping/ainsert.cpp
 */
template <typename AssocSeq, typename Elem>
struct ainsert
{
  /**
   * @brief Result
   *
   * The associative sequence with the new element or key-value pair.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_extensiblemapping
 * @brief Erases an element from an associative sequence
 *
 * Given a key, removes its associated element from an associative sequence. If
 * the key does not exist in the sequence, nothing will be done.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key of the element to remove.
 *
 * ## Example
 *
 * @include example/individual/extensible_mapping/aerase.cpp
 */
template <typename AssocSeq, typename Key>
struct aerase
{
  /**
   * @brief Result
   *
   * The associative sequence, but the element associated with `Key` is removed.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_extensiblemapping
 * @brief *Clears* an associative sequence
 *
 * Creaates an empty version of an associative sequence.
 *
 * @tparam AssocSeq
 *   An associative sequence.
 *
 * ## Example
 *
 * @include example/individual/extensible_mapping/aclear.cpp
 */
template <typename AssocSeq>
struct aclear
{
  /**
   * @brief Result
   *
   * An empty associative sequence of the same type as `AssocSeq`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::ainsert
 *
 * @invokesmfn{ainsert}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Elem
 *   The element to insert. It might be a key-value pair or a plain element,
 *   depending of the kind of sequence.
 */
template <typename AssocSeq, typename Elem>
using ainsert_t = typename ainsert<AssocSeq, Elem>::type;

/**
 * @relates erythronelumbo::maihuenia::aerase
 *
 * @invokesmfn{aerase}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 * @tparam Key
 *   The key of the element to remove.
 */
template <typename AssocSeq, typename Key>
using aerase_t = typename aerase<AssocSeq, Key>::type;

/**
 * @relates erythronelumbo::maihuenia::aclear
 *
 * @invokesmfn{aclear}
 *
 * @tparam AssocSeq
 *   An associative sequence.
 */
template <typename AssocSeq>
using aclear_t = typename aclear<AssocSeq>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_EXTENSIBLE_MAPPING_HPP
