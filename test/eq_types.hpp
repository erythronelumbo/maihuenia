// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef EQ_TYPES_HPP
#define EQ_TYPES_HPP

template <typename A, typename B>
struct eq_types
{
  enum { value = 0 };
};

template <typename A>
struct eq_types<A, A>
{
  enum { value = 1 };
};

template <typename A, typename B>
inline constexpr void test_eq_types()
{
  static_assert(eq_types<A, B>::value, "[test_eq_types] FAILED");
}

#endif // EQ_TYPES_HPP
