#include "gtest/gtest.h"

#include "Dive.h"
#include "Utils.h"

const auto TEST_INPUT_VALUES = Utils::readLines<std::string>(TEST_INPUT_FILE);
const auto INPUT_VALUES = Utils::readLines<std::string>(INPUT_FILE);

TEST(Dive, part1_testInput)
{
  EXPECT_EQ(150, Dive::horizontalPosDepth(TEST_INPUT_VALUES));
}

TEST(Dive, part2_testInput)
{
  EXPECT_EQ(900, Dive::horizontalPosDepthAim(TEST_INPUT_VALUES));
}

TEST(Dive, part1_input)
{
  EXPECT_EQ(1936494, Dive::horizontalPosDepth(INPUT_VALUES));
}

TEST(Dive, part2_input)
{
  EXPECT_EQ(1997106066, Dive::horizontalPosDepthAim(INPUT_VALUES));
}
