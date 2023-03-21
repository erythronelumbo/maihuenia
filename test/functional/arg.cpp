// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/arg.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

template <unsigned X> struct dummy {};

template <unsigned X>
inline void test_arg()
{
  test_eq_types<
    typename mhn::arg<X>::template apply<
      dummy<0>, dummy<1>, dummy<2>, dummy<3>, dummy<4>,
      dummy<5>, dummy<6>, dummy<7>, dummy<8>, dummy<9>
    >::type,
    dummy<X>
  >();
}


int main()
{
  test_arg<0>();
  test_arg<1>();
  test_arg<2>();
  test_arg<3>();
  test_arg<4>();
  test_arg<5>();
  test_arg<6>();
  test_arg<7>();
  test_arg<8>();
  test_arg<9>();
}
