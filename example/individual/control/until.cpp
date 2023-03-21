// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/until.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;


template <typename X>
struct factorial :
  mhn::at_c<
    mhn::until_t<
      /* Keep calculating until `n == 1` */
      mhn::lambda<
        mhn::equals<
          mhn::integer_c<typename X::value_type, 1>,
          mhn::at<_1, mhn::size_c<0>>
        >
      >,
      /* State transformation: `{n, r} -> {n-1, r*(n-1)}` */
      mhn::lambda<
        mhn::vector<
          mhn::decr<mhn::at<_1, mhn::size_c<0>>>,
          mhn::mul<
            mhn::at<_1, mhn::size_c<1>>,
            mhn::decr<mhn::at<_1, mhn::size_c<0>>>
          >
        >
      >,
      mhn::vector<X, X>
    >,
    1
  >
{};

static_assert(factorial<mhn::uint_<5>>::type::value == 5*4*3*2*1, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
