#include "gtest/gtest.h"

#include "SonarSweep.h"
#include "Utils.h"

const auto TEST_INPUT_VALUES = Utils::readLines<int>(TEST_INPUT_FILE);
const auto INPUT_VALUES = Utils::readLines<int>(INPUT_FILE);

TEST(SonarSweep, part1_testInput)
{
  EXPECT_EQ(7, SonarSweep::timesIncreased(TEST_INPUT_VALUES));
}

TEST(SonarSweep, part2_testInput)
{
  EXPECT_EQ(5, SonarSweep::sumsLarger(TEST_INPUT_VALUES));
}

TEST(SonarSweep, part1_input)
{
  EXPECT_EQ(1374, SonarSweep::timesIncreased(INPUT_VALUES));
}

TEST(SonarSweep, part2_input)
{
  EXPECT_EQ(1418, SonarSweep::sumsLarger(INPUT_VALUES));
}
