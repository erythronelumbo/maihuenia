// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/monad_plus.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

template <typename D>
struct divmod
{
  template <typename X>
  struct apply :
    mhn::cons<
      mhn::div_t<X, D>,
      mhn::cons<
        mhn::mod_t<X, D>
      >
    >
  {};
};

template <typename ITp>
struct divmod<mhn::integer_c<ITp, 0>>
{
  template <typename X>
  struct apply : mhn::null_type {};
};

using res = mhn::mplus<
  mhn::mbind_t<mhn::cons<mhn::uint_<10>>, divmod<mhn::uint_<0>>>,
  mhn::mbind_t<mhn::cons<mhn::uint_<10>>, divmod<mhn::uint_<5>>>,
  mhn::mbind_t<mhn::cons<mhn::uint_<10>>, divmod<mhn::uint_<3>>>
>;

using expected = mhn::make_seq_t<
  mhn::linked_list_tag,
  mhn::uint_<2>, mhn::uint_<0>,
  mhn::uint_<3>, mhn::uint_<1>
>;

static_assert(
  mhn::equals_t<typename res::type, expected>::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
