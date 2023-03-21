// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/lexicographical_compare.hpp>


#define STR_ ERYTHRONELUMBO_MAIHUENIA_STRING

namespace mhn = erythronelumbo::maihuenia;

using word1 = STR_("ant");
using word2 = STR_("bed bug");
using word3 = STR_("beetle");

using cmp_ = mhn::quote<mhn::less>;

using res1 = mhn::lexicographical_compare<word1, word2, cmp_>;
using res2 = mhn::lexicographical_compare<word1, word3, cmp_>;
using res3 = mhn::lexicographical_compare<word2, word3, cmp_>;
using res4 = mhn::lexicographical_compare<word3, word1, cmp_>;

static_assert(res1::type::value, "!!!");
static_assert(res2::type::value, "!!!");
static_assert(res3::type::value, "!!!");
static_assert(!res4::type::value, "!!!");


int main() { return EXIT_SUCCESS; }

