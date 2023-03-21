// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace mhn = erythronelumbo::maihuenia;

using zero_elem1 = mhn::mident<mhn::integer_c_tag<int>>;
using zero_elem2 = mhn::mident<mhn::string_tag>;
using zero_elem3 = mhn::mident<mhn::linked_list_tag>;
using zero_elem4 = mhn::mident_t<mhn::vector_tag>;


static_assert(
  mhn::equal_types_t<typename zero_elem1::type, mhn::integer_c<int, 0>>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<typename zero_elem2::type, mhn::string<>>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<typename zero_elem3::type, mhn::null_type>::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<zero_elem4, mhn::vector<>>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
