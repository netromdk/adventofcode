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
  SHARED
  gtest/src/gtest-all.cc
  gtest/src/gtest_main.cc
  )
