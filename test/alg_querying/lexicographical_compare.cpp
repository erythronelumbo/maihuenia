// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/lexicographical_compare.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


using x0 = mhn::char_<'0'>;
using x1 = mhn::char_<'1'>;
using x2 = mhn::char_<'2'>;


template <typename SeqTag>
void test_lexcmp()
{
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag>,
      mhn::make_seq_t<SeqTag>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0>,
      mhn::make_seq_t<SeqTag>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag>,
      mhn::make_seq_t<SeqTag, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0>,
      mhn::make_seq_t<SeqTag, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0>,
      mhn::make_seq_t<SeqTag, x0, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0>,
      mhn::make_seq_t<SeqTag, x0, x1>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0, x0>,
      mhn::make_seq_t<SeqTag, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0, x0>,
      mhn::make_seq_t<SeqTag, x1>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x0, x0>,
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x1>,
      mhn::make_seq_t<SeqTag, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x1>,
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x1, x0, x2>,
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::make_seq_t<SeqTag, x1, x0, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    !mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x2>,
      mhn::make_seq_t<SeqTag, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x2>,
      mhn::make_seq_t<SeqTag, x2, x1, x0>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x2, x1, x0>,
      mhn::make_seq_t<SeqTag, x2, x2>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
  static_assert(
    mhn::lexicographical_compare<
      mhn::make_seq_t<SeqTag, x2, x1, x0, x2, x1, x0>,
      mhn::make_seq_t<SeqTag, x2, x2>,
      mhn::quote<mhn::less>
    >::type::value,
    "!!!"
  );
}


int main()
{
  test_lexcmp<mhn::vector_tag>();
  test_lexcmp<mhn::string_tag>();
  test_lexcmp<mhn::linked_list_tag>();

  return EXIT_SUCCESS;
}
