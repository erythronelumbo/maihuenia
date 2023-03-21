// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file has_repeated.hpp
 *
 * @brief `has_repeated` metafunction
 *
 * Defines the `has_repeated` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_HAS_REPEATED_HPP
#define ERYTHRONELUMBO_MAIHUENIA_HAS_REPEATED_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename It, bool = empty_t<It>::value>
  struct has_repeated_helper :
    eval_if<
      contains_t<pop_front_t<It>, front_t<It>>,
      true_,
      has_repeated_helper<pop_front_t<It>>
    >
  {};

  template <typename It>
  struct has_repeated_helper<It, true>
  {
    using type = false_;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_querying
 * @brief Checks if an iterable has repeated elements
 *
 * Checks if an @ref tc_iterable has more than one instances of any element,
 * i.e., has repeated elements.
 *
 * @see @ref count
 *
 * @tparam It
 *   The @ref tc_iterable to check.
 *
 * ## Example
 *
 * @include example/individual/alg_querying/has_repeated.cpp
 */
template <typename It>
struct has_repeated
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN(: detail::has_repeated_helper<It>)
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_`: `true_` if `It` has repeated elements, `false_` otherwise.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @related erythronelumbo::maihuenia::has_repeated
 *
 * @invokesmfn{has_repeated}
 *
 * @tparam It
 *   The @ref tc_iterable to check.
 */
template <typename It>
using has_repeated_t = typename has_repeated<It>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_HAS_REPEATED_HPP
