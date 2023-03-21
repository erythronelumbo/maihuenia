// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file contains.hpp
 *
 * @brief `contains` metafunction
 *
 * Defines the `contains` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_CONTAINS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_CONTAINS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename It, typename Elem, bool = empty_t<It>::value>
  struct contains_helper :
    eval_if<
      typename equal_types<front_t<It>, Elem>::type,
      true_,
      contains_helper<pop_front_t<It>, Elem>
    >
  {};

  template <typename It, typename Elem>
  struct contains_helper<It, Elem, true>
  {
    using type = false_;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks the presence of an element in an iterable.
 *
 * Checks if an @ref tc_iterable contains one or more instances of an element
 * or not.
 *
 * @see @ref has_key
 * @see @ref count
 * @see @ref count_if
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Elem
 *   The element to find.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/contains.cpp
 */
template <typename It, typename Elem>
struct contains
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::contains_helper<It, Elem> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_` : `true_` if the sequence contains the `Elem`, `false_`
   * otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::contains
 *
 * @invokesmfn{contains}
 *
 * @tparam It
 *   An @ref tc_iterable.
 * @tparam Elem
 *   The element to find.
 */
template <typename It, typename Elem>
using contains_t = typename contains<It, Elem>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_CONTAINS_HPP
