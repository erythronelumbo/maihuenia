// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file version.hpp
 *
 * @brief Version
 *
 * Contains the version of this library.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_VERSION_HPP
#define ERYTHRONELUMBO_MAIHUENIA_VERSION_HPP


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_STRINGIZE_VERSION_(mj, mn, pt) \
  #mj "." #mn "." #pt

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_STRINGIZE_VERSION(mj, mn, pt) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_STRINGIZE_VERSION_(mj, mn, pt)
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup lib_info
 * @brief Major version
 *
 * The *major* version of this library.
 */
#define ERYTHRONELUMBO_MAIHUENIA_VERSION_MAJOR 0

/**
 * @ingroup lib_info
 * @brief Minor version
 *
 * The *minor* version of this library.
 */
#define ERYTHRONELUMBO_MAIHUENIA_VERSION_MINOR 1


/**
 * @ingroup lib_info
 * @brief Patch version
 *
 * The *patch* version of this library.
 */
#define ERYTHRONELUMBO_MAIHUENIA_VERSION_PATCH 0


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #define ERYTHRONELUMBO_MAIHUENIA_VERSION           \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_STRINGIZE_VERSION( \
    ERYTHRONELUMBO_MAIHUENIA_VERSION_MAJOR,          \
    ERYTHRONELUMBO_MAIHUENIA_VERSION_MINOR,          \
    ERYTHRONELUMBO_MAIHUENIA_VERSION_PATCH           \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup lib_info
 * @brief Version of this library
 *
 * The version of this library, represented as a string literal in the form
 * `"x.y.z"` (`x`: major, `y`: minor, `z`: patch).
 */
#define ERYTHRONELUMBO_MAIHUENIA_VERSION /* see description */

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_VERSION_HPP
