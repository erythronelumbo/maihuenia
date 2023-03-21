// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file placeholders.hpp
 *
 * @brief Placeholders
 *
 * Defines placeholders.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_PLACEHOLDERS_HPP
#define ERYTHRONELUMBO_MAIHUENIA_PLACEHOLDERS_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>
#include <erythronelumbo/maihuenia/arg.hpp>


namespace erythronelumbo { namespace maihuenia
{

/**
 * @ingroup functional
 * @brief Placeholders
 *
 * Shorthands for @ref arg, where each placeholder of the form `_N` is an alias
 * of `arg<N-1>`.
 *
 * These placeholders are defined as follows:
 * ```
 * namespace placeholders
 * {
 *   using _1 = arg<0>;
 *   using _2 = arg<1>;
 *   using _3 = arg<2>;
 *   ...
 *   using _100 = arg<99>;
 * } // namespace placeholders
 * ```
 *
 * These are used in @ref lambda and @ref bind to mark the *unbound arguments*.
 *
 * ## Example
 *
 * @include example/individual/functional/placeholders.cpp
 */
namespace placeholders
{
  #ifndef ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
  using _1   = arg< 0>;
  using _2   = arg< 1>;
  using _3   = arg< 2>;
  using _4   = arg< 3>;
  using _5   = arg< 4>;
  using _6   = arg< 5>;
  using _7   = arg< 6>;
  using _8   = arg< 7>;
  using _9   = arg< 8>;
  using _10  = arg< 9>;
  using _11  = arg<10>;
  using _12  = arg<11>;
  using _13  = arg<12>;
  using _14  = arg<13>;
  using _15  = arg<14>;
  using _16  = arg<15>;
  using _17  = arg<16>;
  using _18  = arg<17>;
  using _19  = arg<18>;
  using _20  = arg<19>;
  using _21  = arg<20>;
  using _22  = arg<21>;
  using _23  = arg<22>;
  using _24  = arg<23>;
  using _25  = arg<24>;
  using _26  = arg<25>;
  using _27  = arg<26>;
  using _28  = arg<27>;
  using _29  = arg<28>;
  using _30  = arg<29>;
  using _31  = arg<30>;
  using _32  = arg<31>;
  using _33  = arg<32>;
  using _34  = arg<33>;
  using _35  = arg<34>;
  using _36  = arg<35>;
  using _37  = arg<36>;
  using _38  = arg<37>;
  using _39  = arg<38>;
  using _40  = arg<39>;
  using _41  = arg<40>;
  using _42  = arg<41>;
  using _43  = arg<42>;
  using _44  = arg<43>;
  using _45  = arg<44>;
  using _46  = arg<45>;
  using _47  = arg<46>;
  using _48  = arg<47>;
  using _49  = arg<48>;
  using _50  = arg<49>;
  using _51  = arg<50>;
  using _52  = arg<51>;
  using _53  = arg<52>;
  using _54  = arg<53>;
  using _55  = arg<54>;
  using _56  = arg<55>;
  using _57  = arg<56>;
  using _58  = arg<57>;
  using _59  = arg<58>;
  using _60  = arg<59>;
  using _61  = arg<60>;
  using _62  = arg<61>;
  using _63  = arg<62>;
  using _64  = arg<63>;
  using _65  = arg<64>;
  using _66  = arg<65>;
  using _67  = arg<66>;
  using _68  = arg<67>;
  using _69  = arg<68>;
  using _70  = arg<69>;
  using _71  = arg<70>;
  using _72  = arg<71>;
  using _73  = arg<72>;
  using _74  = arg<73>;
  using _75  = arg<74>;
  using _76  = arg<75>;
  using _77  = arg<76>;
  using _78  = arg<77>;
  using _79  = arg<78>;
  using _80  = arg<79>;
  using _81  = arg<80>;
  using _82  = arg<81>;
  using _83  = arg<82>;
  using _84  = arg<83>;
  using _85  = arg<84>;
  using _86  = arg<85>;
  using _87  = arg<86>;
  using _88  = arg<87>;
  using _89  = arg<88>;
  using _90  = arg<89>;
  using _91  = arg<90>;
  using _92  = arg<91>;
  using _93  = arg<92>;
  using _94  = arg<93>;
  using _95  = arg<94>;
  using _96  = arg<95>;
  using _97  = arg<96>;
  using _98  = arg<97>;
  using _99  = arg<98>;
  using _100 = arg<99>;
  #endif // ERYTHRONELUMBO_MAIHUENIA_DOXYGEN_INVOKED
} // namespace placeholders

}} // namespace erythronelumbo::maihuenia


#endif // ERYTHRONELUMBO_MAIHUENIA_PLACEHOLDERS_HPP
