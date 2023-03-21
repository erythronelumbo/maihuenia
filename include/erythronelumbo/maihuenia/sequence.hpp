// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file sequence.hpp
 *
 * @brief `Sequence` typeclass
 *
 * Defines the `Sequence` typeclass.
 */

/**
 * @defgroup tc_sequence Sequence
 * @ingroup typeclasses
 *
 * @brief Sequences of elements
 *
 * An extension of @ref tc_iterable which represents container-like types that
 * can be initialized with the elements to be contained, as well as inserting
 * and erasing elements from them.
 *
 * This typeclass can also implement @ref tc_functor, @ref tc_functor,
 * @ref tc_applicative, @ref tc_monad, @ref tc_monadplus and @ref tc_foldable.
 *
 * ### Minimal complete definition
 *
 * `make_seq<SeqTag, Xs...>`, `clear<Seq>`, `concat<Seq1, Seq2, Seqs...>`.
 *
 * @see @ref tc_extensiblemapping
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_SEQUENCE_HPP
#define ERYTHRONELUMBO_MAIHUENIA_SEQUENCE_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typeclasstag{tc_sequence}
 */
struct Sequence ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Sequence, \
    1, \
    (::erythronelumbo::maihuenia::Iterable), \
    ( \
      (make_seq, 0, 0, 1, 1, ()), \
      (clear, 0, 1, 0, 0, (0)), \
      (concat, 1, (0)) \
    ), \
    ( \
      (push_front, 0, 2, 0, 0, (0)), \
      (push_back, 0, 2, 0, 0, (0)), \
      (pop_back, 0, 1, 0, 0, (0)), \
      (take, 0, 2, 0, 0, (0)), \
      (insert, 0, 3, 0, 0, (0)), \
      (erase, 0, 2, 0, 0, (0)) \
    ) \
  )

  namespace erythronelumbo { namespace maihuenia { namespace detail
  {
    template <typename Seq, typename X>
    using generic_push_front = concat<
      typename make_seq<tag_t<Seq>, X>::type, Seq
    >;

    template <typename Seq, typename X>
    using generic_push_back = concat<
      Seq, typename make_seq<tag_t<Seq>, X>::type
    >;


    template <
      typename Seq, ::std::size_t N,
      bool = (empty<Seq>::type::value || N == 0)
    >
    struct generic_take_ne :
      concat<
        typename make_seq<
          tag_t<Seq>, typename front<Seq>::type
        >::type,
        typename generic_take_ne<
          typename pop_front<Seq>::type, N - 1
        >::type
      >
    {};

    template <typename Seq, ::std::size_t N>
    struct generic_take_ne<Seq, N, true> : clear<Seq> {};

    template <typename Seq, ::std::size_t N, bool = empty<Seq>::type::value>
    struct generic_take :
      generic_take_ne<Seq, N>
    {};

    template <typename Seq, ::std::size_t N>
    struct generic_take<Seq, N, true> :
      Seq
    {};


    template <typename Seq, bool = empty<Seq>::type::value>
    struct generic_pop_back :
      generic_take_ne<Seq, size<Seq>::type::value - 1>
    {};

    template <typename Seq>
    struct generic_pop_back<Seq, true> :
      Seq
    {};


    template <typename Seq, typename Idx, typename Elem>
    using generic_insert = concat<
      typename take<Seq, Idx>::type,
      typename push_front<
        typename drop<Seq, Idx>::type,
        Elem
      >::type
    >;


    template <typename Seq, typename Idx>
    using generic_erase = concat<
      typename take<Seq, Idx>::type,
      typename drop<Seq, size_c<Idx::value + 1>>::type
    >;
  }}} // namespace erythronelumbo::maihuenia::detail

  ERYTHRONELUMBO_MAIHUENIA_DEFINE_DERIVED_TYPECLASS_OPS( \
    (erythronelumbo, maihuenia), \
    ::erythronelumbo::maihuenia::Sequence, \
    1, \
    ( \
      ( \
        push_front, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_push_front<X0, X1>) \
      ), \
      ( \
        push_back, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_push_back<X0, X1>) \
      ), \
      ( \
        pop_back, 0, 1, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_pop_back<X0>) \
      ), \
      ( \
        take, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_take<X0, X1::value>) \
      ), \
      ( \
        insert, 0, 3, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_insert<X0, X1, X2>) \
      ), \
      ( \
        erase, 0, 2, 0, 0, (0), \
        (::erythronelumbo::maihuenia::detail::generic_erase<X0, X1>) \
      ) \
    ) \
  )
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup tc_sequence
 * @brief Makes a sequence
 *
 * Initializes a sequence with its respective type tag and the elements to be
 * contained.
 *
 * @tparam SeqTag
 *   The tag that represents the new sequence.
 * @tparam Elems...
 *   The elements to be contained.
 *
 * ## Example
 *
 * @include example/individual/sequence/make_seq.cpp
 */
template <typename SeqTag, typename... Elems>
struct make_seq
{
  /**
   * @brief Result
   *
   * A new sequence containing the specified elements.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief *Clears* a sequence
 *
 * Creates an empty version (with no elements) of a sequence.
 *
 * @tparam Seq
 *   A sequence.
 *
 * ## Example
 *
 * @include example/individual/sequence/clear.cpp
 */
template <typename Seq>
struct clear
{
  /**
   * @brief Result
   *
   * An empty sequence.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Concatenates sequences
 *
 * Concatenates several sequences, creating a new one.
 *
 * @tparam Seq1
 *   A sequence.
 * @tparam Seq2
 *   A sequence.
 * @tparam Seqs...
 *   Sequences.
 *
 * ## Example
 *
 * @include example/individual/sequence/concat.cpp
 */
template <typename Seq1, typename Seq2, typename... Seqs>
struct concat
{
  /**
   * @brief Result
   *
   * A sequence that results from concatenting other sequences.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Inserts an element at the beginning of a sequence
 *
 * Inserts an element that will be located at the beginning of a sequence.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam X
 *   The element to insert.
 *
 * ## Example
 *
 * @include example/individual/sequence/push_front.cpp
 */
template <typename Seq, typename X>
struct push_front
{
  /**
   * @brief Result
   *
   * A sequence with all the elements of `Seq` and the new element located at
   * the beginning.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Inserts an element at the end of a sequence
 *
 * Inserts an element that will be located at the end of a sequence.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam X
 *   The element to insert.
 *
 * ## Example
 *
 * @include example/individual/sequence/push_back.cpp
 */
template <typename Seq, typename X>
struct push_back
{
  /**
   * @brief Result
   *
   * A sequence with all the elements of `Seq` and the new element located at
   * the end.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Removes the last element of a sequence
 * 
 * Removes the element located at the end of a sequence.
 *
 * @tparam Seq
 *   A sequence.
 *
 * ## Example
 *
 * @include example/individual/sequence/pop_back.cpp
 */
template <typename Seq>
struct pop_back
{
  /**
   * brief Result
   *
   * A sequence with all the elements of `Seq` except the last one.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Takes the first elements of a sequence
 *
 * Creates a new sequence by taking the first elements of another one.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam N
 *   An integral constant with the number of elements to take.
 *
 * ## Example
 *
 * @include example/individual/sequence/take.cpp
 */
template <typename Seq, typename N>
struct take
{
  /**
   * @brief Result
   *
   * A sequence with the first `N` elements of `Seq`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Inserts an element at any position
 *
 * Inserts an element at any position of the sequence, between `0` and
 * `size<Seq>::value`.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   An integral constant with the position.
 * @tparam Elem
 *   The element to insert.
 *
 * ## Example
 *
 * @include example/individual/sequence/insert.cpp
 */
template <typename Seq, typename Idx, typename Elem>
struct insert
{
  /**
   * @brief Result
   *
   * A sequence with all the elements from `Seq` and the element specified in
   * `Elem` located in `Idx`.
   */
  using type = unspecified;
};

/**
 * @ingroup tc_sequence
 * @brief Removes an element at any position
 *
 * Erases an element at any position of the sequence, between `0` and
 * `size<Seq>::value`.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   An integral constant with the position of the element to remove.
 *
 * ## Example
 *
 * @include example/individual/sequence/erase.cpp
 */
template <typename Seq, typename Idx>
struct erase
{
  /**
   * @brief Result
   *
   * A sequence with all the elements from `Seq` except the one that was located
   * in `Idx`.
   */
  using type = unspecified;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

/**
 * @relates erythronelumbo::maihuenia::make_seq
 *
 * @invokesmfn{make_seq}
 *
 * @tparam SeqTag
 *   The tag that represents the new sequence.
 * @tparam Elems...
 *   The elements to be contained.
 */
template <typename SeqTag, typename... Elems>
using make_seq_t = typename make_seq<SeqTag, Elems...>::type;

/**
 * @relates erythronelumbo::maihuenia::clear
 *
 * @invokesmfn{clear}
 *
 * @tparam Seq
 *   A sequence.
 */
template <typename Seq>
using clear_t = typename clear<Seq>::type;

/**
 * @relates erythronelumbo::maihuenia::concat
 *
 * @invokesmfn{concat}
 *
 * @tparam Seq1
 *   A sequence.
 * @tparam Seq2
 *   A sequence.
 * @tparam Seqs...
 *   Sequences.
 */
template <typename Seq1, typename Seq2, typename... Seqs>
using concat_t = typename concat<Seq1, Seq2, Seqs...>::type;

/**
 * @relates erythronelumbo::maihuenia::push_front
 *
 * @invokesmfn{push_front}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam X
 *   The element to insert.
 */
template <typename Seq, typename X>
using push_front_t = typename push_front<Seq, X>::type;

/**
 * @relates erythronelumbo::maihuenia::push_back
 *
 * @invokesmfn{push_back}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam X
 *   The element to insert.
 */
template <typename Seq, typename X>
using push_back_t = typename push_back<Seq, X>::type;

/**
 * @relates erythronelumbo::maihuenia::pop_back
 * 
 * @invokesmfn{pop_back}
 *
 * @tparam Seq
 *   A sequence.
 */
template <typename Seq>
using pop_back_t = typename pop_back<Seq>::type;

/**
 * @relates erythronelumbo::maihuenia::take
 *
 * @invokesmfn{take}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam N
 *   An integral constant with the number of elements to take.
 */
template <typename Seq, typename N>
using take_t = typename take<Seq, N>::type;

/**
 * @relates erythronelumbo::maihuenia::take
 * @brief Takes the first elements of a sequence
 *
 * Creates a new sequence by taking the first elements of another one.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam N
 *   The number of elements to take.
 */
template <typename Seq, ::std::size_t N>
using take_c = take<Seq, size_c<N>>;

/**
 * @relates erythronelumbo::maihuenia::take
 *
 * @invokesmfn{take}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam N
 *   The number of elements to take.
 */
template <typename Seq, ::std::size_t N>
using take_c_t = typename take<Seq, size_c<N>>::type;

/**
 * @relates erythronelumbo::maihuenia::insert
 *
 * @invokesmfn{insert}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   An integral constant with the position.
 * @tparam Elem
 *   The element to insert.
 */
template <typename Seq, typename Idx, typename Elem>
using insert_t = typename insert<Seq, Idx, Elem>::type;

/**
 * @relates erythronelumbo::maihuenia::insert
 * @brief Inserts an element at any position
 *
 * Inserts an element at any position of the sequence, between `0` and
 * `size<Seq>::value`.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   The position.
 * @tparam Elem
 *   The element to insert.
 */
template <typename Seq, ::std::size_t Idx, typename Elem>
using insert_c = insert<Seq, size_c<Idx>, Elem>;

/**
 * @relates erythronelumbo::maihuenia::insert
 *
 * @invokesmfn{insert}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   The position.
 * @tparam Elem
 *   The element to insert.
 */
template <typename Seq, ::std::size_t Idx, typename Elem>
using insert_c_t = typename insert<Seq, size_c<Idx>, Elem>::type;

/**
 * @relates erythronelumbo::maihuenia::erase
 *
 * @invokesmfn{erase}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   An integral constant with the position of the element to remove.
 */
template <typename Seq, typename Idx>
using erase_t = typename erase<Seq, Idx>::type;

/**
 * @relates erythronelumbo::maihuenia::erase
 * @brief Removes an element at any position
 *
 * Erases an element at any position of the sequence, between `0` and
 * `size<Seq>::value`.
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   The position of the element to remove.
 */
template <typename Seq, ::std::size_t Idx>
using erase_c = erase<Seq, size_c<Idx>>;

/**
 * @relates erythronelumbo::maihuenia::erase
 *
 * @invokesmfn{erase}
 *
 * @tparam Seq
 *   A sequence.
 * @tparam Idx
 *   The position of the element to remove.
 */
template <typename Seq, ::std::size_t Idx>
using erase_c_t = typename erase<Seq, size_c<Idx>>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_SEQUENCE_HPP
