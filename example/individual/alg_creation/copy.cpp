// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/filled_view.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/copy.hpp>


namespace mhn = erythronelumbo::maihuenia;

using eight_voids = mhn::filled_view_c<void, 8>;

using list_of_voids = typename mhn::copy<
  mhn::linked_list_tag, eight_voids
>::type;

using expected = mhn::cons<
  void, mhn::cons<void, mhn::cons<void, mhn::cons<
    void,
    mhn::cons<void, mhn::cons<void, mhn::cons<void, mhn::cons<void>>>>
  >>>
>;

static_assert(mhn::equal_types_t<list_of_voids, expected>::value, "!!!");


int main() { return EXIT_SUCCESS; }
