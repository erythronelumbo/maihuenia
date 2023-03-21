// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/all_of.hpp>

#include "../eq_types.hpp"



namespace mhn = erythronelumbo::maihuenia;

struct geq5
{
  template <typename X>
  struct apply : mhn::greater_equal<X, mhn::uint_<5>> {};
};


struct geq5_
{
  template <typename X>
  struct apply : mhn::greater_equal<X, mhn::int_<5>> {};
};


int main()
{
  using tv1 = mhn::vector_c<unsigned>;
  using tv2 = mhn::vector_c<unsigned, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9>;
  using tv3 = mhn::vector_c<unsigned, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14>;
  using tv4 = mhn::vector_c<int, -4, -3, -2, -1, 0>;

  static_assert(mhn::all_of<tv1, geq5>::type::value, "!!!");
  static_assert(!mhn::all_of<tv2, geq5>::type::value, "!!!");
  static_assert(mhn::all_of<tv3, geq5>::type::value, "!!!");
  static_assert(!mhn::all_of<tv4, geq5_>::type::value, "!!!");

  return EXIT_SUCCESS;
}
