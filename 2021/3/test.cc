#include "gtest/gtest.h"

#include "BinaryDiagnostic.h"
#include "Utils.h"

const auto TEST_INPUT_VALUES = Utils::readLines<std::string>(TEST_INPUT_FILE);
const auto INPUT_VALUES = Utils::readLines<std::string>(INPUT_FILE);

TEST(BinaryDiagnostic, part1_testInput)
{
  EXPECT_EQ(198, BinaryDiagnostic::powerConsumption(TEST_INPUT_VALUES));
}

TEST(BinaryDiagnostic, part2_testInput)
{
  EXPECT_EQ(230, BinaryDiagnostic::lifeSupportRating(TEST_INPUT_VALUES));
}

TEST(BinaryDiagnostic, part1_input)
{
  EXPECT_EQ(3901196, BinaryDiagnostic::powerConsumption(INPUT_VALUES));
}

TEST(BinaryDiagnostic, part2_input)
{
  EXPECT_EQ(4412188, BinaryDiagnostic::lifeSupportRating(INPUT_VALUES));
}
