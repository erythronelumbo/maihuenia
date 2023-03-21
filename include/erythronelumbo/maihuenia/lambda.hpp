// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `lambda` metafunction class
 *
 * Defines the `lambda` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_LAMBDA_HPP
#define ERYTHRONELUMBO_MAIHUENIA_LAMBDA_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/arg.hpp>
#include <erythronelumbo/maihuenia/always.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>
#include <erythronelumbo/maihuenia/fwd/lambda.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Arg>
  struct pick_lambda_arg_action : always<Arg> {};

  template <template <typename...> class Fn, typename... Args>
  struct pick_lambda_arg_action<Fn<Args...>> : lambda<Fn<Args...>> {};

  template <::std::size_t N>
  struct pick_lambda_arg_action<arg<N>> : arg<N> {};

  template <template <typename...> class Fn, typename... Args>
  struct pick_lambda_arg_action<protect<Fn<Args...>>> :
    always<Fn<Args...>>
  {};

  template <typename Expr>
  struct pick_lambda_arg_action<protect<lambda<Expr>>> :
    always<lambda<Expr>>
  {};

  template <::std::size_t N>
  struct pick_lambda_arg_action<protect<arg<N>>> : always<arg<N>> {};


  template <typename... Args>
  struct lambda_args_pack_ {};


  template <typename, typename>
  struct lambda_apply_wrap_args_pack;

  template <typename Fn, typename... Args>
  struct lambda_apply_wrap_args_pack<Fn, lambda_args_pack_<Args...>> :
    apply_wrap<Fn, Args...>
  {};


  template <
    template <typename...> class Fn, typename FnArgsPack, typename... Args
  >
  using lambda_packed = typename quote<Fn>::template apply<
    typename lambda_apply_wrap_args_pack<
      pick_lambda_arg_action<Args>, FnArgsPack
    >::type...
  >;
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <typename Expr>
  struct lambda : always<Expr> { using type = lambda; };

  template <::std::size_t N>
  struct lambda<arg<N>> : arg<N> { using type = lambda; };

  template <template <typename...> class Fn, typename... ExprArgs>
  struct lambda<Fn<ExprArgs...>>
  {
    using type = lambda;

    template <typename... Args>
    struct apply :
      detail::lambda_packed<
        Fn,
        detail::lambda_args_pack_<Args...>,
        ExprArgs...
      >
    {};
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup functional
 * @brief Treats an expression with placeholders as a metafunction class
 *
 * Takes an expression with placeholders and composed metafunctions for invoking
 * it as a metafunction class. Said placeholders indicate the positions of the
 * arguments that will be passed through the `apply` member.
 *
 * @see @ref bind
 * @see @ref quote
 *
 * @tparam Expr
 *   An expression that can have placeholders.
 *
 * ## Example
 *
 * @include example/individual/functional/lambda.cpp
 */
template <typename Expr>
struct lambda
{
  /**
   * @brief Reference to itself
   *
   * Calls to itself when treated as a metafunction.
   */
  using type = lambda;

  /**
   * @brief Invocation
   *
   * Takes elements from a parameter pack, which are located as indicated in the
   * placeholders in `Expr`. Said elements will *replace* the placeholders from
   * `Expr`.
   *
   * @tparam Args...
   *   The parameter pack.
   */
  template <typename... Args>
  struct apply
  {
    /**
     * @brief Result
     *
     * The result of the evaluation of `Expr`.
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_LAMBDA_HPP
