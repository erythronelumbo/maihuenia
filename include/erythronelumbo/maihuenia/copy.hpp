// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file copy.hpp
 *
 * @brief `copy` metafunction
 *
 * Defines the `copy` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_COPY_HPP
#define ERYTHRONELUMBO_MAIHUENIA_COPY_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename DstSeqTag, typename SrcIt, typename Res,
    bool = empty_t<SrcIt>::value
  >
  struct copy_helper_sa :
    copy_helper_sa<
      DstSeqTag,
      pop_front_t<SrcIt>,
      push_back_t<Res, front_t<SrcIt>>
    >
  {};

  template <typename DstSeqTag, typename SrcIt, typename Res>
  struct copy_helper_sa<DstSeqTag, SrcIt, Res, true> :
    Res
  {};


  template <
    typename DstSeqTag, typename SrcIt,
    typename = varseq_make_idx_seq_t<
      size<SrcIt>::type::value
    >
  >
  struct copy_helper_ra;

  template <typename DstSeqTag, typename SrcIt, ::std::size_t... Idcs>
  struct copy_helper_ra<
    DstSeqTag, SrcIt, varseq_idx_seq<Idcs...>
  > :
    make_seq<DstSeqTag, at_c_t<SrcIt, Idcs>...>
  {};


  template <
    typename DstSeqTag, typename SrcIt,
    bool = iterable_tag_is_random_access<DstSeqTag>::type::value
  >
  struct copy_helper :
    copy_helper_ra<DstSeqTag, SrcIt>
  {};

  template <typename DstSeqTag, typename SrcIt>
  struct copy_helper<DstSeqTag, SrcIt, false> :
    copy_helper_sa<DstSeqTag, SrcIt, make_seq_t<DstSeqTag>>
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_creation
 * @brief *Copies* an iterable
 *
 * Creates a new @ref tc_sequence by "copying" the elements of an
 * @ref tc_iterable.
 *
 * @tparam DstSeqTag
 *   The type tag of the @ref tc_sequence to be created.
 * @tparam SrcIt
 *   The @ref tc_iterable to be "copied".
 *
 * ## Example
 *
 * @include example/individual/alg_creation/copy.cpp
 */
template <typename DstSeqTag, typename SrcIt>
struct copy
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::copy_helper<DstSeqTag, SrcIt> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref tc_sequence containing all the elements contained in `SrcIt`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::copy
 *
 * @invokesmfn{copy}
 *
 * @tparam DstSeqTag
 *   The type tag of the @ref tc_sequence to be created.
 * @tparam SrcIt
 *   The @ref tc_iterable to be "copied".
 */
template <typename DstSeqTag, typename SrcIt>
using copy_t = typename copy<DstSeqTag, SrcIt>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_COPY_HPP
