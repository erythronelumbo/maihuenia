// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file variadic_indexers.hpp
 *
 * @brief Element indexing for variadic sequences
 *
 * Contains tools for indexing an element from variadic sequences.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARIADIC_INDEXERS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARIADIC_INDEXERS_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <::std::size_t Idx>
struct varseq_index_elem_
{
  template <typename T> struct item { using type = T; };
};


template <typename>
struct varseq_idx_tp_inheritor;

template <::std::size_t... Idcs>
struct varseq_idx_tp_inheritor<varseq_idx_seq<Idcs...>>
{
  template <typename... Ts>
  struct result_ : varseq_index_elem_<Idcs>::template item<Ts>... {};
};


template <::std::size_t I, typename T>
constexpr typename varseq_index_elem_<I>::template item<T>
varseq_get_from_inheritor(typename varseq_index_elem_<I>::template item<T>*);


template <::std::size_t Idx>
struct variadic_type_indexer_impl
{
  template <typename... Args>
  struct result_
  {
    using type = typename decltype(
      varseq_get_from_inheritor<Idx>(
        (typename varseq_idx_tp_inheritor<
          varseq_make_idx_seq_t<sizeof...(Args)>
        >::template result_<
          Args...
        >*)0
      )
    )::type;
  };
};

template <::std::size_t Idx, typename... Args>
using variadic_type_indexer = eval_if_c<
  (Idx >= sizeof...(Args)),
  identity<index_out_of_range>,
  typename variadic_type_indexer_impl<
    Idx
  >::template result_<Args...>
>;


template <::std::size_t Idx, typename IntType, IntType... Args>
using variadic_integral_indexer = variadic_type_indexer<
  Idx, integer_c<IntType, Args>...
>;


} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_VARIADIC_INDEXERS_HPP
