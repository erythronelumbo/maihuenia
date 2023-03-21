// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file bitwise.hpp
 *
 * @brief `Bitwise` typeclass
 *
 * Defines the `Bitwise` typeclass.
 */

/**
 * @defgroup tc_bitwise Bitwise
 * @ingroup typeclasses
 *
 * @brief Sequences of bits
 *
 * Corresponds to types that represent sequences of bits or behave as such. In a
 * way analogous to @ref tc_logical, this typeclass also provides logical
 * operations, but they are done with each bit contained in the sequences.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_BITWISE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_BITWISE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_bitwise}
 */
struct Bitwise ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Bitwise, \
    2, \
    (), \
    ( \
      (bit_and, 1, (0)), \
      (bit_or, 1, (0)), \
      (bit_xor, 1, (0)), \
      (bit_not, 0, 1, 0, 0, (0)), \
      (shift_left, 1, (0)), \
      (shift_right, 1, (0)) \
    ), \
    () \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_bitwise
 * @brief Bitwise AND
 *
 * Performs a bitwise AND of several sequences of bits.
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 *
 * ## Example
 *
 * @include example/individual/bitwise/bit_and.cpp
 */
template <typename X1, typename X2, typename... Xs>
struct bit_and
{
  /**
   * @brief Result
   *
   * A value equivalent to `X1 & X2 & ...`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_bitwise
 * @brief Bitwise OR
 *
 * Performs a bitwise OR of several sequences of bits.
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 *
 * ## Example
 *
 * @include example/individual/bitwise/bit_or.cpp
 */
template <typename X1, typename X2, typename... Xs>
struct bit_or
{
  /**
   * @brief Result
   *
   * A value equivalent to `X1 | X2 | ...`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_bitwise
 * @brief Bitwise XOR
 *
 * Performs a bitwise XOR of several sequences of bits.
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 *
 * ## Example
 *
 * @include example/individual/bitwise/bit_xor.cpp
 */
template <typename X1, typename X2, typename... Xs>
struct bit_xor
{
  /**
   * @brief Result
   *
   * A value equivalent to `X1 ^ X2 ^ ...`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_bitwise
 * @brief Bitwise NOT
 *
 * Negates the bits of a given sequence of bits: zero bits are *flipped* to one
 * and viceversa.
 *
 * @tparam X
 *   The sequence of bits.
 *
 * ## Example
 *
 * @include example/individual/bitwise/bit_not.cpp
 */
template <typename X>
struct bit_not
{
  /**
   * @brief Result
   *
   * The value given in `X`, but its bits are *flipped*. Equivalent to `~X`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_bitwise
 * @brief Shifts bits to the left
 *
 * Shifts the bits of a sequence of bits to the left.
 *
 * @tparam X
 *   A sequence of bits.
 * @tparam Sh1
 *   The ammount of bits to shift.
 * @tparam Shs...
 *   Bits to shift.
 *
 * ## Example
 *
 * @include example/individual/bitwise/shift_left.cpp
 */
template <typename X, typename Sh1, typename... Shs>
struct shift_left
{
  /**
   * @brief Result
   *
   * A value equivalent to `(((X << Sh1) << Sh2) ...) << ShN`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_bitwise
 * @brief Shifts bits to the right
 *
 * Shifts the bits of a sequence of bits to the right.
 *
 * @tparam X
 *   A sequence of bits.
 * @tparam Sh1
 *   The ammount of bits to shift.
 * @tparam Shs...
 *   Bits to shift.
 *
 * ## Example
 *
 * @include example/individual/bitwise/shift_right.cpp
 */
template <typename X, typename Sh1, typename... Shs>
struct shift_right
{
  /**
   * @brief Result
   *
   * A value equivalent to `(((X >> Sh1) >> Sh2) ...) >> ShN`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::bit_and
 *
 * @invokesmfn{bit_and}
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 */
template <typename X1, typename X2, typename... Xs>
using bit_and_t = typename bit_and<X1, X2, Xs...>::type;


/**
 * @relates erythronelumbo::maihuenia::bit_or
 *
 * @invokesmfn{bit_or}
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 */
template <typename X1, typename X2, typename... Xs>
using bit_or_t = typename bit_or<X1, X2, Xs...>::type;


/**
 * @relates erythronelumbo::maihuenia::bit_xor
 *
 * @invokesmfn{bit_xor}
 *
 * @tparam X1
 *   A sequence of bits.
 * @tparam X2
 *   A sequence of bits.
 * @tparam Xs...
 *   Sequences of bits.
 */
template <typename X1, typename X2, typename... Xs>
using bit_xor_t = typename bit_xor<X1, X2, Xs...>::type;


/**
 * @relates erythronelumbo::maihuenia::bit_not
 *
 * @invokesmfn{bit_not}
 *
 * @tparam X
 *   The sequence of bits.
 */
template <typename X>
using bit_not_t = typename bit_not<X>::type;


/**
 * @relates erythronelumbo::maihuenia::shift_left
 *
 * @invokesmfn{shift_left}
 *
 * @tparam X
 *   A sequence of bits.
 * @tparam Sh1
 *   The ammount of bits to shift.
 * @tparam Shs...
 *   Bits to shift.
 */
template <typename X, typename Sh1, typename... Shs>
using shift_left_t = typename shift_left<X, Sh1, Shs...>::type;


/**
 * @relates erythronelumbo::maihuenia::shift_right
 *
 * @invokesmfn{shift_right}
 *
 * @tparam X
 *   A sequence of bits.
 * @tparam Sh1
 *   The ammount of bits to shift.
 * @tparam Shs...
 *   Bits to shift.
 */
template <typename X, typename Sh1, typename... Shs>
using shift_right_t = typename shift_right<X, Sh1, Shs...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_BITWISE_HPP
