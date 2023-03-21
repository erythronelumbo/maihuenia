// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/size_of.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace erythronelumbo::maihuenia::placeholders; // _1, _2, ...


// With `bind`:

using expr1 = mhn::bind<
  mhn::quote<mhn::make_seq>,
  _1,
  mhn::protect<mhn::bind<mhn::quote<mhn::add>, _1, mhn::int_<10>>>,
  mhn::protect<mhn::bind<mhn::quote<mhn::sub>, _1, mhn::int_<29>>>,
  mhn::protect<mhn::bind<mhn::quote<mhn::mul>, _1, mhn::int_<38>>>,
  mhn::protect<mhn::bind<mhn::quote<mhn::div>, _1, mhn::int_<47>>>,
  mhn::protect<mhn::bind<mhn::quote<mhn::mod>, _1, mhn::int_<56>>>
>;

using res1 = mhn::apply_wrap_t<expr1, mhn::linked_list_tag>;

using expected1 = mhn::make_seq_t<
  mhn::linked_list_tag,
  mhn::bind<mhn::quote<mhn::add>, _1, mhn::int_<10>>,
  mhn::bind<mhn::quote<mhn::sub>, _1, mhn::int_<29>>,
  mhn::bind<mhn::quote<mhn::mul>, _1, mhn::int_<38>>,
  mhn::bind<mhn::quote<mhn::div>, _1, mhn::int_<47>>,
  mhn::bind<mhn::quote<mhn::mod>, _1, mhn::int_<56>>
>;

static_assert(mhn::equal_types<res1, expected1>::type::value, "!!!");



// With `lambda`:

using expr2 = mhn::lambda<
  mhn::transform<
    mhn::protect<
      mhn::lambda<mhn::mul<mhn::size_c<8>, mhn::size_of<_1>>>
    >,
    _1
  >
>;

using res2 = mhn::apply_wrap_t<
  expr2,
  mhn::vector<std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t>
>;

using expected2 = mhn::vector<
  mhn::size_c<8>, mhn::size_c<16>, mhn::size_c<32>, mhn::size_c<64>
>;

static_assert(mhn::equal_types<res2, expected2>::type::value, "!!!");


int main()
{
  return EXIT_SUCCESS;
}
