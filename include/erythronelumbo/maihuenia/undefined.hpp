// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file undefined.hpp
 *
 * @brief `undefined` type
 *
 * Defines the `undefined` utility type and the `unless_undefined` metafunction.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_UNDEFINED_HPP
#define ERYTHRONELUMBO_MAIHUENIA_UNDEFINED_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup mfn_core
 * @brief Undefined result
 *
 * Indicates that an operation has an undefined or invalid result (for example,
 * locating an element in an empty sequence).
 *
 * @see @ref dt_misc_optional
 */
struct undefined
{
  /**
   * @mfncalltoitself
   */
  using type = undefined;
};


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  template <typename Res, typename IfUndefined>
  struct unless_undefined
  {
    using type = Res;
  };

  template <typename IfUndefined>
  struct unless_undefined<undefined, IfUndefined>
  {
    using type = IfUndefined;
  };
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup mfn_core
 * @brief Returns a non-undefined output for undefined results.
 *
 * If the result of an operation is `undefined`, it will output a
 * non-`undefined` result; otherwise, the output will be the aforementioned
 * result as is.
 *
 * @tparam Res
 *   The result of an operation, which may be `undefined`.
 * @tparam IfUndefined
 *   The output when `Res` is `undefined`.
 */
template <typename Res, typename IfUndefined>
struct unless_undefined
{
  /**
   * @brief Result
   *
   * `IfUndefined` if `Res` is `undefined`, `Res` otherwise.
   */
  using type = unspecified;
};

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @relates erythronelumbo::maihuenia::unless_undefined
 *
 * @invokesmfn{unless_undefined}
 *
 * @tparam Res
 *   The result of an operation, which may be `undefined`.
 * @tparam IfUndefined
 *   The output when `Res` is `undefined`.
 */
template <typename Res, typename IfUndefined>
using unless_undefined_t = typename unless_undefined<Res, IfUndefined>::type;

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_UNDEFINED_HPP
