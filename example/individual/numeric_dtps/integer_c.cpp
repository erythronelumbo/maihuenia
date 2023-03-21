// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;


using x1 = mhn::int_<7>;
using x2 = mhn::int_<-3>;
using x3 = mhn::int_<132>;
using x4 = mhn::int_<10>;


static_assert(
  mhn::equals_t<
    mhn::integer_c<unsigned short, 1320>,
    mhn::integer_c<long long, 1320>
  >::value, "!!!"
);

static_assert(
  mhn::equals_t<mhn::u32_c<904311>, mhn::u32_c<904311>>::value,
  "!!!"
);

static_assert(!mhn::equals_t<mhn::char_<8>, x1>::value, "!!!");

static_assert(
  mhn::not_equals_t<mhn::size_c<143>, mhn::ptrdiff_c<-109439>>::value,
  "!!!"
);

static_assert(!mhn::not_equals<x4, x4>::type::value, "!!!");


static_assert(mhn::less_t<x2, x1>::value, "!!!");
static_assert(mhn::less_equal_t<x2, x1>::value, "!!!");
static_assert(mhn::less_equal_t<x3, x3>::value, "!!!");
static_assert(mhn::greater_t<x3, x1>::value, "!!!");
static_assert(mhn::greater_equal_t<x3, x4>::value, "!!!");
static_assert(mhn::greater_equal_t<x4, x4>::value, "!!!");


static_assert(
  mhn::equal_types_t<
    mhn::incr_t<mhn::integer_c<long, 1>>,
    mhn::integer_c<long, 2>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::decr_t<mhn::integer_c<long, 1>>,
    mhn::integer_c<long, 0>
  >::value,
  "!!!"
);


static_assert(
  mhn::add<x1, x2, x3, x4>::type::value == (7 - 3 + 132 + 10),
  "!!!"
);

static_assert(mhn::sub<x3, x2>::type::value == (132 + 3), "!!!");

static_assert(mhn::sub<x2, x3>::type::value == (-3 - 132),"!!!");

static_assert(mhn::mul<x1, x4>::type::value == 70, "!!!");

static_assert(mhn::equals_t<mhn::int_<3>, mhn::abs_t<x2>>::value, "!!!");

static_assert(mhn::negate_t<x3>::value == -132, "!!!");

static_assert(
  mhn::sign<mhn::uint_<2020>>::type::value == 1, "!!!"
);
static_assert(
  mhn::sign_t<mhn::int_<-321>>::value == -1, "!!!"
);
static_assert(
  mhn::sign_t<mhn::ushort_<0>>::value == 0, "!!!"
);
static_assert(
  mhn::sign_t<mhn::integer_c<std::int16_t, -9120>>::value == -1, "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
