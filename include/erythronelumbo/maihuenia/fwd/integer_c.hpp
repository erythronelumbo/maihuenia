// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `integer_c` data type
 *
 * Defines the `integer_c` data type.
 */

/**
 * @defgroup dt_num_integer_c integer_c
 * @ingroup dt_numeric
 *
 * @brief Integral constant
 *
 * Describes a data type that wraps an integral constant.
 *
 * ### Models
 *
 * @ref cn_integralconstant, @ref tc_enumerable, @ref tc_comparable,
 * @ref tc_orderable, @ref tc_logical, @ref tc_bitwise, @ref tc_numeric,
 * @ref tc_integral, @ref tc_withstringrepr, @ref tc_monoid
 *
 * @note
 *   Integral types have two monoidal operations, addition and multiplication,
 *   with zero and one as their respective identity values, but addition was
 *   chosen to be used for implementing the @ref tc_monoid typeclass.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGER_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGER_C_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_num_integer_c}
 */
template <typename IntType>
struct integer_c_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_num_integer_c
 * @brief Integral constant
 *
 * A data type that wraps an integral constant, as well as its type.
 *
 * @tparam IntType
 *   The type of the constant, which must be integral.
 * @tparam X
 *   The value.
 *
 * ## Example
 *
 * @include example/individual/numeric_dtps/integer_c.cpp
 */
template <typename IntType, IntType X>
struct integer_c
{
  /**
   * @mfncalltoitself
   */
  using type = integer_c;

  /**
   * @memtypetag
   */
  using tag = integer_c_tag<IntType>;

  /**
   * @brief Value type
   *
   * The type of the wrapped constant.
   */
  using value_type = IntType;

  /**
   * @brief Value
   *
   * The value of the wrapped constant.
   */
  static constexpr IntType value = X;

  /**
   * @brief Conversion
   *
   * Returns the wrapped value. This allows @ref integer_c to be treated as a
   * value of its underlying type.
   */
  inline constexpr operator value_type() const noexcept
  {
    return value;
  }

  /**
   * @brief Call
   *
   * Returns the wrapped value. This allows @ref integer_c to be used as a
   * function object at runtime.
   */
  inline constexpr value_type operator()() const noexcept
  {
    return value;
  }
};

template <typename IntType, IntType X>
constexpr IntType integer_c<IntType, X>::value;


/// @relates integer_c
template <bool X>
using bool_ = integer_c<bool, X>;


/// @relates integer_c
using true_ = integer_c<bool, true>;

/// @relates integer_c
using false_ = integer_c<bool, false>;


/// @relates integer_c
template <char X>
using char_ = integer_c<char, X>;

/// @relates integer_c
template <short X>
using short_ = integer_c<short, X>;

/// @relates integer_c
template <int X>
using int_ = integer_c<int, X>;

/// @relates integer_c
template <long X>
using long_ = integer_c<long, X>;

/// @relates integer_c
template <long long X>
using longlong_ = integer_c<long long, X>;


/// @relates integer_c
template <unsigned char X>
using uchar_ = integer_c<unsigned char, X>;

/// @relates integer_c
template <unsigned short X>
using ushort_ = integer_c<unsigned short, X>;

/// @relates integer_c
template <unsigned int X>
using uint_ = integer_c<unsigned int, X>;

/// @relates integer_c
template <unsigned long X>
using ulong_ = integer_c<unsigned long, X>;

/// @relates integer_c
template <unsigned long long X>
using ulonglong_ = integer_c<unsigned long long, X>;


/// @relates integer_c
template <::std::int8_t X>
using i8_c = integer_c<::std::int8_t, X>;

/// @relates integer_c
template <::std::int16_t X>
using i16_c = integer_c<::std::int16_t, X>;

/// @relates integer_c
template <::std::int32_t X>
using i32_c = integer_c<::std::int32_t, X>;

/// @relates integer_c
template <::std::int64_t X>
using i64_c = integer_c<::std::int64_t, X>;

/// @relates integer_c
template <::std::uint8_t X>
using u8_c = integer_c<::std::uint8_t, X>;

/// @relates integer_c
template <::std::uint16_t X>
using u16_c = integer_c<::std::uint16_t, X>;

/// @relates integer_c
template <::std::uint32_t X>
using u32_c = integer_c<::std::uint32_t, X>;

/// @relates integer_c
template <::std::uint64_t X>
using u64_c = integer_c<::std::uint64_t, X>;


/// @relates integer_c
template <::std::intmax_t X>
using intmax_c = integer_c<::std::intmax_t, X>;

/// @relates integer_c
template <::std::uintmax_t X>
using uintmax_c = integer_c<::std::uintmax_t, X>;


/// @relates integer_c
template <::std::size_t X>
using size_c = integer_c<::std::size_t, X>;

/// @relates integer_c
template <::std::ptrdiff_t X>
using ptrdiff_c = integer_c<::std::ptrdiff_t, X>;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_INTEGER_C_HPP
