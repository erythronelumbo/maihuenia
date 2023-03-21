// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/tag.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


struct with_tag_tag;

struct with_tag
{
  using type = with_tag;
  using tag = with_tag_tag;
};


template <typename T>
struct template_type_tag;

template <typename T>
struct template_type
{
  using type = template_type;
  using tag = template_type_tag<T>;
};


struct without_tag {};


struct mhn_tag_mfn_overloaded_tag;

struct mhn_tag_mfn_overloaded {};

namespace erythronelumbo { namespace maihuenia
{
  template <>
  struct tag<mhn_tag_mfn_overloaded>
  {
    using type = ::mhn_tag_mfn_overloaded_tag;
  };
}} // namespace erythronelumbo::maihuenia


int main()
{
  test_eq_types<typename mhn::tag<without_tag>::type, mhn::foreign>();
  test_eq_types<typename mhn::tag<with_tag>::type, with_tag_tag>();
  test_eq_types<
    typename mhn::tag<mhn_tag_mfn_overloaded>::type,
    mhn_tag_mfn_overloaded_tag
  >();
  test_eq_types<
    typename mhn::tag<template_type<int>>::type,
    template_type_tag<int>
  >();

  return EXIT_SUCCESS;
}
