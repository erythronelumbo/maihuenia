// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file compose.hpp
 *
 * @brief `compose` metafunction class
 *
 * Defines the `compose` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_COMPOSE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_COMPOSE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename...>
  struct compose_helper;

  template <
    typename Fn0, typename Fn1, typename Fn2, typename Fn3,
    typename Fn4, typename Fn5, typename Fn6, typename Fn7,
    typename... Fns
  >
  struct compose_helper<Fn0, Fn1, Fn2, Fn3, Fn4, Fn5, Fn6, Fn7, Fns...>
  {
    template <typename X>
    struct apply :
      compose_helper<Fns...>::template apply<
        typename Fn7::template apply<
          typename Fn6::template apply<
            typename Fn5::template apply<
              typename Fn4::template apply<
                typename Fn3::template apply<
                  typename Fn2::template apply<
                    typename Fn1::template apply<
                      typename Fn0::template apply<
                        X
                      >::type
                    >::type
                  >::type
                >::type
              >::type
            >::type
          >::type
        >::type
      >
    {};
  };

  template <
    typename Fn0, typename Fn1, typename Fn2, typename Fn3,
    typename Fn4, typename Fn5, typename Fn6, typename Fn7
  >
  struct compose_helper<Fn0, Fn1, Fn2, Fn3, Fn4, Fn5, Fn6, Fn7>
  {
    template <typename X>
    struct apply :
      Fn7::template apply<
        typename Fn6::template apply<
          typename Fn5::template apply<
            typename Fn4::template apply<
              typename Fn3::template apply<
                typename Fn2::template apply<
                  typename Fn1::template apply<
                    typename Fn0::template apply<
                      X
                    >::type
                  >::type
                >::type
              >::type
            >::type
          >::type
        >::type
      >
    {};
  };

  template <
    typename Fn0, typename Fn1, typename Fn2, typename Fn3,
    typename Fn4, typename Fn5, typename Fn6
  >
  struct compose_helper<Fn0, Fn1, Fn2, Fn3, Fn4, Fn5, Fn6>
  {
    template <typename X>
    struct apply :
      Fn6::template apply<
        typename Fn5::template apply<
          typename Fn4::template apply<
            typename Fn3::template apply<
              typename Fn2::template apply<
                typename Fn1::template apply<
                  typename Fn0::template apply<
                    X
                  >::type
                >::type
              >::type
            >::type
          >::type
        >::type
      >
    {};
  };

  template <
    typename Fn0, typename Fn1, typename Fn2, typename Fn3,
    typename Fn4, typename Fn5
  >
  struct compose_helper<Fn0, Fn1, Fn2, Fn3, Fn4, Fn5>
  {
    template <typename X>
    struct apply :
      Fn5::template apply<
        typename Fn4::template apply<
          typename Fn3::template apply<
            typename Fn2::template apply<
              typename Fn1::template apply<
                typename Fn0::template apply<
                  X
                >::type
              >::type
            >::type
          >::type
        >::type
      >
    {};
  };

  template <
    typename Fn0, typename Fn1, typename Fn2, typename Fn3,
    typename Fn4
  >
  struct compose_helper<Fn0, Fn1, Fn2, Fn3, Fn4>
  {
    template <typename X>
    struct apply :
      Fn4::template apply<
        typename Fn3::template apply<
          typename Fn2::template apply<
            typename Fn1::template apply<
              typename Fn0::template apply<
                X
              >::type
            >::type
          >::type
        >::type
      >
    {};
  };

  template <typename Fn0, typename Fn1, typename Fn2, typename Fn3>
  struct compose_helper<Fn0, Fn1, Fn2, Fn3>
  {
    template <typename X>
    struct apply :
      Fn3::template apply<
        typename Fn2::template apply<
          typename Fn1::template apply<
            typename Fn0::template apply<
              X
            >::type
          >::type
        >::type
      >
    {};
  };

  template <typename Fn0, typename Fn1, typename Fn2>
  struct compose_helper<Fn0, Fn1, Fn2>
  {
    template <typename X>
    struct apply :
      Fn2::template apply<
        typename Fn1::template apply<
          typename Fn0::template apply<
            X
          >::type
        >::type
      >
    {};
  };

  template <typename Fn0, typename Fn1>
  struct compose_helper<Fn0, Fn1>
  {
    template <typename X>
    struct apply :
      Fn1::template apply<
        typename Fn0::template apply<
          X
        >::type
      >
    {};
  };

  template <typename Fn0>
  struct compose_helper<Fn0> :
    Fn0
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <typename... Fns>
  struct compose :
    detail::compose_helper<Fns...>
  {
    using type = compose;
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup functional
 * @brief Composition of metafunction classes
 *
 * A metafunction class that is created by composing several unary metafunction
 * classes.
 *
 * @tparam Fns... Unary metafunction classes.
 *
 * ## Example
 *
 * @include example/individual/functional/compose.cpp
 */
template <typename... Fns>
struct compose
{
  /**
   * @mfncalltoitself
   */
  using type = compose;

  /**
   * @brief Invocation
   */
  template <typename X>
  struct apply
  {
    /**
     * @brief Result
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_COMPOSE_HPP
