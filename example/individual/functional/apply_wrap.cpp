// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct pyth
{
  template <typename X, typename Y, typename Z>
  struct apply :
    mhn::add<mhn::mul_t<X, X>, mhn::mul_t<Y, Y>, mhn::mul_t<Z, Z>>
  {};
};

using res = typename mhn::apply_wrap<
  pyth, mhn::int_<3>, mhn::int_<-2>, mhn::int_<-4>
>::type;

static_assert(res::value == (3*3 + 2*2 + 4*4), "!!!");


int main()
{
  return EXIT_SUCCESS;
}
