// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file enumerable.hpp
 *
 * @brief `Enumerable` typeclass
 *
 * Defines the `Enumerable` typeclass.
 */

/**
 * @defgroup tc_enumerable Enumerable
 * @ingroup typeclasses
 *
 * @brief Incrementable and decrementable values
 *
 * Indicates that the value of a data type can have a *previous* and a *next*
 * value, i.e., can be incremented or decremented.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ENUMERABLE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ENUMERABLE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_enumerable}
 */
struct Enumerable ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (erythronelumbo, maihuenia), \
  ::erythronelumbo::maihuenia::Enumerable, \
  1, \
  (), \
  ( \
    /* incr<X> */ \
    (incr, 0, 1, 0, 0, (0)), \
    /* decr<X> */ \
    (decr, 0, 1, 0, 0, (0)) \
  ), \
  () \
)


namespace erythronelumbo { namespace maihuenia
{

template <>
struct typeclass<Enumerable>::define_for<not_a_number> : true_
{
  template <typename X>
  using incr_impl = not_a_number;

  template <typename X>
  using decr_impl = not_a_number;
};

}} // namespace erythronelumbo::maihuenia

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_enumerable
 * @brief Increment
 *
 * Increments the value of a type.
 *
 * @tparam X
 *   A type.
 *
 * ## Example
 *
 * @include example/individual/enumerable/incr.cpp
 */
template <typename X>
struct incr
{
  /**
   * @brief Result
   * 
   * A type like the one given in `X`, but its underlying value has been
   * incremented.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_enumerable
 * @brief Decrement
 *
 * Decrements the value of a type.
 *
 * @tparam X
 *   A type.
 *
 * ## Example
 *
 * @include example/individual/enumerable/decr.cpp
 */
template <typename X>
struct decr
{
  /**
   * @brief Result
   * 
   * A type like the one given in `X`, but its underlying value has been
   * decremented.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::incr
 *
 * @invokesmfn{incr}
 *
 * @tparam X
 *   A type.
 */
template <typename X>
using incr_t = typename incr<X>::type;


/**
 * @relates erythronelumbo::maihuenia::decr
 *
 * @invokesmfn{decr}
 *
 * @tparam X
 *   A type.
 */
template <typename X>
using decr_t = typename decr<X>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ENUMERABLE_HPP
