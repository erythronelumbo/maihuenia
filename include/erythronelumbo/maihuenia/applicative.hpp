// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file applicative.hpp
 *
 * @brief `Applicative` typeclass
 *
 * Defines the `Applicative` typeclass.
 */

/**
 * @defgroup tc_applicative Applicative
 * @ingroup typeclasses
 *
 * @brief Functors that allow lifting of *values* and combining operations.
 *
 * A refinement of @ref tc_functor, which specifies that a data type can *lift*
 * or store a value into it. It can also combine computations, by applying the
 * metafunction classes contained in an instance of an `Applicative` type to the
 * *values* from another instance of such type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_APPLICATIVE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_APPLICATIVE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_applicative}
 */
struct Applicative ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Applicative, \
    1, \
    (::erythronelumbo::maihuenia::Functor), \
    ( \
      /* lift<TypeTag, T> */ \
      (lift, 0, 1, 0, 1, ()), \
      /* ap<FnFctr, Fctr> (FnFctr, Fctr: applicatives, same type) */ \
      (ap, 0, 2, 0, 0, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_applicative
 * @brief Lifting of a value into a functor
 *
 * Creates an instance of a data type by lifting (encapsulating) a *value* into
 * it.
 *
 * ```
 * lift(F, x) == F(x)
 * 
 * (F is a data structure)
 * ```
 *
 * @tparam FunctorTag
 *   The functor type to initialize.
 * @tparam T
 *   The *value* to be contained into the functor.
 *
 * ## Example
 *
 * @include example/individual/applicative/lift.cpp
 */
template <typename FunctorTag, typename T>
struct lift
{
  /**
   * @brief Result
   *
   * A functor encapsulating the *value* given in `T`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_applicative
 * @brief Combination of computations
 *
 * Uses the metafunction classes contained in a functor to transform the
 * elements in another one, in a one-by-one manner, illustrated as follows:
 * 
 * ```
 * ap([f1, f2, ..., fm], [x1, x2, ..., xn])
 * == [
 *   f1(x1), f1(x2), ..., f1(xn), f2(x1), f2(x2), ..., f2(xn), ...,
 *   fm(x1), fm(x2), ..., fm(xn)
 * ]
 * 
 * ([] represents a list, but applies to any other data structure)
 * ```
 *
 * @tparam FnFctr
 *   A functor with metafunction classes corresponding to the transformations.
 * @tparam Fctr
 *   A functor with the elements to be transformed.
 *
 * ## Example
 *
 * @include example/individual/applicative/ap.cpp
 */
template <typename FnFctr, typename Fctr>
struct ap
{
  /**
   * @brief Result
   *
   * A functor with encapsulated elements as in `Fctr`, but transformed with
   * the elements in `FnFctr`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::lift
 *
 * @invokesmfn{lift}
 *
 * @tparam FunctorTag
 *   The functor type to initialize.
 * @tparam T
 *   The *value* to be contained into the functor.
 */
template <typename FunctorTag, typename T>
using lift_t = typename lift<FunctorTag, T>::type;


/**
 * @relates erythronelumbo::maihuenia::ap
 *
 * @invokesmfn{ap}
 *
 * @tparam FnFctr
 *   A functor with metafunction classes corresponding to the transformations.
 * @tparam Fctr
 *   A functor with the elements to be transformed.
 */
template <typename FnFctr, typename Fctr>
using ap_t = typename ap<FnFctr, Fctr>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_APPLICATIVE_HPP
