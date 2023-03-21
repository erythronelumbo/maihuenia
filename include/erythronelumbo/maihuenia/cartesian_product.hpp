// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file cartesian_product.hpp
 *
 * @brief `cartesian_product` metafunction
 *
 * Defines the `cartesian_product` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_CARTESIAN_PRODUCT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_CARTESIAN_PRODUCT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/unpack_args.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/copy.hpp>
#include <erythronelumbo/maihuenia/transformed_view.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  // [a], b -> [a, b]
  template <typename ItFront1>
  struct cprod_append_to_front
  {
    template <typename It2Elem>
    struct apply :
      push_back<ItFront1, It2Elem>
    {};
  };

  /**
   * ```
   * [a], [b0, b1, b2, ...]
   * -> [pbk([a], b0), pbk([a], b1), pbk([a], b2), ...]
   * -> [[a, b0], [a, b1], [a, b2], ...]
   * ```
   */
  template <typename ResTag, typename ItFront1, typename It2>
  struct cprod_front :
    /* Assumes that `It2` does not implement `Functor` */
    copy<
      ResTag,
      transformed_view<
        It2,
        cprod_append_to_front<ItFront1>
      >
    >
  {};

  /**
   * ```
   * [[a0], [a1], [a2], ...], [b0, b1, b2, ...]
   * -> concat(
   *   cprod_front([a0], [b0, b1, b2, ...]),
   *   cprod_front([a1], [b0, b1, b2, ...]),
   *   cprod_front([a2], [b0, b1, b2, ...])
   * )
   * -> concat(
   *   [[a0, b0], [a0, b1], [a0, b2], ...],
   *   [[a1, b0], [a1, b1], [a1, b2], ...],
   *   [[a2, b0], [a2, b1], [a2, b2], ...],
   *   ...
   * )
   * -> [
   *   [a0, b0], [a0, b1], [a0, b2], ...,
   *   [a1, b0], [a1, b1], [a1, b2], ...,
   *   [a2, b0], [a2, b1], [a2, b2], ...
   * ]
   * ```
   */
  template <typename It1, typename It2>
  struct cprod_two :
    unpack_args<quote<concat>>::template apply<
      transform_t<
        lambda<cprod_front<tag_t<It1>, placeholders::_1, It2>>,
        It1
      >
    >
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_creation
 * @brief Cartesian product
 *
 * Computes the *Cartesian product* of two or more @ref tc_iterable s, resulting
 * in a @ref tc_sequence of @ref vector s.
 *
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence. It must be also a
 *   @ref tc_functor.
 * @tparam It1, It2, Its...
 *   @ref tc_iterable s.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/cartesian_product.cpp
 */
template <typename ResTag, typename It1, typename It2, typename... Its>
struct cartesian_product
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : bin_op_many_c< \
      detail::cprod_two, false, \
      copy_t<ResTag, transformed_view<It1, quote<vector>>>, \
      It2, \
      Its... \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref tc_sequence of @ref vector s corresponding to the Cartesian product
   * of the supplied iterables.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};

/**
 * @relates erythronelumbo::maihuenia::cartesian_product
 *
 * @invokesmfn{cartesian_product}
 *
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence. It must be also a
 *   @ref tc_functor.
 * @tparam It1, It2, Its...
 *   @ref tc_iterable s.
 */
template <typename ResTag, typename It1, typename It2, typename... Its>
using cartesian_product_t = typename cartesian_product<
  ResTag, It1, It2, Its...
>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_CARTESIAN_PRODUCT_HPP
