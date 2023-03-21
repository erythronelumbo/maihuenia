// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `bind` metafunction class
 *
 * Defines the `bind` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_BIND_HPP
#define ERYTHRONELUMBO_MAIHUENIA_BIND_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/arg.hpp>
#include <erythronelumbo/maihuenia/always.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/fwd/bind.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Arg>
  struct pick_bind_arg_action : always<Arg> {};

  template <::std::size_t N>
  struct pick_bind_arg_action<arg<N>> : arg<N> {};

  template <typename Fn, typename... Args>
  struct pick_bind_arg_action<bind<Fn, Args...>> : bind<Fn, Args...> {};

  template <::std::size_t N>
  struct pick_bind_arg_action<protect<arg<N>>> : always<arg<N>> {};

  template <typename Fn, typename... Args>
  struct pick_bind_arg_action<protect<bind<Fn, Args...>>> :
    always<bind<Fn, Args...>>
  {};


  template <typename...>
  struct bind_args_pack_ {};


  template <typename, typename>
  struct bind_apply_wrap_args_pack;

  template <typename Fn, typename... Args>
  struct bind_apply_wrap_args_pack<Fn, bind_args_pack_<Args...>> :
    apply_wrap<Fn, Args...>
  {};


  template <typename Fn, typename FnArgsPack, typename... Args>
  using bind_packed = typename Fn::template apply<
    typename bind_apply_wrap_args_pack<
      pick_bind_arg_action<Args>, FnArgsPack
    >::type...
  >;
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <typename Fn, typename... Args>
  struct bind
  {
    using type = bind;

    template <typename... FnArgs>
    struct apply :
      detail::bind_packed<Fn, detail::bind_args_pack_<FnArgs...>, Args...>
    {};
  };

  template <typename Fn> struct bind<Fn> : Fn
  {
    using type = bind<Fn>;
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup functional
 * @brief Binds arguments to a metafunction class
 *
 * Wraps a metafunction class in a way that some arguments are fixed (or bound)
 * to it, while other unbound arguments, indicated as placeholders, are passed
 * through the `apply` member.
 *
 * @see @ref quote
 * @see @ref curry_quote
 * @see @ref curry
 * @see @ref lambda
 *
 * @tparam Fn
 *   A metafunction class.
 * @tparam Args...
 *   The arguments to bind. They can also be placeholders or nested instances
 *   of `bind`. If a placeholder/@ref arg or a bind expression needs to be
 *   treated as a normal argument, it must be wrapped with @ref protect.
 *
 * ## Example
 *
 * @include example/individual/functional/bind.cpp
 */
template <typename Fn, typename... Args>
struct bind
{
  /**
   * @mfncalltoitself
   */
  using type = bind;

  /**
   * @brief Invocation
   *
   * Takes only the unbound arguments, located as indicated in their respective
   * placeholders.
   *
   * @tparam FnArgs...
   *   The parameters needed for the unbound arguments.
   */
  template <typename... FnArgs>
  struct apply
  {
    /**
     * @brief Result
     *
     * The result of `Fn` with the bound arguments from `Args...` and the ones
     * taken from `FnArgs...`.
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_BIND_HPP
