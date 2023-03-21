// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file iterable.hpp
 *
 * @brief `Iterable` typeclass
 *
 * Defines the `Iterable` typeclass.
 */

/**
 * @defgroup tc_iterable Iterable
 * @ingroup typeclasses
 *
 * @brief Iterable data types
 *
 * Represents data structures which can be traversed over, one element at the
 * time. It allows accessing the first element (or *head*) of the structure, as
 * well as the remaining elements (or *tail*) and checking if the *iterable* has
 * no elements (is *empty*).
 *
 * The involved iteration process implies taking the tail of a type, the tail of
 * the previous tail, the tail of the tail of the tail and so on, while also
 * taking the head elements from those tails, until the resulting tail is empty.
 *
 * ### Minimal complete definition
 *
 * `empty<T>`, `front<T>`, `pop_front<T>`.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_ITERABLE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_ITERABLE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_iterable}
 */
struct Iterable ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Iterable, \
    1, \
    (), \
    ( \
      (empty, 0, 1, 0, 0, (0)), \
      (front, 0, 1, 0, 0, (0)), \
      (pop_front, 0, 1, 0, 0, (0)) \
    ), \
    ( \
      (back, 0, 1, 0, 0, (0)), \
      (at, 0, 2, 0, 0, (0)), \
      (size, 0, 1, 0, 0, (0)), \
      (drop, 0, 2, 0, 0, (0)) \
    ) \
  )

  namespace erythronelumbo { namespace maihuenia { namespace detail
  {
    template <
      typename It, bool = empty<typename pop_front<It>::type>::type::value
    >
    struct generic_back_ne : generic_back_ne<typename pop_front<It>::type> {};

    template <typename It>
    struct generic_back_ne<It, true> : front<It> {};

    template <typename It, bool = empty<It>::type::value>
    struct generic_back : generic_back_ne<It> {};

    template <typename It>
    struct generic_back<It, true> : identity<index_out_of_range> {};


    template <typename It, ::std::size_t Idx, bool = empty<It>::type::value>
    struct generic_at :
      generic_at<typename pop_front<It>::type, Idx - 1>
    {};

    template <typename It> struct generic_at<It, 0, false> : front<It> {};

    template <typename It, ::std::size_t Idx>
    struct generic_at<It, Idx, true> : identity<index_out_of_range> {};


    template <
      typename It, ::std::size_t N, bool = (empty<It>::type::value || N == 0)
    >
    struct generic_drop :
      generic_drop<typename pop_front<It>::type, N - 1>
    {};

    template <typename It, ::std::size_t N>
    struct generic_drop<It, N, true> :
      It
    {};


    template <typename It, bool = empty<It>::type::value>
    struct generic_size :
      size_c<1 + generic_size<typename pop_front<It>::type>::type::value>
    {};

    template <typename It>
    struct generic_size<It, true> : size_c<0> {};
  }}} // namespace erythronelumbo::maihuenia::detail


  ERYTHRONELUMBO_MAIHUENIA_DEFINE_DERIVED_TYPECLASS_OPS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Iterable, \
    1, \
    ( \
      ( \
        back, 0, 1, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_back<X0>) \
      ), \
      ( \
        at, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_at<X0, X1::value>) \
      ), \
      ( \
        size, 0, 1, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_size<X0>) \
      ), \
      ( \
        drop, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_drop<X0, X1::value>) \
      ) \
    ) \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_iterable
 * @brief Checks emptiness of an iterable
 *
 * Checks if an iterable contains no elements.
 *
 * @tparam It
 *   A type to check.
 *
 * ## Example
 *
 * @include example/individual/iterable/empty.cpp
 */
template <typename It>
struct empty
{
  /**
   * @brief Result
   *
   * A `bool_`: `true_` if the iterable is empty, `false_` otherwise.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief First element of an iterable
 *
 * Retrieves the first element contained in an iterable.
 *
 * @tparam It
 *   An iterable.
 *
 * ## Example
 *
 * @include example/individual/iterable/front.cpp
 */
template <typename It>
struct front
{
  /**
   * @brief Result
   *
   * The first element contained in the iterable or @ref undefined if empty.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief Tail of an iterable
 *
 * Gets the *tail* of an iterable, i.e., it *removes* the first element of the
 * given iterable.
 *
 * @tparam It
 *   An iterable.
 *
 * ## Example
 *
 * @include example/individual/iterable/pop_front.cpp
 */
template <typename It>
struct pop_front
{
  /**
   * @brief Result
   *
   * The iterable given in `It`, but without its first element.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief Last element of an iterable
 *
 * Retrieves the *back* (the last element) of an iterable, if it is not empty.
 *
 * @tparam It
 *   An iterable.
 *
 * ## Example
 *
 * @include example/individual/iterable/back.cpp
 */
template <typename It>
struct back
{
  /**
   * @brief Result
   *
   * The last element contained in the given iterable or @ref undefined if
   * empty.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief Arbitrary element of an iterable
 *
 * Retrieves an arbitrary element of an iterable, which is located in the
 * `Idx`-th position (starting from zero).
 *
 * @tparam It
 *   An iterable.
 * @tparam Idx
 *   An integral constant representing the position.
 *
 * ## Example
 *
 * @include example/individual/iterable/at.cpp
 */
template <typename It, typename Idx>
struct at
{
  /**
   * @brief Result
   *
   * The `Idx`-th element of `It` ot @ref undefined if empty.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief Size of an element
 *
 * Counts the number of elemnts contained in an iterable.
 *
 * @tparam It
 *   An iterable.
 *
 * ## Example
 *
 * @include example/individual/iterable/size.cpp
 */
template <typename It>
struct size
{
  /**
   * @brief Result
   *
   * A `size_c` with the number of elements of `It`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_iterable
 * @brief Drops the first elements of an iterable
 *
 * Removes an arbitrary number of elements at the front of an iterable or
 * *advances* it by an ammount of steps.
 *
 * @tparam It
 *   An iterable.
 * @tparam N
 *   An integral constant with the number of elements to drop.
 *
 * ## Example
 *
 * @include example/individual/iterable/drop.cpp
 */
template <typename It, typename N>
struct drop
{
  /**
   * @brief Result
   *
   * An iterable with all the elements of `It` except for the first `N`
   * elements.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::empty
 *
 * @invokesmfn{empty}
 *
 * @tparam It
 *   An iterable.
 */
template <typename It>
using empty_t = typename empty<It>::type;

/**
 * @relates erythronelumbo::maihuenia::front
 *
 * @invokesmfn{front}
 *
 * @tparam It
 *   An iterable.
 */
template <typename It>
using front_t = typename front<It>::type;

/**
 * @relates erythronelumbo::maihuenia::pop_front
 *
 * @invokesmfn{pop_front}
 *
 * @tparam It
 *   An iterable.
 */
template <typename It>
using pop_front_t = typename pop_front<It>::type;

/**
 * @relates erythronelumbo::maihuenia::back
 *
 * @invokesmfn{back}
 *
 * @tparam It
 *   An iterable.
 */
template <typename It>
using back_t = typename back<It>::type;

/**
 * @relates erythronelumbo::maihuenia::at
 *
 * @invokesmfn{at}
 *
 * @tparam It
 *   An iterable.
 * @tparam Idx
 *   An integral constant representing the position.
 */
template <typename It, typename Idx>
using at_t = typename at<It, Idx>::type;

/**
 * @relates erythronelumbo::maihuenia::at
 * @brief Arbitrary element of an iterable
 *
 * Retrieves an arbitrary element of an iterable, which is located in the
 * `Idx`-th position (starting from zero).
 *
 * @tparam It
 *   An iterable.
 * @tparam Idx
 *   The position.
 */
template <typename It, ::std::size_t Idx>
using at_c = at<It, size_c<Idx>>;

/**
 * @relates erythronelumbo::maihuenia::at
 *
 * @invokesmfn{at_c}
 *
 * @tparam It
 *   An iterable.
 * @tparam Idx
 *   The position.
 */
template <typename It, ::std::size_t Idx>
using at_c_t = typename at<It, size_c<Idx>>::type;

/**
 * @relates erythronelumbo::maihuenia::drop
 *
 * @invokesmfn{drop}
 *
 * @tparam It
 *   An iterable.
 * @tparam N
 *   An integral constant with the number of elements to drop.
 */
template <typename It, typename N>
using drop_t = typename drop<It, N>::type;

/**
 * @relates erythronelumbo::maihuenia::drop
 * @brief Drops the first elements of an iterable
 *
 * Removes an arbitrary number of elements at the front of an iterable or
 * *advances* it by an ammount of steps.
 *
 * @tparam It
 *   An iterable.
 * @tparam N
 *   The number of elements to drop.
 */
template <typename It, ::std::size_t N>
using drop_c = drop<It, size_c<N>>;

/**
 * @relates erythronelumbo::maihuenia::drop
 *
 * @invokesmfn{drop_c}
 *
 * @tparam It
 *   An iterable.
 * @tparam N
 *   The number of elements to drop.
 */
template <typename It, ::std::size_t N>
using drop_c_t = typename drop<It, size_c<N>>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_ITERABLE_HPP
