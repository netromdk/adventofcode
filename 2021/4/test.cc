#include "gtest/gtest.h"

#include "GiantSquid.h"
#include "Utils.h"

TEST(GiantSquid, part1_testInput)
{
  auto results = GiantSquid::parseFile(TEST_INPUT_FILE);
  ASSERT_TRUE(results.has_value());
  EXPECT_EQ(4512, GiantSquid::part1(results));
}

TEST(GiantSquid, part2_testInput)
{
  auto results = GiantSquid::parseFile(TEST_INPUT_FILE);
  ASSERT_TRUE(results.has_value());
  EXPECT_EQ(1924, GiantSquid::part2(results));
}

TEST(GiantSquid, part1_input)
{
  auto results = GiantSquid::parseFile(INPUT_FILE);
  ASSERT_TRUE(results.has_value());
  EXPECT_EQ(28082, GiantSquid::part1(results));
}

TEST(GiantSquid, part2_input)
{
  auto results = GiantSquid::parseFile(INPUT_FILE);
  ASSERT_TRUE(results.has_value());
  EXPECT_EQ(8224, GiantSquid::part2(results));
}
