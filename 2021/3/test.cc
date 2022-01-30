#include "gtest/gtest.h"

#include "BinaryDiagnostic.h"
#include "utils.h"

using LineType = std::string;

TEST(BinaryDiagnostic, part1_testInput)
{
  EXPECT_EQ(198, BinaryDiagnostic::powerConsumption(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(BinaryDiagnostic, part2_testInput)
{
  EXPECT_EQ(230, BinaryDiagnostic::lifeSupportRating(utils::readLines<LineType>(TEST_INPUT_FILE)));
}

TEST(BinaryDiagnostic, part1_input)
{
  EXPECT_EQ(3901196, BinaryDiagnostic::powerConsumption(utils::readLines<LineType>(INPUT_FILE)));
}

TEST(BinaryDiagnostic, part2_input)
{
  EXPECT_EQ(4412188, BinaryDiagnostic::lifeSupportRating(utils::readLines<LineType>(INPUT_FILE)));
}
