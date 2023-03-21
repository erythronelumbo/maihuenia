// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/typeclass.hpp>


namespace mhn = erythronelumbo::maihuenia;

// The tag of the custom typeclass
struct MyNumeric;

// The declaration of the typeclass
ERYTHRONELUMBO_MAIHUENIA_DECLARE_TYPECLASS( \
  (), /* in the global namespace */ \
  ::MyNumeric, \
  2, \
  (), /* does not "inherit" from other typeclasses */ \
  ( \
    /* All of these operations are left-associative, taking two arguments */ \
    /* or more. */ \
    (plus, 1, (0, 1)), \
    (minus, 1, (0, 1)), \
    (times, 1, (0, 1)), \
    (divides, 1, (0, 1)) \
  ), \
  () \
)

// The tag of the custom type
struct my_number_tag;

// The custom type
template <int X>
struct my_number
{
  using type       = my_number;
  using tag        = my_number_tag;
  using value_type = int;

  static constexpr int value = X;
};

template <int X>
constexpr int my_number<X>::value;


// Specializing the typeclass for `my_number`
ERYTHRONELUMBO_MAIHUENIA_SPECIALIZE_TYPECLASS( \
  ::MyNumeric, \
  ((::my_number_tag), (::my_number_tag)), \
  ( \
    (plus, 2, 0, (::my_number<X0::value + X1::value>)), \
    (minus, 2, 0, (::my_number<X0::value - X1::value>)), \
    (times, 2, 0, (::my_number<X0::value * X1::value>)), \
    (divides, 2, 0, (::my_number<X0::value / X1::value>)) \
  ), \
  () \
)


static_assert(
  mhn::equal_types_t<
    typename plus<my_number<1>, my_number<2>, my_number<3>>::type,
    my_number<6>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename minus<my_number<1>, my_number<2>, my_number<3>>::type,
    my_number<-4>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename times<my_number<2>, my_number<3>, my_number<5>>::type,
    my_number<30>
  >::value,
  "!!!"
);

static_assert(
  mhn::equal_types_t<
    typename divides<my_number<35>, my_number<5>>::type,
    my_number<7>
  >::value,
  "!!!"
);


int main()
{
  return EXIT_SUCCESS;
}
