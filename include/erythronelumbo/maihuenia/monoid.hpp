// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file monoid.hpp
 *
 * @brief `Monoid` typeclass
 *
 * Defines the `Monoid` typeclass.
 */

/**
 * @defgroup tc_monoid Monoid
 * @ingroup typeclasses
 *
 * @brief Structures with an identity and an associative binary operation
 *
 * Describes structures which have an associative binary operation associated to
 * them and an *identity* element or value, which has no effect in the
 * aforementioned binary operation.
 *
 * Note that some types, like integrals, can have more than one monoidal
 * operation (like, for example, addition and multiplication).
 *
 * ### Minimal complete definition
 * 
 * `mident<TpTag>`, `mappend<X0, X1>`.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MONOID_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MONOID_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_monoid}
 */
struct Monoid ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Monoid, \
    2, \
    (), \
    ((mident, 0, 0, 0, 1, ()), (mappend, 1, (0, 1))), () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_monoid
 * @brief Identity of a monoid
 *
 * Results in the *identity* element or *value* of a monoidal data type and its
 * associated binary operation.
 *
 * @tparam TypeTag
 *   The tag of the desired data type.
 *
 * ## Example
 *
 * @include example/individual/monoid/mident.cpp
 */
template <typename TypeTag>
struct mident
{
  /**
   * @brief Result
   *
   * The identity element of the desired monoidal data type.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_monoid
 * @brief Associative operation of a monoid
 *
 * Performs the internal associative operation of a monoidal data structure,
 * applying it to several *values* of the same type.
 *
 * @tparam M0
 *   A *value* of a monoidal data type.
 * @tparam M1
 *   A *value* of a monoidal data type.
 * @tparam Ms...
 *   *Values* of a monoidal data type.
 *
 * ## Example
 *
 * @include example/individual/monoid/mappend.cpp
 */
template <typename M0, typename M1, typename... Ms>
struct mappend
{
  /**
   * @brief Result
   *
   * The monoidal associative operator applies to the supplied value types.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::mident
 *
 * @invokesmfn{mident}
 *
 * @tparam TypeTag
 *   The tag of the desired data type.
 */
template <typename TypeTag>
using mident_t = typename mident<TypeTag>::type;

/**
 * @relates erythronelumbo::maihuenia::mappend
 *
 * @invokesmfn{mappend}
 *
 * @tparam M0
 *   A *value* of a monoidal data type.
 * @tparam M1
 *   A *value* of a monoidal data type.
 * @tparam Ms...
 *   *Values* of a monoidal data type.
 */
template <typename M0, typename M1, typename... Ms>
using mappend_t = typename mappend<M0, M1, Ms...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_MONOID_HPP
