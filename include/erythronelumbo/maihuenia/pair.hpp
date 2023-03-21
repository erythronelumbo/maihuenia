// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file pair.hpp
 *
 * @brief Pair data type
 *
 * Defines a pair data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_PAIR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_PAIR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup dt_miscellaneous
 * @brief Pair
 *
 * A type that contains two elements.
 *
 * @tparam Fst The first element.
 * @tparam Snd The second element.
 */
template <typename Fst, typename Snd>
struct pair
{
  /**
   * @mfncalltoitself
   */
  using type = pair;

  /**
   * @brief First element
   *
   * The first element of the pair.
   */
  using first = Fst;

  /**
   * @brief Second element
   *
   * The second element of the pair.
   */
  using second = Snd;
};

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_PAIR_HPP
