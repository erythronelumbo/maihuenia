// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/monad_plus.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

static_assert(
  mhn::equal_types_t<
    typename mhn::mzero<mhn::linked_list_tag>::type,
    mhn::null_type
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
