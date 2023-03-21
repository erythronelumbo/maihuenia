// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file intercalate.hpp
 *
 * @brief `intercalate` metafunction
 *
 * Defines the `intercalate` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INTERCALATE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INTERCALATE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename SepSeq>
  struct intercalate_two
  {
    template <typename Xa, typename Xb>
    using apply = concat<Xa, SepSeq, Xb>;
  };
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_creation
 * @brief Joins sequences with another sequence
 *
 * Creates a new @ref tc_sequence by inserting the content of a *separator*
 * @ref tc_sequence between all the sequences contained in an @ref tc_iterable.
 *
 * @see @ref concat
 * @see @ref intersperse
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_sequence s.
 * @tparam SepSeq
 *   The @ref tc_sequence to insert.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/intercalate.cpp
 */
template <typename It, typename SepSeq>
struct intercalate
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      typename empty<It>::type, \
      undefined, \
      fold_left<detail::intercalate_two<SepSeq>, It> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref tc_sequence where `SepSeq` joins all the other sequences contained
   * in `It`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::intercalate
 *
 * @invokesmfn{intercalate}
 *
 * @tparam It
 *   An @ref tc_iterable of @ref tc_sequence s.
 * @tparam SepSeq
 *   The @ref tc_sequence to insert.
 */
template <typename It, typename SepSeq>
using intercalate_t = typename intercalate<It, SepSeq>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_INTERCALATE_HPP
