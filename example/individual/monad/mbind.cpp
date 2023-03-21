// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

template <typename D>
struct divmod
{
  template <typename X>
  struct apply :
    mhn::vector<mhn::div_t<X, D>, mhn::mod_t<X, D>>
  {};
};

template <typename ITp>
struct divmod<mhn::integer_c<ITp, 0>>
{
  template <typename X>
  struct apply : mhn::vector<> {};
};

using res = mhn::mbind<
  mhn::vector<mhn::int_<0>>,
  /* x -> {x+1, x+2, x+3} */
  mhn::lambda<
    mhn::vector<
      mhn::incr<_1>,
      mhn::incr<mhn::incr<_1>>,
      mhn::incr<mhn::incr<mhn::incr<_1>>>
    >
  >,
  /* take only the odd numbers */
  mhn::lambda<
    mhn::if_<
      mhn::equals<mhn::mod<_1, mhn::int_<2>>, mhn::int_<1>>,
      mhn::vector<_1>,
      mhn::vector<>
    >
  >,
  /* x -> {x/3, x%3} */
  /* ==> {1, 3} -> {1/3 == 0, 1%3 == 1, 3/3 == 1, 3%3 == 0} */
  divmod<mhn::int_<3>>,
  /* x -> {} if x==0, {x} otherwise */
  mhn::lambda<
    mhn::if_<
      mhn::equals<_1, mhn::int_<0>>,
      mhn::vector<>,
      mhn::vector<_1>
    >
  >,
  /* x -> {} (division by zero) */
  divmod<mhn::int_<0>>
>;

static_assert(
  mhn::equal_types_t<typename res::type, mhn::vector<>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
