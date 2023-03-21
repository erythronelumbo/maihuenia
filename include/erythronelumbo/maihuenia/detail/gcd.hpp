// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_GCD_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_GCD_HPP


#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <::std::uint64_t X, ::std::uint64_t Count, ::std::uint64_t Idx>
struct ctz_impl_u64;

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 6> :
  ctz_impl_u64<
    (X >> (((X & 0x00000000ffffffffull) == 0)*32)),
    Count + ((X & 0x00000000ffffffffull) == 0)*32,
    5
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 5> :
  ctz_impl_u64<
    (X >> ((X & 0x000000000000ffffull) == 0)*16),
    Count + ((X & 0x000000000000ffffull) == 0)*16,
    4
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 4> :
  ctz_impl_u64<
    (X >> ((X & 0x00000000000000ffull) == 0)*8),
    Count + ((X & 0x00000000000000ffull) == 0)*8,
    3
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 3> :
  ctz_impl_u64<
    (X >> ((X & 0x000000000000000full) == 0)*4),
    Count + ((X & 0x000000000000000full) == 0)*4,
    2
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 2> :
  ctz_impl_u64<
    (X >> ((X & 0x0000000000000003ull) == 0)*2),
    Count + ((X & 0x0000000000000003ull) == 0)*2,
    1
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 1> :
  ctz_impl_u64<
    (X >> ((X & 0x0000000000000001ull) == 0)),
    Count + ((X & 0x0000000000000001ull) == 0),
    0
  >
{};

template <::std::uint64_t X, ::std::uint64_t Count>
struct ctz_impl_u64<X, Count, 0> : u64_c<Count>
{};


/**
 * @brief Count-trailing-zeros operation
 *
 * Counts the trailing zero bits of an integer.
 *
 * @tparam X The integer.
 */
template <::std::uint64_t X> struct ctz : ctz_impl_u64<X, 0, 6> {};

template <> struct ctz<0> : u64_c<0> {};


template <::std::uint64_t A, ::std::uint64_t B>
struct gcd;

template <::std::uint64_t A, ::std::uint64_t B>
struct gcd_impl :
  u64_c<
    (
      gcd<
        (A & 1) ? ((B & 1) ? ((A > B) ? (A - B) : (B - A)) : A) : (A >> 1),
        (B & 1) ? ((A & 1) ? ((A > B) ? B       : A      ) : B) : (B >> 1)
      >::value << ((~(A | B)) & 1)
    )
  >
{};


template <::std::uint64_t A, ::std::uint64_t B, ::std::uint64_t Z>
struct gcd_impl_z : u64_c<(gcd_impl<(A >> Z), (B >> Z)>::value << Z)> {};


template <::std::uint64_t A, ::std::uint64_t B>
struct gcd : gcd_impl_z<A, B, ctz<A | B>::value> {};

template <::std::uint64_t A> struct gcd<A, 0> : u64_c<A> {};

template <::std::uint64_t B> struct gcd<0, B> : u64_c<B> {};

template <> struct gcd<0, 0> : u64_c<0> {};

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_GCD_HPP
