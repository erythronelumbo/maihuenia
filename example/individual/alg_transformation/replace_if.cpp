// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdint>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/replace_if.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>


namespace mhn = erythronelumbo::maihuenia;

struct my_base_class {};

struct aaa {};
struct bbb : my_base_class {};
struct ccc {};
struct ddd : my_base_class {};
struct eee : my_base_class {};
struct fff {};
struct ggg {};
struct hhh : my_base_class {};

constexpr mhn::false_ test_(my_base_class*);
constexpr mhn::true_ test_(...);

struct is_not_inherited_from_mbc
{
  template <typename T>
  struct apply
  {
    using type = decltype(test_((T*)nullptr));
  };
};

using input_vec = mhn::vector<aaa, bbb, ccc, ddd, eee, fff, ggg, hhh>;

using res = mhn::replace_if<
  input_vec,
  is_not_inherited_from_mbc,
  void*
>;

static_assert(
  mhn::equal_types_t<
    typename res::type,
    mhn::vector<void*, bbb, void*, ddd, eee, void*, void*, hhh>
  >::value,
  "!!!"
);


int main() { return EXIT_SUCCESS; }
