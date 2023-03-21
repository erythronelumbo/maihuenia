// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file monad.hpp
 *
 * @brief `Monad` typeclass
 *
 * Defines the `Monad` typeclass.
 */

/**
 * @defgroup tc_monad Monad
 * @ingroup typeclasses
 *
 * @brief Allows the chained application of actions
 *
 * An extension of @ref tc_applicative that allows the chaining of computations
 * that modify the internal content of a data type (for example, altering the
 * ammount of elements contained in a sequence in some way or composing
 * metafunctions that can have a valid result or not, which can be represented
 * by an option type), which must result in an instance of the given monadic
 * type.
 *
 * The concept of monads is known to be a broad (and even confusing) subject,
 * so, further explanations are out of the scope of this documentation.
 * Therefore, it is encouraged to read other resources about them.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MONAD_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MONAD_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_monad}
 */
struct Monad ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Monad, \
    1, \
    (::erythronelumbo::maihuenia::Applicative), \
    ( \
      /* mbind<M, MFnC> (M: monad) */ \
      (mbind, 1, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_monad
 * @brief Monadic bind
 *
 * Applies several metafunction classes to a monad. Those metafunction classes
 * must return monads of the same type as the input.
 * 
 * ```
 * mbind(M(x1, x2, ..., xn), f)
 * == (flattening-operation)(M(f(x1), f(x2), ..., f(xn)))
 * == (flattening-operation)(M(M(y1...), M(y2...), ..., M(ym...)))
 * == M(y1..., y2..., ..., ym...)
 * 
 * (M is a monadic structure)
 * 
 * mbind(M, f1, f2, ..., fn) = mbind(mbind(... mbind(M, f1), f2), ...), fn)
 * ```
 *
 * @tparam M
 *   A monadic structure.
 * @tparam MFnC
 *   A metafunction class that results in a monadic structure of the same type
 *   as `M`.
 * @tparam MFnCs...
 *   Other metafunction classes as described for `MFnC`.
 *
 * ## Example
 *
 * @include example/individual/monad/mbind.cpp
 */
template <typename M, typename MFnC, typename... MFnCs>
struct mbind
{
  /**
   * @brief Result
   *
   * The output of feeding `M` to `MFnC[s...]`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::mbind
 *
 * @invokesmfn{mbind}
 *
 * @tparam M
 *   A monadic structure.
 * @tparam MFnC
 *   A metafunction class that results in a monadic structure of the same type
 *   as `M`.
 * @tparam MFnCs...
 *   Other metafunction classes as described for `MFnC`.
 */
template <typename M, typename MFnC, typename... MFnCs>
using mbind_t = typename mbind<M, MFnC, MFnCs...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MONAD_HPP
