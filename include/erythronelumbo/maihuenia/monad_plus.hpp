// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file monad_plus.hpp
 *
 * @brief `MonadPlus` typeclass
 *
 * Defines the `MonadPlus` typeclass.
 */

/**
 * @defgroup tc_monadplus MonadPlus
 * @ingroup typeclasses
 *
 * @brief Monads with empty element and combination operations
 *
 * An extension of @ref tc_monad, where the instantiated types have a *nullary*
 * (or empty) value and a binary, associative operation that combines two
 * monadic types and results in another monadic type, in a way similar to
 * @ref tc_monoid.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MONAD_PLUS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MONAD_PLUS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_monadplus}
 */
struct MonadPlus ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::MonadPlus, \
    1, \
    (::erythronelumbo::maihuenia::Monad), \
    ( \
      /* mplus<M1, M2> (M1, M2: monadpluses, same type) */ \
      (mplus, 1, (0)), \
      /* mzero<TypeTag> */ \
      (mzero, 0, 0, 0, 1, ()) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_monadplus
 * @brief Binary combination of monadic structures
 *
 * Combines the contents of two monadic values that instantiate a same data
 * type, resulting in a monadic value of the same type.
 *
 * This operation corresponds to an associative operation:
 *
 * ```
 * M1 @ M2 @ M3 == M1 @ (M2 @ M3) == (M1 @ M2) @ M3
 * 
 * (@ is a binary operation)
 * ```
 *
 * @tparam M1
 *   A monadic structure.
 * @tparam M2
 *   A monadic structure.
 * @tparam Ms...
 *   Monadic structures (same data type as `M1` and `M2`).
 *
 * ## Example
 *
 * @include example/individual/monad_plus/mplus.cpp
 */
template <typename M1, typename M2, typename... Ms>
struct mplus
{
  /**
   * @brief Result
   *
   * A data structure containing the values of `M1`, `M2` and `Ms...` combined.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_monadplus
 * @brief Nullary monadic value
 *
 * Creates the *nullary* value of a monadic type.
 *
 * @tparam TypeTag
 *   The tag of a monadic type, with a *nullary* value.
 *
 * ## Example
 *
 * @include example/individual/monad_plus/mzero.cpp
 */
template <typename TypeTag>
struct mzero
{
  /**
   * @brief Result
   *
   * The nullary value of the monadic type represented by `TypeTag`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::mplus
 *
 * @invokesmfn{mplus}
 *
 * @tparam Ms...
 *   Monadic structures. Must be at least two arguments.
 */
template <typename... Ms>
using mplus_t = typename mplus<Ms...>::type;

/**
 * @relates erythronelumbo::maihuenia::mzero
 *
 * @invokesmfn{mzero}
 *
 * @tparam TypeTag
 *   The tag of a monadic type, with a *nullary* value.
 */
template <typename TypeTag>
using mzero_t = typename mzero<TypeTag>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MONAD_PLUS_HPP
