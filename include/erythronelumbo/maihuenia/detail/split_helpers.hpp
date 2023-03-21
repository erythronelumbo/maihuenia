// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file split_helpers.hpp
 *
 * @brief \[...\]
 *
 * \[...\]
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_SPLIT_HELPERS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_SPLIT_HELPERS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/count_while.hpp>
#include <erythronelumbo/maihuenia/count_until.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace erythronelumbo { namespace maihuenia { namespace detail
{

template <typename Delims>
using is_delim_ = lambda<contains<Delims, placeholders::_1>>;

template <typename Str, typename Delims>
struct split_count_non_delims : count_until<Str, is_delim_<Delims>> {};

template <typename Str, typename Delims>
struct split_count_delims : count_while<Str, is_delim_<Delims>> {};

}}} // namespace erythronelumbo::maihuenia::detail


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_SPLIT_HELPERS_HPP
