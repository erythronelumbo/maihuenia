// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/string.hpp>

#include "../eq_types.hpp"


namespace mhn = erythronelumbo::maihuenia;


template <typename...> struct res0 { using type = res0; };
template <typename...> struct res1 { using type = res1; };

struct res0_q
{
  template <typename... Ts>
  using apply = res0<Ts...>;
};


using str1 = mhn::string<>;
using str2 = mhn::string<'a'>;
using str3 = mhn::string<'a', 'b'>;
using str4 = mhn::string<'a', 'b', 'c', 'x', 'y', 'z'>;
using str5 = mhn::string<'1', '2', '3', '4'>;

template <
  typename Str,
  typename E0,
  typename E1 = mhn::index_out_of_range,
  typename E2 = mhn::index_out_of_range,
  typename E3 = mhn::index_out_of_range,
  typename E4 = mhn::index_out_of_range,
  typename E5 = mhn::index_out_of_range
>
constexpr void test_at()
{
  test_eq_types<typename mhn::at<Str, mhn::int_<0>>::type, E0>();
  test_eq_types<typename mhn::at<Str, mhn::int_<1>>::type, E1>();
  test_eq_types<typename mhn::at<Str, mhn::int_<2>>::type, E2>();
  test_eq_types<typename mhn::at<Str, mhn::int_<3>>::type, E3>();
  test_eq_types<typename mhn::at<Str, mhn::int_<4>>::type, E4>();
  test_eq_types<typename mhn::at<Str, mhn::int_<5>>::type, E5>();
}

template <typename Str>
constexpr void test_drop()
{
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<0>>::type,
    Str
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<1>>::type,
    mhn::pop_front_t<Str>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<2>>::type,
    mhn::pop_front_t<mhn::pop_front_t<Str>>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<3>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<Str>>>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<4>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<Str>>>>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<5>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<
      mhn::pop_front_t<Str>
    >>>>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<6>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<
      mhn::pop_front_t<mhn::pop_front_t<Str>>
    >>>>
  >();
  test_eq_types<
    typename mhn::drop<Str, mhn::size_c<7>>::type,
    mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<
      mhn::pop_front_t<mhn::pop_front_t<mhn::pop_front_t<Str>>>
    >>>>
  >();
}


int main()
{
  static_assert(mhn::empty<str1>::type::value, "!!!");
  static_assert(!mhn::empty<str2>::type::value, "!!!");
  static_assert(!mhn::empty<str3>::type::value, "!!!");
  static_assert(!mhn::empty<str4>::type::value, "!!!");

  test_eq_types<typename mhn::front<str1>::type, mhn::undefined>();
  test_eq_types<typename mhn::front<str2>::type, mhn::char_<'a'>>();
  test_eq_types<typename mhn::front<str3>::type, mhn::char_<'a'>>();
  test_eq_types<typename mhn::front<str4>::type, mhn::char_<'a'>>();
  test_eq_types<typename mhn::front<str5>::type, mhn::char_<'1'>>();

  test_eq_types<typename mhn::pop_front<str1>::type, mhn::string<>>();
  test_eq_types<typename mhn::pop_front<str2>::type, mhn::string<>>();
  test_eq_types<
    typename mhn::pop_front<str3>::type,
    mhn::string<'b'>
  >();
  test_eq_types<
    typename mhn::pop_front<str4>::type,
    mhn::string<'b', 'c', 'x', 'y', 'z'>
  >();

  test_eq_types<typename mhn::back<str1>::type, mhn::index_out_of_range>();
  test_eq_types<typename mhn::back<str2>::type, mhn::char_<'a'>>();
  test_eq_types<typename mhn::back<str3>::type, mhn::char_<'b'>>();
  test_eq_types<typename mhn::back<str4>::type, mhn::char_<'z'>>();

  test_at<str1, mhn::index_out_of_range>();
  test_at<str2, mhn::char_<'a'>>();
  test_at<str3, mhn::char_<'a'>, mhn::char_<'b'>>();
  test_at<
    str4,
    mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>,
    mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>
  >();

  static_assert(mhn::size<str1>::type::value == 0, "!!!");
  static_assert(mhn::size<str2>::type::value == 1, "!!!");
  static_assert(mhn::size<str3>::type::value == 2, "!!!");
  static_assert(mhn::size<str4>::type::value == 6, "!!!");

  test_drop<str1>();
  test_drop<str2>();
  test_drop<str3>();
  test_drop<str4>();


  test_eq_types<
    typename mhn::make_seq<mhn::string_tag>::type,
    str1
  >();
  test_eq_types<
    typename mhn::make_seq<mhn::string_tag, mhn::char_<'a'>>::type,
    str2
  >();
  test_eq_types<
    typename mhn::make_seq<
      mhn::string_tag, mhn::char_<'a'>, mhn::char_<'b'>
    >::type,
    str3
  >();
  test_eq_types<
    typename mhn::make_seq<
      mhn::string_tag,
      mhn::char_<'a'>, mhn::char_<'b'>, mhn::char_<'c'>,
      mhn::char_<'x'>, mhn::char_<'y'>, mhn::char_<'z'>
    >::type,
    str4
  >();

  test_eq_types<typename mhn::clear<str1>::type, str1>();
  test_eq_types<typename mhn::clear<str2>::type, str1>();
  test_eq_types<typename mhn::clear<str3>::type, str1>();
  test_eq_types<typename mhn::clear<str4>::type, str1>();
  test_eq_types<typename mhn::clear<str5>::type, str1>();

  test_eq_types<
    typename mhn::concat<str1, str1>::type, str1
  >();
  test_eq_types<
    typename mhn::concat<str1, str3>::type, str3
  >();
  test_eq_types<
    typename mhn::concat<str3, str1>::type, str3
  >();
  test_eq_types<
    typename mhn::concat<str3, str5>::type,
    mhn::string<'a', 'b', '1', '2', '3', '4'>
  >();
  test_eq_types<
    typename mhn::concat<str3, str5, str4>::type,
    mhn::string<'a', 'b', '1', '2', '3', '4', 'a', 'b', 'c', 'x', 'y', 'z'>
  >();

  test_eq_types<
    typename mhn::push_front<str1, mhn::char_<'0'>>::type, mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::push_front<str3, mhn::char_<'0'>>::type,
    mhn::string<'0', 'a', 'b'>
  >();

  test_eq_types<
    typename mhn::push_back<str1, mhn::char_<'0'>>::type, mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::push_back<str3, mhn::char_<'0'>>::type,
    mhn::string<'a', 'b', '0'>
  >();

  test_eq_types<
    typename mhn::pop_back<str1>::type,
    mhn::string<>
  >();
  test_eq_types<
    typename mhn::pop_back<str2>::type,
    mhn::string<>
  >();
  test_eq_types<
    typename mhn::pop_back<str3>::type,
    mhn::string<'a'>
  >();
  test_eq_types<
    typename mhn::pop_back<str5>::type,
    mhn::string<'1', '2', '3'>
  >();
  test_eq_types<
    typename mhn::pop_back<typename mhn::pop_back<str5>::type>::type,
    mhn::string<'1', '2'>
  >();

  test_eq_types<
    typename mhn::take<str4, mhn::size_c<6>>::type, str4
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<5>>::type,
    mhn::pop_back_t<str4>
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<4>>::type,
    mhn::pop_back_t<mhn::pop_back_t<str4>>
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<3>>::type,
    mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<str4>>>
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<2>>::type,
    mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<str4>>>>
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<1>>::type,
    mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<mhn::pop_back_t<
      mhn::pop_back_t<str4>
    >>>>
  >();
  test_eq_types<
    typename mhn::take<str4, mhn::size_c<0>>::type,
    mhn::clear_t<str4>
  >();

  test_eq_types<
    typename mhn::insert<str1, mhn::size_c<0>, mhn::char_<'0'>>::type,
    mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::insert<str1, mhn::size_c<1>, mhn::char_<'0'>>::type,
    mhn::string<'0'>
  >();
  test_eq_types<
    typename mhn::insert<str2, mhn::size_c<0>, mhn::char_<'0'>>::type,
    mhn::string<'0', 'a'>
  >();
  test_eq_types<
    typename mhn::insert<str2, mhn::size_c<1>, mhn::char_<'0'>>::type,
    mhn::string<'a', '0'>
  >();
  test_eq_types<
    typename mhn::insert<str3, mhn::size_c<0>, mhn::char_<'0'>>::type,
    mhn::string<'0', 'a', 'b'>
  >();
  test_eq_types<
    typename mhn::insert<str3, mhn::size_c<1>, mhn::char_<'0'>>::type,
    mhn::string<'a', '0', 'b'>
  >();
  test_eq_types<
    typename mhn::insert<str3, mhn::size_c<2>, mhn::char_<'0'>>::type,
    mhn::string<'a', 'b', '0'>
  >();

  test_eq_types<
    typename mhn::erase<str1, mhn::size_c<0>>::type, str1
  >();
  test_eq_types<
    typename mhn::erase<str1, mhn::size_c<1>>::type, str1
  >();
  test_eq_types<
    typename mhn::erase<str2, mhn::size_c<0>>::type,
    mhn::string<>
  >();
  test_eq_types<
    typename mhn::erase<str3, mhn::size_c<0>>::type,
    mhn::string<'b'>
  >();
  test_eq_types<
    typename mhn::erase<str3, mhn::size_c<1>>::type,
    mhn::string<'a'>
  >();


  test_eq_types<
    typename mhn::mident<mhn::string_tag>::type, mhn::string<>
  >();

  test_eq_types<
    typename mhn::mappend<str1, str1>::type, str1
  >();
  test_eq_types<
    typename mhn::mappend<str1, str3>::type, str3
  >();
  test_eq_types<
    typename mhn::mappend<str3, str1>::type, str3
  >();
  test_eq_types<
    typename mhn::mappend<str3, str5>::type,
    mhn::string<'a', 'b', '1', '2', '3', '4'>
  >();
  test_eq_types<
    typename mhn::mappend<str3, str5, str4>::type,
    mhn::string<'a', 'b', '1', '2', '3', '4', 'a', 'b', 'c', 'x', 'y', 'z'>
  >();


  return EXIT_SUCCESS;
}
