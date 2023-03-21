// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file transformed_view.hpp
 *
 * @brief `transformed_view` type
 *
 * Defines the `transformed_view` type.
 */

/**
 * @defgroup dt_seq_views_transformed_view transformed_view
 * @ingroup dt_seq_views
 *
 * @brief Transformed view
 *
 * Describes a sequence view where the transformation of elements on demand is
 * involved.
 *
 * ### Models
 * @ref tc_foldable, @ref tc_iterable
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_TRANSFORMED_VIEW_HPP
#define ERYTHRONELUMBO_MAIHUENIA_TRANSFORMED_VIEW_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_seq_views_transformed_view}
 */
struct transformed_view_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

/**
 * @ingroup dt_seq_views_transformed_view
 * @brief Transformed view
 *
 * A sequence view where the elements of the underlying @ref tc_iterable are
 * transformed when they are being queried.
 *
 * @see @ref transform
 *
 * @tparam It
 *   The @ref tc_iterable to be adapted.
 * @tparam Fn
 *   The transformation (an unary metafunction class).
 *
 * ## Example
 *
 * @include example/individual/sequence_views/transformed_view.cpp
 */
template <typename It, typename Fn>
struct transformed_view
{
  /**
   * @mfncalltoitself
   */
  using type = transformed_view;

  /**
   * @memtypetag
   */
  using tag = transformed_view_tag;

  /**
   * @brief Underlying iterable
   *
   * The @ref tc_iterable that is being adapted.
   */
  using base_it = It;

  /**
   * @brief Transformation
   *
   * The transformation applied to the elements of the provided
   * @ref tc_iterable.
   */
  using trfm = Fn;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <>
struct typeclass<Foldable>::define_for<transformed_view_tag> :
  detail::sequence_folds<transformed_view_tag>
{};


namespace detail
{
  template <typename>
  struct trfmv_front;

  template <typename It, typename Fn>
  struct trfmv_front<transformed_view<It, Fn>> :
    eval_if<
      typename empty<It>::type,
      undefined,
      typename Fn::template apply<front_t<It>>
    >
  {};


  template <typename>
  struct trfmv_back;

  template <typename It, typename Fn>
  struct trfmv_back<transformed_view<It, Fn>> :
    eval_if<
      typename empty<It>::type,
      identity<index_out_of_range>,
      typename Fn::template apply<back_t<It>>
    >
  {};


  template <typename, typename>
  struct trfmv_at;

  template <typename It, typename Fn, typename I>
  struct trfmv_at<transformed_view<It, Fn>, I> :
    eval_if_c<
      (
        empty<It>::type::value ||
        (I::value < 0) ||
        (I::value >= size<It>::type::value)
      ),
      identity<index_out_of_range>,
      typename Fn::template apply<at_t<It, I>>
    >
  {};
} // namespace detail

#endif //ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
    ::erythronelumbo::maihuenia::Iterable, \
    ((::erythronelumbo::maihuenia::transformed_view_tag)), \
    ( \
      ( \
        empty, 1, 0, \
        (::erythronelumbo::maihuenia::empty<typename X0::base_it>) \
      ), \
      (front, 1, 0, (::erythronelumbo::maihuenia::detail::trfmv_front<X0>)), \
      ( \
        pop_front, 1, 0, \
        ( \
          ::erythronelumbo::maihuenia::transformed_view< \
            ::erythronelumbo::maihuenia::pop_front_t<typename X0::base_it>, \
            typename X0::trfm \
          > \
        ) \
      ) \
    ), \
    ( \
      (back, 1, 0, (::erythronelumbo::maihuenia::detail::trfmv_back<X0>)), \
      (at, 2, 0, (::erythronelumbo::maihuenia::detail::trfmv_at<X0, X1>)), \
      (size, 1, 0, (::erythronelumbo::maihuenia::size<typename X0::base_it>)), \
      ( \
        drop, 2, 0, \
        ( \
          ::erythronelumbo::maihuenia::transformed_view< \
            ::erythronelumbo::maihuenia::drop_t<typename X0::base_it, X1>, \
            typename X0::trfm \
          > \
        ) \
      ) \
    ) \
  )
#endif //ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_TRANSFORMED_VIEW_HPP
