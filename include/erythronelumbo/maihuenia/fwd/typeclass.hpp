// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file
 *
 * @brief Facilities for typeclasses
 *
 * Contains facilities for declaring and defining typeclasses.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_FWD_TYPECLASS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_FWD_TYPECLASS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/fwd/integer_c.hpp>


namespace erythronelumbo { namespace maihuenia
{

#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

namespace detail
{
  struct non_typeclass_base {};
  struct typeclass_has_no_parents {};
  template <typename> struct parent_typeclass_tag_box {};

  template <typename>
  struct typeclass_parents : non_typeclass_base {};


  template <typename ParentTpcl>
  struct parent_typeclass_checker
  {
    inline static constexpr true_
    call(parent_typeclass_tag_box<ParentTpcl>*);

    inline static constexpr false_ call(typeclass_has_no_parents*);
  };

  template <typename TCTag, typename ParentTCTag>
  struct is_typeclass_child_of :
    decltype(
      parent_typeclass_checker<ParentTCTag>::call((typeclass_parents<TCTag>*)0)
    )
  {};

  template <typename TCTag>
  struct is_typeclass_child_of<TCTag, typeclass_has_no_parents> : true_ {};

  template <typename TCTag, typename...> struct parent_typeclass_test {};
} // namespace detail

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup tpc_definition
 * @brief Derived operations of typeclasses
 *
 * Contains the *default* definitions of the *derived* operations of
 * typeclasses, i.e., those that are defined in terms of the *basic* operations.
 * The operations are contained in a member struct named `define_for`.
 *
 * @tparam TypeclassTag
 *   A tag type that corresponds to the typeclass.
 */
template <typename TypeclassTag>
struct derived_typeclass_ops ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

/**
 * @ingroup tpc_definition
 * @brief Typeclass definition
 *
 * Contains the definitions of the *basic* operations of a typeclass and the
 * specializations for any given type that must instance it. Those operations
 * are contained in a member struct named `define_for`.
 *
 * The declaration is done as in the following example:
 *
 * ```
 * namespace erythronelumbo { namespace maihuenia
 * {
 * 
 * template <>
 * struct typeclass<::my_namespace::MyTypeclass>
 * {
 *   // Definition of the "basic" operations
 *   template <typename Tag1, typename Tag2, ..., typename TagN>
 *   struct define_for : false_
 *   {
 *     template <typename, typename...>
 *     struct op1_impl;
 * 
 *     template <typename>
 *     struct op2_impl;
 * 
 *     template <typename, typename>
 *     struct op3_impl;
 *   };
 * };
 * 
 * }} // namespace erythronelumbo::maihuenia
 * ```
 * 
 * Also, the *free* metafunctions are defined as follows:
 * ```
 * namespace my_namespace
 * {
 *   template <typename X, typename... Args>
 *   struct op1 :
 *     ::erythronelumbo::maihuenia::typeclass<
 *       MyTypeclass
 *     >::template define_for<
 *       typename tag<X>::type
 *     >::template op1_impl<X, Xs...>
 *   {};
 * 
 *   template <typename T>
 *   struct op2 :
 *     ::erythronelumbo::maihuenia::typeclass<
 *       MyTypeclass
 *     >::template define_for<
 *       typename tag<T>::type
 *     >::template op1_impl<T>
 *   {};
 * 
 *   template <typename A, typename B>
 *   struct op3 :
 *     ::erythronelumbo::maihuenia::typeclass<
 *       MyTypeclass
 *     >::template define_for<
 *       typename tag<A>::type, typename tag<B>::type
 *     >::template op3_impl<A, B>
 *   {};
 * } // namespace my_namespace
 * ```
 * 
 * If the typeclass has operations that are defined in terms of the *basic*
 * operations, which are known in this library as *derived operations*, the
 * definition of them is done in @ref derived_typeclass_ops and the typeclass
 * should be declared as follows:
 *
 * ```
 * template <>
 * struct typeclass<MyTypeclass>
 * {
 *   // Definition of the "basic" operations
 *   template <typename Tag1, typename Tag2, ..., typename TagN>
 *   struct define_for :
 *     derived_typeclass_ops<MyTypeclass>::template define_for<
 *       Tag1, Tag2, ..., TagN
 *     >
 *   {
 *     // ...the basic operations...
 *   };
 * };
 * ```
 *
 * Another way to declare a typeclass, where this utility is used, is given in
 * @ref ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS.
 *
 * @tparam TypeclassTag
 *   A tag type that corresponds to the typeclass.
 */
template <typename TypeclassTag>
struct typeclass ERYTHRONELUMBO_MAIHUENIA_IF_DOXYGEN({});

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_FWD_TYPECLASS_HPP
