// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file replace_if.hpp
 *
 * @brief `replace_if` metafunction
 *
 * Defines the `replace_if` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_REPLACE_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_REPLACE_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Pred, typename NewElem>
  struct replace_if_fn
  {
    template <typename Res, typename X>
    using apply = push_back<
      Res,
      if_t<
        typename Pred::template apply<X>::type,
        NewElem, X
      >
    >;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Replaces elements according to a condition
 *
 * Replaces all the elements from a sequence that satisfy a condition, given by
 * an unary predicate, to another new one.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Pred
 *   The unary predicate.
 * @tparam NewElem
 *   The new element.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/replace_if.cpp
 */
template <typename Seq, typename Pred, typename NewElem>
struct replace_if
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial< \
      detail::replace_if_fn<Pred, NewElem>, Seq, clear_t<Seq> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, but all the elements that satisfied
   * `Pred` are replaced by `NewElem`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::replace_if
 *
 * @invokesmfn{replace_if}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Pred
 *   The unary predicate.
 * @tparam NewElem
 *   The new element.
 */
template <typename Seq, typename Pred, typename NewElem>
using replace_if_t = typename replace_if<Seq, Pred, NewElem>::type;


/**
 * @ingroup alg_transformation
 * @brief Replaces an element
 *
 * Replaces all the instances of an element from a sequence to another one.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam OldElem
 *   The element to be replaced.
 * @tparam NewElem
 *   The new element.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/replace.cpp
 */
template <typename Seq, typename OldElem, typename NewElem>
struct replace
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial< \
      detail::replace_if_fn< \
        typename curry_quote<equal_types, 2>::template apply<OldElem>, \
        NewElem \
      >, \
      Seq, clear_t<Seq> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, but all the instances of `OldElem`
   * are replaced by `NewElem`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::replace
 *
 * @invokesmfn{replace}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam OldElem
 *   The element to be replaced.
 * @tparam NewElem
 *   The new element.
 */
template <typename Seq, typename OldElem, typename NewElem>
using replace_t = typename replace<Seq, OldElem, NewElem>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_REPLACE_IF_HPP
