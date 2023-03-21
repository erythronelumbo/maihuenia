// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file sort.hpp
 *
 * @brief `sort` metafunction
 *
 * Defines the `sort` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SORT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SORT_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename HalfSeqL, typename HalfSeqR, typename Cmp,
    typename Res,
    bool = empty_t<HalfSeqL>::value,
    bool = empty_t<HalfSeqR>::value
  >
  struct sort_merge :
    eval_if<
      typename Cmp::template apply<
        front_t<HalfSeqL>, front_t<HalfSeqR>
      >::type,
      sort_merge<
        pop_front_t<HalfSeqL>, HalfSeqR, Cmp,
        push_back_t<Res, front_t<HalfSeqL>>
      >,
      sort_merge<
        HalfSeqL, pop_front_t<HalfSeqR>, Cmp,
        push_back_t<Res, front_t<HalfSeqR>>
      >
    >
  {};

  template <typename HalfSeqL, typename HalfSeqR, typename Cmp, typename Res>
  struct sort_merge<HalfSeqL, HalfSeqR, Cmp, Res, false, true> :
    concat<Res, HalfSeqL>
  {};

  template <typename HalfSeqL, typename HalfSeqR, typename Cmp, typename Res>
  struct sort_merge<HalfSeqL, HalfSeqR, Cmp, Res, true, false> :
    concat<Res, HalfSeqR>
  {};

  template <typename HalfSeqL, typename HalfSeqR, typename Cmp, typename Res>
  struct sort_merge<HalfSeqL, HalfSeqR, Cmp, Res, true, true> : Res {};


  template <
    typename Seq, typename Cmp,
    ::std::size_t SeqSize = size<typename Seq::type>::type::value,
    bool = (SeqSize >= 2)
  >
  struct sort_helper :
    sort_merge<
      typename sort_helper<take_c_t<Seq, (SeqSize >> 1)>, Cmp>::type,
      typename sort_helper<drop_c_t<Seq, (SeqSize >> 1)>, Cmp>::type,
      Cmp,
      clear_t<Seq>
    >
  {};

  template <
    typename Seq, typename Cmp,
    ::std::size_t SeqSize
  >
  struct sort_helper<Seq, Cmp, SeqSize, false> :
    identity<Seq>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Sorts a sequence
 *
 * Sorts the elements of a sequence according to a binary comparator. It uses
 * the *merge sort* algorithm.
 *
 * @see @ref partition
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Cmp
 *   The binary comparator.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/sort.cpp
 */
template <typename Seq, typename Cmp>
struct sort
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if<empty_t<Seq>, Seq, detail::sort_helper<Seq, Cmp>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, but all of its elements are sorted.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::sort
 *
 * @invokesmfn{sort}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Cmp
 *   The binary comparator.
 */
template <typename Seq, typename Cmp>
using sort_t = typename sort<Seq, Cmp>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SORT_HPP
