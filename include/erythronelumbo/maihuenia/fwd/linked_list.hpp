// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief Linked list
 *
 * Defines a linked list data type.
 */

/**
 * @defgroup dt_seq_linkedlist Linked list
 * @ingroup dt_sequences
 *
 * @brief Linked list
 *
 * Defines a singly linked list, which is composed of *nodes* (represented by
 * `cons`) containing an element and a *tail*, which can be another node or
 * a nullary element (represented by `null_type`).
 * 
 * ### Models
 * @ref tc_iterable, @ref tc_sequence, @ref tc_monoid, @ref tc_functor,
 * @ref tc_applicative, @ref tc_monad, @ref tc_monadplus, @ref tc_foldable
 *
 * ## Example
 *
 * @include example/individual/sequences/linked_list.cpp
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_LINKED_LIST_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_LINKED_LIST_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>


namespace erythronelumbo { namespace maihuenia
{


/**
 * @typetag_group{dt_seq_linkedlist}
 */
struct linked_list_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_linkedlist
 * @brief Null type
 *
 * A data type that acts like an empty linked list.
 *
 * @see @ref cons
 */
struct null_type
{
  /**
   * @mfncalltoitself
   */
  using type = null_type;

  /**
   * @memtypetag
   */
  using tag = linked_list_tag;

  /**
   * @brief Head of the list
   *
   * Undefined result, since empty lists have no elements. Used for convenience.
   */
  using head = undefined;

  /**
   * @brief Tail of the list
   * 
   * An empty list. Used for convenience.
   */
  using tail = null_type;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <typename, typename = null_type>
  struct cons;

  template <typename Head, typename Second, typename Tail>
  struct cons<Head, cons<Second, Tail>>
  {
    using type = cons;
    using tag  = linked_list_tag;
    using head = Head;
    using tail = cons<Second, Tail>;
  };

  template <typename Head>
  struct cons<Head, null_type>
  {
    using type = cons;
    using tag  = linked_list_tag;
    using head = Head;
    using tail = null_type;
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup dt_seq_linkedlist
 * @brief Node of a linked list
 *
 * The node of a singly linked list. It contains an element and the next nodes
 * of the list.
 *
 * @see @ref null_type
 *
 * @tparam Head
 *   The contained element.
 * @tparam Tail
 *   The following nodes of the list. It **must** be an instance of `cons` or
 *   `null_type`; otherwise, the current instance of `cons` is undefined.
 */
template <typename Head, typename Tail = null_type>
struct cons
{
  /**
   * @mfncalltoitself
   */
  using type = cons;

  /**
   * @memtypetag
   */
  using tag = linked_list_tag;

  /**
   * @brief Head of the list
   *
   * The *head* (or first) element of the list.
   */
  using head = Head;

  /**
   * @brief Tail of the list
   * 
   * The tail (or the following elements) of the list.
   */
  using tail = Tail;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_LINKED_LIST_HPP
