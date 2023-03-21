// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/numeric.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>


namespace mhn = erythronelumbo::maihuenia;

using res = mhn::mul<mhn::long_<123>, mhn::long_<-321>>;

static_assert(
  mhn::equals_t<typename res::type, mhn::long_<-39483>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
