// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace mhn = erythronelumbo::maihuenia;

using nums = mhn::vector_c<int, 2, 3, 4, 5>;

using res = mhn::fold_left_initial<mhn::quote<mhn::mul>, nums, mhn::int_<1>>;

static_assert(
  mhn::equals_t<typename res::type, mhn::int_<120>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
