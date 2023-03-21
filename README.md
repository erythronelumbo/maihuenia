# Maihuenia

*Maihuenia* (named after a genus of cushion-forming cacti) is a template
metaprogramming library for C++11 and later standards.

## Requirements

- A working C++11-compatible compiler.
- CMake (for building and installation).
- A Python interpreter (for generating some of the library's headers).
- Doxygen (for generating the documentation; optional).

## Building

This library is header-only, so it does not need to build binaries. However,
the examples, the unit tests and the documentation need to be built; also,
some of the library's header files are automatically generated with the Python
scripts provided in the `codegen` directory.

Said generated header files are the following:
```
include/erythronelumbo/maihuenia/detail/bin_op_many_impl.hpp
include/erythronelumbo/maihuenia/detail/get_string_chars.hpp
include/erythronelumbo/maihuenia/detail/preprocessor/pp_num_args_impl.hpp
include/erythronelumbo/maihuenia/detail/preprocessor/pp_for_impl.hpp
include/erythronelumbo/maihuenia/detail/preprocessor/pp_at_impl.hpp
include/erythronelumbo/maihuenia/detail/preprocessor/pp_transform_impl.hpp
```

Run `mkdir build && cd build && cmake [options] .. && make` (it can be done
with the equivalents from your toolset) for building. If prefered, CMake's GUI
can also be used. Starting CMake will also generate the aforementioned header
files.

### Compiling the unit tests

Set `-DERYTHRONELUMBO_MAIHUENIA_BUILD_TEST=1` for enabling the compilation of
the unit tests.

Run `make test` to run the tests.

Note that they are not proper unit tests, but they only checks if the
compilation is done successfully.

### Compiling the examples

Set `-DERYTHRONELUMBO_MAIHUENIA_BUILD_EXAMPLE=1` for enabling the compilation of
the examples.

Run `make example` for compiling them.

### Generating the documentation

Set `-DERYTHRONELUMBO_MAIHUENIA_BUILD_DOC=1` for enabling the generation of
the documentation. It will be located in the
`build/doc/erythronelumbo/maihuenia` directory. This will also generate a
`erythronelumbo_maihuenia_tagfile.tag` file, located in the aforementioned path,
which is used for linking an external library's documentation (if Doxygen is
also used) to this library's one.

Run `make doc` to generate the documentation.

### Code generation

The options `-DERYTHRONELUMBO_MAIHUENIA_PP_NUM_ARGS_UNROLL_FACTOR=<num>`,
`-DERYTHRONELUMBO_MAIHUENIA_PP_AT_UNROLL_FACTOR=<num>`,
`-DERYTHRONELUMBO_MAIHUENIA_PP_FOR_UNROLL_FACTOR=<num>` and
`-DERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM_UNROLL_FACTOR=<num>` are for
preprocessor-based utilities that are used internally by the library. The
default value for all these options is 200.

Use `-DERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_UNROLL_FACTOR=<number>` for setting
how much the `bin_op_many` metafunction (used by other operations from this
library) can be unrolled (default value: 20).

Use `-DERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_MAX_LENGTH=<number>` for setting
the maximum length for string literals when constructing `string`s from the
respective macros (the default value is 1024). Also, the related option
`-DERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_UNROLL_FACTOR=<number>` determines how
much the underlying process of putting each character from a string literal into
the resulting `string` is unrolled (the default value is 16).

## Installing the library

Use `-DCMAKE_INSTALL_PREFIX=/path/to/your/libraries` to set the installation
path. The `/include` directory will be located in said path.

Run `make install` for installing the library.

## License

This library is licensed under the Boost Software License, Version 1.0.
