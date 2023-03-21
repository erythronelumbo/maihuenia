// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `string` type
 *
 * Defines the `string` type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_STRING_HPP
#define ERYTHRONELUMBO_MAIHUENIA_STRING_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/fwd/string.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/size.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/drop.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/take.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/variadic_indexers.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <>
struct iterable_is_random_access_impl<string_tag>
{
  struct apply
  {
    using type = true_;
  };
};

template <>
struct typeclass<Foldable>::define_for<string_tag> :
  detail::sequence_folds<string_tag>
{};


template <>
struct typeclass<WithStringRepr>::define_for<string_tag> : true_
{
  template <typename Str>
  using to_string_impl = Str;
};


namespace detail
{
  template <typename ITp, ITp...>
  struct string_dummy
  {
    using type = string_dummy;
  };

  template <typename>
  struct str2strdummy;

  template <char... Cs>
  struct str2strdummy<string<Cs...>> : string_dummy<char, Cs...> {};

  template <typename>
  struct strdummy2str;

  template <char... Cs>
  struct strdummy2str<string_dummy<char, Cs...>> : string<Cs...> {};


  template <typename>
  struct str_front;

  template <char C, char... Cs>
  struct str_front<string<C, Cs...>> : char_<C> {};

  template <>
  struct str_front<string<>> : undefined {};


  template <typename>
  struct str_pop_front;

  template <char C, char... Cs>
  struct str_pop_front<string<C, Cs...>> : string<Cs...> {};

  template <>
  struct str_pop_front<string<>> : string<> {};


  template <typename>
  struct str_back;

  template <char... Cs>
  struct str_back<string<Cs...>> :
    variadic_integral_indexer<sizeof...(Cs) - 1, char, Cs...>
  {};

  template <>
  struct str_back<string<>> : identity<index_out_of_range> {};


  template <typename, typename>
  struct str_at;

  template <char... Cs, typename Idx>
  struct str_at<string<Cs...>, Idx> :
    variadic_integral_indexer<(::std::size_t)Idx::value, char, Cs...>
  {};

  template <typename Idx>
  struct str_at<string<>, Idx> : identity<index_out_of_range> {};


  template <typename> struct str_size;

  template <char... Cs>
  struct str_size<string<Cs...>> : size_c<sizeof...(Cs)>
  {};


  template <typename, typename>
  struct str_push_front;

  template <char... Cs, typename X>
  struct str_push_front<string<Cs...>, X> : string<(char)X::value, Cs...> {};


  template <typename, typename>
  struct str_push_back;

  template <char... Cs, typename X>
  struct str_push_back<string<Cs...>, X> : string<Cs..., (char)X::value> {};


  template <bool>
  struct enable_str_sc
  {
    template <char C>
    struct result_ : string<C> {};
  };

  template <>
  struct enable_str_sc<false>
  {
    template <char>
    struct result_ : string<> {};
  };


  template <
    ::std::size_t StrSz, ::std::size_t N,
    typename = varseq_make_idx_seq_t<StrSz>
  >
  struct str_take_impl_ne;

  template <
    ::std::size_t StrSz, ::std::size_t N,
    ::std::size_t... SIdcs
  >
  struct str_take_impl_ne<
    StrSz, N, varseq_idx_seq<SIdcs...>
  >
  {
    template <typename, typename>
    struct result_;

    template <char... Cs, typename X>
    struct result_<string<Cs...>, X> :
      bin_op_many_c<
        str_concat_two,
        false,
        typename enable_str_sc<
          (SIdcs < N)
        >::template result_<
          Cs
        >::type...
      >
    {};
  };


  template <typename Str, typename N>
  struct str_take;

  template <char... Cs, typename N>
  struct str_take<string<Cs...>, N> :
    str_take_impl_ne<sizeof...(Cs), (::std::size_t)N::value>::template result_<
      string<Cs...>, void
    >
  {};

  template <typename N>
  struct str_take<string<>, N> :
    string<>
  {};


  template <typename Str>
  struct str_pop_back;

  template <char... Cs>
  struct str_pop_back<string<Cs...>> :
    str_take_impl_ne<sizeof...(Cs), sizeof...(Cs) - 1>::template result_<
      string<Cs...>, void
    >
  {};

  template <>
  struct str_pop_back<string<>> :
    string<>
  {};
} // namespace detail

}} // namespace erythronelumbo::maihuenia

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::string_tag)), \
  ( \
    ( \
      empty, 1, 0, \
      (::erythronelumbo::maihuenia::detail::varseq_empty< \
        typename ::erythronelumbo::maihuenia::detail::str2strdummy<X0>::type \
      >) \
    ), \
    ( \
      front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::str_front<X0>) \
    ), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::str_pop_front<X0>) \
    ) \
  ), \
  ( \
    (back, 1, 0, (::erythronelumbo::maihuenia::detail::str_back<X0>)), \
    (at, 2, 0, (::erythronelumbo::maihuenia::detail::str_at<X0, X1>)), \
    (size, 1, 0, (::erythronelumbo::maihuenia::detail::str_size<X0>)), \
    ( \
      drop, 2, 0, \
      (::erythronelumbo::maihuenia::detail::strdummy2str< \
        typename ::erythronelumbo::maihuenia::detail::varseq_drop< \
          typename ::erythronelumbo::maihuenia::detail::str2strdummy< \
            X0 \
          >::type, \
          (::std::size_t)X1::value \
        >::type \
      >) \
    ) \
  ) \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Monoid, \
  ( \
    (::erythronelumbo::maihuenia::string_tag), \
    (::erythronelumbo::maihuenia::string_tag) \
  ), \
  ( \
    (mident, 0, 0, (::erythronelumbo::maihuenia::string<>)), \
    ( \
      mappend, 2, 0, \
      (::erythronelumbo::maihuenia::detail::str_concat_two<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Sequence, \
  ((::erythronelumbo::maihuenia::string_tag)), \
  ( \
    ( \
      make_seq, 0, 1, \
      (::erythronelumbo::maihuenia::string<(char)Xs::value...>) \
    ), \
    ( \
      concat, 2, 0, \
      (::erythronelumbo::maihuenia::detail::str_concat_two<X0, X1>) \
    ), \
    (clear, 1, 0, (::erythronelumbo::maihuenia::string<>)) \
  ), \
  ( \
    ( \
      push_front, 2, 0, \
      (::erythronelumbo::maihuenia::detail::str_push_front<X0, X1>) \
    ), \
    ( \
      push_back, 2, 0, \
      (::erythronelumbo::maihuenia::detail::str_push_back<X0, X1>) \
    ), \
    ( \
      pop_back, 1, 0, \
      (::erythronelumbo::maihuenia::detail::str_pop_back<X0>) \
    ), \
    ( \
      take, 2, 0, \
      (::erythronelumbo::maihuenia::detail::str_take<X0, X1>) \
    ), \
    ( \
      insert, 3, 0, \
      (::erythronelumbo::maihuenia::detail::generic_insert<X0, X1, X2>) \
    ), \
    ( \
      erase, 2, 0, \
      (::erythronelumbo::maihuenia::detail::generic_erase<X0, X1>) \
    ) \
  ) \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_STRING_HPP
