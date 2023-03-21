// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file count_if.hpp
 *
 * @brief `count_if` and `count` metafunctions
 *
 * Defines the `count_if` and `count` metafunctions.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_COUNT_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_COUNT_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Pred>
  struct count_if_fn
  {
    template <typename Xa, typename Xb>
    using apply = if_<typename Pred::template apply<Xb>::type, incr_t<Xa>, Xa>;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Counts elements that satisfy a given condition
 *
 * Counts how many elements in an @ref tc_iterable satisfy a condition, which is
 * determined by an unary predicate.
 *
 * @see @ref contains
 * @see @ref count
 * @see @ref count_while
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   A metafunction class corresponding to the unary predicate.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/count_if.cpp
 */
template <typename It, typename Pred>
struct count_if
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial<detail::count_if_fn<Pred>, It, size_c<0>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `size_c` with the number of elements satisfying `Pred`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::count_if
 *
 * @invokesmfn{count_if}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Pred
 *   A metafunction class corresponding to the unary predicate.
 */
template <typename It, typename Pred>
using count_if_t = typename count_if<It, Pred>::type;


/**
 * @ingroup alg_querying
 * @brief Counts ocurrences of an element
 *
 * Counts how many times an element appears in an @ref tc_iterable.
 * 
 * @see @ref contains
 * @see @ref count_if
 * @see @ref count_while
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Elem
 *   The element which ocurrences will be counted.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/count.cpp
 */
template <typename It, typename Elem>
struct count
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : fold_left_initial< \
      detail::count_if_fn< \
        typename curry_quote<equal_types, 2>::template apply<Elem> \
      >, \
      It, size_c<0> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `size_c` with the number of ocurrences of the given element.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::count
 *
 * @invokesmfn{count}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Elem
 *   The element which ocurrences will be counted.
 */
template <typename It, typename Elem>
using count_t = typename count<It, Elem>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_COUNT_IF_HPP
