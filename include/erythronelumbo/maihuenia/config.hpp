// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file config.hpp
 *
 * @brief Configuration
 *
 * Contains parameters for configuring this library.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_CONFIG_HPP
#define ERYTHRONELUMBO_MAIHUENIA_CONFIG_HPP


#include <erythronelumbo/maihuenia/version.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #ifndef ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION
  #define ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION 1
  #endif

  #ifndef ERYTHRONELUMBO_MAIHUENIA_NESTED_EVAL_IF_DEFINITION
  #define ERYTHRONELUMBO_MAIHUENIA_NESTED_EVAL_IF_DEFINITION 1
  #endif

  #define ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN(...)

  #define ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN(...) __VA_ARGS__
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup configuration
 * @brief Determines the underlying definition of `if_`
 *
 * Determines how should be the underlying definition of the `if_` metafunction.
 *
 * If its value is non-zero, the underlying definition will be
 * `if_impl<C>::template apply<T, F>`; otherwise, `if_impl<C, T, F>`.
 *
 * For setting a custom value, it must be set before the first header file of
 * this library. If not set, its value (the default) is `1`.
 */
#define ERYTHRONELUMBO_MAIHUENIA_NESTED_IF_DEFINITION /* unspecified */

/**
 * @ingroup configuration
 * @brief Determines the underlying definition of `eval_if`
 *
 * Determines how should be the underlying definition of the `eval_if`
 * metafunction.
 *
 * If its value is non-zero, the underlying definition will be
 * `eval_if_impl<C>::template apply<T, F>`; otherwise, `eval_if_impl<C, T, F>`.
 *
 * For setting a custom value, it must be set before the first header file of
 * this library. If not set, its value (the default) is `1`.
 */
#define ERYTHRONELUMBO_MAIHUENIA_NESTED_EVAL_IF_DEFINITION /* unspecified */

/**
 * @ingroup configuration
 * @brief Macro expansion with Doxygen
 *
 * Expands the supplied arguments when Doxygen is invoked; otherwise, it does
 * nothing.
 *
 * Used internally in this library when building its documentation.
 */
#define ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN(...) __VA_ARGS__

/**
 * @ingroup configuration
 * @brief Prevents macro expansion with Doxygen
 *
 * Prevents an expression from being read by Doxygen.
 *
 * Used internally in this library when building its documentation.
 */
#define ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN(...)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_CONFIG_HPP
