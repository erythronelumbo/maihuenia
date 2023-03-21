// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file iterable_is_random_access.hpp
 *
 * @brief `iterable_is_random_access` metafunction
 *
 * Defines the `iterable_is_random_access` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ITERABLE_IS_RANDOM_ACCESS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ITERABLE_IS_RANDOM_ACCESS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/enable_if.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <typename ItTag>
struct iterable_is_random_access_impl
{
  struct apply
  {
    using type = false_;
  };
};

namespace detail
{
  template <
    typename It,
    bool = typeclass<Iterable>::template define_for<tag_t<It>>::value
  >
  struct iterable_is_random_access_safe
  {
    using type = typename iterable_is_random_access_impl<
      tag_t<It>
    >::apply::type;
  };

  template <typename It>
  struct iterable_is_random_access_safe<It, false>
  {};
} // namespace detail

template <typename It>
struct iterable_is_random_access :
  detail::iterable_is_random_access_safe<It>
{};

template <typename ItTag>
struct iterable_tag_is_random_access :
  iterable_is_random_access_impl<ItTag>::template apply
{};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup tc_iterable
 * @brief Checks if an iterable is *random-access*
 *
 * Checks if any element from an @ref tc_iterable can be retrieved in a
 * *random-access* manner, i.e., in *constant* time, in contrast to *sequential
 * access*, where the access to any element is done in a *step-by-step* manner.
 *
 * @note This is not an intrinsic operation of @ref tc_iterable, but it is a
 * helper for optimizing certain metafunctions from this library.
 *
 * @see @ref iterable_tag_is_random_access
 *
 * @tparam It
 *   An @ref tc_iterable.
 */
template <typename It>
struct iterable_is_random_access
{
  /**
   * @brief Result
   *
   * If `It` is an instance of @ref tc_iterable, it will be `true_` or `false_`;
   * otherwise, it will fail.
   *
   * For custom types, the `iterable_is_random_access_impl` struct must be
   * overloaded as follows:
   *
   * ```
   * namespace erythronelumbo { namespace maihuenia
   * {
   *
   * template <>
   * struct iterable_is_random_access_impl<my_type_tag>
   * {
   *   struct apply
   *   {
   *     using type = true_-or-false_;
   *   };
   * };
   *  
   * }}
   * ```
   *
   * If the previous struct was not overloaded, the default result will be
   * `false_`.
   */
  using type = unspecified;
};


/**
 * @ingroup tc_iterable
 * @brief Checks if the type tag an iterable is *random-access*
 *
 * Checks if the elements of a data type, represented by its type tag, can be
 * retrieved in a *random-access* manner or not.
 *
 * @note This is not an intrinsic operation of @ref tc_iterable, but it is a
 * helper for optimizing certain metafunctions from this library.
 *
 * @see @ref iterable_is_random_access
 *
 * @tparam It
 *   The typr tag of an @ref tc_iterable.
 */
template <typename It>
struct iterable_tag_is_random_access
{
  /**
   * @brief Result
   *
   * `true_` if the @ref tc_iterable represented by `ItTag` is random-access,
   * `false_` otherwise.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ITERABLE_IS_RANDOM_ACCESS_HPP
