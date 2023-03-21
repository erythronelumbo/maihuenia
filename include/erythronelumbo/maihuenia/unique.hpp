// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file unique.hpp
 *
 * @brief `unique` metafunction
 *
 * Defines the `unique` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_UNIQUE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_UNIQUE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/remove_if.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/*
abaccdefeab

[a][baccdefeab] -> [a][bccdefeb]
[a][b][ccdefeb] -> [a][b][ccdefe]
[a][b][c][cdefe] -> [a][b][c][defe]
[a][b][c][d][efe] -> [a][b][c][d][efe]
[a][b][c][d][e][fe] -> [a][b][c][d][e][f]
*/

namespace detail
{
  template <typename Seq, typename Result, bool = empty<Seq>::type::value>
  struct unique_helper :
    unique_helper<
      remove_t<pop_front_t<Seq>, front_t<Seq>>,
      push_back_t<Result, front_t<Seq>>
    >
  {};

  template <typename Seq, typename Result>
  struct unique_helper<Seq, Result, true> :
    Result
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_transformation
 * @brief Makes elements in a sequence unique
 *
 * If there are repeated instances of a same element in a @ref tc_sequence, it
 * will remove all of them but one, in a way there can be only one instance of
 * each contained element.
 *
 * @see @ref set
 * @see @ref remove
 * @see @ref contains
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/unique.cpp
 */
template <typename Seq>
struct unique
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::unique_helper<Seq, clear_t<Seq>> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A sequence similar to `Seq`, wih no repeated elements.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::unique
 *
 * @invokesmfn{unique}
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 */
template <typename Seq>
using unique_t = typename unique<Seq>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_UNIQUE_HPP
