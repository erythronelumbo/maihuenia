// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_SIZE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_SIZE_HPP


#include <cstddef>

#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

namespace detail
{

template <typename>
struct varseq_size;

template <template <typename...> class VarTypeSeq, typename... Xs>
struct varseq_size<VarTypeSeq<Xs...>> : size_c<sizeof...(Xs)>
{};

template <
  template <typename ITp, ITp...> class VarIntSeq,
  typename IntType, IntType... Xs
>
struct varseq_size<VarIntSeq<IntType, Xs...>> : size_c<sizeof...(Xs)>
{};


template <typename Seq>
using varseq_empty = bool_<varseq_size<Seq>::type::value == 0>;

} // namespace detail

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_DETAIL_VARSEQ_SIZE_HPP
