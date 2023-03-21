// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file tag.hpp
 *
 * @brief `tag` metafunction
 *
 * Defines the `tag` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_TAG_HPP
#define ERYTHRONELUMBO_MAIHUENIA_TAG_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/void_sink.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_core
 * @brief Foreign type tag
 *
 * A *dummy* type tag that indicates that a data type does not have an
 * associated, proper type tag.
 */
struct foreign ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename, typename = void>
  struct get_tag_safe
  {
    using type = foreign;
  };

  template <typename T>
  struct get_tag_safe<T, void_sink_t<typename T::tag>>
  {
    using type = typename T::tag;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup mfn_core
 * @brief Tag of a type
 *
 * Obtains the *type tag* that represents a type.
 *
 * This metafunction assumes that the type to inspect has a `tag` member type,
 * which applies to the data types providad by this library. If necessary, this
 * metafunction can be overloaded for an external data type, assuming that there
 * is a *type tag* defined for it.
 *
 * @tparam T
 *   A type.
 *
 * ## Example
 *
 * @include example/individual/core/tag.cpp
 */
template <typename T>
struct tag
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * The tag of the type (usually from `typename T::tag`) or @ref foreign if
   * the type does not have a proper type tag.
   */
  using type = unspecified;

  #else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  using type = typename detail::get_tag_safe<T>::type;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::tag
 *
 * @invokesmfn{tag}
 *
 * @tparam T
 *   A type.
 */
template <typename T>
using tag_t = typename tag<T>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_TAG_HPP
