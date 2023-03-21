// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file bin_op_many.hpp
 *
 * @brief `bin_op_many` metafunction
 *
 * Defines the `bin_op_many` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_HPP
#define ERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/detail/bin_op_many_impl.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

template <
  template <typename...> class BinOp,
  typename IsRightAssoc,
  typename X, typename... Xs
>
struct bin_op_many :
  detail::bin_op_many_impl<BinOp, IsRightAssoc::value, X, Xs...>
{};

template <
  template <typename...> class BinOp,
  typename IsRightAssoc,
  typename X
>
struct bin_op_many<BinOp, IsRightAssoc, X>
{
  using type = X;
};


template <
  template <typename...> class BinOp,
  bool IsRightAssoc,
  typename X, typename... Xs
>
struct bin_op_many_c :
  detail::bin_op_many_impl<BinOp, IsRightAssoc, X, Xs...>
{};

template <
  template <typename...> class BinOp,
  bool IsRightAssoc,
  typename X
>
struct bin_op_many_c<BinOp, IsRightAssoc, X>
{
  using type = X;
};

#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup mfn_miscellaneous
 * @brief Applies a binary metafunction to one or more arguments
 *
 * Appplies a binary metafunction to one or more types, in a *left-associative*
 * or a *right-associative* manner. If there is only one argument supplied, it
 * will return the argument as-is.
 *
 * @note
 *   This metafunction depends on an automatically generated header, since its
 *   use can imply high depths of recursion.
 *
 * @see @ref tc_foldable, which comprehends similar operations.
 * @see @ref bin_op_many_c
 *
 * @tparam BinOp
 *   A binary metafunction.
 * @tparam IsRightAssoc
 *   A Boolean-like integral constant that indicates if the operation from
 *   `BinOp` is right-associative or not.
 * @tparam X, Xs...
 *   The arguments.
 */
template <
  template <typename...> class BinOp,
  typename IsRightAssoc,
  typename X, typename... Xs
>
struct bin_op_many
{
  /**
   * @brief Result
   *
   * The result of applying `BinOp` to the supplied arguments.
   */
  using type = unspecified;
};

/**
 * @ingroup mfn_miscellaneous
 * @brief Applies a binary metafunction to one or more arguments
 *
 * Appplies a binary metafunction to one or more types, in a *left-associative*
 * or a *right-associative* manner. If there is only one argument supplied, it
 * will return the argument as-is.
 *
 * @note
 *   This metafunction depends on an automatically generated header, since its
 *   use can imply high depths of recursion.
 *
 * @see @ref tc_foldable, which comprehends similar operations.
 * @see @ref bin_op_many
 *
 * @tparam BinOp
 *   A binary metafunction.
 * @tparam IsRightAssoc
 *   Indicates if the operation from `BinOp` is right-associative or not.
 * @tparam X, Xs...
 *   The arguments.
 */
template <
  template <typename...> class BinOp,
  bool IsRightAssoc,
  typename X, typename... Xs
>
struct bin_op_many_c
{
  /**
   * @brief Result
   *
   * The result of applying `BinOp` to the supplied arguments.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_HPP
