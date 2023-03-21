// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/string.hpp>


namespace mhn = erythronelumbo::maihuenia;

using str = mhn::string<'a', 'e', 'i', 'o', 'u'>;

static_assert(
  mhn::equal_types_t<
    typename mhn::erase<str, mhn::size_c<1>>::type,
    mhn::string<'a', 'i', 'o', 'u'>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename mhn::erase_c<str, 3>::type,
    mhn::string<'a', 'e', 'i', 'u'>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
