// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file functor.hpp
 *
 * @brief `functor` typeclass
 *
 * Defines the `functor` typeclass.
 */

/**
 * @defgroup tc_functor Functor
 * @ingroup typeclasses
 *
 * @brief Data types where only its content can be transformed
 *
 * Specifies that each element of a container-like data type can be modified by
 * a metafunction class, without modifying the container.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FUNCTOR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FUNCTOR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_functor}
 */
struct Functor ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Functor, \
    1, \
    (), \
    ((transform, 0, 2, 0, 0, (1))), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_functor
 * @brief Transformation of elements in a data structure
 *
 * Transforms the elements encapsulated in a data structure with a metafunction
 * class, without transforming said data structure. It is done in the following
 * manner:
 * 
 * ```
 * transform(f, [x1, x2, ..., xn]) == [f(x1), f(x2), ... f(xn)]
 * ```
 *
 * @tparam Fn
 *   A metafunction class.
 * @tparam X
 *   The data structure with the elements to transform.
 *
 * ## Example
 *
 * @include example/individual/functor/transform.cpp
 */
template <typename Fn, typename X>
struct transform
{
  /**
   * @brief Result
   *
   * A data structure like the one given in `X`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::transform
 *
 * @invokesmfn{transform}
 *
 * @tparam Fn
 *   A metafunction class.
 * @tparam X
 *   The data structure with the elements to transform.
 */
template <typename Fn, typename X>
using transform_t = typename transform<Fn, X>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FUNCTOR_HPP
