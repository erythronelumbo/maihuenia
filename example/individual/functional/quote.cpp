// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>


namespace mhn = erythronelumbo::maihuenia;


struct xxxxx {};
struct yyyyy {};
struct zzzzz {};
struct wwwww {};

using lifted_concat = mhn::quote<mhn::concat>;

using res = typename lifted_concat::template apply<
  mhn::cons<xxxxx, mhn::cons<yyyyy>>,
  mhn::cons<zzzzz, mhn::cons<wwwww>>
>::type;

static_assert(
  mhn::equal_types<
    res,
    mhn::make_seq_t<mhn::linked_list_tag, xxxxx, yyyyy, zzzzz, wwwww>
  >::type::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
