// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/is_permutation.hpp>


namespace mhn = erythronelumbo::maihuenia;

using word1 = mhn::string<'L', 'I', 'S', 'T', 'E', 'N'>;
using word2 = mhn::vector_c<char, 'S', 'I', 'L', 'E', 'N', 'T'>;
using word3 = mhn::string<'S', 'T', 'I', 'L', 'L'>;

using res1 = mhn::is_permutation_t<word1, word2>;
using res2 = mhn::is_permutation<word2, word3>;

static_assert(res1::value, "!!!");
static_assert(!res2::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
