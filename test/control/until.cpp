// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/until.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;


template <typename X> struct fn { using type = fn; };

template <typename X>
struct stop_fn_impl : mhn::false_ {};
template <>
struct stop_fn_impl<fn<fn<fn<fn<void>>>>> : mhn::true_ {};

struct stop_fn
{
  template <typename X>
  using apply = stop_fn_impl<X>;
};

struct fn_q { template <typename X> using apply = fn<X>; };


int main()
{
  test_eq_types<
    typename mhn::until<stop_fn, fn_q, void>::type,
    fn<fn<fn<fn<void>>>>
  >();
}
