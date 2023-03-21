// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file inherit.hpp
 *
 * @brief `inherit` metafunction
 *
 * Defines the `inherit` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INHERIT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INHERIT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/empty_base.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename T>
  inline constexpr identity<T> inherit_fail_if_not_class_fn(void* T::*);

  template <typename T>
  inline constexpr identity<invalid_argument>
  inherit_fail_if_not_class_fn(...);

  template <typename T>
  struct inherit_fail_if_not_class :
    decltype(inherit_fail_if_not_class_fn<T>(nullptr))
  {};

  template <typename T>
  using inherit_fail_if_not_class_t = typename inherit_fail_if_not_class<
    T
  >::type;


  template <typename T1, typename T2>
  struct inherit_two { struct type : T1, T2 {}; };

  template <typename T1>
  struct inherit_two<T1, empty_base> { struct type : T1 {}; };

  template <typename T2>
  struct inherit_two<empty_base, T2> { struct type : T2 {}; };

  template <typename X>
  struct inherit_two<X, invalid_argument>
  {
    using type = invalid_argument;
  };

  template <typename X>
  struct inherit_two<invalid_argument, X>
  {
    using type = invalid_argument;
  };

  template <>
  struct inherit_two<empty_base, empty_base> { using type = empty_base; };

  template <>
  struct inherit_two<invalid_argument, invalid_argument>
  {
    using type = invalid_argument;
  };
} // namespace detail


template <typename...>
struct inherit;

template <> struct inherit<> { using type = empty_base; };

template <typename T> struct inherit<T> :
  detail::inherit_two<detail::inherit_fail_if_not_class_t<T>, empty_base>
{};

template <> struct inherit<empty_base> { using type = empty_base; };

template <typename T, typename... Ts>
struct inherit<T, Ts...> :
  bin_op_many_c<
    detail::inherit_two, false,
    detail::inherit_fail_if_not_class_t<T>,
    detail::inherit_fail_if_not_class_t<Ts>...
  >
{};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup mfn_miscellaneous
 * @brief Creates a class type derived from other classes
 *
 * Crates a class type that inherits from the supplied classes. If one or more
 * @ref empty_base s are supplied, the resulting class type will not derive from
 * them.
 *
 * This metafunction has the following semantics:
 * ```
 * typename inherit<>::type == empty_base
 * typename inherit<T1>::type == struct ... : T1 {}
 * typename inherit<empty_base>::type == empty_base
 * typename inherit<T1, T2>::type == struct ... : T1, T2 {}
 * typename inherit<T1, empty_base>::type == struct ... : T1 {}
 * typename inherit<empty_base, T2>::type == struct ... : T2 {}
 * typename inherit<empty_base, empty_base>::type == empty_base
 * typename inherit<T1, T2, Ts...>::type
 * == struct ... : inherit<typename inherit<T1, T2>::type, Ts...>::type {}
 * typename inherit<T1, ..., non_class, ..., Ts...>::type
 * == invalid_argument
 * ```
 *
 * @tparam Ts...
 *   The base classes.
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/inherit.cpp
 */
template <typename... Ts>
struct inherit
{
  /**
   * @brief Result
   *
   * A `struct` that derives from all or some of the classes given in `Ts...` or
   * @ref empty_base in some cases. If at least one argument is not a class, it
   * will result in an `invalid_argument` error.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @relates erythronelumbo::maihuenia::inherit
 *
 * @invokesmfn{inherit}
 *
 * @tparam Ts...
 *   The base classes.
 */
template <typename... Ts>
using inherit_t = typename inherit<Ts...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_INHERIT_HPP
