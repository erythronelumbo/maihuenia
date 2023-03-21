// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/optional.hpp>

#include "../eq_types.hpp"

namespace mhn = erythronelumbo::maihuenia;

struct x0 {};
struct x1 {};

template <typename...> struct res0 { using type = res0; };
template <typename> struct res1 { using type = res1; };
template <typename> struct res2 { using type = res2; };

struct res0_q
{
  template <typename... Ts>
  using apply = res0<Ts...>;
};

struct res1_q
{
  template <typename A>
  using apply = res1<A>;
};

struct res2_q
{
  template <typename A>
  using apply = res2<A>;
};


int main()
{
  using opt1 = mhn::none;
  using opt2 = mhn::some<x0>;
  using opt3 = mhn::some<x1>;
  using optf1 = mhn::some<res1_q>;
  using optf2 = mhn::some<res2_q>;

  static_assert(mhn::equals<opt1, opt1>::type::value, "!!!");
  static_assert(!mhn::equals<opt2, opt1>::type::value, "!!!");
  static_assert(!mhn::equals<opt1, opt2>::type::value, "!!!");
  static_assert(mhn::equals<opt2, opt2>::type::value, "!!!");
  static_assert(!mhn::equals<opt2, opt3>::type::value, "!!!");


  test_eq_types<
    typename mhn::transform<res1_q, opt1>::type, mhn::none
  >();
  test_eq_types<
    typename mhn::transform<res1_q, opt2>::type, mhn::some<res1<x0>>
  >();
  test_eq_types<
    typename mhn::transform<res1_q, opt3>::type, mhn::some<res1<x1>>
  >();


  test_eq_types<typename lift<mhn::optional_tag, x0>::type, mhn::some<x0>>();
  test_eq_types<typename lift<mhn::optional_tag, x1>::type, mhn::some<x1>>();

  test_eq_types<typename ap<opt1, opt1>::type, mhn::none>();
  test_eq_types<typename ap<opt1, opt2>::type, mhn::none>();
  test_eq_types<typename ap<opt1, opt3>::type, mhn::none>();
  test_eq_types<typename ap<optf1, opt1>::type, mhn::none>();
  test_eq_types<typename ap<optf1, opt2>::type, mhn::some<res1<x0>>>();
  test_eq_types<typename ap<optf1, opt3>::type, mhn::some<res1<x1>>>();
  test_eq_types<typename ap<optf2, opt1>::type, mhn::none>();
  test_eq_types<typename ap<optf2, opt2>::type, mhn::some<res2<x0>>>();
  test_eq_types<typename ap<optf2, opt3>::type, mhn::some<res2<x1>>>();


  return EXIT_SUCCESS;
}
