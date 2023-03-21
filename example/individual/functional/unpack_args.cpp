// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/unpack_args.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/iota.hpp>


namespace mhn = erythronelumbo::maihuenia;

using args = mhn::vector<
  mhn::linked_list_tag,
  long,
  mhn::long_<20>,
  mhn::long_<6>,
  mhn::long_<-2>
>;

using res = mhn::apply_wrap_t<
  mhn::unpack_args<mhn::quote<mhn::iota>>,
  args
>;

static_assert(
  mhn::equal_types_t<
    res,
    mhn::make_seq_t<
      mhn::linked_list_tag,
      mhn::long_<20>,
      mhn::long_<18>,
      mhn::long_<16>,
      mhn::long_<14>,
      mhn::long_<12>,
      mhn::long_<10>
    >
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
