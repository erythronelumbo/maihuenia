// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief `integral_vector_c` data type
 *
 * Defines the `integral_vector_c` data type.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_VECTOR_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_VECTOR_C_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/error.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/detail/enable_if.hpp>
#include <erythronelumbo/maihuenia/fwd/integral_vector_c.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/size.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/drop.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/take.hpp>
#include <erythronelumbo/maihuenia/detail/varseq/variadic_indexers.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/detail/sequence_folds.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace erythronelumbo { namespace maihuenia
{

template <typename IntType>
struct iterable_is_random_access_impl<integral_vector_c_tag<IntType>>
{
  struct apply
  {
    using type = true_;
  };
};


namespace detail
{
  template <bool...> struct ivec_eq_bools;

  template <typename X1, typename X2, typename = void>
  struct ivec_eq : false_ {};

  template <
    typename IntType1, IntType1... Xs1,
    typename IntType2, IntType2... Xs2
  >
  struct ivec_eq<
    integral_vector_c<IntType1, Xs1...>,
    integral_vector_c<IntType2, Xs2...>,
    enable_if_t<(sizeof...(Xs1) == sizeof...(Xs2))>
  > :
    equal_types<
      ivec_eq_bools<(Xs1 == Xs2)...>,
      ivec_eq_bools<((void)Xs1, true)...>
    >
  {};

  template <
    typename IntType1, IntType1... Xs1,
    typename IntType2, IntType2... Xs2
  >
  struct ivec_eq<
    integral_vector_c<IntType1, Xs1...>,
    integral_vector_c<IntType2, Xs2...>,
    enable_if_t<(sizeof...(Xs1) != sizeof...(Xs2))>
  > :
    false_
  {};


  template <typename, typename>
  struct ivec_cat;

  template <typename IntType, IntType... Xs1, IntType... Xs2>
  struct ivec_cat<
    integral_vector_c<IntType, Xs1...>, integral_vector_c<IntType, Xs2...>
  > :
    integral_vector_c<IntType, Xs1..., Xs2...>
  {};


  template <typename IntType, bool>
  struct enable_ivec_se
  {
    template <IntType X>
    using result_ = integral_vector_c<IntType, X>;
  };

  template <typename IntType>
  struct enable_ivec_se<IntType, false>
  {
    template <IntType X>
    using result_ = integral_vector_c<IntType>;
  };


  template <
    ::std::size_t Sz, ::std::size_t N, typename = varseq_make_idx_seq_t<Sz>
  >
  struct ivec_take_ne;

  template <::std::size_t Sz, ::std::size_t N, ::std::size_t... Idcs>
  struct ivec_take_ne<Sz, N, varseq_idx_seq<Idcs...>>
  {
    template <typename, typename> struct result_;

    template <typename IntType, IntType... Xs, typename X>
    struct result_<integral_vector_c<IntType, Xs...>, X> :
      bin_op_many_c<
        ivec_cat, false,
        typename enable_ivec_se<
          IntType, (Idcs < N)
        >::template result_<Xs>::type...
      >
    {};
  };
} // namespace detail


template <typename IntType1, typename IntType2>
struct typeclass<Comparable>::define_for<
  integral_vector_c_tag<IntType1>, integral_vector_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct equals_impl : detail::ivec_eq<X1, X2> {};

  template <typename X1, typename X2>
  using not_equals_impl = bool_<!detail::ivec_eq<X1, X2>::type::value>;
};


template <typename IntType>
struct typeclass<Iterable>::define_for<integral_vector_c_tag<IntType>> : true_
{
  template <typename X0>
  using empty_impl = detail::varseq_empty<X0>;


  template <typename>
  struct front_impl;

  template <typename ITp_, ITp_ X, ITp_... Xs>
  struct front_impl<integral_vector_c<ITp_, X, Xs...>> :
    integer_c<IntType, X>
  {};

  template <typename ITp_>
  struct front_impl<integral_vector_c<ITp_>> :
    undefined
  {};


  template <typename>
  struct pop_front_impl;

  template <typename ITp_, ITp_ X, ITp_... Xs>
  struct pop_front_impl<integral_vector_c<ITp_, X, Xs...>> :
    integral_vector_c<ITp_, Xs...>
  {};

  template <typename ITp_>
  struct pop_front_impl<integral_vector_c<ITp_>> :
    integral_vector_c<ITp_>
  {};


  template <typename>
  struct back_impl;

  template <typename ITp_, ITp_... Xs>
  struct back_impl<integral_vector_c<ITp_, Xs...>> :
    detail::variadic_integral_indexer<sizeof...(Xs) - 1, ITp_, Xs...>
  {};

  template <typename ITp_>
  struct back_impl<integral_vector_c<ITp_>>
  {
    using type = index_out_of_range;
  };


  template <typename, typename>
  struct at_impl;

  template <typename ITp_, ITp_... Xs, typename Idx>
  struct at_impl<integral_vector_c<ITp_, Xs...>, Idx> :
    detail::variadic_integral_indexer<
      (::std::size_t)Idx::value, ITp_, Xs...
    >
  {};

  template <typename ITp_, typename Idx>
  struct at_impl<integral_vector_c<ITp_>, Idx>
  {
    using type = index_out_of_range;
  };


  template <typename X, typename N>
  using drop_impl = detail::varseq_drop<X, (::std::size_t)N::value>;


  template <typename X>
  using size_impl = detail::varseq_size<X>;
};


template <typename IntType>
struct typeclass<Foldable>::define_for<integral_vector_c_tag<IntType>> :
  detail::sequence_folds<integral_vector_c_tag<IntType>>
{};


template <typename IntType>
struct typeclass<Sequence>::define_for<integral_vector_c_tag<IntType>> : true_
{
  template <typename... Xs>
  using make_seq_impl = integral_vector_c<IntType, (IntType)Xs::value...>;

  template <typename X>
  struct clear_impl :
    integral_vector_c<IntType>
  {};

  template <typename X1, typename X2>
  using concat_impl = detail::ivec_cat<X1, X2>;


  template <typename, typename>
  struct push_front_impl;

  template <typename ITp_, ITp_... Xs, typename Elem>
  struct push_front_impl<integral_vector_c<ITp_, Xs...>, Elem> :
    integral_vector_c<ITp_, (ITp_)Elem::value, Xs...>
  {};


  template <typename, typename>
  struct push_back_impl;

  template <typename ITp_, ITp_... Xs, typename Elem>
  struct push_back_impl<integral_vector_c<ITp_, Xs...>, Elem> :
    integral_vector_c<ITp_, Xs..., (ITp_)Elem::value>
  {};


  template <typename>
  struct pop_back_impl;

  template <typename ITp_, ITp_... Xs>
  struct pop_back_impl<integral_vector_c<ITp_, Xs...>> :
    detail::ivec_take_ne<sizeof...(Xs), sizeof...(Xs) - 1>::template result_<
      integral_vector_c<ITp_, Xs...>, void
    >
  {};

  template <typename ITp_>
  struct pop_back_impl<integral_vector_c<ITp_>> :
    integral_vector_c<ITp_>
  {};


  template <typename, typename>
  struct take_impl;

  template <typename ITp_, ITp_... Xs, typename N>
  struct take_impl<integral_vector_c<ITp_, Xs...>, N> :
    detail::ivec_take_ne<
      sizeof...(Xs), (::std::size_t)N::value
    >::template result_<
      integral_vector_c<ITp_, Xs...>, void
    >
  {};

  template <typename ITp_, typename N>
  struct take_impl<integral_vector_c<ITp_>, N> :
    integral_vector_c<ITp_>
  {};


  template <typename X, typename Idx, typename Elem>
  using insert_impl = detail::generic_insert<X, Idx, Elem>;

  template <typename X, typename Idx>
  using erase_impl = detail::generic_erase<X, Idx>;
};


template <typename IntType>
struct typeclass<Monoid>::define_for<integral_vector_c_tag<IntType>> : true_
{
  using mident_impl = integral_vector_c<IntType>;

  template <typename X1, typename X2>
  using mappend_impl = detail::ivec_cat<X1, X2>;
};

}} // namespace erythronelumbo::maihuenia

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_INTEGRAL_VECTOR_C_HPP
