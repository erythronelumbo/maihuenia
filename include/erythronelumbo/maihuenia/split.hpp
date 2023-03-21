// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file split.hpp
 *
 * @brief `split` metafunction
 *
 * Defines the `split` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SPLIT_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SPLIT_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/take_until.hpp>
#include <erythronelumbo/maihuenia/detail/split_helpers.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename Str, typename Delims, typename Res,
    bool = empty_t<Str>::value
  >
  struct split_helper :
    split_helper<
      drop_t<
        Str,
        eval_if_t<
          contains_t<Delims, front_t<Str>>,
          split_count_delims<Str, Delims>,
          split_count_non_delims<Str, Delims>
        >
      >,
      Delims,
      eval_if_t<
        contains_t<Delims, front_t<Str>>,
        Res,
        push_back<Res, take_until_t<Str, is_delim_<Delims>>>
      >
    >
  {};

  template <typename Str, typename Delims, typename Res>
  struct split_helper<Str, Delims, Res, true> : Res {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_creation
 * @brief Splits a sequence by multiple delimiters
 *
 * Splits a @ref tc_sequence by taking *substrings* separated by one or more
 * consecutive delimiters. if the first elements of the sequence are
 * delimieters, this metafunction will ignore them until it detects the first
 * non-delimiter element.
 *
 * @see @ref split_sd
 *
 * @tparam Str
 *   A @ref tc_sequence.
 * @tparam Delims
 *   A @ref tc_iterable with the elements that delimit the substrings to take.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/split.cpp
 */
template <typename Str, typename Delims, typename ResTag>
struct split
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::split_helper< \
      Str, Delims, make_seq_t<ResTag> \
    > \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref tc_sequence as specified in `ResTag` with the obtained substrings.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::split
 *
 * @invokesmfn{split}
 *
 * @tparam Str
 *   A @ref tc_sequence.
 * @tparam Delims
 *   A @ref tc_iterable with the elements that delimit the substrings to take.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 */
template <typename Str, typename Delims, typename ResTag>
using split_t = typename split<Str, Delims, ResTag>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SPLIT_HPP
