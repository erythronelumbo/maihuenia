// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file optional.hpp
 *
 * @brief Optional data type
 *
 * Defines an optional data type.
 */

/**
 * @defgroup dt_misc_optional Option type
 * @ingroup dt_miscellaneous
 *
 * @brief Option type
 *
 * A data type that indicates that it contain a *value* or not, which is useful
 * for results that can be valid or not.
 *
 * ### Models
 *
 * @ref tc_functor, @ref tc_applicative, @ref tc_monad
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_OPTIONAL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_OPTIONAL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_misc_optional}
 */
struct optional_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_misc_optional
 * @brief Optional with value
 *
 * Corresponds to the case where an instance of an @ref dt_misc_optional has
 * a value type.
 *
 * @tparam T
 *   The contained value type.
 */
template <typename T>
struct some
{
  /**
   * @mfncalltoitself
   */
  using type = some;

  /**
   * @memtypetag
   */
  using tag = optional_tag;

  /**
   * @brief Contained element
   *
   * The contained element.
   */
  using elem = T;
};

/**
 * @ingroup dt_misc_optional
 * @brief Optional with no value
 *
 * Corresponds to the case where an instance of an @ref dt_misc_optional does
 * not have a value type.
 */
struct none
{
  /**
   * @mfncalltoitself
   */
  using type = none;

  /**
   * @memtypetag
   */
  using tag = optional_tag;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename, typename>
  struct optional_eq : false_ {};

  template <typename T1, typename T2>
  struct optional_eq<some<T1>, some<T2>> : equals<T1, T2> {};

  template <typename T>
  struct optional_eq<some<T>, none> : false_ {};

  template <typename T>
  struct optional_eq<none, some<T>> : false_ {};
} // namespace detail


template <>
struct typeclass<Comparable>::define_for<optional_tag, optional_tag> : true_
{
  template <typename X1, typename X2>
  struct equals_impl : detail::optional_eq<X1, X2> {};

  template <typename X1, typename X2>
  struct not_equals_impl : bool_<!detail::optional_eq<X1, X2>::type::value> {};
};


template <>
struct typeclass<Functor>::define_for<optional_tag> : true_
{
  template <typename, typename>
  struct transform_impl;

  template <typename Fn, typename T>
  struct transform_impl<Fn, some<T>> :
    some<typename Fn::template apply<T>::type>
  {};

  template <typename Fn>
  struct transform_impl<Fn, none> : none {};
};


template <>
struct typeclass<Applicative>::define_for<optional_tag> : true_
{
  template <typename T>
  struct lift_impl : some<T> {};

  template <typename F1, typename F2>
  struct ap_impl;

  template <typename Fn, typename T>
  struct ap_impl<some<Fn>, some<T>> :
    some<typename Fn::template apply<T>::type>
  {};

  template <typename Fn>
  struct ap_impl<some<Fn>, none> : none {};

  template <typename T>
  struct ap_impl<none, T> : none {};
};


template <>
struct typeclass<Monad>::define_for<optional_tag> : true_
{
  template <typename, typename>
  struct mbind_impl;

  template <typename T, typename Fn>
  struct mbind_impl<some<T>, Fn> : Fn::template apply<T>::type {};

  template <typename Fn>
  struct mbind_impl<none, Fn> : none {};
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_OPTIONAL_HPP
