// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file eval_if.hpp
 *
 * @brief `eval_if` utility
 *
 * Defines the `eval_if` utility metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_EVAL_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_EVAL_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #if ERYTHRONELUMBO_MAIHUENIA_NESTED_EVAL_IF_DEFINITION != 0
    namespace detail
    {
      template <bool C>
      struct eval_if_impl_c
      {
        template <typename F1>
        struct r1_
        {
          template <typename F2>
          struct r0_
          {
            using type = typename F1::type;
          };
        };
      };

      template <>
      struct eval_if_impl_c<false>
      {
        template <typename F1>
        struct r1_
        {
          template <typename F2>
          struct r0_
          {
            using type = typename F2::type;
          };
        };
      };

      template <typename C>
      struct eval_if_impl : eval_if_impl_c<C::value> {};
    } // namespace detail


    template <typename C, typename F1, typename F2>
    struct eval_if
    {
      using type = typename detail::eval_if_impl<
        C
      >::template r1_<F1>::template r0_<F2>::type;
    };

    template <typename C, typename F1, typename F2>
    using eval_if_t = typename detail::eval_if_impl<
      C
    >::template r1_<F1>::template r0_<F2>::type;


    template <bool C, typename F1, typename F2>
    struct eval_if_c
    {
      using type = typename detail::eval_if_impl_c<
        C
      >::template r1_<F1>::template r0_<F2>::type;
    };

    template <bool C, typename F1, typename F2>
    using eval_if_c_t = typename detail::eval_if_impl_c<
      C
    >::template r1_<F1>::template r0_<F2>::type;
  #elif ERYTHRONELUMBO_MAIHUENIA_NESTED_EVAL_IF_DEFINITION == 0
    namespace detail
    {
      template <bool C, typename F1, typename F2>
      struct eval_if_impl_c
      {
        using type = typename F1::type;
      };

      template <typename F1, typename F2>
      struct eval_if_impl_c<false, F1, F2>
      {
        using type = typename F2::type;
      };
    } // namespace detail


    template <typename C, typename F1, typename F2>
    struct eval_if
    {
      using type = typename detail::eval_if_impl_c<C::value, F1, F2>::type;
    };

    template <typename C, typename F1, typename F2>
    using eval_if_t = typename detail::eval_if_impl<C, F1, F2>::type;


    template <bool C, typename F1, typename F2>
    struct eval_if_c
    {
      using type = typename detail::eval_if_impl_c<C, F1, F2>::type;
    };

    template <bool C, typename F1, typename F2>
    using eval_if_c_t = typename detail::eval_if_impl_c<C, F1, F2>::type;
  #endif
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup control
 * @brief Conditional evaluation of metafunctions
 *
 * Evaluates one of the two metafunctions given in `F1` and `F2`, depending on
 * the value of `C`.
 *
 * @defdifffromh
 *
 * @tparam C
 *   An integral constant, corresponding to a Boolean value.
 * @tparam F1
 *   The result if `C` has a `true` value.
 * @tparam F2
 *   The result if `C` has a `false` value.
 *
 * ## Example
 *
 * @include example/individual/control/eval_if.cpp
 */
template <typename C, typename F1, typename F2>
struct eval_if
{
  using type = unspecified;
};

/**
 * @ingroup control
 * @brief Conditional evaluation of metafunctions
 *
 * Evaluates one of the two metafunctions given in `F1` and `F2`, depending on
 * the value of `C`.
 *
 * @defdifffromh
 *
 * @tparam C
 *   A Boolean value.
 * @tparam F1
 *   The result if `C` is `true`.
 * @tparam F2
 *   The result if `C` is `false`.
 *
 * ## Example
 *
 * @include example/individual/control/eval_if.cpp
 */
template <bool C, typename F1, typename F2>
struct eval_if_c
{
  using type = unspecified;
};

/**
 * @relates erythronelumbo::maihuenia::eval_if
 *
 * @invokesmfn{eval_if}
 *
 * @defdifffromh
 *
 * @tparam C
 *   An integral constant, corresponding to a Boolean value.
 * @tparam F1
 *   The result if `C` has a `true` value.
 * @tparam F2
 *   The result if `C` has a `false` value.
 */
template <typename C, typename F1, typename F2>
using eval_if_t = typename eval_if<C, F1, F2>::type;

/**
 * @relates erythronelumbo::maihuenia::eval_if_c
 *
 * @invokesmfn{eval_if_c}
 *
 * @defdifffromh
 *
 * @tparam C
 *   A Boolean value.
 * @tparam F1
 *   The result if `C` is `true`.
 * @tparam F2
 *   The result if `C` is `false`.
 */
template <bool C, typename F1, typename F2>
using eval_if_c_t = typename eval_if_c<C, F1, F2>::type;

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_EVAL_IF_HPP
