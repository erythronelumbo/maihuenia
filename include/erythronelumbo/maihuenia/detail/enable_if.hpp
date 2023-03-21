// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_ENABLE_IF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_ENABLE_IF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <bool C, typename T = void>
struct enable_if
{
  using type = T;
};

template <typename T>
struct enable_if<false, T>
{};


template <bool C, typename T = void>
using enable_if_t = typename enable_if<C, T>::type;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_ENABLE_IF_HPP
