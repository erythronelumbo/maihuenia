// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file define_error.hpp
 *
 * @brief Definition of error codes
 *
 * Contains utilities for error handling and definition of custom error codes.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/detail/preprocessor.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <typename T>
struct error_tag;

template <typename T> struct is_error { using type = false_; };

template <typename T, typename ResIfError>
struct unless_error
{
  using type = T;
};

}} // namespace erythronelumbo::maihuenia

#define ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR(nsps, err_name) \
ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_OP, \
  nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
) \
  struct err_name \
  { \
    using tag = ::erythronelumbo::maihuenia::error_tag<err_name>; \
  }; \
ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_CL, \
  nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
) \
namespace erythronelumbo { namespace maihuenia \
{ \
  template <> \
  struct is_error< \
    ::ERYTHRONELUMBO_MAIHUENIA_DETAIL_MEM_ACC_MANY(nsps)::err_name \
  > \
  { \
    using type = true_; \
  }; \
  template <typename ResIfError> \
  struct unless_error< \
    ::ERYTHRONELUMBO_MAIHUENIA_DETAIL_MEM_ACC_MANY(nsps)::err_name, \
    ResIfError\
  > \
  { \
    using type = ResIfError; \
  }; \
}}

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup err_handling
 * @brief Type tag
 *
 * Type tag used by error types.
 *
 * @tparam T
 *   The error type that uses this type as a tag.
 */
template <typename T>
struct error_tag {};


/**
 * @ingroup err_handling
 * @brief Checks if a type is an error
 *
 * Checks if a type represents an error.
 *
 * @tparam T
 *   A type.
 */
template <typename T>
struct is_error
{
  /**
   * @brief Result
   *
   * `true_` if the type is an error, `false_` otherwise.
   */
  using type = unspecified;
};


/**
 * @ingroup err_handling
 * @brief Returns a non-error type
 *
 * If the result of an operation is an error, this metafunction will return a
 * non-error type; otherwise, it will return the result as-is.
 *
 * @tparam T
 *   The type, which can be an error or not.
 * @tparam ResIfError
 *   The type that will be returned if `T` is an error.
 */
template <typename T, typename ResIfError>
struct unless_error
{
  /**
   * @brief Result
   *
   * `ResIfError` if `T` is an error, `T` otherwise.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia


/**
 * @ingroup err_handling
 * @brief Defines an error type
 *
 * Defines a type that represents an error.
 *
 * @note
 *   Since the usage of this macro involves namespace injection, it must be
 *   used in the global namespace.
 *
 * @param nsps
 *   The namespaces. It must be of the form `(ns1, ns2, ...)`, where `ns1`,
 *   `ns2` and so on are the namespaces.
 * @param err_name
 *   The name of the error type.
 */
#define ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR(nsps, err_name) \
/* unspecified */

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::is_error
 *
 * @invokesmfn{is_error}
 *
 * @tparam T
 *   A type.
 */
template <typename T>
using is_error_t = typename is_error<T>::type;

/**
 * @relates erythronelumbo::maihuenia::unless_error
 *
 * @invokesmfn{unless_error}
 *
 * @tparam T
 *   The type, which can be an error or not.
 * @tparam ResIfError
 *   The type that will be returned if `T` is an error.
 */
template <typename T, typename ResIfError>
using unless_error_t = typename unless_error<T, ResIfError>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR_HPP
