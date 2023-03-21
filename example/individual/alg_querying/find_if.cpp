// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/find_if.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct my_base_class {};

struct aaa {};
struct bbb : my_base_class {};
struct ccc {};
struct ddd {};
struct eee : my_base_class {};
struct fff {};
struct ggg {};

struct www {};
struct xxx {};
struct yyy {};
struct zzz {};

using seq1 = mhn::vector<aaa, bbb, ccc, ddd, eee, fff, ggg>;
using seq2 = mhn::vector<www, xxx, yyy, zzz>;

constexpr mhn::true_ test_(my_base_class*);
constexpr mhn::false_ test_(...);

struct inherits_from_my_base_class
{
  template <typename T>
  struct apply
  {
    using type = decltype(test_((T*)nullptr));
  };
};

using res1 = mhn::find_if<seq1, inherits_from_my_base_class>;
using res2 = mhn::find_if<seq2, inherits_from_my_base_class>;

static_assert(
  mhn::equal_types_t<
    typename res1::type,
    mhn::some<mhn::size_c<1>>
  >::value,
  "!!!"
);
static_assert(
  mhn::equal_types_t<
    typename res2::type,
    mhn::none
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
