// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `bind` metafunction class
 *
 * Defines the `bind` metafunction class.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_BIND_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_BIND_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

template <typename Fn, typename... Args>
struct bind;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_BIND_HPP
