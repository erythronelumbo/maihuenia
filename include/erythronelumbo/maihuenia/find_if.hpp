// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file find_if.hpp
 *
 * @brief `find_if` and `find` metafunctions
 *
 * Defines the `find_if` and `find` metafunctions.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FIND_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FIND_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename It, typename UnaryPredicate, ::std::size_t Idx,
    bool = empty_t<It>::value
  >
  struct find_if_impl :
    eval_if<
      typename UnaryPredicate::template apply<front_t<It>>::type,
      some<size_c<Idx>>,
      find_if_impl<pop_front_t<It>, UnaryPredicate, Idx + 1>
    >
  {};

  template <typename It, typename UnaryPredicate, ::std::size_t Idx>
  struct find_if_impl<It, UnaryPredicate, Idx, true> :
    none
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Finds the position of an item satisfying a given condition
 *
 * Finds the position of the first element from an @ref tc_iterable that
 * satisfies the condition given by an unary predicate.
 *
 * @see @ref contains
 * @see @ref find
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam UnaryPredicate
 *   An unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/find_if.cpp
 */
template <typename It, typename UnaryPredicate>
struct find_if
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::find_if_impl<It, UnaryPredicate, 0> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * An @ref dt_misc_optional : `some<size_c<Idx>>` if an element was found in
   * the `(Idx + 1)`-th position, @ref none otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @ingroup alg_querying
 * @brief Finds the position of an element.
 *
 * Finds the position of the first ocurrence of an element in a given
 * @ref tc_iterable.
 *
 * @see @ref at_key
 * @see @ref contains
 * @see @ref find_if
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Elem
 *   The element to be found.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/find.cpp
 */
template <typename It, typename Elem>
struct find
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::find_if_impl< \
      It, typename curry_quote<equal_types, 2>::template apply<Elem>, 0 \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * An @ref dt_misc_optional : `some<size_c<Idx>>` if the element was found in
   * the `(Idx + 1)`-th position, @ref none otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::find_if
 *
 * @invokesmfn{find_if}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam UnaryPredicate
 *   An unary predicate.
 */
template <typename It, typename UnaryPredicate>
using find_if_t = typename find_if<It, UnaryPredicate>::type;


/**
 * @relates erythronelumbo::maihuenia::find
 *
 * @invokesmfn{find}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Item
 *   The element to be found.
 */
template <typename It, typename Item>
using find_t = typename find<It, Item>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FIND_IF_HPP
