// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq = mhn::cons<double, mhn::cons<bool, mhn::cons<float>>>;

using res = mhn::pop_back<seq>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    mhn::cons<double, mhn::cons<bool>>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
