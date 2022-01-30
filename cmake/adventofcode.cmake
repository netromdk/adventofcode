function(adventofcode_puzzle name)
  project(${name})

  include_directories(
    ${CMAKE_SOURCE_DIR}/src
    )

  set(testName "test_${PROJECT_NAME}")

  file(
    GLOB sources
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.cc"
    )

  add_executable(
    ${testName}
    ${sources}
    )

  cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME day)
  cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH parentDir)
  cmake_path(GET parentDir FILENAME year)

  add_test(
    NAME ${year}_${day}_${PROJECT_NAME}
    COMMAND ${testName}
    )

  target_link_libraries(
    ${testName}
    utils
    gtest
    )

  set_target_properties(
    ${testName}
    PROPERTIES
    COMPILE_DEFINITIONS
    "TEST_INPUT_FILE=\"${CMAKE_CURRENT_SOURCE_DIR}/test-input.txt\";\
     INPUT_FILE=\"${CMAKE_CURRENT_SOURCE_DIR}/input.txt\""
    )
endfunction()
