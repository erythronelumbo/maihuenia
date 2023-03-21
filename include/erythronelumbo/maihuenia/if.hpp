// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file if.hpp
 *
 * @brief `if_` utility
 *
 * Defines the `if_` utility metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #if ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION != 0
    namespace detail
    {
      template <bool C>
      struct if_impl_c
      {
        template <typename T1>
        struct r1_
        {
          template <typename T2>
          struct r0_
          {
            using type = T1;
          };
        };
      };

      template <>
      struct if_impl_c<false>
      {
        template <typename T1>
        struct r1_
        {
          template <typename T2>
          struct r0_
          {
            using type = T2;
          };
        };
      };

      template <typename C>
      struct if_impl : if_impl_c<C::value> {};
    } // namespace detail

    template <typename C, typename T, typename F>
    struct if_
    {
      using type = typename detail::if_impl<
        C
      >::template r1_<T>::template r0_<F>::type;
    };

    template <typename C, typename T, typename F>
    using if_t = typename if_<C, T, F>::type;

    template <bool C, typename T, typename F>
    struct if_c
    {
      using type = typename detail::if_impl_c<
        C
      >::template r1_<T>::template r0_<F>::type;
    };

    template <bool C, typename T, typename F>
    using if_c_t = typename if_c<C, T, F>::type;
  #elif ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION == 0
    namespace detail
    {
      template <bool C, typename T, typename F>
      struct if_impl_c
      {
        using type = T;
      };

      template <typename T, typename F>
      struct if_impl_c<false, T, F>
      {
        using type = F;
      };
    } // namespace detail

    template <typename C, typename T, typename F>
    struct if_
    {
      using type = typename detail::if_impl_c<C::value, T, F>::type;
    };

    template <bool C, typename T, typename F>
    using if_c
    {
      using type = typename detail::if_impl_c<C, T, F>::type;
    };

    template <typename C, typename T, typename F>
    using if_t = typename detail::if_impl<C, T, F>::type;

    template <bool C, typename T, typename F>
    using if_c_t = typename detail::if_impl_c<C, T, F>::type;
  #endif // ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION != 0
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup control
 * @brief If-else
 *
 * Selects one of two types, depending on the value of `C`.
 *
 * @defdifffromh
 *
 * @tparam C
 *   An integral constant, corresponding to a Boolean value.
 * @tparam T
 *   The result if `C` has a `true` value.
 * @tparam F
 *   The result if `C` has a `false` value.
 *
 * ## Example
 *
 * @include example/individual/control/if.cpp
 */
template <typename C, typename T, typename F>
struct if_
{
  /**
   * @brief Result
   *
   * `T` if `C` corresponds to a `true` value, `F` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup control
 * @brief If-else
 *
 * Selects one of two types, depending on the value of `C`.
 *
 * @defdifffromh
 *
 * @tparam C
 *   A Boolean value.
 * @tparam T
 *   The result if `C` is `true`.
 * @tparam F
 *   The result if `C` is `false`.
 *
 * ## Example
 *
 * @include example/individual/control/if.cpp
 */
template <bool C, typename T, typename F>
struct if_c
{
  /**
   * @brief Result
   *
   * `T` if `C` is `true`, `F` otherwise.
   */
  using type = unspecified;
};

/**
 * @relates erythronelumbo::maihuenia::if_
 *
 * @invokesmfn{if_}
 *
 * @defdifffromh
 *
 * @tparam C
 *   An integral constant, corresponding to a Boolean value.
 * @tparam T
 *   The result if `C` has a `true` value.
 * @tparam F
 *   The result if `C` has a `false` value.
 */
template <typename C, typename T, typename F>
using if_t = typename if_<C, T, F>::type;

/**
 * @relates erythronelumbo::maihuenia::if_c
 *
 * @invokesmfn{if_c}
 *
 * @defdifffromh
 *
 * @tparam C
 *   A Boolean value.
 * @tparam T
 *   The result if `C` is `true`.
 * @tparam F
 *   The result if `C` is `false`.
 */
template <typename C, typename T, typename F>
using if_c_t = typename if_c<C, T, F>::type;

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_IF_HPP
