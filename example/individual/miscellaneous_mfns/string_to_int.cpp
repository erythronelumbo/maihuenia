// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string_to_int.hpp>


namespace mhn = erythronelumbo::maihuenia;

using str1 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("-60321", 6);
using str2 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("529235822043", 12);
using str3 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("-11", 3);
using str4 = ERYTHRONELUMBO_MAIHUENIA_STRING_ML("255", 3);

using res1 = typename mhn::string_to_int<str1, std::int32_t>::type;
using res2 = typename mhn::string_to_int<str2, std::uint64_t>::type;
using res3 = typename mhn::string_to_int<str3, std::int8_t>::type;
using res4 = mhn::string_to_int_t<str4, std::uint16_t>;

static_assert(mhn::equal_types_t<res1, mhn::i32_c<-60321>>::value, "!!!");
static_assert(mhn::equal_types_t<res2, mhn::u64_c<529235822043>>::value, "!!!");
static_assert(mhn::equal_types_t<res3, mhn::i8_c<-11>>::value, "!!!");
static_assert(mhn::equal_types_t<res4, mhn::u16_c<255>>::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
