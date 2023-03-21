// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/always.hpp>


namespace mhn = erythronelumbo::maihuenia;


using hello = mhn::string<'H', 'e', 'l', 'l', 'o', '!'>;

using mfn = mhn::always<hello>;

using res1 = typename mfn::template apply<char[10], void, void*>::type;
using res2 = typename mfn::template apply<>::type;
using res3 = typename mfn::template apply<bool>::type;


static_assert(mhn::equal_types_t<res1, hello>::value, "!!!");
static_assert(mhn::equal_types_t<res2, hello>::value, "!!!");
static_assert(mhn::equal_types_t<res3, hello>::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
