// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `set` data type
 *
 * Defines the `set` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SET_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SET_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/fwd/set.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/mapping.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename> struct set_empty;

template <typename... Xs>
struct set_empty<set<Xs...>> : bool_<sizeof...(Xs) == 0>
{};

template <typename IntType, IntType... Xs>
struct set_empty<set_c<IntType, Xs...>> : bool_<sizeof...(Xs) == 0>
{};


template <typename X> inline constexpr identity<X> set_get(set_box<X>*);
template <typename X>
inline constexpr identity<index_out_of_range> set_get(...);

template <typename, typename> struct set_at_key;

template <typename... Xs, typename Elem>
struct set_at_key<set<Xs...>, Elem> :
  decltype(set_get<Elem>((set<Xs...>*)0))
{};

template <typename IntType, IntType... Xs, typename Elem>
struct set_at_key<set_c<IntType, Xs...>, Elem> :
  decltype(
    set_get<integer_c<IntType, (IntType)Elem::value>>(
      (set_c<IntType, Xs...>*)0
    )
  )
{};


template <typename X> inline constexpr true_ set_check_elem(set_box<X>*);
template <typename X> inline constexpr false_ set_check_elem(...);

template <typename, typename> struct set_has_key;

template <typename... Xs, typename Elem>
struct set_has_key<set<Xs...>, Elem> :
  decltype(set_check_elem<Elem>((set<Xs...>*)0))
{};

template <typename IntType, IntType... Xs, typename Elem>
struct set_has_key<set_c<IntType, Xs...>, Elem> :
  decltype(set_check_elem<Elem>((set_c<IntType, Xs...>*)0))
{};


template <typename, typename> struct set_insert;

template <typename... Xs, typename Elem>
struct set_insert<set<Xs...>, Elem> :
  if_<
    decltype(set_check_elem<Elem>((set<Xs...>*)0)),
    set<Xs...>, set<Xs..., Elem>
  >
{};

template <typename IntType, IntType... Xs, typename Elem>
struct set_insert<set_c<IntType, Xs...>, Elem> :
  if_<
    decltype(set_check_elem<Elem>((set_c<IntType, Xs...>*)0)),
    set_c<IntType, Xs...>,
    set_c<IntType, Xs..., (IntType)Elem::value>
  >
{};


template <typename, typename>
struct set_cat_two;

template <typename... Xs1, typename... Xs2>
struct set_cat_two<set<Xs1...>, set<Xs2...>> : set<Xs1..., Xs2...> {};

template <typename ITp, ITp... Xs1, ITp... Xs2>
struct set_cat_two<set_c<ITp, Xs1...>, set_c<ITp, Xs2...>> :
  set_c<ITp, Xs1..., Xs2...>
{};

template <typename... Sets>
using set_cat = bin_op_many_c<set_cat_two, false, Sets...>;


template <typename RefElem, typename X>
struct set_empty_if_eq : set<X> {};

template <typename RefElem>
struct set_empty_if_eq<RefElem, RefElem> : set<> {};

template <typename IntType, IntType RefElem, IntType X>
struct set_c_empty_if_eq : set_c<IntType, X> {};

template <typename IntType, IntType RefElem>
struct set_c_empty_if_eq<IntType, RefElem, RefElem> : set_c<IntType> {};


template <typename, typename>
struct set_erase_impl;

template <typename... Xs, typename Elem>
struct set_erase_impl<set<Xs...>, Elem> :
  set_cat<typename set_empty_if_eq<Elem, Xs>::type...>
{};

template <typename Elem>
struct set_erase_impl<set<>, Elem> :
  set<>
{};


template <typename IntType, typename, IntType>
struct set_c_erase_impl;

template <typename IntType, IntType... Xs, IntType Elem>
struct set_c_erase_impl<IntType, set_c<IntType, Xs...>, Elem> :
  set_cat<typename set_c_empty_if_eq<IntType, Elem, Xs>::type...>
{};

template <typename IntType, IntType Elem>
struct set_c_erase_impl<IntType, set_c<IntType>, Elem> :
  set_c<IntType>
{};


template <typename Set, typename Elem>
struct set_erase;

template <typename... Xs, typename Elem>
struct set_erase<set<Xs...>, Elem> :
  set_erase_impl<set<Xs...>, Elem>
{};

template <typename IntType, IntType... Xs, typename Elem>
struct set_erase<set_c<IntType, Xs...>, Elem> :
  set_c_erase_impl<
    IntType,
    set_c<IntType, Xs...>,
    (IntType)Elem::value
  >
{};

} // namespace detail

}} // namespace erythronelumbo::maihuenia

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Mapping, \
  ((::erythronelumbo::maihuenia::set_tag)), \
  ( \
    ( \
      aempty, 1, 0, \
      (::erythronelumbo::maihuenia::detail::set_empty<X0>) \
    ), \
    ( \
      at_key, 2, 0, \
      (::erythronelumbo::maihuenia::detail::set_at_key<X0, X1>) \
    ), \
    ( \
      has_key, 2, 0, \
      (::erythronelumbo::maihuenia::detail::set_has_key<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::ExtensibleMapping, \
  ((::erythronelumbo::maihuenia::set_tag)), \
  ( \
    ( \
      ainsert, 2, 0, \
      (::erythronelumbo::maihuenia::detail::set_insert<X0, X1>) \
    ), \
    ( \
      aerase, 2, 0, \
      (::erythronelumbo::maihuenia::detail::set_erase<X0, X1>) \
    ), \
    (aclear, 1, 0, (::erythronelumbo::maihuenia::set<>)) \
  ), \
  () \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_SET_HPP
