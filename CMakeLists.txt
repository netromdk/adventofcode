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

include(compilation)

add_subdirectory(src)

include(adventofcode)
include(testing)

add_subdirectory(2021)
