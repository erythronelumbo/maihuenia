// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file with_string_repr.hpp
 *
 * @brief `WithStringRepr` typeclass
 *
 * Defines the `WithStringRepr` typeclass.
 */

/**
 * @defgroup tc_withstringrepr WithStringRepr
 * @ingroup typeclasses
 *
 * @brief String-representable types
 *
 * Describes types that can have a human-readable representation, in form of a
 * @ref dt_seq_string.
 *
 * ### Minimal complete definition
 *
 * `to_string<T>`
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_WITH_STRING_REPR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_WITH_STRING_REPR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_withstringrepr}
 */
struct WithStringRepr ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::WithStringRepr, \
    1, \
    (), \
    ((to_string, 0, 1, 0, 0, (0))), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_withstringrepr
 * @brief Type to string representation
 *
 * Generates the string representation, in a human-readable form, of an instance
 * of a data type.
 *
 * @tparam T
 *   A string-representable type.
 *
 * ## Example
 *
 * @include example/individual/with_string_repr/to_string.cpp
 */
template <typename T>
struct to_string
{
  /**
   * @brief Result
   *
   * A @ref dt_seq_string with the representation of the supplied type.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::to_string
 *
 * @invokesmfn{to_string}
 *
 * @tparam T
 *   A string-representable type.
 */
template <typename T>
using to_string_t = typename to_string<T>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_WITH_STRING_REPR_HPP
