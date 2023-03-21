// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>
#include <erythronelumbo/maihuenia/count_if.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 40)

namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders;

using the_str = STR_("The five boxing wizards jump quickly");

using res = mhn::count_if<
  the_str,
  mhn::lambda<mhn::contains<STR_("aeiouAEIOU"), _1>>
>;

static_assert(res::type::value == 10, "!!!");


int main() { return EXIT_SUCCESS; }
