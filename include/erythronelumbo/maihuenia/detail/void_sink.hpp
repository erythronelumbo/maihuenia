// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file void_sink.hpp
 *
 * @brief \[...\]
 *
 * \[...\]
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VOID_SINK_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VOID_SINK_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia { namespace detail
{

template <typename...>
struct void_sink
{
  using type = void;
};


template <typename... Ts>
using void_sink_t = typename void_sink<Ts...>::type;

}}} // namespace erythronelumbo::maihuenia::detail


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VOID_SINK_HPP
