// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file curry.hpp
 *
 * @brief `curry` and `curry_quote` metafunction classes
 *
 * Defines the `curry` and `curry_quote` metafunction classes.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_CURRY_HPP
#define ERYTHRONELUMBO_MAIHUENIA_CURRY_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename MetaFn, ::std::size_t N, typename... ArgsAcc>
  struct curry_helper
  {
    template <typename... Xs>
    using apply = curry_helper<
      MetaFn, N - sizeof...(Xs), ArgsAcc..., Xs...
    >;
  };

  template <typename MetaFn, typename... ArgsAcc>
  struct curry_helper<MetaFn, 0, ArgsAcc...>
  {
    using type = typename MetaFn::template apply<ArgsAcc...>::type;
  };
} // namespace detail

template <template <typename...> class MetaFn, ::std::size_t Arity>
struct curry_quote : detail::curry_helper<quote<MetaFn>, Arity>
{
  using type = curry_quote;
};


template <typename MFnC, ::std::size_t Arity>
struct curry :
  detail::curry_helper<MFnC, Arity>
{
  using type = curry;
};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup functional
 * @brief Curries a metafunction class
 *
 * Turns a metafunction class into a sequence of metafunction classes, each one
 * taking less arguments that the given metafunction class. This technique is
 * known as *currying*.
 *
 * @see @ref curry_quote
 * @see @ref bind
 *
 * @tparam MFnC
 *   A metafunction class.
 * @tparam Arity
 *   The arity (or number of arguments taken) of `MFnC`.
 *
 * ## Example
 *
 * @include example/individual/functional/curry.cpp
 */
template <typename MFnC, ::std::size_t Arity>
struct curry
{
  /**
   * @mfncalltoitself
   */
  using type = curry;

  /**
   * @brief Invocation
   *
   * Takes any number of arguments as long as it is not higher that the
   * metafunction's arity. If the number of arguments is the same as the arity,
   * it will have the result in the `type` member; otherwise, it will behave as
   * a metafunction class, with the usual `apply` invocation member.
   *
   * @tparam Xs...
   *   The arguments that will be *fed* to `MFnC`'s invocation member.
   */
  template <typename... Xs>
  struct apply
  {
    /**
     * @brief Result
     *
     * Same as `typename MFnC::template apply<Xs1..., Xs2..., ...>::type`.
     *
     * @note This member will be present **only** when all the metafunction's
     * arguments are passed.
     */
    using type = unspecified;
  };
};


/**
 * @ingroup functional
 * @brief Curries a metafunction
 *
 * Turns a metafunction into a sequence of metafunction classes, each one taking
 * less arguments that the given metafunction. This technique is known as
 * *currying*.
 *
 * @see @ref curry
 * @see @ref quote
 * @see @ref bind
 *
 * @tparam MetaFn
 *   A metafunction.
 * @tparam Arity
 *   The arity (or number of arguments taken) of `MetaFn`.
 *
 * ## Example
 *
 * @include example/individual/functional/curry_quote.cpp
 */
template <template <typename...> class MetaFn, ::std::size_t Arity>
struct curry_quote
{
  /**
   * @mfncalltoitself
   */
  using type = curry_quote;

  /**
   * @brief Invocation
   *
   * Takes any number of arguments as long as it is not higher that the
   * metafunction's arity. If the number of arguments is the same as the arity,
   * it will have the result in the `type` member; otherwise, it will behave as
   * a metafunction class, with the usual `apply` invocation member.
   *
   * @tparam Xs...
   *   The arguments that will be *fed* to `MetaFn`.
   */
  template <typename... Xs>
  struct apply
  {
    /**
     * @brief Result
     *
     * Same as `typename MetaFn<Xs1..., Xs2..., ...>::type`.
     *
     * @note This member will be present **only** when all the metafunction's
     * arguments are passed.
     */
    using type = unspecified;
  };
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_CURRY_HPP
