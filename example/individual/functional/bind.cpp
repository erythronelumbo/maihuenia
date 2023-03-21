// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders; // _1, _2, ...


struct aaa {};
struct eee {};
struct iii {};
struct ooo {};
struct uuu {};

using lst = mhn::make_seq_t<mhn::linked_list_tag, aaa, eee, iii, ooo, uuu>;

using insert_a_void = mhn::bind<mhn::quote<mhn::insert>, _1, _2, void>;

static_assert(
  mhn::equal_types_t<
    mhn::apply_wrap_t<insert_a_void, lst, mhn::size_c<2>>,
    mhn::make_seq_t<mhn::linked_list_tag, aaa, eee, void, iii, ooo, uuu>
  >::value, "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
