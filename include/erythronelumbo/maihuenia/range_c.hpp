// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `range_c` data type
 *
 * Defines the `range_c` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_RANGE_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_RANGE_C_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/range_c.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

namespace detail
{
  template <typename, typename>
  struct range_eq;

  template <
    typename IntType1, IntType1 Stt1, ::std::size_t N1, ::std::ptrdiff_t Step1,
    typename IntType2, IntType2 Stt2, ::std::size_t N2, ::std::ptrdiff_t Step2
  >
  struct range_eq<
    range_c<IntType1, Stt1, N1, Step1>,
    range_c<IntType2, Stt2, N2, Step2>
  > :
    bool_<(Stt1 == Stt2) && (N1 == N2) && (Step1 == Step2)>
  {};

  template <typename, typename>
  struct range_neq;

  template <
    typename IntType1, IntType1 Stt1, ::std::size_t N1, ::std::ptrdiff_t Step1,
    typename IntType2, IntType2 Stt2, ::std::size_t N2, ::std::ptrdiff_t Step2
  >
  struct range_neq<
    range_c<IntType1, Stt1, N1, Step1>,
    range_c<IntType2, Stt2, N2, Step2>
  > :
    bool_<!((Stt1 == Stt2) && (N1 == N2) && (Step1 == Step2))>
  {};


  template <typename> struct range_front;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step
  >
  struct range_front<range_c<IntType, Start, Num, Step>> :
    eval_if_c<(Num == 0), identity<undefined>, integer_c<IntType, Start>>
  {};


  template <typename> struct range_pop_front;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step
  >
  struct range_pop_front<range_c<IntType, Start, Num, Step>> :
    range_c<
      IntType,
      (IntType)(Num == 0 ? Start : Start + Step),
      (Num == 0 ? 0 : Num - 1),
      Step
    >
  {};


  template <typename> struct range_empty;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step
  >
  struct range_empty<range_c<IntType, Start, Num, Step>>
  {
    using type = bool_<Num == 0>;
  };


  template <typename> struct range_back;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step
  >
  struct range_back<range_c<IntType, Start, Num, Step>> :
    eval_if_c<
      (Num == 0),
      identity<index_out_of_range>,
      integer_c<IntType, (IntType)(Start + Step*(Num - 1))>
    >
  {};


  template <typename, typename>
  struct range_at;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step,
    typename Idx
  >
  struct range_at<range_c<IntType, Start, Num, Step>, Idx> :
    eval_if_c<
      (Idx::value >= 0) && (Idx::value < Num),
      integer_c<IntType, Start + Step*(::std::ptrdiff_t)Idx::value>,
      identity<index_out_of_range>
    >
  {};

  template <
    typename IntType, IntType Start, ::std::ptrdiff_t Step,
    typename Idx
  >
  struct range_at<range_c<IntType, Start, 0, Step>, Idx> :
    identity<index_out_of_range>
  {};


  template <typename> struct range_size;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step
  >
  struct range_size<range_c<IntType, Start, Num, Step>>
  {
    using type = size_c<(::std::size_t)Num>;
  };


  template <typename, typename>
  struct range_drop;

  template <
    typename IntType, IntType Start, ::std::size_t Num, ::std::ptrdiff_t Step,
    typename N
  >
  struct range_drop<range_c<IntType, Start, Num, Step>, N> :
    eval_if_c<
      (N::value >= 0),
      if_c<
        (N::value < Num),
        range_c<
          IntType,
          Start + Step*N::value,
          Num - (::std::size_t)N::value,
          Step
        >,
        range_c<IntType, 0, 0, 1>
      >,
      identity<invalid_argument>
    >
  {};

  template <
    typename IntType, IntType Start, ::std::ptrdiff_t Step,
    typename N
  >
  struct range_drop<range_c<IntType, Start, 0, Step>, N> :
    range_c<IntType, Start, 0, Step>
  {};
} // namespace detail


template <>
struct iterable_is_random_access_impl<range_c_tag>
{
  struct apply
  {
    using type = true_;
  };
};


template <>
struct typeclass<Foldable>::define_for<range_c_tag> :
  detail::sequence_folds<range_c_tag>
{};

}} // namespace erythronelumbo::maihuenia


ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Comparable, \
  ((::erythronelumbo::maihuenia::range_c_tag)), \
  ( \
    (equals, 2, 0, (::erythronelumbo::maihuenia::detail::range_eq<X0, X1>)), \
    ( \
      not_equals, 2, 0, \
      (::erythronelumbo::maihuenia::detail::range_neq<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::range_c_tag)), \
  ( \
    (empty, 1, 0, (::erythronelumbo::maihuenia::detail::range_empty<X0>)), \
    (front, 1, 0, (::erythronelumbo::maihuenia::detail::range_front<X0>)), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::range_pop_front<X0>) \
    ) \
  ), \
  ( \
    (back, 1, 0, (::erythronelumbo::maihuenia::detail::range_back<X0>)), \
    (at, 2, 0, (::erythronelumbo::maihuenia::detail::range_at<X0, X1>)), \
    (size, 1, 0, (::erythronelumbo::maihuenia::detail::range_size<X0>)), \
    (drop, 2, 0, (::erythronelumbo::maihuenia::detail::range_drop<X0, X1>)) \
  ) \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_RANGE_C_HPP
