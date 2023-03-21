// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders; // _1, _2, ...

using naive_iota = mhn::lambda<
  mhn::make_seq<
    _1,
    mhn::add<mhn::mul<_2, mhn::intmax_c<0>>, _3>,
    mhn::add<mhn::mul<_2, mhn::intmax_c<1>>, _3>,
    mhn::add<mhn::mul<_2, mhn::intmax_c<2>>, _3>,
    mhn::add<mhn::mul<_2, mhn::intmax_c<3>>, _3>,
    mhn::add<mhn::mul<_2, mhn::intmax_c<4>>, _3>
  >
>;

using compare_five_elems = mhn::lambda<
  mhn::logical_and<
    mhn::equals<mhn::at<_1, mhn::size_c<0>>, _2>,
    mhn::equals<mhn::at<_1, mhn::size_c<1>>, _3>,
    mhn::equals<mhn::at<_1, mhn::size_c<2>>, _4>,
    mhn::equals<mhn::at<_1, mhn::size_c<3>>, _5>,
    mhn::equals<mhn::at<_1, mhn::size_c<4>>, _6>
  >
>;

using res = typename naive_iota::template apply<
  mhn::vector_tag, mhn::intmax_c<3>, mhn::intmax_c<1>
>::type;


static_assert(
  mhn::apply_wrap_t<
    compare_five_elems,
    res,
    mhn::intmax_c<1>,
    mhn::intmax_c<4>,
    mhn::intmax_c<7>,
    mhn::intmax_c<10>,
    mhn::intmax_c<13>
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
