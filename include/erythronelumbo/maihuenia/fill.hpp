// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file fill.hpp
 *
 * @brief `fill` metafunction
 *
 * Defines the `fill` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FILL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FILL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe,
    ::std::size_t Diff = (Xe - Xs)
  >
  struct fill_helper :
    concat<
      typename fill_helper<Tag, Elem, Xs, ((Xs + Xe) >> 1)>::type,
      typename fill_helper<Tag, Elem, ((Xs + Xe) >> 1) + 1, Xe>::type
    >
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 8> :
    make_seq<Tag, Elem, Elem, Elem, Elem, Elem, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 7> :
    make_seq<Tag, Elem, Elem, Elem, Elem, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 6> :
    make_seq<Tag, Elem, Elem, Elem, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 5> :
    make_seq<Tag, Elem, Elem, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 4> :
    make_seq<Tag, Elem, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 3> :
    make_seq<Tag, Elem, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 2> :
    make_seq<Tag, Elem, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 1> :
    make_seq<Tag, Elem, Elem>
  {};

  template <typename Tag, typename Elem, ::std::size_t Xs, ::std::size_t Xe>
  struct fill_helper<Tag, Elem, Xs, Xe, 0> :
    make_seq<Tag, Elem>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief *Fills* a sequence
 *
 * Creates a @ref tc_sequence with an element that is repeated any number of
 * times.
 *
 * @see @ref filled_view
 * @see @ref filled_view_c
 *
 * @tparam Tag
 *   The tag that corresponds to the @ref tc_sequence to create.
 * @tparam Elem
 *   The element.
 * @tparam N
 *   An integral constant corresponding to the number of instances of the
 *   element.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/fill.cpp
 */
template <typename Tag, typename Elem, typename N>
struct fill
#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  : eval_if_c<
    (N::value > 0),
    detail::fill_helper<Tag, Elem, 0, (N::value - 1)>,
    make_seq<Tag>
  >
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence with `N` times the supplied element.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @ingroup alg_creation
 * @brief *Fills* a sequence
 *
 * Creates a @ref tc_sequence with an element that is repeated any number of
 * times.
 *
 * @see @ref filled_view
 * @see @ref filled_view_c
 *
 * @tparam Tag
 *   The tag that corresponds to the @ref tc_sequence to create.
 * @tparam Elem
 *   The element.
 * @tparam N
 *   The number of instances of the element.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/fill.cpp
 */
template <typename Tag, typename Elem, ::std::size_t N>
struct fill_c
#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  : eval_if_c<
    (N > 0),
    detail::fill_helper<Tag, Elem, 0, (N - 1)>,
    make_seq<Tag>
  >
#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence with `N` times the supplied element.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::fill
 *
 * @invokesmfn{fill}
 *
 * @tparam Tag
 *   The tag corresponding to the @ref tc_sequence.
 * @tparam Elem
 *   The element.
 * @tparam N
 *   An integral constant with the number of elements.
 */
template <typename Tag, typename Elem, typename N>
using fill_t = typename fill<Tag, Elem, N>::type;


/**
 * @relates erythronelumbo::maihuenia::fill_c
 *
 * @invokesmfn{fill_c}
 *
 * @tparam Tag
 *   The tag corresponding to the @ref tc_sequence.
 * @tparam Elem
 *   The element.
 * @tparam N
 *   The number of elements.
 */
template <typename Tag, typename Elem, ::std::size_t N>
using fill_c_t = typename fill_c<Tag, Elem, N>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FILL_HPP
