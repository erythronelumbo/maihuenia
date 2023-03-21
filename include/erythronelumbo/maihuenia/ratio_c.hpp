// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file ratio_c.hpp
 *
 * @brief `ratio_c` data type
 *
 * Defines the `ratio_c` data type.
 */

/**
 * @defgroup dt_num_ratio_c ratio_c
 * @ingroup dt_numeric
 *
 * @brief Rational number
 *
 * Describes a data type that represents a fraction by using two integral
 * values.
 *
 * ### Models
 *
 * @ref tc_comparable, @ref tc_orderable, @ref tc_numeric, @ref tc_rational,
 * @ref tc_withstringrepr, @ref tc_monoid
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_RATIO_C_HPP
#define ERYTHRONELUMBO_MAIHUENIA_RATIO_C_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>
#include <erythronelumbo/maihuenia/detail/gcd.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>
#include <erythronelumbo/maihuenia/rational.hpp>
#include <erythronelumbo/maihuenia/fwd/string.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/detail/integral_to_string.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @typetag_group{dt_num_ratio_c}
 */
template <typename IntType>
struct ratio_c_tag ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});


/**
 * @ingroup dt_num_ratio_c
 * @brief Rational
 *
 * A data type that represents a fraction and contains its numerator and
 * denominator.
 *
 * @tparam IntType
 *   An integral type.
 * @tparam Num
 *   The numerator.
 * @tparam Den
 *   The denominator.
 *
 * ## Example
 *
 * @include example/individual/numeric_dtps/ratio_c.cpp
 */
template <typename IntType, IntType Num, IntType Den>
struct ratio_c
{
  /**
   * @mfncalltoitself
   */
  using type = ratio_c;

  /**
   * @memtypetag
   */
  using tag = ratio_c_tag<IntType>;

  /**
   * @brief Value type
   *
   * The type of both numerator and denominator.
   */
  using value_type = IntType;

  /**
   * @brief Numerator
   *
   * The numerator.
   */
  static constexpr IntType num = (
    (Den < 0 ? -Num : Num) /
    (IntType)detail::gcd<
      (::std::uint64_t)(Num < 0 ? -Num : Num),
      (::std::uint64_t)(Den < 0 ? -Den : Den)
    >::value
  );

  /**
   * @brief Denominator
   *
   * The denominator.
   */
  static constexpr IntType den = (
    (Den < 0 ? -Den : Den) /
    (IntType)detail::gcd<
      (::std::uint64_t)(Num < 0 ? -Num : Num),
      (::std::uint64_t)(Den < 0 ? -Den : Den)
    >::value
  );
};

template <typename IntType, IntType Num, IntType Den>
constexpr IntType ratio_c<IntType, Num, Den>::num;

template <typename IntType, IntType Num, IntType Den>
constexpr IntType ratio_c<IntType, Num, Den>::den;


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  template <typename Q>
  using ratio_c_to_str = str_concat_two<
    typename str_concat_two<
      to_string_t<integer_c<typename Q::value_type, Q::num>>,
      string<'/'>
    >::type,
    to_string_t<integer_c<typename Q::value_type, Q::den>>
  >;

  template <
    typename IntType, IntType Num, IntType Den,
    IntType NumDenGCD = (IntType)gcd<
      (::std::uint64_t)(Num < 0 ? -Num : Num),
      (::std::uint64_t)(Den < 0 ? -Den : Den)
    >::value
  >
  struct simplified_ratio_c_impl :
    eval_if_c<
      (Den == 0),
      not_a_number,
      ratio_c<
        IntType,
        ((Den < 0 ? -Num : Num) / NumDenGCD),
        ((Den < 0 ? -Den : Den) / NumDenGCD)
      >
    >
  {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


/**
 * @ingroup dt_num_ratio_c
 * @brief Simplified rational type
 *
 * Initializes a @ref ratio_c with the parameters for the numerator and
 * denominator simplified.
 *
 * @tparam IntType
 *   An integral type.
 * @tparam Num
 *   The non-simplified numerator.
 * @tparam Den
 *   The non-simplified denominator.
 */
template <typename IntType, IntType Num, IntType Den>
struct simplified_ratio_c
  ERYTHRONELUMBO_MAIHUENIA_IF_NOT_DOXYGEN( \
    : detail::simplified_ratio_c_impl<IntType, Num, Den> \
  )
{
  #ifdef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

  /**
   * @brief Result
   *
   * A @ref ratio_c with the simplified `Num` and `Den` parameters.
   */
  using type = unspecified;

  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
};


/**
 * @relates erythronelumbo::maihuenia::simplified_ratio_c
 *
 * @invokesmfn{simplified_ratio_c}
 *
 * @tparam IntType
 *   An integral type.
 * @tparam Num
 *   The non-simplified numerator.
 * @tparam Den
 *   The non-simplified denominator.
 */
template <typename IntType, IntType Num, IntType Den>
using simplified_ratio_c_t = typename simplified_ratio_c<
  IntType, Num, Den
>::type;


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <typename IntType1, typename IntType2>
struct typeclass<Comparable>::define_for<
  ratio_c_tag<IntType1>, ratio_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct equals_impl : bool_<X1::num*X2::den == X2::num*X1::den> {};

  template <typename X1, typename X2>
  struct not_equals_impl : bool_<X1::num*X2::den != X2::num*X1::den> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Orderable>::define_for<
  ratio_c_tag<IntType1>, ratio_c_tag<IntType2>
> :
  true_
{
  template <typename X1, typename X2>
  struct less_impl : bool_<(X1::num*X2::den < X2::num*X1::den)> {};

  template <typename X1, typename X2>
  struct less_equal_impl : bool_<(X1::num*X2::den <= X2::num*X1::den)> {};

  template <typename X1, typename X2>
  struct greater_impl : bool_<(X1::num*X2::den > X2::num*X1::den)> {};

  template <typename X1, typename X2>
  struct greater_equal_impl : bool_<(X1::num*X2::den >= X2::num*X1::den)> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Numeric>::define_for<
  ratio_c_tag<IntType1>, ratio_c_tag<IntType2>
> :
  true_
{
  template <typename X0, typename X1>
  struct add_impl :
    simplified_ratio_c<
      decltype(X0::num*X1::den + X1::num*X0::den),
      X0::num*X1::den + X1::num*X0::den,
      X0::den*X1::den
    >
  {};

  template <typename X0, typename X1>
  struct sub_impl :
    simplified_ratio_c<
      decltype(X0::num*X1::den - X1::num*X0::den),
      X0::num*X1::den - X1::num*X0::den,
      X0::den*X1::den
    >
  {};

  template <typename X0, typename X1>
  struct mul_impl :
    simplified_ratio_c<
      decltype(X0::num*X1::num),
      X0::num*X1::num,
      X0::den*X1::den
    >
  {};

  template <typename X0>
  struct negate_impl :
    simplified_ratio_c<IntType1, -X0::num, X0::den>
  {};

  template <typename X0>
  struct abs_impl :
    simplified_ratio_c<
      IntType1,
      (X0::num < 0) ? -X0::num : X0::num,
      (X0::den < 0) ? -X0::den : X0::den
    >
  {};

  template <typename X0>
  struct sign_impl :
    ratio_c<
      IntType1,
      (X0::num == 0) ? 0 : ((X0::num < 0) ? -1 : 1),
      1
    >
  {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Rational>::define_for<
  ratio_c_tag<IntType1>, ratio_c_tag<IntType2>
> :
  true_
{
  template <typename X0, typename X1>
  struct quot_impl :
    simplified_ratio_c<
      decltype(X0::num*X1::den),
      X0::num*X1::den, X1::num*X0::den
    >
  {};

  template <typename X0>
  struct recip_impl :
    simplified_ratio_c<IntType1, X0::den, X0::num>
  {};
};


template <typename IntType>
struct typeclass<WithStringRepr>::define_for<ratio_c_tag<IntType>> : true_
{
  template <typename X0>
  struct to_string_impl : detail::ratio_c_to_str<X0> {};
};


template <typename IntType1, typename IntType2>
struct typeclass<Monoid>::define_for<
  ratio_c_tag<IntType1>, ratio_c_tag<IntType2>
> :
  true_
{
  struct mident_impl : ratio_c<IntType1, 1, 0> {};

  template <typename X0, typename X1>
  struct mappend_impl :
    simplified_ratio_c<
      decltype(X0::num*X1::den + X1::num*X0::den),
      X0::num*X1::den + X1::num*X0::den,
      X0::den*X1::den
    >
  {};
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_RATIO_C_HPP
