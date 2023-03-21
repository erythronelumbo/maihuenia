// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file comparable.hpp
 *
 * @brief `Comparable` typeclass
 *
 * Defines the `Comparable` typeclass.
 */

/**
 * @defgroup tc_comparable Comparable
 * @ingroup typeclasses
 *
 * @brief Defines comparisons about the equality of two types
 *
 * Indicates that two instances of a type (or even two different types) can be
 * compared by checking if they are equal or not. It can also be done by
 * checking their underlying values.
 *
 * For value types with no associated type tags, the intrinsic metafunctions
 * will behave like `equal_types`. 
 *
 * ### Minimal complete definition
 *
 * `equals<X0, X1>`, `not_equals<X0, X1>`
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_COMPARABLE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_COMPARABLE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_comparable}
 */
struct Comparable ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (erythronelumbo, maihuenia), \
  ::erythronelumbo::maihuenia::Comparable, \
  2, \
  (), \
  ( \
    (equals, 0, 2, 0, 0, (0, 1)), \
    (not_equals, 0, 2, 0, 0, (0, 1)) \
  ), \
  () \
)

namespace erythronelumbo { namespace maihuenia
{

template <>
struct typeclass<Comparable>::define_for<foreign, foreign> : true_
{
  template <typename X0, typename X1>
  using equals_impl = equal_types<X0, X1>;

  template <typename X0, typename X1>
  using not_equals_impl = bool_<!equal_types_t<X0, X1>::value>;
};

template <typename OtherTag>
struct typeclass<Comparable>::define_for<OtherTag, foreign> : true_
{
  template <typename X0, typename X1>
  using equals_impl = equal_types<X0, X1>;

  template <typename X0, typename X1>
  using not_equals_impl = bool_<!equal_types_t<X0, X1>::value>;
};

template <typename OtherTag>
struct typeclass<Comparable>::define_for<foreign, OtherTag> : true_
{
  template <typename X0, typename X1>
  using equals_impl = equal_types<X0, X1>;

  template <typename X0, typename X1>
  using not_equals_impl = bool_<!equal_types_t<X0, X1>::value>;
};

}}

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_comparable
 * @brief Equality comparator
 *
 * Checks if the values of two types are equal.
 *
 * @tparam X1
 *   A type to be compared.
 * @tparam X2
 *   A type to be compared.
 *
 * ## Example
 *
 * @include example/individual/comparable/equals.cpp
 */
template <typename X1, typename X2>
struct equals
{
  /**
   * @brief Result
   *
   * A `bool_` indicating the equality of two values.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_comparable
 * @brief Inequality comparator
 *
 * Checks if the values of two types are not equal.
 *
 * @tparam X1
 *   A type to be compared.
 * @tparam X2
 *   A type to be compared.
 *
 * ## Example
 *
 * @include example/individual/comparable/not_equals.cpp
 */
template <typename X1, typename X2>
struct not_equals
{
  /**
   * @brief Result
   *
   * A `bool_` indicating the inequality of two values.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::equals
 *
 * @invokesmfn{equals}
 *
 * @tparam X1
 *   A type to be compared.
 * @tparam X2
 *   A type to be compared.
 */
template <typename X1, typename X2>
using equals_t = typename equals<X1, X2>::type;


/**
 * @relates erythronelumbo::maihuenia::not_equals
 *
 * @invokesmfn{not_equals}
 *
 * @tparam X1
 *   A type to be compared.
 * @tparam X2
 *   A type to be compared.
 */
template <typename X1, typename X2>
using not_equals_t = typename not_equals<X1, X2>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_COMPARABLE_HPP
