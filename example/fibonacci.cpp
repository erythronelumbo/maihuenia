// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <cstdlib>
#include <cstdio>

#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/until.hpp>
#include <erythronelumbo/maihuenia/for_each.hpp>
#include <erythronelumbo/maihuenia/transformed_view.hpp>


namespace mhn = erythronelumbo::maihuenia;

using namespace mhn::placeholders;

/*
fib(n) = fib(n-1) + fib(n-2)
fib(1) = 1
fib(0) = 0

(n,  a,  b) -> (n+1, a+b, a)
(0,  0,  1)
(1,  1,  0)
(2,  1,  1)
(3,  2,  1)
(4,  3,  2)
(5,  5,  3)
(6,  8,  5)
(7, 13,  8)
(8, 21, 13)
(9, 34, 21)
     ^
     |
     +--- The result
*/

// Naïve, recursive implementation
template <typename N, bool = (N::value <= 1)>
struct fibonacci_naive :
  mhn::add<
    typename fibonacci_naive<mhn::sub_t<N, mhn::int_<1>>>::type,
    typename fibonacci_naive<mhn::sub_t<N, mhn::int_<2>>>::type
  >
{};

template <typename N>
struct fibonacci_naive<N, true> :
  N
{};


// Using the `until` metafunction
template <typename N>
struct fibonacci_until :
  mhn::at_c<
    /* The result is in the second element of the "state" */
    mhn::until_t<
      /* Run until N == 0 */
      mhn::lambda<
        mhn::equals<mhn::front<_1>, mhn::int_<0>>
      >,
      /* State transition: */
      /* (N, a, b) -> (N - 1, a + b, a) */
      mhn::lambda<
        mhn::vector<
          mhn::sub<mhn::front<_1>, mhn::int_<1>>,
          mhn::add<mhn::at<_1, mhn::int_<1>>, mhn::at<_1, mhn::int_<2>>>,
          mhn::at<_1, mhn::int_<1>>
        >
      >,
      /* Start with (N, 0, 1) */
      mhn::vector<N, mhn::int_<0>, mhn::int_<1>>
    >,
    1
  >
{};


// Same as `fibonacci_until`, but defined as a lambda expression
using fibonacci_lambda = mhn::lambda<
  mhn::at<
    mhn::until<
      /* This stop condition `lambda` should be left unevaluated until the */
      /* `apply` member is invoked, therefore, `protect` is used here. */
      mhn::protect<
        mhn::lambda<
          mhn::equals<mhn::front<_1>, mhn::int_<0>>
        >
      >,
      /* Same with the previous `lambda`. */
      mhn::protect<
        mhn::lambda<
          mhn::vector<
            mhn::sub<mhn::front<_1>, mhn::int_<1>>,
            mhn::add<mhn::at<_1, mhn::int_<1>>, mhn::at<_1, mhn::int_<2>>>,
            mhn::at<_1, mhn::int_<1>>
          >
        >
      >,
      /* `N` must be passed only here. */
      mhn::vector<_1, mhn::int_<0>, mhn::int_<1>>
    >,
    mhn::int_<1>
  >
>;


struct calc_fibonacci
{
  template <typename N>
  using apply = mhn::vector<
    N,
    typename fibonacci_naive<N>::type,
    typename fibonacci_until<N>::type,
    mhn::apply_wrap_t<fibonacci_lambda, N>
  >;
};


struct print_row
{
  template <typename T>
  inline void operator()(T)
  {
    std::printf(
      "| %2u | %8u | %8u | %8u |\n",
      mhn::at_c_t<T, 0>::value,
      mhn::at_c_t<T, 1>::value,
      mhn::at_c_t<T, 2>::value,
      mhn::at_c_t<T, 3>::value
    );
  }
};


int main()
{
  std::puts(
    "Fibonacci numbers:\n"
    "+----+----------+----------+----------+\n"
    "|    |          |   With   |   With   |\n"
    "| N  |  Naive   |  `until` | `lambda` |\n"
    "+----+----------+----------+----------+"
  );

  mhn::for_each<
    mhn::transformed_view<mhn::range_c<unsigned, 0, 31>, calc_fibonacci>
  >(print_row{});

  std::puts("+----+----------+----------+----------+");

  return EXIT_SUCCESS;
}
