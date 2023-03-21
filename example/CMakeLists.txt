# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

set(
  cg_examples
  custom_typeclass
  fibonacci
  ordering_strings
)

file(
  GLOB
  individual_example_dirs
  ${CMAKE_SOURCE_DIR}/example/individual/*
)

add_custom_target(example)

foreach(ind_cg_ex ${cg_examples})
  add_executable(${ind_cg_ex} ${ind_cg_ex}.cpp)
  set_target_properties(
    ${ind_cg_ex}
    PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/example/${ind_cg_ex}"
  )
  target_include_directories(
    ${ind_cg_ex}
    PUBLIC ${CMAKE_SOURCE_DIR}/include
  )
  add_dependencies(example ${ind_cg_ex})
endforeach()

foreach(ind_ex_dir ${individual_example_dirs})
  get_filename_component(ind_ex_dir_clean ${ind_ex_dir} NAME)
  #message("Individual example directory: ${ind_ex_dir_clean}")

  file(
    GLOB
    example_exec_names
    ${ind_ex_dir}/*.cpp
  )
  foreach(example_nm ${example_exec_names})
    get_filename_component(example_nm_clean ${example_nm} NAME_WE)
    add_executable(
      ${example_nm_clean}
      ${CMAKE_SOURCE_DIR}/example/individual/${ind_ex_dir_clean}/${example_nm_clean}.cpp
    )
    set_target_properties(
      ${example_nm_clean}
      PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
          "${CMAKE_BINARY_DIR}/example/individual/${ind_ex_dir_clean}"
    )
    target_include_directories(
      ${example_nm_clean}
      PUBLIC ${CMAKE_SOURCE_DIR}/include
    )
    add_dependencies(example ${example_nm_clean})
  endforeach()
endforeach()
