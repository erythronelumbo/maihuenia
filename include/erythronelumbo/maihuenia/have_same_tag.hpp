// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file have_same_tag.hpp
 *
 * @brief `have_same_tag` metafunction
 *
 * Defines the `have_same_tag` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_HAVE_SAME_TAG_HPP
#define ERYTHRONELUMBO_MAIHUENIA_HAVE_SAME_TAG_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_core
 * @brief Checks equality of type tags
 *
 * Checks if several value types have the same *type tag*.
 *
 * @tparam Ts...
 *   The elements to check.
 */
template <typename... Ts>
using have_same_tag = equal_types<typename tag<Ts>::type...>;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_HAVE_SAME_TAG_HPP
