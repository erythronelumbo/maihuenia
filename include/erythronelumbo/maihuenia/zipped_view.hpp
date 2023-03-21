// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file zipped_view.hpp
 *
 * @brief `zipped_view` type
 *
 * Defines the `zipped_view` type.
 */

/**
 * @defgroup dt_seq_views_zipped_view zipped_view
 * @ingroup dt_seq_views
 *
 * @brief Zipped view of several iterables
 *
 * A view that allows iterating through several @ref tc_iterable s in parallel.
 *
 * ### Models
 *
 * @ref tc_iterable, @ref tc_foldable
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ZIPPED_VIEW_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ZIPPED_VIEW_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_views_zipped_view}
 */
struct zipped_view_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_views_zipped_view
 * @brief Zipped view of several iterables
 *
 * A view that allows iterating through several @ref tc_iterable s in parallel,
 * where the "contained" elements are @ref vector s. Each `I`-th `vector`
 * contains the `I`-th elements from the supplied iterables.
 *
 * @see @ref zip
 *
 * @tparam Its...
 *   The @ref tc_iterable s.
 *
 * ## Example
 *
 * @include example/individual/sequence_views/zipped_view.cpp
 */
template <typename... Its>
struct zipped_view
{
  /**
   * @mfncalltoitself
   */
  using type = zipped_view;

  /**
   * @memtypetag
   */
  using tag = zipped_view_tag;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <>
struct typeclass<Foldable>::define_for<zipped_view_tag> :
  detail::sequence_folds<zipped_view_tag>
{};


namespace detail
{
  template <typename... Its>
  struct zipv_front_impl
  {
    template <
      typename X,
      bool = logical_or<typename empty<Its>::type...>::type::value
    >
    struct result_ : undefined {};

    template <typename X>
    struct result_<X, false> : vector<front_t<Its>...> {};
  };

  template <typename>
  struct zipv_front;

  template <typename... Its>
  struct zipv_front<zipped_view<Its...>> :
    zipv_front_impl<Its...>::template result_<void>
  {};

  template <>
  struct zipv_front<zipped_view<>> : undefined {};


  template <typename>
  struct zipv_pop_front;

  template <typename... Its>
  struct zipv_pop_front<zipped_view<Its...>> :
    zipped_view<pop_front_t<Its>...>
  {};


  template <typename>
  struct zipv_empty;

  template <typename... Its>
  struct zipv_empty<zipped_view<Its...>> :
    logical_or<typename empty<Its>::type...>
  {};

  template <>
  struct zipv_empty<zipped_view<>> : true_ {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::zipped_view_tag)), \
  ( \
    (empty, 1, 0, (::erythronelumbo::maihuenia::detail::zipv_empty<X0>)), \
    (front, 1, 0, (::erythronelumbo::maihuenia::detail::zipv_front<X0>)), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::zipv_pop_front<X0>) \
    ) \
  ), \
  () \
)
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_ZIPPED_VIEW_HPP
