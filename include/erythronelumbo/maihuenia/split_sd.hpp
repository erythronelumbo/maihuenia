// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file split_sd.hpp
 *
 * @brief `split_sd` metafunction
 *
 * Defines the `split_sd` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SPLIT_SD_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SPLIT_SD_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/take_until.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>
#include <erythronelumbo/maihuenia/detail/split_helpers.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <
    typename Str, typename Delims, typename Res,
    bool = empty_t<Str>::value,
    bool = empty_t<pop_front_t<Str>>::value
  >
  struct split_sd_helper :
    split_sd_helper<
      drop_t<
        Str,
        eval_if_t<
          contains_t<Delims, front_t<Str>>,
          /* [delim][...] --> [...] */
          size_c<1>,
          /* [non-delims...][delim][...] --> [delim][...] */
          split_count_non_delims<Str, Delims>
        >
      >,
      Delims,
      eval_if_t<
        contains_t<Delims, front_t<Str>>,
        /* [delim][x][...] -> [x][...] */
        eval_if<
          contains_t<Delims, front_t<pop_front_t<Str>>>,
          push_back<Res, clear_t<Str>>,
          Res
        >,
        /* [non-delims...][delim][...] -> [take_until(Str, is_delim), ...] */
        push_back<Res, take_until_t<Str, is_delim_<Delims>>>
      >
    >
  {};

  template <typename Str, typename Delims, typename Res>
  struct split_sd_helper<Str, Delims, Res, false, true> :
    eval_if<
      contains_t<Delims, front_t<Str>>,
      push_back<Res, clear_t<Str>>,
      push_back<Res, Str>
    >
  {};

  template <typename Str, typename Delims, typename Res>
  struct split_sd_helper<Str, Delims, Res, true, true> :
    Res
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup alg_creation
 * @brief Splits a sequence by a single delimiter
 *
 * Splits a @ref tc_sequence by taking *substrings* separated by a single
 * delimiter. If there are two or more consecutive delimiters, this metafuction
 * will assume that there are empty substrings between them.
 *
 * @note
 *   The `_sd` in this metafunction's name stands for "single delimiter".
 *
 * @see @ref split
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
 * @include example/individual/alg_creation/split_sd.cpp
 */
template <typename Str, typename Delims, typename ResTag>
struct split_sd
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : eval_if< \
      empty_t<Str>, \
      make_seq<ResTag>, \
      detail::split_sd_helper< \
        Str, \
        Delims, \
        eval_if_t< \
          contains_t<Delims, front_t<Str>>, \
          make_seq<ResTag, clear_t<Str>>, \
          make_seq<ResTag> \
        > \
      > \
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
 * @relates erythronelumbo::maihuenia::split_sd
 *
 * @invokesmfn{split_sd}
 *
 * @tparam Str
 *   A @ref tc_sequence.
 * @tparam Delims
 *   A @ref tc_iterable with the elements that delimit the substrings to take.
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 */
template <typename Str, typename Delims, typename ResTag>
using split_sd_t = typename split_sd<Str, Delims, ResTag>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SPLIT_SD_HPP
