// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/count_if.hpp>


namespace mhn = erythronelumbo::maihuenia;

using the_str = ERYTHRONELUMBO_MAIHUENIA_STRING("Hello, world!");

using res = typename mhn::count<the_str, mhn::char_<'l'>>::type;

static_assert(res::value == 3, "!!!");


int main() { return EXIT_SUCCESS; }
