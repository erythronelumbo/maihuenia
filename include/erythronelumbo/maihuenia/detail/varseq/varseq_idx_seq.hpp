// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file varseq_idx_seq.hpp
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARSEQ_IDX_SEQ_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARSEQ_IDX_SEQ_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <::std::size_t... Idcs> struct varseq_idx_seq;


template <typename, typename>
struct varseq_idx_seq_cat;

template <::std::size_t... IdcsA, ::std::size_t... IdcsB>
struct varseq_idx_seq_cat<varseq_idx_seq<IdcsA...>, varseq_idx_seq<IdcsB...>>
{
  using type = varseq_idx_seq<IdcsA..., IdcsB...>;
};


template <::std::size_t Xs, ::std::size_t Xe, ::std::size_t Diff = (Xe - Xs)>
struct varseq_make_idx_seq_impl :
  varseq_idx_seq_cat<
    typename varseq_make_idx_seq_impl<Xs, ((Xs + Xe) >> 1)>::type,
    typename varseq_make_idx_seq_impl<((Xs + Xe) >> 1) + 1, Xe>::type
  >
{};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 8>
{
  using type = varseq_idx_seq<
    Xs, Xs + 1, Xs + 2, Xs + 3, Xs + 4, Xs + 5, Xs + 6, Xs + 7, Xe
  >;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 7>
{
  using type = varseq_idx_seq<
    Xs, Xs + 1, Xs + 2, Xs + 3, Xs + 4, Xs + 5, Xs + 6, Xe
  >;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 6>
{
  using type = varseq_idx_seq<Xs, Xs + 1, Xs + 2, Xs + 3, Xs + 4, Xs + 5, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 5>
{
  using type = varseq_idx_seq<Xs, Xs + 1, Xs + 2, Xs + 3, Xs + 4, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 4>
{
  using type = varseq_idx_seq<Xs, Xs + 1, Xs + 2, Xs + 3, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 3>
{
  using type = varseq_idx_seq<Xs, Xs + 1, Xs + 2, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 2>
{
  using type = varseq_idx_seq<Xs, Xs + 1, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 1>
{
  using type = varseq_idx_seq<Xs, Xe>;
};

template <::std::size_t Xs, ::std::size_t Xe>
struct varseq_make_idx_seq_impl<Xs, Xe, 0>
{
  using type = varseq_idx_seq<Xs>;
};


template <::std::size_t N>
struct varseq_make_idx_seq :
  varseq_make_idx_seq_impl<0, (N - 1)>
{};

template <>
struct varseq_make_idx_seq<0>
{
  using type = varseq_idx_seq<>;
};


template <::std::size_t N>
using varseq_make_idx_seq_t = typename varseq_make_idx_seq<N>::type;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARSEQ_IDX_SEQ_HPP
