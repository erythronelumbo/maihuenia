// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file c_str.hpp
 *
 * @brief `c_str` metafunction
 *
 * Defines the `c_str` utility metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_C_STR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_C_STR_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/fwd/string.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <char...> struct c_str_accum {};

  template <typename It, typename, bool = empty<It>::type::value>
  struct c_str_helper_impl;

  template <typename It, char... Cs>
  struct c_str_helper_impl<It, c_str_accum<Cs...>, false> :
    c_str_helper_impl<
      pop_front_t<It>,
      c_str_accum<Cs..., (char)front_t<It>::value>
    >
  {};

  template <typename It, char... Cs>
  struct c_str_helper_impl<It, c_str_accum<Cs...>, true>
  {
    static constexpr const char value[sizeof...(Cs) + 1] = {Cs..., '\0'};
  };

  template <typename It, char... Cs>
  constexpr const char
  c_str_helper_impl<It, c_str_accum<Cs...>, true>::value[sizeof...(Cs) + 1];

  template <typename It>
  using c_str_helper = c_str_helper_impl<It, c_str_accum<>>;
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup mfn_miscellaneous
 * @brief Type to C string
 *
 * Represents a string-like type as a zero-terminated C string, if possible.
 *
 * @tparam Str
 *   An @ref tc_iterable with elements which underlying values can be converted
 *   to `char`-typed values.
 *
 * ## Example
 *
 * @include example/individual/miscellaneous_mfns/c_str.cpp
 */
template <typename Str>
struct c_str
{
  /**
   * @mfncalltoitself
   */
  using type = c_str;

  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Resulting string
   *
   * A static, constant array representing a zero-terminated C string. The size
   * of this array is `size<Str>::value + 1`, since it has a final zero
   * character.
   */
  static constexpr const char* value = unspecified;

  #else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  static constexpr const char* value = detail::c_str_helper<Str>::value;
  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

template <typename Str>
constexpr const char* c_str<Str>::value;

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
template <char... Cs>
struct c_str<string<Cs...>>
{
  using type = c_str;
  static constexpr const char value[sizeof...(Cs) + 1] = {Cs..., '\0'};
};
template <char... Cs>
constexpr const char c_str<string<Cs...>>::value[sizeof...(Cs) + 1];
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_C_STR_HPP
