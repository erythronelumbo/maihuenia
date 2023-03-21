// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>


namespace mhn = erythronelumbo::maihuenia;

using it1 = mhn::null_type;
using it2 = mhn::vector<>;
using it3 = mhn::cons<int, mhn::cons<void, mhn::cons<double>>>;
using it4 = mhn::vector<int, void, double>;

static_assert(mhn::empty<it1>::type::value, "!!!");
static_assert(mhn::empty<it2>::type::value, "!!!");
static_assert(!mhn::empty<it3>::type::value, "!!!");
static_assert(!mhn::empty<it4>::type::value, "!!!");


int main() { return EXIT_SUCCESS; }
