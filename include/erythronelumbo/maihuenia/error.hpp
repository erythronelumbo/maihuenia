// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file error.hpp
 *
 * @brief Error codes
 *
 * Contains error codes.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ERROR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ERROR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/define_error.hpp>

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR( \
  (erythronelumbo, maihuenia), index_out_of_range \
);
ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR( \
  (erythronelumbo, maihuenia), invalid_argument \
);
ERYTHRONELUMBO_MAIHUENIA_DEFINE_ERROR( \
  (erythronelumbo, maihuenia), division_by_zero \
);


#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup err_codes
 * @brief *Index out of range* error
 *
 * Used as a result of attempting to access an element outside a defined range.
 */
struct index_out_of_range { /* ...unspecified... */ };

/**
 * @ingroup err_codes
 * @brief *Invalid argument* error
 *
 * Used as a result of passing wrong or invalid arguments to a metafunction.
 */
struct invalid_argument { /* ...unspecified... */ };

/**
 * @ingroup err_codes
 * @brief Division by zero error
 *
 * Used as a result when there is a division by zero.
 */
struct division_by_zero { /* ...unspecified... */ };

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_ERROR_HPP
