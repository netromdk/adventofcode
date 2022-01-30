include(CTest)
enable_testing()

# Include gtest as system headers so no warnings will be shown.
include_directories(
  SYSTEM
  gtest/
  gtest/include
  )

add_library(
  gtest
  STATIC
  gtest/src/gtest-all.cc
  gtest/src/gtest_main.cc
  )
