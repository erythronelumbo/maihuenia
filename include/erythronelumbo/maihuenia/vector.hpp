// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `vector` type
 *
 * Defines the `vector` type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_VECTOR_HPP
#define ERYTHRONELUMBO_MAIHUENIA_VECTOR_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/fwd/vector.hpp>
#include <erythronelumbo/maihuenia/detail/enable_if.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/size.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/drop.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/variadic_indexers.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>
#include <erythronelumbo/maihuenia/monad_plus.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <>
struct iterable_is_random_access_impl<vector_tag>
{
  struct apply
  {
    using type = true_;
  };
};


namespace detail
{
  template <bool...> struct vector_eq_bools;

  template <typename X1, typename X2, typename = void>
  struct vector_eq : false_ {};

  template <typename X>
  struct vector_eq<X, X, void> : true_ {};

  template <
    typename IntType1, IntType1... Xs1,
    typename IntType2, IntType2... Xs2
  >
  struct vector_eq<
    vector_c<IntType1, Xs1...>, vector_c<IntType2, Xs2...>,
    enable_if_t<(sizeof...(Xs1) != sizeof...(Xs2))>
  > :
    false_
  {};

  template <
    typename IntType1, IntType1... Xs1,
    typename IntType2, IntType2... Xs2
  >
  struct vector_eq<
    vector_c<IntType1, Xs1...>, vector_c<IntType2, Xs2...>,
    enable_if_t<
      (sizeof...(Xs1) == sizeof...(Xs2)) &&
      !equal_types_t<IntType1, IntType2>::value
    >
  > :
    equal_types<
      vector_eq_bools<(Xs1 == Xs2)...>,
      vector_eq_bools<((void)Xs1, true)...>
    >
  {};

  template <typename ITp1, ITp1... Xs1, typename... Xs2>
  struct vector_eq<
    vector_c<ITp1, Xs1...>, vector<Xs2...>,
    enable_if_t<(sizeof...(Xs1) != sizeof...(Xs2))>
  > :
    false_
  {};

  template <typename ITp1, ITp1... Xs1, typename... Xs2>
  struct vector_eq<
    vector_c<ITp1, Xs1...>, vector<Xs2...>,
    enable_if_t<(sizeof...(Xs1) == sizeof...(Xs2))>
  > :
    equal_types<
      vector_eq_bools<equals_t<integer_c<ITp1, Xs1>, Xs2>::value...>,
      vector_eq_bools<((void)Xs1, true)...>
    >
  {};

  template <typename... Xs1, typename ITp2, ITp2... Xs2>
  struct vector_eq<
    vector<Xs1...>, vector_c<ITp2, Xs2...>,
    enable_if_t<(sizeof...(Xs1) != sizeof...(Xs2))>
  > :
    false_
  {};

  template <typename... Xs1, typename ITp2, ITp2... Xs2>
  struct vector_eq<
    vector<Xs1...>, vector_c<ITp2, Xs2...>,
    enable_if_t<(sizeof...(Xs1) == sizeof...(Xs2))>
  > :
    equal_types<
      vector_eq_bools<equals_t<Xs1, integer_c<ITp2, Xs2>>::value...>,
      vector_eq_bools<((void)Xs2, true)...>
    >
  {};

  template <typename X1, typename X2>
  using vector_neq = bool_<!vector_eq<X1, X2>::type::value>;


  template <typename>
  struct vector_front;

  template <typename X, typename... Xs>
  struct vector_front<vector<X, Xs...>> { using type = X; };

  template <> struct vector_front<vector<>> : undefined {};

  template <typename IntType, IntType... Xs>
  struct vector_front<vector_c<IntType, Xs...>> :
    vector_front<vector<integer_c<IntType, Xs>...>>
  {};


  template <typename>
  struct vector_pop_front;

  template <typename X, typename... Xs>
  struct vector_pop_front<vector<X, Xs...>> : vector<Xs...> {};

  template <typename IntType, IntType X, IntType... Xs>
  struct vector_pop_front<vector_c<IntType, X, Xs...>> :
    vector_c<IntType, Xs...>
  {};

  template <> struct vector_pop_front<vector<>> : vector<> {};

  template <typename IntType>
  struct vector_pop_front<vector_c<IntType>> : vector_c<IntType> {};



  template <typename, typename>
  struct vector_at;

  template <typename... Xs, typename Idx>
  struct vector_at<vector<Xs...>, Idx> :
    variadic_type_indexer<(::std::size_t)Idx::value, Xs...>
  {};

  template <typename Idx>
  struct vector_at<vector<>, Idx> : identity<index_out_of_range>
  {};

  template <typename IntType, IntType... Xs, typename Idx>
  struct vector_at<vector_c<IntType, Xs...>, Idx> :
    variadic_integral_indexer<(::std::size_t)Idx::value, IntType, Xs...>
  {};

  template <typename IntType, typename Idx>
  struct vector_at<vector_c<IntType>, Idx> : identity<index_out_of_range>
  {};


  template <typename>
  struct vector_back;

  template <typename... Xs>
  struct vector_back<vector<Xs...>> :
    variadic_type_indexer<sizeof...(Xs) - 1, Xs...>
  {};

  template <typename IntType, IntType... Xs>
  struct vector_back<vector_c<IntType, Xs...>> :
    variadic_integral_indexer<sizeof...(Xs) - 1, IntType, Xs...>
  {};


  template <typename> struct vec_clear;

  template <typename... Xs> struct vec_clear<vector<Xs...>> : vector<> {};

  template <typename ITp, ITp... Xs>
  struct vec_clear<vector_c<ITp, Xs...>> : vector_c<ITp> {};


  template <typename, typename>
  struct vector_cat;

  template <typename... Xs1, typename... Xs2>
  struct vector_cat<vector<Xs1...>, vector<Xs2...>> :
    vector<Xs1..., Xs2...>
  {};

  template <typename IntType, IntType... Xs1, typename... Xs2>
  struct vector_cat<vector_c<IntType, Xs1...>, vector<Xs2...>> :
    vector<integer_c<IntType, Xs1>..., Xs2...>
  {};

  template <typename... Xs1, typename IntType, IntType... Xs2>
  struct vector_cat<vector<Xs1...>, vector_c<IntType, Xs2...>> :
    vector<Xs1..., integer_c<IntType, Xs2>...>
  {};

  template <
    typename IntType1, IntType1... Xs1,
    typename IntType2, IntType2... Xs2
  >
  struct vector_cat<vector_c<IntType1, Xs1...>, vector_c<IntType2, Xs2...>> :
    vector<integer_c<IntType1, Xs1>..., integer_c<IntType2, Xs2>...>
  {};

  template <
    typename IntType, IntType... Xs1, IntType... Xs2
  >
  struct vector_cat<vector_c<IntType, Xs1...>, vector_c<IntType, Xs2...>> :
    vector_c<IntType, Xs1..., Xs2...>
  {};


  template <bool>
  struct enable_vec_se
  {
    template <typename C>
    struct result_ : vector<C> {};
  };

  template <>
  struct enable_vec_se<false>
  {
    template <typename>
    struct result_ : vector<> {};
  };


  template <typename ITp, bool>
  struct enable_vec_c_se
  {
    template <ITp C>
    struct result_ : vector_c<ITp, C> {};
  };

  template <typename ITp>
  struct enable_vec_c_se<ITp, false>
  {
    template <ITp>
    struct result_ : vector_c<ITp> {};
  };


  template <
    ::std::size_t VecSz, ::std::size_t N,
    typename = varseq_make_idx_seq_t<VecSz>
  >
  struct vec_take_impl_ne;

  template <
    ::std::size_t VecSz, ::std::size_t N,
    ::std::size_t... Idcs
  >
  struct vec_take_impl_ne<
    VecSz, N, varseq_idx_seq<Idcs...>
  >
  {
    template <typename, typename>
    struct result_;

    template <typename... Xs, typename X>
    struct result_<vector<Xs...>, X> :
      bin_op_many_c<
        vector_cat,
        false,
        typename enable_vec_se<(Idcs < N)>::template result_<Xs>::type...
      >
    {};

    template <typename ITp, ITp... Xs, typename X>
    struct result_<vector_c<ITp, Xs...>, X> :
      bin_op_many_c<
        vector_cat,
        false,
        typename enable_vec_c_se<
          ITp, (Idcs < N)
        >::template result_<Xs>::type...
      >
    {};
  };


  template <typename Str, typename N>
  struct vec_take;

  template <typename... Xs, typename N>
  struct vec_take<vector<Xs...>, N> :
    vec_take_impl_ne<sizeof...(Xs), (::std::size_t)N::value>::template result_<
      vector<Xs...>, void
    >
  {};

  template <typename N>
  struct vec_take<vector<>, N> :
    vector<>
  {};

  template <typename ITp, ITp... Xs, typename N>
  struct vec_take<vector_c<ITp, Xs...>, N> :
    vec_take_impl_ne<sizeof...(Xs), (::std::size_t)N::value>::template result_<
      vector_c<ITp, Xs...>, void
    >
  {};

  template <typename ITp, typename N>
  struct vec_take<vector_c<ITp>, N> :
    vector_c<ITp>
  {};


  template <typename Str>
  struct vec_pop_back;

  template <typename... Xs>
  struct vec_pop_back<vector<Xs...>> :
    vec_take_impl_ne<sizeof...(Xs), sizeof...(Xs) - 1>::template result_<
      vector<Xs...>, void
    >
  {};

  template <>
  struct vec_pop_back<vector<>> :
    vector<>
  {};

  template <typename ITp, ITp... Xs>
  struct vec_pop_back<vector_c<ITp, Xs...>> :
    vec_take_impl_ne<sizeof...(Xs), sizeof...(Xs) - 1>::template result_<
      vector_c<ITp, Xs...>, void
    >
  {};

  template <typename ITp>
  struct vec_pop_back<vector_c<ITp>> :
    vector_c<ITp>
  {};



  template <typename, typename>
  struct vector_trfm;

  template <typename Fn, typename... Xs>
  struct vector_trfm<Fn, vector<Xs...>> :
    vector<typename Fn::template apply<Xs>::type...>
  {};

  template <typename Fn, typename IntType, IntType... Xs>
  struct vector_trfm<Fn, vector_c<IntType, Xs...>> :
    vector<typename Fn::template apply<integer_c<IntType, Xs>>::type...>
  {};


  template <typename, typename>
  struct vector_ap;

  template <typename Fn, typename... Fns, typename... Xs>
  struct vector_ap<vector<Fn, Fns...>, vector<Xs...>> :
    concat<
      typename transform<Fn, vector<Xs...>>::type,
      typename vector_ap<vector<Fns...>, vector<Xs...>>::type
    >
  {};

  template <typename Fn, typename... Xs>
  struct vector_ap<vector<Fn>, vector<Xs...>> :
    transform<Fn, vector<Xs...>>
  {};

  template <typename... Xs>
  struct vector_ap<vector<>, vector<Xs...>> : vector<> {};

  template <typename... Fns>
  struct vector_ap<vector<Fns...>, vector<>> : vector<> {};

  template <typename... Fns, typename IntType, IntType... Xs>
  struct vector_ap<vector<Fns...>, vector_c<IntType, Xs...>> :
    vector_ap<vector<Fns...>, vector<integer_c<IntType, Xs>...>>
  {};


  template <typename, typename>
  struct vector_mbind;

  template <typename... Xs, typename Fn>
  struct vector_mbind<vector<Xs...>, Fn> :
    concat<vector<>, typename Fn::template apply<Xs>::type...>
  {};

  template <typename Fn>
  struct vector_mbind<vector<>, Fn> :
    vector<>
  {};

  template <typename IntType, IntType... Xs, typename Fn>
  struct vector_mbind<vector_c<IntType, Xs...>, Fn> :
    concat<
      vector<>,
      typename Fn::template apply<integer_c<IntType, Xs>>::type...
    >
  {};

  template <typename IntType, typename Fn>
  struct vector_mbind<vector_c<IntType>, Fn> :
    vector_c<IntType>
  {};
} // namespace detail


template <>
struct typeclass<Foldable>::define_for<vector_tag> :
  detail::sequence_folds<vector_tag>
{};

}} // namespace erythronelumbo::maihuenia


ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Comparable, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (equals, 2, 0, (::erythronelumbo::maihuenia::detail::vector_eq<X0, X1>)), \
    ( \
      not_equals, 2, 0, \
      (::erythronelumbo::maihuenia::detail::vector_neq<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Monoid, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (mident, 0, 0, (::erythronelumbo::maihuenia::vector<>)), \
    (mappend, 2, 0, (::erythronelumbo::maihuenia::detail::vector_cat<X0, X1>)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Iterable, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (empty, 1, 0, (::erythronelumbo::maihuenia::detail::varseq_empty<X0>)), \
    (front, 1, 0, (::erythronelumbo::maihuenia::detail::vector_front<X0>)), \
    ( \
      pop_front, 1, 0, \
      (::erythronelumbo::maihuenia::detail::vector_pop_front<X0>) \
    ) \
  ), \
  ( \
    (back, 1, 0, (::erythronelumbo::maihuenia::detail::vector_back<X0>)), \
    (at, 2, 0, (::erythronelumbo::maihuenia::detail::vector_at<X0, X1>)), \
    (size, 1, 0, (::erythronelumbo::maihuenia::detail::varseq_size<X0>)), \
    ( \
      drop, 2, 0, \
      ( \
        ::erythronelumbo::maihuenia::detail::varseq_drop< \
          X0, (::std::size_t)X1::value \
        > \
      ) \
    ) \
  ) \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Sequence, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (make_seq, 0, 1, (::erythronelumbo::maihuenia::vector<Xs...>)), \
    (concat, 2, 0, (::erythronelumbo::maihuenia::detail::vector_cat<X0, X1>)), \
    (clear, 1, 0, (::erythronelumbo::maihuenia::detail::vec_clear<X0>)) \
  ), \
  ( \
    ( \
      push_front, 2, 0, \
      (::erythronelumbo::maihuenia::detail::generic_push_front<X0, X1>) \
    ), \
    ( \
      push_back, 2, 0, \
      (::erythronelumbo::maihuenia::detail::generic_push_back<X0, X1>) \
    ), \
    ( \
      pop_back, 1, 0, \
      (::erythronelumbo::maihuenia::detail::vec_pop_back<X0>) \
    ), \
    ( \
      take, 2, 0, \
      (::erythronelumbo::maihuenia::detail::vec_take<X0, X1>) \
    ), \
    ( \
      insert, 3, 0, \
      (::erythronelumbo::maihuenia::detail::generic_insert<X0, X1, X2>) \
    ), \
    ( \
      erase, 2, 0, \
      (::erythronelumbo::maihuenia::detail::generic_erase<X0, X1>) \
    ) \
  ) \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Functor, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    ( \
      transform, 2, 0, \
      (::erythronelumbo::maihuenia::detail::vector_trfm<X0, X1>) \
    ) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Applicative, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (lift, 1, 0, (::erythronelumbo::maihuenia::vector<X0>)), \
    (ap, 2, 0, (::erythronelumbo::maihuenia::detail::vector_ap<X0, X1>)) \
  ), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::Monad, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ((mbind, 2, 0, (::erythronelumbo::maihuenia::detail::vector_mbind<X0, X1>))), \
  () \
)

ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::erythronelumbo::maihuenia::MonadPlus, \
  ((::erythronelumbo::maihuenia::vector_tag)), \
  ( \
    (mplus, 2, 0, (::erythronelumbo::maihuenia::concat<X0, X1>)), \
    (mzero, 0, 0, (::erythronelumbo::maihuenia::vector<>)) \
  ), \
  () \
)

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_VECTOR_HPP
