// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief Linked list
 *
 * Defines a linked list data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_LINKED_LIST_HPP
#define ERYTHRONELUMBO_MAIHUENIA_LINKED_LIST_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/linked_list.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>
#include <erythronelumbo/maihuenia/monad_plus.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <>
struct iterable_is_random_access_impl<linked_list_tag>
{
  struct apply
  {
    using type = false_;
  };
};

template <>
struct typeclass<Foldable>::define_for<linked_list_tag> :
  detail::sequence_folds<linked_list_tag>
{};

}} // namespace erythronelumbo::maihuenia


ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    ( \
      empty, 1, 0, \
      ( \
        ::erythronelumbo::maihuenia::equal_types< \
          X0, ::erythronelumbo::maihuenia::null_type \
        > \
      ) \
    ), \
    ( \
      front, 1, 0, (::erythronelumbo::maihuenia::identity<typename X0::head>) \
    ), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::identity<typename X0::tail>) \
    ) \
  ), \
  () \
)

namespace erythronelumbo { namespace maihuenia { namespace detail
{
  template <typename...>
  struct make_linked_list;

  template <
    typename X0, typename X1, typename X2, typename X3,
    typename X4, typename X5, typename X6, typename X7,
    typename... Xs
  >
  struct make_linked_list<X0, X1, X2, X3, X4, X5, X6, X7, Xs...> :
    cons<X0, cons<X1, cons<X2, cons<X3,
      cons<X4, cons<X5, cons<X6, cons<
        X7, typename make_linked_list<Xs...>::type
      >>>>
    >>>>
  {};

  template <
    typename X0, typename X1, typename X2, typename X3,
    typename X4, typename X5, typename X6, typename X7
  >
  struct make_linked_list<X0, X1, X2, X3, X4, X5, X6, X7> :
    cons<X0, cons<X1, cons<X2, cons<X3,
      cons<X4, cons<X5, cons<X6, cons<X7>>>>
    >>>>
  {};

  template <
    typename X0, typename X1, typename X2, typename X3,
    typename X4, typename X5, typename X6
  >
  struct make_linked_list<X0, X1, X2, X3, X4, X5, X6> :
    cons<X0, cons<X1, cons<X2, cons<X3,
      cons<X4, cons<X5, cons<X6>>>
    >>>>
  {};

  template <
    typename X0, typename X1, typename X2, typename X3,
    typename X4, typename X5
  >
  struct make_linked_list<X0, X1, X2, X3, X4, X5> :
    cons<X0, cons<X1, cons<X2, cons<X3,
      cons<X4, cons<X5>>
    >>>>
  {};

  template <
    typename X0, typename X1, typename X2, typename X3,
    typename X4
  >
  struct make_linked_list<X0, X1, X2, X3, X4> :
    cons<X0, cons<X1, cons<X2, cons<X3,
      cons<X4>
    >>>>
  {};

  template <
    typename X0, typename X1, typename X2, typename X3
  >
  struct make_linked_list<X0, X1, X2, X3> :
    cons<X0, cons<X1, cons<X2, cons<X3>>>>
  {};

  template <
    typename X0, typename X1, typename X2
  >
  struct make_linked_list<X0, X1, X2> :
    cons<X0, cons<X1, cons<X2>>>
  {};

  template <
    typename X0, typename X1
  >
  struct make_linked_list<X0, X1> :
    cons<X0, cons<X1>>
  {};

  template <
    typename X0
  >
  struct make_linked_list<X0> :
    cons<X0>
  {};

  template <>
  struct make_linked_list<> : null_type {};


  template <typename, typename>
  struct list_cat;

  template <>
  struct list_cat<null_type, null_type> : null_type {};

  template <typename H1, typename T1>
  struct list_cat<cons<H1, T1>, null_type> : cons<H1, T1> {};

  template <typename H2, typename T2>
  struct list_cat<null_type, cons<H2, T2>> : cons<H2, T2> {};

  template <typename H1, typename H2, typename T2>
  struct list_cat<cons<H1, null_type>, cons<H2, T2>> :
    cons<H1, cons<H2, T2>>
  {};

  template <typename H1, typename T1, typename H2, typename T2>
  struct list_cat<cons<H1, T1>, cons<H2, T2>> :
    cons<H1, typename list_cat<T1, cons<H2, T2>>::type>
  {};


  template <typename, typename>
  struct list_trfm;

  template <typename Fn, typename Head, typename Tail>
  struct list_trfm<Fn, cons<Head, Tail>> :
    cons<
      typename Fn::template apply<Head>::type,
      typename list_trfm<Fn, Tail>::type
    >
  {};

  template <typename Fn, typename Head>
  struct list_trfm<Fn, cons<Head, null_type>> :
    cons<
      typename Fn::template apply<Head>::type,
      null_type
    >
  {};

  template <typename Fn>
  struct list_trfm<Fn, null_type> : null_type {};


  template <typename, typename>
  struct list_ap;

  template <typename FnH, typename FnT, typename Xs>
  struct list_ap<cons<FnH, FnT>, Xs> :
    concat<
      typename transform<FnH, Xs>::type,
      typename list_ap<FnT, Xs>::type
    >
  {};

  template <typename FnH, typename Xs>
  struct list_ap<cons<FnH, null_type>, Xs> :
    transform<FnH, Xs>
  {};

  template <typename FnList>
  struct list_ap<FnList, null_type> : null_type {};

  template <typename XList>
  struct list_ap<null_type, XList> : null_type {};


  template <typename, typename>
  struct list_mbind;

  template <typename Head, typename Tail, typename Fn>
  struct list_mbind<cons<Head, Tail>, Fn> :
    concat<
      null_type,
      typename Fn::template apply<Head>::type,
      typename list_mbind<Tail, Fn>::type
    >
  {};

  template <typename Fn>
  struct list_mbind<null_type, Fn> :
    null_type
  {};
}}} // namespace erythronelumbo::maihuenia::detail

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Comparable, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    (equals, 2, 0, (::erythronelumbo::maihuenia::equal_types<X0, X1>)), \
    ( \
      not_equals, 2, 0, \
      (::erythronelumbo::maihuenia::bool_< \
        !::erythronelumbo::maihuenia::equal_types_t<X0, X1>::value \
      >) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Sequence, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    ( \
      make_seq, 0, 1, \
      (::erythronelumbo::maihuenia::detail::make_linked_list<Xs...>) \
    ), \
    (concat, 2, 0, (::erythronelumbo::maihuenia::detail::list_cat<X0, X1>)), \
    (clear, 1, 0, (::erythronelumbo::maihuenia::null_type)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Monoid, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    (mappend, 2, 0, (::erythronelumbo::maihuenia::detail::list_cat<X0, X1>)), \
    (mident, 0, 0, (::erythronelumbo::maihuenia::null_type)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Functor, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    ( \
      transform, 2, 0, \
      (::erythronelumbo::maihuenia::detail::list_trfm<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Applicative, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    (lift, 1, 0, (::erythronelumbo::maihuenia::cons<X0>)), \
    (ap, 2, 0, (::erythronelumbo::maihuenia::detail::list_ap<X0, X1>)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Monad, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    (mbind, 2, 0, (::erythronelumbo::maihuenia::detail::list_mbind<X0, X1>)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::MonadPlus, \
  ((::erythronelumbo::maihuenia::linked_list_tag)), \
  ( \
    (mplus, 2, 0, (::erythronelumbo::maihuenia::detail::list_cat<X0, X1>)), \
    (mzero, 0, 0, (::erythronelumbo::maihuenia::null_type)) \
  ), \
  () \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_LINKED_LIST_HPP
