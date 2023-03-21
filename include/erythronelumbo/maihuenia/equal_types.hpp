// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file equal_types.hpp
 *
 * @brief `equal_types` utility
 *
 * Defines the `equal_types` utility metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_EQUAL_TYPES_HPP
#define ERYTHRONELUMBO_MAIHUENIA_EQUAL_TYPES_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename T0, typename T1> struct equal_types_two : false_ {};
  template <typename T0> struct equal_types_two<T0, T0> : true_ {};

  template <typename T>
  struct equal_to_single_type
  {
    template <typename...> struct result_;

    template <
      typename U0, typename U1, typename U2, typename U3,
      typename U4, typename U5, typename U6, typename U7,
      typename... Us
    >
    struct result_<U0, U1, U2, U3, U4, U5, U6, U7, Us...> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value &&
        equal_types_two<T, U4>::type::value &&
        equal_types_two<T, U5>::type::value &&
        equal_types_two<T, U6>::type::value &&
        equal_types_two<T, U7>::type::value &&
        result_<Us...>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2, typename U3,
      typename U4, typename U5, typename U6, typename U7
    >
    struct result_<U0, U1, U2, U3, U4, U5, U6, U7> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value &&
        equal_types_two<T, U4>::type::value &&
        equal_types_two<T, U5>::type::value &&
        equal_types_two<T, U6>::type::value &&
        equal_types_two<T, U7>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2, typename U3,
      typename U4, typename U5, typename U6
    >
    struct result_<U0, U1, U2, U3, U4, U5, U6> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value &&
        equal_types_two<T, U4>::type::value &&
        equal_types_two<T, U5>::type::value &&
        equal_types_two<T, U6>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2, typename U3,
      typename U4, typename U5
    >
    struct result_<U0, U1, U2, U3, U4, U5> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value &&
        equal_types_two<T, U4>::type::value &&
        equal_types_two<T, U5>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2, typename U3,
      typename U4
    >
    struct result_<U0, U1, U2, U3, U4> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value &&
        equal_types_two<T, U4>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2, typename U3
    >
    struct result_<U0, U1, U2, U3> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value &&
        equal_types_two<T, U3>::type::value
      >
    {};

    template <
      typename U0, typename U1, typename U2
    >
    struct result_<U0, U1, U2> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value &&
        equal_types_two<T, U2>::type::value
      >
    {};

    template <
      typename U0, typename U1
    >
    struct result_<U0, U1> :
      bool_<
        equal_types_two<T, U0>::type::value &&
        equal_types_two<T, U1>::type::value
      >
    {};

    template <
      typename U0
    >
    struct result_<U0> :
      equal_types_two<T, U0>
    {};
  };


  template <typename...>
  struct equal_types_helper;

  template <
    typename T0, typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6, typename T7,
    typename... Ts
  >
  struct equal_types_helper<T0, T1, T2, T3, T4, T5, T6, T7, Ts...> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3, T4, T5, T6, T7, Ts...
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3, T4, T5, T6, T7, Ts...
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3, T4, T5, T6, T7, Ts...
      >::value &&
      equal_to_single_type<T3>::template result_<
        T4, T5, T6, T7, Ts...
      >::value &&
      equal_to_single_type<T4>::template result_<
        T5, T6, T7, Ts...
      >::value &&
      equal_to_single_type<T5>::template result_<
        T6, T7, Ts...
      >::value &&
      equal_to_single_type<T6>::template result_<
        T7, Ts...
      >::value &&
      equal_to_single_type<T7>::template result_<
        Ts...
      >::value &&
      equal_types_helper<Ts...>::value
    >
  {};

  template <
    typename T0, typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6, typename T7
  >
  struct equal_types_helper<T0, T1, T2, T3, T4, T5, T6, T7> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3, T4, T5, T6, T7
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3, T4, T5, T6, T7
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3, T4, T5, T6, T7
      >::value &&
      equal_to_single_type<T3>::template result_<
        T4, T5, T6, T7
      >::value &&
      equal_to_single_type<T4>::template result_<
        T5, T6, T7
      >::value &&
      equal_to_single_type<T5>::template result_<
        T6, T7
      >::value &&
      equal_to_single_type<T6>::template result_<
        T7
      >::value
    >
  {};

  template <
    typename T0, typename T1, typename T2, typename T3,
    typename T4, typename T5, typename T6
  >
  struct equal_types_helper<T0, T1, T2, T3, T4, T5, T6> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3, T4, T5, T6
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3, T4, T5, T6
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3, T4, T5, T6
      >::value &&
      equal_to_single_type<T3>::template result_<
        T4, T5, T6
      >::value &&
      equal_to_single_type<T4>::template result_<
        T5, T6
      >::value &&
      equal_to_single_type<T5>::template result_<
        T6
      >::value
    >
  {};

  template <
    typename T0, typename T1, typename T2, typename T3,
    typename T4, typename T5
  >
  struct equal_types_helper<T0, T1, T2, T3, T4, T5> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3, T4, T5
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3, T4, T5
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3, T4, T5
      >::value &&
      equal_to_single_type<T3>::template result_<
        T4, T5
      >::value &&
      equal_to_single_type<T4>::template result_<
        T5
      >::value
    >
  {};

  template <
    typename T0, typename T1, typename T2, typename T3,
    typename T4
  >
  struct equal_types_helper<T0, T1, T2, T3, T4> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3, T4
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3, T4
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3, T4
      >::value &&
      equal_to_single_type<T3>::template result_<
        T4
      >::value
    >
  {};

  template <
    typename T0, typename T1, typename T2, typename T3
  >
  struct equal_types_helper<T0, T1, T2, T3> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2, T3
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2, T3
      >::value &&
      equal_to_single_type<T2>::template result_<
        T3
      >::value
    >
  {};

  template <
    typename T0, typename T1, typename T2
  >
  struct equal_types_helper<T0, T1, T2> :
    bool_<
      equal_to_single_type<T0>::template result_<
        T1, T2
      >::value &&
      equal_to_single_type<T1>::template result_<
        T2
      >::value
    >
  {};

  template <typename T0, typename T1>
  struct equal_types_helper<T0, T1> :
    false_
  {};

  template <typename T0>
  struct equal_types_helper<T0, T0> :
    true_
  {};

  template <typename T0>
  struct equal_types_helper<T0> :
    true_
  {};

  template <>
  struct equal_types_helper<>
  {
    using type = undefined;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup mfn_core
 * @brief Checks equality of types
 *
 * Check if several types are the same.
 *
 * @tparam Ts...
 *   The types to check.
 *
 * ## Example
 *
 * @include example/individual/core/equal_types.cpp
 */
template <typename... Ts>
struct equal_types
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A `bool_`: `true_` if all the types are equal, `false_` otherwise.
   */
  using type = unspecified;

  #else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  using type = typename detail::equal_types_helper<Ts...>::type;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::equal_types
 *
 * @invokesmfn{equal_types}
 *
 * @tparam Ts...
 *   The types to check.
 */
template <typename... Ts>
using equal_types_t = typename equal_types<Ts...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_EQUAL_TYPES_HPP
