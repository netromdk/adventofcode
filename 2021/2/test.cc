#include "gtest/gtest.h"

#include "Dive.h"
#include "utils.h"

using LineType = std::string;

TEST(Dive, part1_testInput)
{
  EXPECT_EQ(150, Dive::horizontalPosDepth(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(Dive, part2_testInput)
{
  EXPECT_EQ(900, Dive::horizontalPosDepthAim(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(Dive, part1_input)
{
  EXPECT_EQ(1936494, Dive::horizontalPosDepth(utils::readLines<LineType>(INPUT_FILE)));
}

TEST(Dive, part2_input)
{
  EXPECT_EQ(1997106066, Dive::horizontalPosDepthAim(utils::readLines<LineType>(INPUT_FILE)));
}
