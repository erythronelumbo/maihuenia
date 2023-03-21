// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file iota.hpp
 *
 * @brief `iota` metafunction
 *
 * Defines the `iota` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_IOTA_HPP
#define ERYTHRONELUMBO_MAIHUENIA_IOTA_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  // Note: `Xe` is assumed to be greater than or equal to `Xs` and
  // `(Xe - Xs) > 0`.

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off,
    ::std::ptrdiff_t Diff = (Xe - Xs)
  >
  struct iota_helper :
    concat<
      typename iota_helper<
        SeqTag, IntType, Xs, ((Xs + Xe)/2), Step, Off
      >::type,
      typename iota_helper<
        SeqTag, IntType, ((Xs + Xe)/2) + 1, Xe, Step, Off
      >::type
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 8> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + (Xs + 3)*Step>,
      integer_c<IntType, Off + (Xs + 4)*Step>,
      integer_c<IntType, Off + (Xs + 5)*Step>,
      integer_c<IntType, Off + (Xs + 6)*Step>,
      integer_c<IntType, Off + (Xs + 7)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 7> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + (Xs + 3)*Step>,
      integer_c<IntType, Off + (Xs + 4)*Step>,
      integer_c<IntType, Off + (Xs + 5)*Step>,
      integer_c<IntType, Off + (Xs + 6)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 6> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + (Xs + 3)*Step>,
      integer_c<IntType, Off + (Xs + 4)*Step>,
      integer_c<IntType, Off + (Xs + 5)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 5> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + (Xs + 3)*Step>,
      integer_c<IntType, Off + (Xs + 4)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 4> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + (Xs + 3)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 3> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + (Xs + 2)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 2> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + (Xs + 1)*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 1> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>,
      integer_c<IntType, Off + Xe*Step>
    >
  {};

  template <
    typename SeqTag, typename IntType,
    IntType Xs,
    IntType Xe,
    ::std::ptrdiff_t Step,
    IntType Off
  >
  struct iota_helper<SeqTag, IntType, Xs, Xe, Step, Off, 0> :
    make_seq<
      SeqTag,
      integer_c<IntType, Off + Xs*Step>
    >
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Generates a sequence
 *
 * Generates a @ref tc_sequence with increasing or decreasing integral values.
 *
 * @see @ref range_c
 *
 * @tparam Tag
 *   The tag of the @ref tc_sequence to generate.
 * @tparam IntType
 *   The type of the encapsulated/contained values. It must be integral.
 * @tparam Start
 *   The initial value.
 * @tparam Num
 *   An integral constant with the number of values.
 * @tparam Step
 *   The increment or decrement.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/iota.cpp
 */
template <
  typename Tag, typename IntType, typename Start, typename Num,
  typename Step = ptrdiff_c<1>
>
struct iota
#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  : eval_if_c<
    (Num::value > 0),
    detail::iota_helper<
      Tag, IntType,
      (IntType)0,
      (IntType)(Num::value <= 0 ? 0 : Num::value - 1),
      (::std::ptrdiff_t)Step::value,
      Start::value
    >,
    make_seq<Tag>
  >
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence containing increasing or decreasing integral values.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @ingroup alg_creation
 * @brief Generates a sequence
 *
 * Generates a @ref tc_sequence with increasing or decreasing integral values.
 *
 * @see @ref range_c
 *
 * @tparam Tag
 *   The tag of the @ref tc_sequence to generate.
 * @tparam IntType
 *   The type of the encapsulated/contained values. It must be integral.
 * @tparam Start
 *   The initial value.
 * @tparam Num
 *   The number of values.
 * @tparam Step
 *   The increment or decrement.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/iota.cpp
 */
template <
  typename Tag, typename IntType, IntType Start, ::std::size_t Num,
  ::std::ptrdiff_t Step = 1
>
struct iota_c
#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  : eval_if_c<
    (Num > 0),
    detail::iota_helper<
      Tag, IntType, 0, (Num == 0 ? 0 : Num - 1), Step, Start
    >,
    make_seq<Tag>
  >
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence containing increasing or decreasing integral values.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::iota
 *
 * @invokesmfn{iota}
 *
 * @tparam Tag
 *   The tag of the @ref tc_sequence to generate.
 * @tparam IntType
 *   The type of the encapsulated/contained values. It must be integral.
 * @tparam Start
 *   The initial value.
 * @tparam Num
 *   An integral constant with the number of values.
 * @tparam Step
 *   The increment or decrement.
 */
template <
  typename Tag, typename IntType, typename Start, typename Num,
  typename Step = ptrdiff_c<1>
>
using iota_t = typename iota<Tag, IntType, Start, Num, Step>::type;


/**
 * @relates erythronelumbo::maihuenia::iota_c
 *
 * @invokesmfn{iota_c}
 *
 * @tparam Tag
 *   The tag of the @ref tc_sequence to generate.
 * @tparam IntType
 *   The type of the encapsulated/contained values. It must be integral.
 * @tparam Start
 *   The initial value.
 * @tparam Num
 *   The number of values.
 * @tparam Step
 *   The increment or decrement.
 */
template <
  typename Tag, typename IntType, IntType Start, ::std::size_t Num,
  ::std::ptrdiff_t Step = 1
>
using iota_c_t = typename iota_c<Tag, IntType, Start, Num, Step>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_IOTA_HPP
