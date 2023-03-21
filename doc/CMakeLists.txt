# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

find_package(Doxygen REQUIRED)


if (NOT DOXYGEN_FOUND)
  message("Doxygen was not found; the documentation files will not be built.")
  return()
endif()


set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR})
set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/doc/erythronelumbo/maihuenia)


configure_file(
  ${CMAKE_SOURCE_DIR}/doc/Doxyfile.in
  ${CMAKE_SOURCE_DIR}/doc/Doxyfile
  @ONLY
)
add_custom_target(
  doc
  ALL
  COMMAND ${CMAKE_COMMAND} -E make_directory ${DOXYGEN_OUTPUT_DIR}
  COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/doc/Doxyfile
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
