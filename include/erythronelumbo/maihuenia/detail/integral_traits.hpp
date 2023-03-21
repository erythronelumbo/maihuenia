// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TRAITS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TRAITS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename T>
using is_signed = bool_<((T)0 > (T)(-1))>;


template <typename T>
using is_unsigned = bool_<((T)0 < (T)(-1))>;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_INTEGRAL_TRAITS_HPP
