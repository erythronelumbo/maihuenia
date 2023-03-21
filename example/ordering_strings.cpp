// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/split_sd.hpp>
#include <erythronelumbo/maihuenia/lexicographical_compare.hpp>
#include <erythronelumbo/maihuenia/sort.hpp>
#include <erythronelumbo/maihuenia/for_each.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>


#define STR_(s) ERYTHRONELUMBO_MAIHUENIA_STRING_ML(s, 220)

namespace mhn = erythronelumbo::maihuenia;

using namespace mhn::placeholders;


using lcmp_q = mhn::quote<mhn::lexicographical_compare>;

using insects = STR_( \
  "Bee,Mosquito,Beetle,Fly,Wasp,Cockroach,Bed bug,Stick insect,Bumblebee," \
  "Moth,Locust,Flea,Ladybug,Butterfly,Ant,Dragonfly,Horsefly,Mantis,Earwig," \
  "Louse,Firefly,Cricket,Grasshopper,Cicada,Termite,Leaf insect" \
);


using insects_splitted = mhn::split_sd_t<
  insects, mhn::string<','>, mhn::vector_tag
>;

using insects_ord = mhn::sort_t<
  insects_splitted,
  mhn::bind<lcmp_q, _1, _2, mhn::quote<mhn::less>>
>;

using insects_rev_ord = mhn::sort_t<
  insects_splitted,
  mhn::bind<lcmp_q, _1, _2, mhn::quote<mhn::greater>>
>;


struct printer
{
  template <typename Str>
  inline void operator()(Str)
  {
    std::puts(mhn::c_str<mhn::concat_t<mhn::string<'-', ' '>, Str>>::value);
  }
};


int main()
{
  printer pr;

  std::puts("List of insects - unordered:");
  mhn::for_each<insects_splitted>(pr);

  std::puts("\nList of insects - alphabetical order:");
  mhn::for_each<insects_ord>(pr);

  std::puts("\nList of insects - reverse alphabetical order:");
  mhn::for_each<insects_rev_ord>(pr);

  return EXIT_SUCCESS;
}
