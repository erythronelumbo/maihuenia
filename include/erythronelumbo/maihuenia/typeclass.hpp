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

#ifndef ERYTHRONELUMBO_MAIHUENIA_TYPECLASS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_TYPECLASS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/fwd/typeclass.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/detail/preprocessor.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>


#ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  // Note:
  //   Some of these utilities are not defined using the macros from
  //   `detail/preprocessor.hpp` because of the limitations of the
  //   preprocessor.

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS(n_) \
  ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_, n_ \
  )()

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_0()

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_1() \
  typename T0

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_2() \
  typename T0, typename T1 = T0

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_3() \
  typename T0, typename T1 = T0, typename T2 = T1

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_4() \
  typename T0, typename T1 = T0, typename T2 = T1, typename T3 = T2

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_5() \
  typename T0     , typename T1 = T0, typename T2 = T1, typename T3 = T2, \
  typename T4 = T3

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_6() \
  typename T0     , typename T1 = T0, typename T2 = T1, typename T3 = T2, \
  typename T4 = T3, typename T5 = T4

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_7() \
  typename T0     , typename T1 = T0, typename T2 = T1, typename T3 = T2, \
  typename T4 = T3, typename T5 = T4, typename T6 = T5

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS_8() \
  typename T0     , typename T1 = T0, typename T2 = T1, typename T3 = T2, \
  typename T4 = T3, typename T5 = T4, typename T6 = T5, typename T7 = T6


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS(n, x) typename X##n

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_A(n, x) typename T##n

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_(n, x) typename

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_1(n, x) X##n

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_1A(n, x) T##n


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_COMMA_IF_FALSE_1
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_COMMA_IF_FALSE_0 ,

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG(ii) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_IMPL(ii) ii

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_IMPL(ii) \
  ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_, \
    ERYTHRONELUMBO_MAIHUENIA_PP_LIST_SIZE(ii) \
  )

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_0()

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_1(i0) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_2(i0, i1) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_3(i0, i1, i2) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_4(i0, i1, i2, i3) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_5(i0, i1, i2, i3, i4) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_6( \
    i0, i1, i2, i3, i4, i5 \
  ) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i5>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_7( \
    i0, i1, i2, i3, i4, i5, i6 \
  ) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i5>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i6>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_8( \
    i0, i1, i2, i3, i4, i5, i6, i7 \
  ) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i5>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i6>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i7>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_9( \
    i0, i1, i2, i3, i4, i5, i6, i7, i8 \
  ) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i5>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i6>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i7>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i8>::type

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG_10( \
    i0, i1, i2, i3, i4, i5, i6, i7, i8, i9 \
  ) \
  typename ::erythronelumbo::maihuenia::tag<X##i0>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i1>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i2>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i3>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i4>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i5>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i6>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i7>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i8>::type, \
  typename ::erythronelumbo::maihuenia::tag<X##i9>::type


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_TAG_TO_BOX(item, x) \
  parent_typeclass_tag_box<item>


  /**
   * Given an element of the form
   * `(fname, fn_mode, n, has_variadic, takes_tp_tag, ops_with_tag)`,
   * generates a `struct` of the following form:
   * 
   * ```
   * template <typename, ..., typename [, typename...]>
   * struct fn_name_impl;
   * ```
   */
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN(item, x) \
  ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN_, \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 1) \
  )(item, x)


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN_0(item, x) \
  /* The metafunction to generate cannot take arguments if it is nullary */ \
  /* (no single arguments and no parameter packs) */ \
  ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AND( \
      ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
      ), \
      ERYTHRONELUMBO_MAIHUENIA_PP_NOT(ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3)) \
    ) \
  )( \
    /* no template arguments */ \
  )( \
    template < \
      /* `typename, typename, ...` */ \
      ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_, \
        ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2), ~ \
      ) \
      ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3) \
      )( \
        ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
          ERYTHRONELUMBO_MAIHUENIA_DETAIL_COMMA_IF_FALSE_, \
          ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
            ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
          ) \
        ) \
        typename... \
      )( \
        /* do nothing */ \
      ) \
    > \
  ) \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
  );

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN_1(item, x) \
  template <typename, typename> \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
  );

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN_2(item, x) \
  template <typename, typename> \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
  );

  /**
   * ```
   * template <typename TpTag, typename X0, ... typename Xn, typename... Xs>
   * struct name :
   *   typeclass<TypeclassTag>::template define_for<
   *     [TpTag,]
   *     typename tag<X0>::type,
   *     ...
   *     typename tag<Xn>::type
   *   >::template apply<X0, ..., Xn, Xs...>
   * {};
   * ```
   */
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN_0( \
    item, tct \
  ) \
  template < \
    ERYTHRONELUMBO_MAIHUENIA_PP_IF(ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 4))( \
      typename TpTag \
      /* Adds a comma if this takes a tag AND non-tag operands. */ \
      /* This hack is here because of the limitations of the */ \
      /* preprocessor. */ \
      ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_COMMA_IF_FALSE_, \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
        ) \
      ) \
    )( \
      ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY() \
    ) \
    /* typename X0, typename X1, ... */ \
    ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS, \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2), ~ \
    ) \
    ERYTHRONELUMBO_MAIHUENIA_PP_IF(ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3))( \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA() \
      typename... Xs \
    )() \
  > \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0) \
  { \
    using type = typename ::erythronelumbo::maihuenia::typeclass< \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 0) \
    >::template define_for< \
      ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 4) \
      )( \
        TpTag \
        /* TODO: add comma if PP_AT(item, 5) is not empty*/ \
      )() \
      /* typename tag<i0>::type, typename tag<i1>::type, ... */ \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 5) \
      ) \
    >::ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
      ERYTHRONELUMBO_MAIHUENIA_PP_AND( \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
        ), \
        ERYTHRONELUMBO_MAIHUENIA_PP_NOT( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3) \
        ) \
      ) \
    )( \
      /* The `template` keyword only applies for non-nullary metafunctions */ \
    )( \
      template \
    ) \
    /* Result: `...::name_impl` or `...::template name_impl<...>` */ \
    ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
    ) \
    /* Nullary metafunctions cannot take arguments */ \
    ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
      ERYTHRONELUMBO_MAIHUENIA_PP_AND( \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
        ), \
        ERYTHRONELUMBO_MAIHUENIA_PP_NOT( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3) \
        ) \
      ) \
    )()( \
      < \
        /* Non-tag operands (`X0, X1, X2, X3, ...`) */ \
        ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
          ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_1, \
          ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2), ~ \
        ) \
        ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3) \
        )( \
          ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
            ERYTHRONELUMBO_MAIHUENIA_DETAIL_COMMA_IF_FALSE_, \
            ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
              ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
            ) \
          ) \
          Xs... \
        )( \
          ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY() \
        ) \
      > \
    )::type; \
  };


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN_1( \
    item, tct \
  ) \
  template <typename X0, typename X1, typename... Xs> \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0) \
  { \
    using type = typename ::erythronelumbo::maihuenia::bin_op_many_c< \
      ::erythronelumbo::maihuenia::typeclass< \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 0) \
      >::template define_for< \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
        ) \
      >::template ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
      ), \
      false, \
      X0, X1, Xs... \
    >::type; \
  };

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN_2( \
    item, tct \
  ) \
  template <typename X0, typename X1, typename... Xs> \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0) \
  { \
    using type = typename ::erythronelumbo::maihuenia::bin_op_many_c< \
      ::erythronelumbo::maihuenia::typeclass< \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 0) \
      >::template define_for< \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ATG( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
        ) \
      >::template ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
      ), \
      true, \
      X0, X1, Xs... \
    >::type; \
  };


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN( \
    item, tct \
  ) \
  ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN_, \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 1) \
  )(item, tct)


  /**
   * If there are derived intrinsic metafunctions declared, generates a
   * definition for `derived_typeclass_ops`.
   */
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECLARE_DERIVED_TC_OPS( \
    typeclass_tag, num_tp_tags, derived_mfns \
  ) \
  namespace erythronelumbo { namespace maihuenia \
  { \
    template <> \
    struct derived_typeclass_ops<typeclass_tag> \
    { \
      template < \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS(num_tp_tags) \
      > \
      struct define_for : true_ \
      { \
        ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
          ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN, \
          derived_mfns, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
        ) \
      }; \
    }; \
  }}


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_UNPACK_TYPE_TAGS_IMPL(...) \
  __VA_ARGS__

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_UNPACK_TYPE_TAGS(item, x) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_UNPACK_TYPE_TAGS_IMPL item


  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL_00()
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL_01() ,
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL_10()
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL_11()

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A(x, y) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL_, x, y \
  )()

  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A_IMPL(z, x, y) z##x##y

  /**
   * Given an element of the form
   * `(fn_name, mode, num_args, has_variadic_args, (definition))`, generates a
   * `struct` definition of the following form:
   *
   * ```
   * template <typename X0, typename X1, ..., typename Xn>
   * struct fn_name_impl : definition
   * {};
   * ```
   * 
   * `definition` can use the generated template parameters `X0, X1, ... Xn`.
   * 
   * TODO: Possibly use `using fn_name_impl = definition(<...>);`
   */
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_DEFINE_TC_SPEC_MFN(item, x) \
  /* The metafunction to generate cannot take arguments if it is nullary */ \
  /* (no single arguments and no parameter packs) */ \
  ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AND( \
      ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 1) \
      ), \
      ERYTHRONELUMBO_MAIHUENIA_PP_NOT(ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2)) \
    ) \
  )()( \
    template < \
      /* typename X0, typename X1, ... */ \
      ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS, \
        ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 1), ~ \
      ) \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_COMMA_IF_A( \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_ZERO( \
          ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 1) \
        ), \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
      ) \
      ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
        ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2) \
      )(typename... Xs)() \
    > \
  ) \
  struct ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
  ) : \
    ERYTHRONELUMBO_MAIHUENIA_PP_UNPACK_1 ERYTHRONELUMBO_MAIHUENIA_PP_AT( \
      item, 3 \
    ) \
  {};

  /**
   * [...]
   */
  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_NON_OVERRIDEN_DRV_MFNS(tct, tpts) \
  derived_typeclass_ops<tct>::template define_for< \
    ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_UNPACK_TYPE_TAGS, \
      tpts, ~, ERYTHRONELUMBO_MAIHUENIA_PP_COMMA \
    ) \
  >


  #define ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
    nsps, typeclass_tag, num_tp_tags, parent_tcts, basic_mfns, derived_mfns \
  ) \
  ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECLARE_DERIVED_TC_OPS( \
    typeclass_tag, num_tp_tags, derived_mfns \
  ) \
  namespace erythronelumbo { namespace maihuenia \
  { \
    template <> \
    struct typeclass<typeclass_tag> \
    { \
      template < \
        /* typename, typename, ... */ \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_DEFFOR_TAG_ARGS(num_tp_tags) \
      > \
      struct define_for : false_ \
      { \
        /* template <...> struct ???_impl; */ \
        ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
          ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_INTRINSIC_MFN, \
          basic_mfns, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
        ) \
      }; \
    }; \
    namespace detail \
    { \
      template <> \
      struct typeclass_parents<typeclass_tag> : \
        ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
          ERYTHRONELUMBO_MAIHUENIA_PP_IS_LIST_EMPTY(parent_tcts) \
        )( \
          typeclass_has_no_parents \
        )( \
          ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
            ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_TAG_TO_BOX, \
            parent_tcts, ~, ERYTHRONELUMBO_MAIHUENIA_PP_COMMA_ \
          ) \
        ) \
      {}; \
    } \
  }} \
  ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_OP, \
    nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
  ) \
    ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN, \
      derived_mfns, (typeclass_tag), \
      ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
    ) \
  ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_CL, \
    nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
  ) \
  ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_OP, \
    nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
  ) \
    ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_DECL_FREE_INTRINSIC_MFN, \
      basic_mfns, (typeclass_tag), \
      ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
    ) \
  ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
    ERYTHRONELUMBO_MAIHUENIA_DETAIL_NSP_CL, \
    nsps, ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
  )




  #define ERYTHRONELUMBO_MAIHUENIA_DETAIL_EXT_DRV_TC_OPS_DEF(item, tct) \
  template <> \
  template < \
    ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_A, \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 1), ~ \
    ) \
  > \
  template < \
    ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS, \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 2), ~ \
    ) \
    ERYTHRONELUMBO_MAIHUENIA_PP_IF(ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 3))( \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA() typename... \
    )( \
      ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY() \
    ) \
  > \
  struct derived_typeclass_ops< \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 0) \
  >::define_for< \
    /* `T0, T1, T2, T3, ...` */ \
    ERYTHRONELUMBO_MAIHUENIA_PP_FOR( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_TC_SMFN_ARGS_1A, \
      ERYTHRONELUMBO_MAIHUENIA_PP_COMMA, \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(tct, 1), ~ \
    ) \
  >::ERYTHRONELUMBO_MAIHUENIA_PP_CONCAT( \
      ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 0), _impl \
  ) : \
    ERYTHRONELUMBO_MAIHUENIA_PP_UNPACK_1 \
    ERYTHRONELUMBO_MAIHUENIA_PP_AT(item, 6) \
  {};


  #define ERYTHRONELUMBO_MAIHUENIA_DEFINE_DERIVED_TYPECLASS_OPS( \
    nsps, typeclass_tag, num_tp_tags, derived_mfns \
  ) \
  namespace erythronelumbo { namespace maihuenia \
  { \
    ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
      ERYTHRONELUMBO_MAIHUENIA_DETAIL_EXT_DRV_TC_OPS_DEF, \
      derived_mfns, (typeclass_tag, num_tp_tags), \
      ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
    ) \
  }}


  #define ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
    typeclass_tag, type_tags, basic_mfns, derived_mfns \
  ) \
  namespace erythronelumbo { namespace maihuenia \
  { \
    template <> \
    struct typeclass<typeclass_tag>::define_for< \
      ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_UNPACK_TYPE_TAGS, \
        type_tags, ~, ERYTHRONELUMBO_MAIHUENIA_PP_COMMA \
      ) \
    > : \
      ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_LIST_EMPTY(derived_mfns) \
      )( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_NON_OVERRIDEN_DRV_MFNS( \
          typeclass_tag, type_tags \
        ) \
      )( \
        true_ \
      ) \
    { \
      ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
        ERYTHRONELUMBO_MAIHUENIA_DETAIL_DEFINE_TC_SPEC_MFN, basic_mfns, ~, \
        ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
      ) \
      ERYTHRONELUMBO_MAIHUENIA_PP_IF( \
        ERYTHRONELUMBO_MAIHUENIA_PP_IS_LIST_EMPTY(derived_mfns) \
      )( \
      )( \
        ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM( \
          ERYTHRONELUMBO_MAIHUENIA_DETAIL_DEFINE_TC_SPEC_MFN, derived_mfns, \
          ~, ERYTHRONELUMBO_MAIHUENIA_PP_EMPTY \
        ) \
      ) \
    }; \
  }}
#else // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED

/**
 * @ingroup tpc_definition
 * @brief Typeclass declaration
 *
 * A macro that eases the declaration of typeclasses. It generates an instance
 * of the `typeclass` type with its intrinsic metafunctions, both as members
 * of said type and *free* ones that will be *injected* into the namespace given
 * in `nsps`.
 *
 * Regarding the names of the intrinsic metafunctions, for example, if a
 * metafunction is named `myfn`, a member named `myfn_impl` will be generated
 * inside the instantiation of `typeclass`, as well as a *free* metafunction
 * named `myfn`.
 *
 * This macro **must** be used in the global namespace, since it involves
 * overloading in the `erythronelumbo::maihuenia` namespace, as well as the one
 * supplied in the `nsps` parameter.
 *
 * @param nsps
 *   The namespaces. This parameter must be set in the form
 *   `(namespace1, namespace2, ..., namespacen)`.
 * @param typeclass_tag
 *   The tag that corresponds to the typeclass.
 * @param num_tp_tags
 *   The maximum number of operands (type tags) that the intrinsic metafunctions
 *   can take.
 * @param parent_tcts
 *   The tags that represent the *parent* typeclasses. This parameter must be
 *   set in the form `(tag_1, tag_2, ...)` or, if no parent typeclasses, as
 *   `()`.
 * @param basic_mfns
 *   The *basic* intrinsic metafunctions. This parameter must be set in the form
 *   `(decl1, decl2, ...)`, where each element can take one of the following
 *   forms:
 *    - `(fn, 0, nargs, has_variadic, takes_tpt, owt)`, where `fn` is the
 *      metafunction's name, `nargs` is the number of arguments that it takes,
 *      `has_variadic` indicates if it has variadic arguments (`0` or `1`),
 *      `takes_tpt` of the first argument is the *tag type* for the data type
 *      specialized and `owt` indicates which arguments correspond to the data
 *      type that is specialized.
 *      - `owt` is a *tuple* of the following form: `(p0, p1, ...)`, where the
 *        elements are integers, starting from `0`.
 *    - `(fn, 1, owt)`, for binary operator-like metafunctions with
 *      *left-associativity*.
 *    - `(fn, 2, owt)`, for binary operator-like metafunctions with
 *      *right-associativity*.
 * @param derived_mfns
 *   The *derived* intrinsic metafunctions, which are those that are defined in
 *   terms of the *basic* ones. This parameter must be set as in `basic_mfns`.
 *   If no derived metafunctions are needed, set this parameter as `()`.
 */
#define ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  nsps, typeclass_tag, num_tp_tags, parent_tcts, basic_mfns, derived_mfns \
) /* unspecified */


/**
 * @ingroup tpc_definition
 * @brief Definition of derived operations of a typeclass
 *
 * Assists the definition of the *derived operations* of a typeclass.
 *
 * This macro **must** be used in the global namespace, since it involves
 * overloading in the `erythronelumbo::maihuenia` namespace, as well as the one
 * supplied in the `nsps` parameter.
 *
 * @param nsps
 *   The namespaces. This parameter must be set in the form
 *   `(namespace1, namespace2, ..., namespacen)`.
 * @param typeclass_tag
 *   The tag that corresponds to the typeclass.
 * @param num_tp_tags
 *   The maximum number of operands (type tags) that the intrinsic metafunctions
 *   can take.
 * @param derived_mfns
 *   The *derived* intrinsic metafunctions, which are those that are defined in
 *   terms of the *basic* ones. This parameter must be set as in `basic_mfns`.
 *   If no derived metafunctions are needed, set this parameter as `()`.
 */
#define ERYTHRONELUMBO_MAIHUENIA_DEFINE_DERIVED_TYPECLASS_OPS( \
  nsps, typeclass_tag, num_tp_tags, derived_mfns \
) /* unspecified */


/**
 * @ingroup tpc_definition
 * @brief Typeclass specialization
 *
 * A macro that assists the specialization of a typeclass for a type, which
 * **must** be represented by a *type tag*.
 *
 * This macro **must** be used in the global namespace, since it involves
 * overloading in the `erythronelumbo::maihuenia` namespace.
 *
 * @param typeclass_tag
 *   The tag of the typeclass.
 * @param type_tags
 *   The tags that represent the types to specialize the given typeclass for.
 *   This parameter must be set in the form `((tt_1), ..., (tt_n))`, where its
 *   elements, `tt_*`, are the type tags. Note that the type tags must be
 *   enclosed in parenthesis, since they are assumed to have template
 *   parameters.
 * @param basic_mfns
 *   The definitions of the basic intrinsic metafunctions. This parameter must
 *   be set in the form `((fn1, n1, v1, (def1)), (fn2, n2, v2, (def2)), ...)`,
 *   where each element, of the form `(fn, n, v, (fndef))`, is a *tuple* where
 *   `fn` is the intrinsic metafunction, `n` is the number of its arguments,
 *   `v` indicates if there are variadic arguments (`0` or `1`) and `fndef` is
 *   its definition, which can be defindef externally and must take **only**
 *   types as parameters. This last element must be enclosed in parenthesis,
 *   because it is assumed to take template parameters.
 *   When the definitions take template parameters, this utility generates them
 *   and they are named as `X0, X1, X2, ...` and, if they take variadic
 *   parameter packs, they are provided as `Xs...`. These parameters must be
 *   indicated as in the following example:
 *   `(mfn, n, v, (mfn_def<X0, X1, ..., Xn [, Xs...]>))`.
 * @param derived_mfns
 *   The definitions of the derived intrinsic metafunctions. This parameter is
 *   set as `basic_mfns`, when it is needed to override the default definitions
 *   of said derived metafunctions; otherwise, set it as `()`.
 */
#define ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  typeclass_tag, type_tags, basic_mfns, derived_mfns \
) /* unspecified */

#endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED


#endif // ERYTHRONELUMBO_MAIHUENIA_TYPECLASS_HPP
