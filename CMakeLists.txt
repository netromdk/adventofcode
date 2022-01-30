cmake_minimum_required(VERSION 3.22)
project(adventofcode)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Output compile_commands.json (Ninja generator only!)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

option(USE_CCACHE "Use ccache (if found) to speed up compile and link" OFF)
option(EVERY_WARNING "Use -Weverything (clang only)" OFF)
option(ADDRESS_SANITIZER "Use memory error detector  (clang only and implies debug mode!)" OFF)

include(compilation)

add_subdirectory(src)

include(adventofcode)
include(testing)

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_ID})")

if (USE_CCACHE)
  message(STATUS "CCache: ${CCACHE} (using to speed up compile + link)")
else()
  message(STATUS "CCache: OFF")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  message(STATUS "Sanitizers:")
  message(STATUS "  Address: ${ADDRESS_SANITIZER}")

  if (EVERY_WARNING)
    message(STATUS "-Weverything: ON")
  else()
    message(STATUS "-Weverything: OFF")
  endif()
endif()

# The year-folders must be last in this file!
add_subdirectory(2021)
