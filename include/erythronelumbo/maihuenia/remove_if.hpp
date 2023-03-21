// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file remove_if.hpp
 *
 * @brief `remove_if` and `remove` metafunctions
 *
 * Defines the `remove_if` and `remove` metafunctions.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_REMOVE_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_REMOVE_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Pred>
  struct remove_if_fn
  {
    template <typename Res, typename X>
    using apply = concat<
      Res,
      eval_if_t<
        typename Pred::template apply<X>::type,
        clear<Res>,
        make_seq<typename tag<Res>::type, X>
      >
    >;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Removes elements according to a condition
 *
 * Removes the elements from a @ref tc_sequence that satisfy a condition,
 * indicated by an unary predicate.
 *
 * @see @ref partition
 * @see @ref remove
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Pred
 *   The unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/remove_if.cpp
 */
template <typename Seq, typename Pred>
struct remove_if
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial<detail::remove_if_fn<Pred>, Seq, clear_t<Seq>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, but the elements that satisfied the
   * conditions given by `Pred` are removed.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::remove_if
 *
 * @invokesmfn{remove_if}
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Pred
 *   The unary predicate.
 */
template <typename Seq, typename Pred>
using remove_if_t = typename remove_if<Seq, Pred>::type;


/**
 * @ingroup alg_transformation
 * @brief Removes an element
 *
 * Removes all the instances of a given element from a @ref tc_sequence.
 *
 * @see @ref remove_if
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Elem
 *   The element to remove.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/remove.cpp
 */
template <typename Seq, typename Elem>
struct remove
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial< \
      detail::remove_if_fn< \
        typename curry_quote<equal_types, 2>::template apply<Elem> \
      >, \
      Seq, clear_t<Seq> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, but the instances of the specified
   * element are removed.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::remove
 *
 * @invokesmfn{remove}
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Elem
 *   The element to remove.
 */
template <typename Seq, typename Elem>
using remove_t = typename remove<Seq, Elem>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_REMOVE_IF_HPP
