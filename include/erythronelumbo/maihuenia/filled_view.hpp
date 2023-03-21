// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file filled_view.hpp
 *
 * @brief `filled_view` type
 *
 * Defines the `filled_view` type.
 */

/**
 * @defgroup dt_seq_views_filled_view filled_view
 * @ingroup dt_seq_views
 *
 * @brief Iterable with repeated instances of an element
 *
 * A view which acts like a container with several instances of a single
 * element.
 *
 * ### Models
 *
 * @ref tc_iterable, @ref tc_foldable
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FILLED_VIEW_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FILLED_VIEW_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/detail/enable_if.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_views_filled_view}
 */
struct filled_view_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_seq_views_filled_view
 * @brief Filled view
 *
 * A view that acts like a container filled with several instances of a single
 * element.
 *
 * @see @ref fill
 * @see @ref fill_c
 *
 * @tparam Elem
 *   The element.
 * @tparam N
 *   An integral constant with the number of repetitions of `Elem`.
 *
 * ## Example
 *
 * @include example/individual/sequence_views/filled_view.cpp
 */
template <typename Elem, typename N>
struct filled_view
{
  /**
   * @mfncalltoitself
   */
  using type = filled_view;

  /**
   * @memtypetag
   */
  using tag = filled_view_tag;

  /**
   * @brief Contained element
   *
   * The "contained" element.
   */
  using elem = Elem;
};


/**
 * @ingroup dt_seq_views_filled_view
 * @brief Filled view
 *
 * A view that acts like a container filled with several instances of a single
 * element.
 *
 * @see @ref fill
 * @see @ref fill_c
 *
 * @tparam Elem
 *   The element.
 * @tparam N
 *   The number of repetitions of `Elem`.
 *
 * ## Example
 *
 * @include example/individual/sequence_views/filled_view.cpp
 */
template <typename Elem, ::std::size_t N>
struct filled_view_c
{
  /**
   * @mfncalltoitself
   */
  using type = filled_view_c;

  /**
   * @memtypetag
   */
  using tag = filled_view_tag;

  /**
   * @brief Contained element
   *
   * The "contained" element.
   */
  using elem = Elem;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <>
struct iterable_is_random_access_impl<filled_view_tag>
{
  struct apply
  {
    using type = true_;
  };
};


template <>
struct typeclass<Foldable>::define_for<filled_view_tag> :
  detail::sequence_folds<filled_view_tag>
{};


namespace detail
{
  template <typename, typename, typename = void>
  struct fldv_eq : false_ {};

  template <typename X>
  struct fldv_eq<X, X, void> : true_ {};

  template <typename T, typename N1, typename N2>
  struct fldv_eq<
    filled_view<T, N1>, filled_view<T, N2>,
    enable_if_t<
      (N1::value == N2::value) &&
      !equal_types<
        typename N1::value_type, typename N2::value_type
      >::value
    >
  > :
    true_
  {};

  template <typename T, typename N1, typename N2>
  struct fldv_eq<
    filled_view<T, N1>, filled_view<T, N2>,
    enable_if_t<
      (N1::value != N2::value) &&
      !equal_types<
        typename N1::value_type, typename N2::value_type
      >::value
    >
  > :
    false_
  {};

  template <typename T, ::std::size_t N1, typename N2>
  struct fldv_eq<filled_view_c<T, N1>, filled_view<T, N2>, void> :
    bool_<N1 == N2::value>
  {};

  template <typename T1, ::std::size_t N1, typename T2, typename N2>
  struct fldv_eq<filled_view_c<T1, N1>, filled_view<T2, N2>, void> :
    false_
  {};

  template <typename T, typename N1, ::std::size_t N2>
  struct fldv_eq<filled_view<T, N1>, filled_view_c<T, N2>, void> :
    bool_<N1::value == N2>
  {};

  template <typename T1, typename N1, typename T2, ::std::size_t N2>
  struct fldv_eq<filled_view<T1, N1>, filled_view_c<T2, N2>, void> :
    false_
  {};

  template <typename X1, typename X2>
  using fldv_neq = bool_<!fldv_eq<X1, X2>::type::value>;


  /**
   * Applies for `front` and `back`.
   */
  template <typename>
  struct fldv_front;

  template <typename Elem, typename N>
  struct fldv_front<filled_view<Elem, N>> :
    eval_if_c<(N::value > 0), identity<Elem>, undefined>
  {};

  template <typename Elem, ::std::size_t N>
  struct fldv_front<filled_view_c<Elem, N>> :
    eval_if_c<(N > 0), identity<Elem>, undefined>
  {};

  template <typename>
  struct fldv_back;

  template <typename Elem, typename N>
  struct fldv_back<filled_view<Elem, N>> :
    eval_if_c<(N::value > 0), identity<Elem>, identity<index_out_of_range>>
  {};

  template <typename Elem, ::std::size_t N>
  struct fldv_back<filled_view_c<Elem, N>> :
    eval_if_c<(N > 0), identity<Elem>, identity<index_out_of_range>>
  {};

  template <typename, typename>
  struct fldv_get_elem_;

  template <typename Elem, typename N, typename Idx>
  struct fldv_get_elem_<filled_view<Elem, N>, Idx> :
    eval_if_c<
      (N::value > 0) && ((Idx::value >= 0) && (Idx::value < N::value)),
      identity<Elem>,
      identity<index_out_of_range>
    >
  {};

  template <typename Elem, ::std::size_t N, typename Idx>
  struct fldv_get_elem_<filled_view_c<Elem, N>, Idx> :
    eval_if_c<
      (N > 0) && ((Idx::value >= 0) && (Idx::value < N)),
      identity<Elem>,
      identity<index_out_of_range>
    >
  {};


  template <typename>
  struct fldv_pop_front;

  template <typename Elem, typename N>
  struct fldv_pop_front<filled_view<Elem, N>> :
    filled_view<Elem, eval_if_c_t<(N::value > 0), decr<N>, size_c<0>>>
  {};

  template <typename Elem, ::std::size_t N>
  struct fldv_pop_front<filled_view_c<Elem, N>> :
    filled_view_c<Elem, (N > 0 ? (N - 1) : 0)>
  {};


  template <typename>
  struct fldv_empty;

  template <typename Elem, typename N>
  struct fldv_empty<filled_view<Elem, N>> : bool_<(N::value <= 0)> {};

  template <typename Elem, ::std::size_t N>
  struct fldv_empty<filled_view_c<Elem, N>> : bool_<(N <= 0)> {};


  template <typename>
  struct fldv_size;

  template <typename Elem, typename N>
  struct fldv_size<filled_view<Elem, N>> : size_c<(::std::size_t)N::value> {};

  template <typename Elem, ::std::size_t N>
  struct fldv_size<filled_view_c<Elem, N>> : size_c<N> {};


  template <typename, typename>
  struct fldv_drop;

  template <typename Elem, typename N, typename NDr>
  struct fldv_drop<filled_view<Elem, N>, NDr> :
    filled_view<
      Elem,
      eval_if_c_t<
        (N::value > 0),
        eval_if_c<
          (NDr::value > N::value),
          size_c<0>,
          sub<N, NDr>
        >,
        size_c<0>
      >
    >
  {};

  template <typename Elem, ::std::size_t N, typename NDr>
  struct fldv_drop<filled_view_c<Elem, N>, NDr> :
    filled_view_c<Elem, (N > 0 ? ((NDr::value > N) ? 0 : N - NDr::value) : 0)>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Comparable, \
  ( \
    (::erythronelumbo::maihuenia::filled_view_tag), \
    (::erythronelumbo::maihuenia::filled_view_tag) \
  ), \
  ( \
    (equals, 2, 0, (::erythronelumbo::maihuenia::detail::fldv_eq<X0, X1>)), \
    ( \
      not_equals, 2, 0, \
      (::erythronelumbo::maihuenia::detail::fldv_neq<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::filled_view_tag)), \
  ( \
    (empty, 1, 0, (::erythronelumbo::maihuenia::detail::fldv_empty<X0>)), \
    (front, 1, 0, (::erythronelumbo::maihuenia::detail::fldv_front<X0>)), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::fldv_pop_front<X0>) \
    ) \
  ), \
  ( \
    (back, 1, 0, (::erythronelumbo::maihuenia::detail::fldv_back<X0>)), \
    (at, 2, 0, (::erythronelumbo::maihuenia::detail::fldv_get_elem_<X0, X1>)), \
    (size, 1, 0, (::erythronelumbo::maihuenia::detail::fldv_size<X0>)), \
    (drop, 2, 0, (::erythronelumbo::maihuenia::detail::fldv_drop<X0, X1>)) \
  ) \
)
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_FILLED_VIEW_HPP
