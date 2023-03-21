// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file empty_base.hpp
 *
 * @brief `empty_base` data type
 *
 * Defines the `empty_base` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_EMPTY_BASE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_EMPTY_BASE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup dt_miscellaneous
 * @brief Empty base class
 *
 * An *empty base* class, which can be used in @ref inherit as a *no-op*.
 */
struct empty_base {};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_EMPTY_BASE_HPP
