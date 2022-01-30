#include "gtest/gtest.h"

#include "SonarSweep.h"
#include "utils.h"

using LineType = int;

TEST(SonarSweep, part1_testInput)
{
  EXPECT_EQ(7, SonarSweep::timesIncreased(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(SonarSweep, part2_testInput)
{
  EXPECT_EQ(5, SonarSweep::sumsLarger(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(SonarSweep, part1_input)
{
  EXPECT_EQ(1374, SonarSweep::timesIncreased(utils::readLines<LineType>(INPUT_FILE)));
}

TEST(SonarSweep, part2_input)
{
  EXPECT_EQ(1418, SonarSweep::sumsLarger(utils::readLines<LineType>(INPUT_FILE)));
}
