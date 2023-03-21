// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file partition.hpp
 *
 * @brief `partition` metafunction
 *
 * Defines the `partition` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_PARTITION_HPP
#define ERYTHRONELUMBO_MAIHUENIA_PARTITION_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename It, typename UnaryPredicate, typename Result,
    bool = empty_t<It>::value
  >
  struct partition_helper :
    partition_helper<
      pop_front_t<It>,
      UnaryPredicate,
      pair<
        eval_if_t<
          typename UnaryPredicate::template apply<front_t<It>>::type,
          push_back<typename Result::first, front_t<It>>,
          typename Result::first
        >,
        eval_if_t<
          typename UnaryPredicate::template apply<front_t<It>>::type,
          typename Result::second,
          push_back<typename Result::second, front_t<It>>
        >
      >
    >
  {};

  template <
    typename It, typename UnaryPredicate, typename Result
  >
  struct partition_helper<It, UnaryPredicate, Result, true> :
    Result
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Divides an iterable into two groups
 *
 * Divides an @ref tc_iterable into two @ref tc_sequence s of the same type: one
 * where all the elements result in `true` for an unary predicate and another
 * one where all the elements result in `false`.
 *
 * @see @ref remove_if
 * @see @ref sort
 *
 * @tparam It
 *   The @ref tc_iterable to divide.
 * @tparam UnaryPredicate
 *   An unary predicate.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence s.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/partition.cpp
 */
template <typename It, typename UnaryPredicate, typename ResTag>
struct partition
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::partition_helper< \
      It, UnaryPredicate, pair<make_seq_t<ResTag>, make_seq_t<ResTag>> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref pair which first element is the sequence with elements satisfying
   * the given predicate and second element is another sequence with the
   * remaining ones.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::partition
 *
 * @invokesmfn{partition}
 *
 * @tparam It
 *   The @ref tc_iterable to divide.
 * @tparam UnaryPredicate
 *   An unary predicate.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence s.
 */
template <typename It, typename UnaryPredicate, typename ResTag>
using partition_t = typename partition<It, UnaryPredicate, ResTag>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_PARTITION_HPP
