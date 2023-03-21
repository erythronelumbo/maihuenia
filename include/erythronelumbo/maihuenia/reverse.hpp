// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file reverse.hpp
 *
 * @brief `reverse` metafunction
 *
 * Defines the `reverse` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_REVERSE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_REVERSE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/varseq_idx_seq.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Seq, bool = empty_t<Seq>::value>
  struct reverse_helper_linear :
    push_back<
      typename reverse_helper_linear<pop_front_t<Seq>>::type,
      front_t<Seq>
    >
  {};

  template <typename Seq>
  struct reverse_helper_linear<Seq, true> : Seq {};


  template <
    typename Seq,
    ::std::size_t SeqSize = size<Seq>::type::value,
    typename = detail::varseq_make_idx_seq_t<SeqSize>
  >
  struct reverse_helper_ra;

  template <typename Seq, ::std::size_t SeqSize, ::std::size_t... Idcs>
  struct reverse_helper_ra<Seq, SeqSize, detail::varseq_idx_seq<Idcs...>> :
    make_seq<tag_t<Seq>, at_c_t<Seq, (SeqSize - 1 - Idcs)>...>
  {};

  template <typename Seq, ::std::size_t SeqSize>
  struct reverse_helper_ra<Seq, SeqSize, detail::varseq_idx_seq<>>
  {
    using type = Seq;
  };


  template <typename Seq, bool = iterable_is_random_access<Seq>::type::value>
  struct reverse_helper : reverse_helper_ra<Seq> {};

  template <typename Seq>
  struct reverse_helper<Seq, false> : reverse_helper_linear<Seq> {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Reverses a sequence
 *
 * Reverses the order of the elements of a @ref tc_sequence.
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/reverse.cpp
 */
template <typename Seq>
struct reverse 
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if<empty_t<Seq>, Seq, detail::reverse_helper<Seq>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence of the same type as `Seq`, with elements in reverse order.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::reverse
 *
 * @invokesmfn{reverse}
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 */
template <typename Seq>
using reverse_t = typename reverse<Seq>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_REVERSE_HPP
