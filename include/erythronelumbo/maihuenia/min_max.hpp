// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file min_max.hpp
 *
 * @brief `min` and `max` metafunctions
 *
 * Defines the `min` and `max` metafunctions.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/orderable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename X1, typename X2>
  struct min_two : if_<typename less<X1, X2>::type, X1, X2> {};

  template <typename X1, typename X2>
  struct max_two : if_<typename less<X2, X1>::type, X1, X2> {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup tc_orderable
 * @brief Minimum
 *
 * Computes the minimum of several @ref tc_orderable elements.
 *
 * @note This metafunction is not defined as an intrinsic operation of
 * @ref tc_orderable, but it is documented as such for convenience.
 *
 * @see @ref less
 * @see @ref min_element
 *
 * @tparam X1, Xs...
 *   @ref tc_orderable elements.
 *
 * ## Example
 *
 * @include example/individual/orderable/min.cpp
 */
template <typename X1, typename... Xs>
struct min
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : bin_op_many_c<detail::min_two, false, X1, Xs...> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The minimum of all the supplied elements.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::min
 *
 * @invokesmfn{min}
 *
 * @tparam X1, Xs...
 *   @ref tc_orderable elements.
 */
template <typename X1, typename... Xs>
using min_t = typename min<X1, Xs...>::type;


/**
 * @ingroup tc_orderable
 * @brief Maximum
 *
 * Computes the maximum of several @ref tc_orderable elements.
 *
 * @note This metafunction is not defined as an intrinsic operation of
 * @ref tc_orderable, but it is documented as such for convenience.
 *
 * @see @ref greater
 * @see @ref max_element
 *
 * @tparam X1, Xs...
 *   @ref tc_orderable elements.
 *
 * ## Example
 *
 * @include example/individual/orderable/max.cpp
 */
template <typename X1, typename... Xs>
struct max
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : bin_op_many_c<detail::max_two, false, X1, Xs...> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The maximum of all the supplied elements.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::max
 *
 * @invokesmfn{max}
 *
 * @tparam X1, Xs...
 *   @ref tc_orderable elements.
 */
template <typename X1, typename... Xs>
using max_t = typename max<X1, Xs...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MIN_MAX_HPP
