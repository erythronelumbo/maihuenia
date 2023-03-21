# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.11)

find_package(PythonInterp REQUIRED)


# Options
option(
  ERYTHRONELUMBO_MAIHUENIA_BUILD_EXAMPLE
  "Builds the examples"
  OFF
)
option(
  ERYTHRONELUMBO_MAIHUENIA_BUILD_DOC
  "Builds the documentation"
  OFF
)
option(
  ERYTHRONELUMBO_MAIHUENIA_BUILD_TEST
  "Builds the unit tests"
  OFF
)
set(
  ERYTHRONELUMBO_MAIHUENIA_PP_NUM_ARGS_UNROLL_FACTOR 200
  CACHE STRING
    "Maximum limit for preprocessor utility."
)
set(
  ERYTHRONELUMBO_MAIHUENIA_PP_AT_UNROLL_FACTOR 200
  CACHE STRING
    "Maximum limit for preprocessor utility."
)
set(
  ERYTHRONELUMBO_MAIHUENIA_PP_FOR_UNROLL_FACTOR 200
  CACHE STRING
    "Maximum limit for preprocessor utility."
)
set(
  ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM_UNROLL_FACTOR 200
  CACHE STRING
    "Maximum limit for preprocessor utility."
)
set(
  ERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_UNROLL_FACTOR 20
  CACHE STRING
    "Unroll factor for some binary metafunctions"
)
set(
  ERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_MAX_LENGTH 1024
  CACHE STRING
    "Maximum length for string literals when constructing `string`s from macro"
)
set(
  ERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_UNROLL_FACTOR 16
  CACHE STRING
    "Unroll factor of the macro for creating `string`s with string literals"
)


message("Generating `pp_num_args_impl.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_pp_num_args_impl_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_PP_NUM_ARGS_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/preprocessor
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")
message("Generating `pp_at_impl.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_pp_at_impl_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_PP_AT_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/preprocessor
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")
message("Generating `pp_for_impl.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_pp_for_impl_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_PP_FOR_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/preprocessor
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")
message("Generating `pp_transform_impl.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_pp_transform_impl_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_PP_TRANSFORM_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/preprocessor
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")
message("Generating `bin_op_many_impl.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_bin_op_many_impl_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_BIN_OP_MANY_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")
message("Generating `get_string_chars.hpp`...")
execute_process(
  COMMAND
    ${PYTHON_EXECUTABLE}
    ${CMAKE_SOURCE_DIR}/codegen/gen_get_string_chars_hpp.py
    ${ERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_MAX_LENGTH}
    ${ERYTHRONELUMBO_MAIHUENIA_STRING_MACRO_UNROLL_FACTOR}
    ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
message("Done.")


file(
  GLOB_RECURSE
  detail_header_files
  ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/*.hpp
  ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/preprocessor/*.hpp
  ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/detail/varseq/*.hpp
)
file(
  GLOB_RECURSE
  header_files
  ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/*.hpp
  ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/fwd/*.hpp
)

set(CMAKE_CXX_STANDARD 11)

# Reads the version from the `version.hpp` header.
file(
  READ ${CMAKE_SOURCE_DIR}/include/erythronelumbo/maihuenia/version.hpp
  _version_hpp_impl
)
foreach(vrs_level MAJOR MINOR PATCH)
  string(
    REGEX MATCH
    "#define ERYTHRONELUMBO_MAIHUENIA_VERSION_${vrs_level} ([0-9]+)(.*)"
    _
    ${_version_hpp_impl}
  )
  set(_vrs_${vrs_level} ${CMAKE_MATCH_1})
endforeach()
set(
  erythronelumbo_maihuenia_version "${_vrs_MAJOR}.${_vrs_MINOR}.${_vrs_PATCH}"
)


project(
  erythronelumbo_maihuenia
  VERSION ${erythronelumbo_maihuenia_version}
  LANGUAGES CXX
)


if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
elseif(
  CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
  CMAKE_CXX_COMPILER_ID MATCHES "Clang"
)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()


add_library(maihuenia INTERFACE)
target_sources(
  maihuenia INTERFACE $<BUILD_INTERFACE:${detail_header_files} ${header_files}>
)
target_include_directories(
  maihuenia INTERFACE $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/include/erythronelumbo"
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)


if (ERYTHRONELUMBO_MAIHUENIA_BUILD_TEST)
  add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

if (ERYTHRONELUMBO_MAIHUENIA_BUILD_EXAMPLE)
  add_subdirectory(${CMAKE_SOURCE_DIR}/example)
endif()

if (ERYTHRONELUMBO_MAIHUENIA_BUILD_DOC)
  add_subdirectory(${CMAKE_SOURCE_DIR}/doc)
endif()
