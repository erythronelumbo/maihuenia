// Copyright (c) 2023 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @file maihuenia_all.hpp
 *
 * @brief All headers
 *
 * Includes all the headers of this library.
 */

#ifndef ERYTHRONELUMBO_MAIHUENIA_MAIHUENIA_ALL_HPP
#define ERYTHRONELUMBO_MAIHUENIA_MAIHUENIA_ALL_HPP


#include <erythronelumbo/maihuenia/version.hpp>
#include <erythronelumbo/maihuenia/config.hpp>

// Core
#include <erythronelumbo/maihuenia/equal_types.hpp>
#include <erythronelumbo/maihuenia/tag.hpp>
#include <erythronelumbo/maihuenia/have_same_tag.hpp>
#include <erythronelumbo/maihuenia/undefined.hpp>

// Error handling
#include <erythronelumbo/maihuenia/define_error.hpp>
#include <erythronelumbo/maihuenia/error.hpp>

// Control structures
#include <erythronelumbo/maihuenia/if.hpp>
#include <erythronelumbo/maihuenia/eval_if.hpp>
#include <erythronelumbo/maihuenia/while.hpp>
#include <erythronelumbo/maihuenia/until.hpp>

// Miscellaneous metafunctions
#include <erythronelumbo/maihuenia/always.hpp>
#include <erythronelumbo/maihuenia/bin_op_many.hpp>
#include <erythronelumbo/maihuenia/apply_wrap.hpp>
#include <erythronelumbo/maihuenia/identity.hpp>
#include <erythronelumbo/maihuenia/inherit.hpp>
#include <erythronelumbo/maihuenia/c_str.hpp>
#include <erythronelumbo/maihuenia/size_of.hpp>
#include <erythronelumbo/maihuenia/string_to_int.hpp>

// Higher-order metafunction operations
#include <erythronelumbo/maihuenia/arg.hpp>
#include <erythronelumbo/maihuenia/quote.hpp>
#include <erythronelumbo/maihuenia/curry.hpp>
#include <erythronelumbo/maihuenia/compose.hpp>
#include <erythronelumbo/maihuenia/protect.hpp>
#include <erythronelumbo/maihuenia/placeholders.hpp>
#include <erythronelumbo/maihuenia/bind.hpp>
#include <erythronelumbo/maihuenia/lambda.hpp>
#include <erythronelumbo/maihuenia/unpack_args.hpp>

// Typeclasses - declaration and definition
#include <erythronelumbo/maihuenia/typeclass.hpp>

// Typeclasses
#include <erythronelumbo/maihuenia/applicative.hpp>
#include <erythronelumbo/maihuenia/bitwise.hpp>
#include <erythronelumbo/maihuenia/comparable.hpp>
#include <erythronelumbo/maihuenia/enumerable.hpp>
#include <erythronelumbo/maihuenia/extensible_mapping.hpp>
#include <erythronelumbo/maihuenia/foldable.hpp>
#include <erythronelumbo/maihuenia/functor.hpp>
#include <erythronelumbo/maihuenia/integral.hpp>
#include <erythronelumbo/maihuenia/iterable.hpp>
#include <erythronelumbo/maihuenia/logical.hpp>
#include <erythronelumbo/maihuenia/mapping.hpp>
#include <erythronelumbo/maihuenia/monad.hpp>
#include <erythronelumbo/maihuenia/monad_plus.hpp>
#include <erythronelumbo/maihuenia/monoid.hpp>
#include <erythronelumbo/maihuenia/numeric.hpp>
#include <erythronelumbo/maihuenia/orderable.hpp>
#include <erythronelumbo/maihuenia/rational.hpp>
#include <erythronelumbo/maihuenia/sequence.hpp>
#include <erythronelumbo/maihuenia/with_string_repr.hpp>

// Typeclasses - Related operations
#include <erythronelumbo/maihuenia/iterable_is_random_access.hpp>
#include <erythronelumbo/maihuenia/min_max.hpp>

// Data types - Miscellaneous
#include <erythronelumbo/maihuenia/box.hpp>
#include <erythronelumbo/maihuenia/pair.hpp>
#include <erythronelumbo/maihuenia/empty_base.hpp>
#include <erythronelumbo/maihuenia/optional.hpp>

// Data types - Numeric
#include <erythronelumbo/maihuenia/integer_c.hpp>
#include <erythronelumbo/maihuenia/ratio_c.hpp>
#include <erythronelumbo/maihuenia/not_a_number.hpp>

// Data types - Sequences
#include <erythronelumbo/maihuenia/integral_vector_c.hpp>
#include <erythronelumbo/maihuenia/linked_list.hpp>
#include <erythronelumbo/maihuenia/map.hpp>
#include <erythronelumbo/maihuenia/range_c.hpp>
#include <erythronelumbo/maihuenia/set.hpp>
#include <erythronelumbo/maihuenia/string.hpp>
#include <erythronelumbo/maihuenia/vector.hpp>

// Data types - Sequence views
#include <erythronelumbo/maihuenia/filled_view.hpp>
#include <erythronelumbo/maihuenia/transformed_view.hpp>
#include <erythronelumbo/maihuenia/zipped_view.hpp>

// Algorithms - Sequence creation
#include <erythronelumbo/maihuenia/copy.hpp>
#include <erythronelumbo/maihuenia/fill.hpp>
#include <erythronelumbo/maihuenia/iota.hpp>
#include <erythronelumbo/maihuenia/scan_left.hpp>
#include <erythronelumbo/maihuenia/scan_right.hpp>
#include <erythronelumbo/maihuenia/partition.hpp>
#include <erythronelumbo/maihuenia/intercalate.hpp>
#include <erythronelumbo/maihuenia/split.hpp>
#include <erythronelumbo/maihuenia/split_sd.hpp>
#include <erythronelumbo/maihuenia/cartesian_product.hpp>
#include <erythronelumbo/maihuenia/zip.hpp>
#include <erythronelumbo/maihuenia/zip_with.hpp>

// Algorithms - Sequence transformation
#include <erythronelumbo/maihuenia/drop_until.hpp>
#include <erythronelumbo/maihuenia/drop_while.hpp>
#include <erythronelumbo/maihuenia/take_until.hpp>
#include <erythronelumbo/maihuenia/take_while.hpp>
#include <erythronelumbo/maihuenia/reverse.hpp>
#include <erythronelumbo/maihuenia/intersperse.hpp>
#include <erythronelumbo/maihuenia/remove_if.hpp>
#include <erythronelumbo/maihuenia/replace_if.hpp>
#include <erythronelumbo/maihuenia/unique.hpp>
#include <erythronelumbo/maihuenia/sort.hpp>

// Algorithms - Querying
#include <erythronelumbo/maihuenia/lexicographical_compare.hpp>
#include <erythronelumbo/maihuenia/min_max_element.hpp>
#include <erythronelumbo/maihuenia/all_of.hpp>
#include <erythronelumbo/maihuenia/any_of.hpp>
#include <erythronelumbo/maihuenia/none_of.hpp>
#include <erythronelumbo/maihuenia/contains.hpp>
#include <erythronelumbo/maihuenia/find_if.hpp>
#include <erythronelumbo/maihuenia/count_if.hpp>
#include <erythronelumbo/maihuenia/count_until.hpp>
#include <erythronelumbo/maihuenia/count_while.hpp>
#include <erythronelumbo/maihuenia/has_repeated.hpp>
#include <erythronelumbo/maihuenia/is_permutation.hpp>

// Algorithms - Runtime
#include <erythronelumbo/maihuenia/for_each.hpp>


#endif // ERYTHRONELUMBO_MAIHUENIA_MAIHUENIA_ALL_HPP
