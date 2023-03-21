// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file intersperse.hpp
 *
 * @brief `intersperse` metafunction
 *
 * Defines the `intersperse` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INTERSPERSE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INTERSPERSE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Tag, typename X>
  struct intersperse_two
  {
    template <typename Xa, typename Xb>
    using apply = concat<Xa, make_seq_t<Tag, X, Xb>>;
  };

  template <typename Seq, typename X>
  struct intersperse_non_empty :
    fold_left_initial<
      intersperse_two<tag_t<Seq>, X>,
      pop_front_t<Seq>, make_seq_t<tag_t<Seq>, front_t<Seq>>
    >
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_transformation
 * @brief Inserts an element between the elements of a sequence
 *
 * Inserts a single element between all the elements of a @ref tc_sequence.
 *
 * @see @ref concat
 * @see @ref intercalate
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Elem
 *   The element to insert.
 *
 * ## Example
 *
 * @include example/individual/alg_transformation/intersperse.cpp
 */
template <typename Seq, typename Elem>
struct intersperse
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      typename empty<Seq>::type, \
      Seq, \
      detail::intersperse_non_empty<Seq, Elem> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A new @ref tc_sequence with `Elem` between the elements of `Seq`.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::intersperse
 *
 * @invokesmfn{intersperse}
 *
 * @tparam Seq
 *   A @ref tc_sequence.
 * @tparam Elem
 *   The element to insert.
 */
template <typename Seq, typename Elem>
using intersperse_t = typename intersperse<Seq, Elem>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_INTERSPERSE_HPP
