// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file size_of.hpp
 *
 * @brief `size_of` metafunction
 *
 * Defines the `size_of` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SIZE_OF_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SIZE_OF_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_miscellaneous
 * @brief Size of a type
 *
 * Calculates the size (in bytes) of a type. Equivalent to `size_c<sizeof(T)>`.
 *
 * @tparam T
 *   Any complete type.
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/size_of.cpp
 */
template <typename T>
struct size_of
{
  using type = size_c<sizeof(T)>;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SIZE_OF_HPP
