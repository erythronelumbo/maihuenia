# Copyright (c) 2023 Álvaro Ceballos
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

file(GLOB test_dir_content ${CMAKE_SOURCE_DIR}/test/*)

set(test_subdirs)

foreach(test_dir_item ${test_dir_content})
  if(IS_DIRECTORY ${test_dir_item})
    list(APPEND test_subdirs ${test_dir_item})
  endif()
endforeach()

add_custom_target(test)

foreach(ind_test_dir ${test_subdirs})
  get_filename_component(ind_test_dir_clean ${ind_test_dir} NAME)
  #message("Individual test directory: ${ind_test_dir_clean}")

  file(
    GLOB
    test_exec_names
    ${ind_test_dir}/*.cpp
  )
  foreach(test_nm ${test_exec_names})
    get_filename_component(test_nm_clean ${test_nm} NAME_WE)
    #message("Test file: ${test_nm_clean}")
    add_executable(
      test_${test_nm_clean}
      ${CMAKE_SOURCE_DIR}/test/${ind_test_dir_clean}/${test_nm_clean}.cpp
    )
    set_target_properties(
      test_${test_nm_clean}
      PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
          "${CMAKE_BINARY_DIR}/test/${ind_test_dir_clean}"
    )
    target_include_directories(
      test_${test_nm_clean}
      PUBLIC ${CMAKE_SOURCE_DIR}/include
    )
    add_dependencies(test test_${test_nm_clean})
  endforeach()
endforeach()
