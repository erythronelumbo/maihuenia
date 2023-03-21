// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file take.hpp
 *
 * @brief `take` helper for variadic sequences
 *
 * Specialization of the `take` intrinsic metafunction, used for variadic
 * sequences.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_TAKE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_TAKE_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/variadic_indexers.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename, std::size_t> struct varseq_take_indexer;

template <
  template <typename...> class VarTypeSeq,
  typename... Xs, std::size_t I
>
struct varseq_take_indexer<VarTypeSeq<Xs...>, I> :
  variadic_type_indexer<I, Xs...>
{};

template <
  template <typename ITp, ITp...> class VarIntSeq,
  typename IntType, IntType... Xs, std::size_t I
>
struct varseq_take_indexer<VarIntSeq<IntType, Xs...>, I> :
  variadic_integral_indexer<I, IntType, Xs...>
{};


template <typename>
struct varseq_take_helper_impl;

template <::std::size_t... Idcs>
struct varseq_take_helper_impl<varseq_idx_seq<Idcs...>>
{
  template <template <typename...> class VarTypeSeqTp>
  struct with_vts
  {
    template <typename Seq>
    struct result :
      VarTypeSeqTp<typename varseq_take_indexer<Seq, Idcs>::type...>
    {};
  };

  template <
    template <typename ITp, ITp...> class VarIntSeqTp, typename IntType
  >
  struct with_vis
  {
    template <typename Seq>
    struct result :
      VarIntSeqTp<
        IntType, varseq_take_indexer<Seq, Idcs>::type::value...
      >
    {};
  };
};


template <typename>
struct varseq_take_helper;

template <std::size_t... Idcs>
struct varseq_take_helper<varseq_idx_seq<Idcs...>>
{
  template <typename, typename _ = void>
  struct result;

  template <template <typename...> class VarTypeSeq, typename... Xs, typename _>
  struct result<VarTypeSeq<Xs...>, _> :
    varseq_take_helper_impl<
      varseq_idx_seq<Idcs...>
    >::template with_vts<
      VarTypeSeq
    >::template result<
      VarTypeSeq<Xs...>
    >
  {};

  template <
    template <typename ITp, ITp...> class VarIntSeq,
    typename IntType, IntType... Xs, typename _
  >
  struct result<VarIntSeq<IntType, Xs...>, _> :
    varseq_take_helper_impl<
      varseq_idx_seq<Idcs...>
    >::template with_vis<
      VarIntSeq, IntType
    >::template result<
      VarIntSeq<IntType, Xs...>
    >
  {};
};


template <typename VarSeq, std::size_t N>
using varseq_take = typename varseq_take_helper<
  varseq_make_idx_seq_t<N>
>::template result<VarSeq>;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_TAKE_HPP
