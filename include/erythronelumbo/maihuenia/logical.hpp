// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file logical.hpp
 *
 * @brief `Logical` typeclass
 *
 * Defines the `Logical` typeclass.
 */

/**
 * @defgroup tc_logical Logical
 * @ingroup typeclasses
 *
 * @brief Data types with logical/Boolean or truth values
 *
 * Also known as Boolean, corresponds to data types that can take logical or
 * truth values (*true* or *false*), where logical operations (conjunction,
 * disjunction and negation) can be done over them.
 *
 * ### Minimal complete definition
 *
 * `logical_not<B>`, `logical_and<B0, B1, ...>`, `logical_or<B0, B1, ...>`.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_LOGICAL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_LOGICAL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_logical}
 */
struct Logical ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Logical, \
    2, \
    (), \
    ( \
      (logical_and, 1, (0, 1)), \
      (logical_or, 1, (0, 1)), \
      (logical_not, 0, 1, 0, 0, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_logical
 * @brief Logical AND
 *
 * Does the logical conjunction (*AND*) of several logical values. Equivalent to
 * `B0 && B1 && ...`.
 *
 * @tparam B0
 *   A logical value.
 * @tparam B1
 *   A logical value.
 * @tparam Bs...
 *   Logical values.
 *
 * ## Example
 *
 * @include example/individual/logical/logical_and.cpp
 */
template <typename B0, typename B1, typename... Bs>
struct logical_and
{
  /**
   * @brief Result
   *
   * A *true* value if all the supplied values are *true*; *false* otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_logical
 * @brief Logical OR
 *
 * Does the logical disjunction (*OR*) of several logical values. Equivalent to
 * `B0 || B1 || ...`.
 *
 * @tparam B0
 *   A logical value.
 * @tparam B1
 *   A logical value.
 * @tparam Bs...
 *   Logical values.
 *
 * ## Example
 *
 * @include example/individual/logical/logical_or.cpp
 */
template <typename B0, typename B1, typename... Bs>
struct logical_or
{
  /**
   * @brief Result
   *
   * A *true* value if at least one of the the supplied values are *true*;
   * *false* otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_logical
 * @brief Logical NOT
 *
 * Negates a logical value. Equivalent to `!B`.
 *
 * @tparam B
 *   A logical value.
 *
 * ## Example
 *
 * @include example/individual/logical/logical_not.cpp
 */
template <typename B>
struct logical_not
{
  /**
   * @brief Result
   *
   * A *true* value if `B` is *false* or a *false* value if *true*.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::logical_and
 *
 * @invokesmfn{logical_and}
 *
 * @tparam B0
 *   A logical value.
 * @tparam B1
 *   A logical value.
 * @tparam Bs...
 *   Logical values.
 */
template <typename B0, typename B1, typename... Bs>
using logical_and_t = typename logical_and<B0, B1, Bs...>::type;

/**
 * @relates erythronelumbo::maihuenia::logical_or
 *
 * @invokesmfn{logical_or}
 *
 * @tparam B0
 *   A logical value.
 * @tparam B1
 *   A logical value.
 * @tparam Bs...
 *   Logical values.
 */
template <typename B0, typename B1, typename... Bs>
using logical_or_t = typename logical_or<B0, B1, Bs...>::type;

/**
 * @relates erythronelumbo::maihuenia::logical_not
 *
 * @invokesmfn{logical_not}
 *
 * @tparam B
 *   A logical value.
 */
template <typename B>
using logical_not_t = typename logical_not<B>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_LOGICAL_HPP
