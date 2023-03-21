// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>


namespace mhn = erythronelumbo::maihuenia;

using str = ERYTHRONELUMBO_MAIHUENIA_STRING("Hello, world!");


int main()
{
  std::puts(mhn::c_str<str>::value);
  return EXIT_SUCCESS;
}
