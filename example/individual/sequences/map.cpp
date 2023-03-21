// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/map.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 40)

namespace mhn = erythronelumbo::maihuenia;

using colors = mhn::map<
  mhn::pair<STR_("red")    , mhn::u8_vec<0xff, 0x00, 0x00>>,
  mhn::pair<STR_("yellow") , mhn::u8_vec<0xff, 0xff, 0x00>>,
  mhn::pair<STR_("green")  , mhn::u8_vec<0x00, 0xff, 0x00>>,
  mhn::pair<STR_("cyan")   , mhn::u8_vec<0x00, 0xff, 0xff>>,
  mhn::pair<STR_("blue")   , mhn::u8_vec<0x00, 0x00, 0xff>>,
  mhn::pair<STR_("magenta"), mhn::u8_vec<0xff, 0x00, 0xff>>,
  mhn::pair<STR_("black")  , mhn::u8_vec<0x00, 0x00, 0x00>>,
  mhn::pair<STR_("white")  , mhn::u8_vec<0xff, 0xff, 0xff>>
>;

using colors1 = mhn::ainsert_t<
  colors,
  mhn::pair<STR_("gray"), mhn::u8_vec<0x7f, 0x7f, 0x7f>>
>;

using colors2 = mhn::ainsert_t<
  colors1,
  mhn::pair<STR_("magenta"), double[3]>
>;

using colors3 = mhn::aerase_t<
  mhn::aerase_t<colors2, STR_("yellow")>,
  STR_("red")
>;

using colors4 = mhn::ainsert_t<
  colors3,
  mhn::pair<STR_("violet"), mhn::u8_vec<0x7f, 0x00, 0xff>>
>;

static_assert(
  mhn::equal_types_t<
    colors4,
    mhn::map<
      mhn::pair<STR_("green")  , mhn::u8_vec<0x00, 0xff, 0x00>>,
      mhn::pair<STR_("cyan")   , mhn::u8_vec<0x00, 0xff, 0xff>>,
      mhn::pair<STR_("blue")   , mhn::u8_vec<0x00, 0x00, 0xff>>,
      mhn::pair<STR_("magenta"), mhn::u8_vec<0xff, 0x00, 0xff>>,
      mhn::pair<STR_("black")  , mhn::u8_vec<0x00, 0x00, 0x00>>,
      mhn::pair<STR_("white")  , mhn::u8_vec<0xff, 0xff, 0xff>>,
      mhn::pair<STR_("gray")   , mhn::u8_vec<0x7f, 0x7f, 0x7f>>,
      mhn::pair<STR_("violet") , mhn::u8_vec<0x7f, 0x00, 0xff>>
    >
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    mhn::at_c_t<mhn::at_key_t<colors4, STR_("violet")>, 0>, mhn::u8_c<0x7f>
  >::value &&
  mhn::equal_types_t<
    mhn::at_c_t<mhn::at_key_t<colors4, STR_("violet")>, 1>, mhn::u8_c<0x00>
  >::value &&
  mhn::equal_types_t<
    mhn::at_c_t<mhn::at_key_t<colors4, STR_("violet")>, 2>, mhn::u8_c<0xff>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
