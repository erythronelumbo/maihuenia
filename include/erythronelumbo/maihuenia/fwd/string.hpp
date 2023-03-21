// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `string` type
 *
 * Defines the `string` data type.
 */

/**
 * @defgroup dt_seq_string string
 * @ingroup dt_sequences
 *
 * @brief String
 *
 * A sequence that represents a string.
 *
 * ### Models
 * @ref tc_iterable, @ref tc_foldable, @ref tc_sequence, @ref tc_monoid,
 * @ref tc_withstringrepr
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_STRING_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_STRING_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_string}
 */
struct string_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_string
 * @brief String
 *
 * A sequence that represents a string.
 *
 * @tparam Chars...
 *   The characters that compose the string.
 *
 * ## Example
 *
 * @include example/individual/sequences/string.cpp
 */
template <char... Chars>
struct string
{
  /**
   * @mfncalltoitself
   */
  using type = string;

  /**
   * @memtypetag
   */
  using tag = string_tag;

  /**
   * @brief Value type
   *
   * The type of the contained elements.
   */
  using value_type = char;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename, typename>
  struct str_concat_two;

  template <char... Chs1, char... Chs2>
  struct str_concat_two<string<Chs1...>, string<Chs2...>> :
    string<Chs1..., Chs2...>
  {};


  template <::std::size_t N>
  inline constexpr char cstr_gch_(const char (&str)[N], const ::std::size_t i)
  {
    return i >= N ? '\0' : str[i];
  }
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  #include <erythronelumbo/maihuenia/detail/get_string_chars.hpp>

  #define ERYTHRONELUMBO_MAIHUENIA_STRING_MAX_ALLOWED_LENGTH \
  ERYTHRONELUMBO_MAIHUENIA_STRING_DETAIL_MAX_ALLOWED_LENGTH

  #define ERYTHRONELUMBO_MAIHUENIA_STRING(str_) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL( \
    ERYTHRONELUMBO_MAIHUENIA_STRING_DETAIL_MAX_ALLOWED_LENGTH \
  )( \
    ::erythronelumbo::maihuenia::string<>, \
    (str_) \
  )

  #define ERYTHRONELUMBO_MAIHUENIA_STRING_ML(str_, maxlen_) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_GSC_IMPL(maxlen_)( \
    ::erythronelumbo::maihuenia::string<>, \
    (str_) \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup dt_seq_string
 * @brief Maximum possible length of string literals for `string` construction
 *
 * Indicates the maximum possible length of the string literals that are used
 * for constructing instances of `string` with the preprocessor-based
 * facilities.
 * 
 * This constant is automatically defined when building this library.
 */
#define ERYTHRONELUMBO_MAIHUENIA_STRING_MAX_ALLOWED_LENGTH /* unspecified */


/**
 * @ingroup dt_seq_string
 * @brief String constructor using a string literal
 *
 * Constructs a `string` from a string literal.
 *
 * @note This cannot admit string literals that have a higher length that what
 * is indicated by `ERYTHRONELUMBO_MAIHUENIA_STRING_MAX_ALLOWED_LENGTH`,
 * because of the limitations of C++'s preprocessor.
 *
 * @param str_
 *   A string literal.
 */
#define ERYTHRONELUMBO_MAIHUENIA_STRING(str_) /* unspecified */


/**
 * @ingroup dt_seq_string
 * @brief String constructor using a string literal
 *
 * Constructs a `string` from a string literal and a known maximum length, which
 * cannot be higher than `ERYTHRONELUMBO_MAIHUENIA_STRING_MAX_ALLOWED_LENGTH`.
 *
 * @note This cannot admit string literals that have a higher length that what
 * is indicated by `ERYTHRONELUMBO_MAIHUENIA_STRING_MAX_ALLOWED_LENGTH`,
 * because of the limitations of C++'s preprocessor.
 *
 * @param str_
 *   A string literal.
 * @param maxlen_
 *   The known maximum length.
 */
#define ERYTHRONELUMBO_MAIHUENIA_STRING_ML(str_, maxlen_) /* unspecified */

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_STRING_HPP
