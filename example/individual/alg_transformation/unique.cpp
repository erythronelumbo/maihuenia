// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/unique.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct red_tag {};
struct green_tag {};
struct blue_tag {};
struct alpha_tag {};

using channels = mhn::cons<
  alpha_tag,
  mhn::cons<
    red_tag,
    mhn::cons<
      blue_tag,
      mhn::cons<
        alpha_tag,
        mhn::cons<
          green_tag,
          mhn::cons<
            green_tag,
            mhn::cons<
              red_tag,
              mhn::cons<
                blue_tag
              >
            >
          >
        >
      >
    >
  >
>;

using res = mhn::unique<channels>;

using expected = mhn::cons<
  alpha_tag,
  mhn::cons<
    red_tag,
    mhn::cons<
      blue_tag,
      mhn::cons<
        green_tag
      >
    >
  >
>;

static_assert(mhn::equal_types_t<typename res::type, expected>::value, "!!!");


int main() { return EXIT_SUCCESS; }
