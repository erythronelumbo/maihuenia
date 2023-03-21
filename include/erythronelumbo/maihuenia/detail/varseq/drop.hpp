// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file drop.hpp
 *
 * @brief `drop` helper for variadic sequences
 *
 * Specialization for the `drop` intrinsic metafunction, used for variadic
 * sequences.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_DROP_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_DROP_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/size.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <::std::size_t> struct szt_void_sink_ { using type = void; };

template <::std::size_t X>
  using szt_void_sink_t_ = typename szt_void_sink_<X>::type;


template <typename, typename>
struct varseq_drop_helper_;

template <
  ::std::size_t... Dummies,
  template <typename...> class VarSeq,
  typename... Xs
>
struct varseq_drop_helper_<varseq_idx_seq<Dummies...>, VarSeq<Xs...>>
{
  template <typename... Boxes>
  static auto call_(szt_void_sink_t_<Dummies>*..., Boxes*...)
  -> VarSeq<typename Boxes::type...>;

  using type = decltype(call_(((identity<Xs>*)0)...));
};

template <
  ::std::size_t... Dummies,
  template <typename...> class VarSeq
>
struct varseq_drop_helper_<varseq_idx_seq<Dummies...>, VarSeq<>>
{
  using type = VarSeq<>;
};

template <
  ::std::size_t... Dummies,
  template <typename ITp, ITp...> class IntSeq,
  typename   IntType,
  IntType... Xs
>
struct varseq_drop_helper_<varseq_idx_seq<Dummies...>, IntSeq<IntType, Xs...>>
{
  template <typename... IntCts>
  static auto call_(szt_void_sink_t_<Dummies>*..., IntCts*...)
  -> IntSeq<IntType, IntCts::value...>;

  using type = decltype(call_(((integer_c<IntType, Xs>*)0)...));
};

template <
  ::std::size_t... Dummies,
  template <typename ITp, ITp...> class IntSeq,
  typename IntType
>
struct varseq_drop_helper_<varseq_idx_seq<Dummies...>, IntSeq<IntType>>
{
  using type = IntSeq<IntType>;
};


template <typename VarSeq, ::std::size_t N>
struct varseq_drop
{
  using type = typename varseq_drop_helper_<
    varseq_make_idx_seq_t<
      (N <= varseq_size<VarSeq>::value) ? N : varseq_size<VarSeq>::value
    >,
    VarSeq
  >::type;
};

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_DROP_HPP
