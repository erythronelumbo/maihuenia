// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `vector` type
 *
 * Defines the `vector` type.
 */

/**
 * @defgroup dt_seq_vector Vector
 * @ingroup dt_sequences
 *
 * @brief Vectors
 *
 * Defines *random-access* sequences of types or integral values, where some
 * operations can be done at an almost constant complexity.
 * 
 * ### Models
 * @ref tc_iterable, @ref tc_sequence, @ref tc_monoid, @ref tc_functor,
 * @ref tc_applicative, @ref tc_monad, @ref tc_monadplus, @ref tc_foldable
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_VECTOR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_VECTOR_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_vector}
 */
struct vector_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_vector
 * @brief Vector of types
 *
 * A *random-access*, variadic sequence of types, which allows some operations
 * (like getting an element at any position) to be done with a *constant*
 * complexity.
 *
 * @see @ref vector_c
 *
 * @tparam Xs...
 *   The contained elements.
 *
 * ## Example
 *
 * @include example/individual/sequences/vector.cpp
 */
template <typename... Xs>
struct vector
{
  /**
   * @mfncalltoitself
   */
  using type = vector;

  /**
   * @memtypetag
   */
  using tag = vector_tag;
};


/**
 * @ingroup dt_seq_vector
 * @brief Vector of integral values
 *
 * A *random-access*, variadic sequence of integral values of the same type,
 * which allows some operations (like getting an element at any position) to be
 * done with a *constant* complexity. This has the same behavior of a
 * @ref vector of only @ref integer_c s
 * (`vector<integer_c<IntType, x0>, integer_c<IntType, x1>, ...>`).
 *
 * @note
 *   This data type should be considered a *special case* of @ref vector.
 *
 * @see @ref vector
 * @see @ref range_c
 * @see @ref integral_vector_c, a similar data type, but with different
 * semantics.
 *
 * @tparam IntType
 *   The type of the contained integral values.
 * @tparam Xs...
 *   The contained elements.
 *
 * ## Example
 *
 * @include example/individual/sequences/vector_c.cpp
 */
template <typename IntType, IntType... Xs>
struct vector_c
{
  /**
   * @mfncalltoitself
   */
  using type = vector_c;

  /**
   * @memtypetag
   */
  using tag = vector_tag;

  /**
   * @brief Value type
   *
   * The type of the contained elements.
   */
  using value_type = IntType;
};


/// @relates erythronelumbo::maihuenia::vector_c
template <bool... Xs>
using bool_vec = vector_c<bool, Xs...>;


/// @relates erythronelumbo::maihuenia::vector_c
template <char... Xs>
using char_vec = vector_c<char, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <short... Xs>
using short_vec = vector_c<short, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <int... Xs>
using int_vec = vector_c<int, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <long... Xs>
using long_vec = vector_c<long, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <long long... Xs>
using longlong_vec = vector_c<long long, Xs...>;


/// @relates erythronelumbo::maihuenia::vector_c
template <unsigned char... Xs>
using uchar_vec = vector_c<unsigned char, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <unsigned short... Xs>
using ushort_vec = vector_c<unsigned short, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <unsigned int... Xs>
using uint_vec = vector_c<unsigned int, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <unsigned long... Xs>
using ulong_vec = vector_c<unsigned long, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <unsigned long long... Xs>
using ulonglong_vec = vector_c<unsigned long long, Xs...>;


/// @relates erythronelumbo::maihuenia::vector_c
template <::std::int8_t... Xs>
using i8_vec = vector_c<::std::int8_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::int16_t... Xs>
using i16_vec = vector_c<::std::int16_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::int32_t... Xs>
using i32_vec = vector_c<::std::int32_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::int64_t... Xs>
using i64_vec = vector_c<::std::int64_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::uint8_t... Xs>
using u8_vec = vector_c<::std::uint8_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::uint16_t... Xs>
using u16_vec = vector_c<::std::uint16_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::uint32_t... Xs>
using u32_vec = vector_c<::std::uint32_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::uint64_t... Xs>
using u64_vec = vector_c<::std::uint64_t, Xs...>;


/// @relates erythronelumbo::maihuenia::vector_c
template <::std::intmax_t... Xs>
using intmax_vec = vector_c<::std::intmax_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::uintmax_t... Xs>
using uintmax_vec = vector_c<::std::uintmax_t, Xs...>;


/// @relates erythronelumbo::maihuenia::vector_c
template <::std::size_t... Xs>
using size_vec = vector_c<::std::size_t, Xs...>;

/// @relates erythronelumbo::maihuenia::vector_c
template <::std::ptrdiff_t... Xs>
using ptrdiff_vec = vector_c<::std::ptrdiff_t, Xs...>;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_VECTOR_HPP
