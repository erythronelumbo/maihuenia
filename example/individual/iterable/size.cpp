// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res1 = mhn::size<mhn::null_type>;
using res2 = mhn::size<mhn::vector<>>;
using res3 = mhn::size<mhn::cons<int, mhn::cons<void, mhn::cons<double>>>>;
using res4 = typename mhn::size<mhn::vector<int, void, double, void*>>::type;

static_assert(
  mhn::equals_t<typename res1::type, mhn::size_c<0>>::value, "!!!"
);
static_assert(
  mhn::equals_t<typename res2::type, mhn::size_c<0>>::value, "!!!"
);
static_assert(
  mhn::equals_t<typename res3::type, mhn::size_c<3>>::value, "!!!"
);
static_assert(
  mhn::equals_t<res4, mhn::size_c<4>>::value, "!!!"
);


int main() { return EXIT_SUCCESS; }
