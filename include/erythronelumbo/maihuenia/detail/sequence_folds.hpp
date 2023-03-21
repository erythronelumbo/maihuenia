// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_SEQUENCE_FOLDS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_SEQUENCE_FOLDS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

// Folding operations - sequential access

template <
  typename Fn, typename Seq, typename Result, bool = empty_t<Seq>::value
>
struct seq_fold_left_sa_impl :
  seq_fold_left_sa_impl<
    Fn,
    pop_front_t<Seq>,
    typename Fn::template apply<Result, front_t<Seq>>::type
  >
{};

template <typename Fn, typename Seq, typename Result>
struct seq_fold_left_sa_impl<Fn, Seq, Result, true> :
  identity<Result>
{};


template <
  typename Fn, typename Seq,
  bool = empty_t<pop_front_t<Seq>>::value,
  bool = empty_t<Seq>::value
>
struct seq_fold_right_sa_impl :
  Fn::template apply<
    front_t<Seq>,
    typename seq_fold_right_sa_impl<
      Fn, pop_front_t<Seq>
    >::type
  >
{};

template <typename Fn, typename Seq>
struct seq_fold_right_sa_impl<Fn, Seq, true, false> :
  front<Seq>
{};

template <typename Fn, typename Seq, bool X>
struct seq_fold_right_sa_impl<Fn, Seq, X, true> :
  identity<undefined>
{};


template <
  typename Fn, typename Seq, typename Head, bool = empty_t<Seq>::value
>
struct seq_fold_right_i_sa_impl :
  Fn::template apply<
    front_t<Seq>,
    typename seq_fold_right_i_sa_impl<
      Fn, pop_front_t<Seq>, Head
    >::type
  >
{};

template <typename Fn, typename Seq, typename Head>
struct seq_fold_right_i_sa_impl<Fn, Seq, Head, true> :
  identity<Head>
{};


// Folding operations - random access

template <
  typename Fn, typename Seq, typename Head,
  typename = varseq_make_idx_seq_t<size<Seq>::type::value>
>
struct seq_fold_left_ra_impl;

template <typename Fn, typename Seq, typename Head, ::std::size_t... Idcs>
struct seq_fold_left_ra_impl<Fn, Seq, Head, varseq_idx_seq<Idcs...>> :
  bin_op_many_c<Fn::template apply, false, Head, at_c_t<Seq, Idcs>...>
{};

template <typename Fn, typename Seq, typename Head>
struct seq_fold_left_ra_impl<Fn, Seq, Head, varseq_idx_seq<>> :
  identity<Head>
{};


template <
  typename Fn, typename Seq,
  typename = varseq_make_idx_seq_t<size<Seq>::type::value>
>
struct seq_fold_right_ra_impl;

template <
  typename Fn, typename Seq, ::std::size_t... Idcs
>
struct seq_fold_right_ra_impl<Fn, Seq, varseq_idx_seq<Idcs...>> :
  bin_op_many_c<Fn::template apply, true, at_c_t<Seq, Idcs>...>
{};

template <
  typename Fn, typename Seq, ::std::size_t Idx
>
struct seq_fold_right_ra_impl<Fn, Seq, varseq_idx_seq<Idx>> :
  bin_op_many_c<Fn::template apply, true, front_t<Seq>>
{};

template <typename Fn, typename Seq>
struct seq_fold_right_ra_impl<Fn, Seq, varseq_idx_seq<>> :
  identity<undefined>
{};


template <
  typename Fn, typename Seq, typename Head,
  typename = varseq_make_idx_seq_t<size<Seq>::type::value>
>
struct seq_fold_right_i_ra_impl;

template <
  typename Fn, typename Seq, typename Head, ::std::size_t... Idcs
>
struct seq_fold_right_i_ra_impl<Fn, Seq, Head, varseq_idx_seq<Idcs...>> :
  bin_op_many_c<Fn::template apply, true, at_c_t<Seq, Idcs>..., Head>
{};

template <typename Fn, typename Seq, typename Head>
struct seq_fold_right_i_ra_impl<Fn, Seq, Head, varseq_idx_seq<>> :
  identity<Head>
{};


template <
  typename ItTag,
  bool = iterable_tag_is_random_access<ItTag>::type::value
>
struct sequence_folds : true_
{
  template <typename Fn, typename Seq>
  struct fold_left_impl
  {
    using type = typename seq_fold_left_ra_impl<
      Fn, pop_front_t<Seq>, front_t<Seq>
    >::type;
  };

  template <typename Fn, typename Seq>
  struct fold_right_impl
  {
    using type = typename seq_fold_right_ra_impl<Fn, Seq>::type;
  };

  template <typename Fn, typename Seq, typename InitialState>
  struct fold_left_initial_impl
  {
    using type = typename seq_fold_left_ra_impl<
      Fn, Seq, InitialState
    >::type;
  };

  template <typename Fn, typename Seq, typename InitialState>
  struct fold_right_initial_impl
  {
    using type = typename seq_fold_right_i_ra_impl<
      Fn, Seq, InitialState
    >::type;
  };
};

template <typename ItTag>
struct sequence_folds<ItTag, false> : true_
{
  template <typename Fn, typename Seq>
  struct fold_left_impl
  {
    using type = typename seq_fold_left_sa_impl<
      Fn, pop_front_t<Seq>, front_t<Seq>
    >::type;
  };

  template <typename Fn, typename Seq>
  struct fold_right_impl
  {
    using type = typename seq_fold_right_sa_impl<Fn, Seq>::type;
  };

  template <typename Fn, typename Seq, typename InitialState>
  struct fold_left_initial_impl
  {
    using type = typename seq_fold_left_sa_impl<
      Fn, Seq, InitialState
    >::type;
  };

  template <typename Fn, typename Seq, typename InitialState>
  struct fold_right_initial_impl
  {
    using type = typename seq_fold_right_i_sa_impl<
      Fn, Seq, InitialState
    >::type;
  };
};

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_SEQUENCE_FOLDS_HPP
