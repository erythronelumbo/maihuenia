// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using seq = mhn::vector<char, float, std::size_t>;

using res = mhn::push_back<seq, void>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    mhn::vector<char, float, std::size_t, void>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
