// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `map` data type
 *
 * Defines the `map` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MAP_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MAP_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/inherit.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/fwd/map.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/mapping.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename> struct map_empty;

template <typename... Ps>
struct map_empty<map<Ps...>> : bool_<sizeof...(Ps) == 0> {};


template <typename... Ks>
struct map_inheritor
{
  template <typename... Vs>
  using result_ = inherit<pair<Ks, Vs>...>;
};


template <typename Key, typename Value>
inline constexpr identity<Value> map_get_from_key(pair<Key, Value>*);

template <typename Key>
inline constexpr identity<index_out_of_range> map_get_from_key(...);


template <typename, typename> struct map_at_key;

template <typename... Ps, typename K>
struct map_at_key<map<Ps...>, K> :
  decltype(
    map_get_from_key<K>(
      (typename map_inheritor<
        typename Ps::first...
      >::template result_<
        typename Ps::second...
      >::type*)0
    )
  )
{};


template <typename Key, typename Value>
inline constexpr true_ map_check_for_key(pair<Key, Value>*);

template <typename Key>
inline constexpr false_ map_check_for_key(...);


template <typename, typename> struct map_has_key;

template <typename... Ps, typename K>
struct map_has_key<map<Ps...>, K> :
  decltype(
    map_check_for_key<K>(
      (typename map_inheritor<
        typename Ps::first...
      >::template result_<
        typename Ps::second...
      >::type*)0
    )
  )
{};


template <typename, typename>
struct map_insert;

template <typename... Ps, typename K, typename V>
struct map_insert<map<Ps...>, pair<K, V>> :
  if_<
    typename map_has_key<map<Ps...>, K>::type,
    map<Ps...>,
    map<Ps..., pair<K, V>>
  >
{};


template <typename, typename>
struct map_cat_two;

template <typename... Xs1, typename... Xs2>
struct map_cat_two<map<Xs1...>, map<Xs2...>> : map<Xs1..., Xs2...> {};


template <typename... Sets>
using map_cat = bin_op_many_c<map_cat_two, false, Sets...>;


template <typename RefKey, typename X>
struct map_empty_if_eq;

template <typename RefKey, typename K, typename V>
struct map_empty_if_eq<RefKey, pair<K, V>> : map<pair<K, V>> {};

template <typename RefKey, typename V>
struct map_empty_if_eq<RefKey, pair<RefKey, V>> : map<> {};


template <typename, typename>
struct map_erase_impl;

template <typename... Ps, typename Key>
struct map_erase_impl<map<Ps...>, Key> :
  map_cat<typename map_empty_if_eq<Key, Ps>::type...>
{};

template <typename Key>
struct map_erase_impl<map<>, Key> : map<> {};

template <typename Map, typename Key>
using map_erase = map_erase_impl<Map, Key>;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Mapping, \
  ((::erythronelumbo::maihuenia::map_tag)), \
  ( \
    ( \
      aempty, 1, 0, \
      (::erythronelumbo::maihuenia::detail::map_empty<X0>) \
    ), \
    ( \
      at_key, 2, 0, \
      (::erythronelumbo::maihuenia::detail::map_at_key<X0, X1>) \
    ), \
    ( \
      has_key, 2, 0, \
      (::erythronelumbo::maihuenia::detail::map_has_key<X0, X1>) \
    ) \
  ), \
  () \
)


ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::ExtensibleMapping, \
  ((::erythronelumbo::maihuenia::map_tag)), \
  ( \
    ( \
      ainsert, 2, 0, \
      (::erythronelumbo::maihuenia::detail::map_insert<X0, X1>) \
    ), \
    ( \
      aerase, 2, 0, \
      (::erythronelumbo::maihuenia::detail::map_erase<X0, X1>) \
    ), \
    (aclear, 1, 0, (::erythronelumbo::maihuenia::map<>)) \
  ), \
  () \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_MAP_HPP
