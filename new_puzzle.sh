#!/bin/sh

if [ ! $# -eq 3 ]; then
  echo "usage: $0 <year> <day> <puzzle name>"
  exit 1
fi

year=$1
day=$2
name=$3
cap_name=$(echo $name | tr '[:lower:]' '[:upper:]')
path=${year}/${day}
hdr_guard="_${year}_${day}_${cap_name}_H_"
year_subdir="add_subdirectory(${year})"
day_subdir="add_subdirectory(${day})"

set -x
mkdir -p ${path}

# Implementation skeleton.
cat <<EOT > ${path}/${name}.h
#ifndef ${hdr_guard}
#define ${hdr_guard}

#include "utils.h"

namespace ${name} {

// Make solution here..

} // namespace ${name}

#endif // ${hdr_guard}
EOT

# Unit test skeleton.
cat <<EOF > ${path}/test.cc
#include "gtest/gtest.h"

#include "${name}.h"
#include "utils.h"

using LineType = int;

TEST(${name}, part1_testInput)
{
  EXPECT_EQ(0, ${name}::part1(Utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(${name}, part2_testInput)
{
  EXPECT_EQ(0, ${name}::part2(Utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(${name}, part1_input)
{
  EXPECT_EQ(0, ${name}::part1(Utils::readLines<LineType>(INPUT_FILE)));
}

TEST(${name}, part2_input)
{
  EXPECT_EQ(0, ${name}::part2(Utils::readLines<LineType>(INPUT_FILE)));
}
EOF

cat <<EOF > ${path}/CMakeLists.txt
adventofcode_puzzle(${name})
EOF

# Empty input files.
touch ${path}/input.txt
touch ${path}/test-input.txt

# Add cmake-traversal of subdirectories if needed.
if [ ! $(grep ${year_subdir} CMakeLists.txt) ]; then
  echo ${year_subdir} >> CMakeLists.txt;
fi
if [ ! $(grep ${day_subdir} ${year}/CMakeLists.txt) ]; then
  echo ${day_subdir} >> ${year}/CMakeLists.txt;
fi
