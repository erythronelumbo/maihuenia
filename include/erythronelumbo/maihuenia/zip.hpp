// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file zip.hpp
 *
 * @brief `zip` metafunction
 *
 * Defines the `zip` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ZIP_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ZIP_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename ResTag, typename... Its>
  struct zip_impl
  {
    template <
      typename X, bool = logical_or<typename empty<Its>::type...>::type::value
    >
    struct result_ : make_seq<ResTag> {};

    template <typename X>
    struct result_<X, false> :
      push_front<
        typename zip_impl<
          ResTag, pop_front_t<Its>...
        >::template result_<X>::type,
        vector<front_t<Its>...>
      >
    {};
  };

  template <typename ResTag, typename It>
  struct zip_impl<ResTag, It>
  {
    template <
      typename X, bool = empty<It>::type::value
    >
    struct result_ : make_seq<ResTag> {};

    template <typename X>
    struct result_<X, false> :
      push_front<
        typename zip_impl<
          ResTag, pop_front_t<It>
        >::template result_<X>::type,
        vector<front_t<It>>
      >
    {};
  };
} // namespace detail


template <typename ResTag, typename... Its>
struct zip :
  detail::zip_impl<ResTag, Its...>::template result_<void>
{};

template <typename ResTag>
struct zip<ResTag> : make_seq<ResTag> {};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup alg_creation
 * @brief Zips iterables
 *
 * *Zips* several @ref tc_iterable s: creates a @ref tc_sequence of
 * @ref vector s, where the `I`-th `vector` contains the `I`-th elements from
 * the supplied iterables, in a parallel fashion.
 *
 * If the supplied iterables have different sizes, the resulting sequence will
 * have the same size as the shortest iterable (it can also be empty).
 *
 * @see @ref zipped_view
 * @see @ref zip_with
 *
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 * @tparam Its...
 *   The @ref tc_iterable s.
 *
 * ## Example
 *
 * @include example/individual/alg_creation/zip.cpp
 */
template <typename ResTag, typename... Its>
struct zip
{
  /**
   * @brief Result
   *
   * A @ref tc_sequence of @ref vector s as described for the respective
   * metafunction or, if no @ref tc_iterable s are provided and/or at least one
   * iterable is empty, an empty sequence.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @relates erythronelumbo::maihuenia::zip
 *
 * @invokesmfn{zip}
 *
 * @tparam ResTag
 *   The type tag of the resulting @ref tc_sequence.
 * @tparam Its...
 *   The @ref tc_iterable s.
 */
template <typename ResTag, typename... Its>
using zip_t = typename zip<ResTag, Its...>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ZIP_HPP
