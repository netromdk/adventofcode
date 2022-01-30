#include "gtest/gtest.h"

#include "HydrothermalVenture.h"

const auto OVERLAPS = 2;

TEST(HydrothermalVenture, part1_testInput)
{
  auto diagram = HydrothermalVenture::parseFile(TEST_INPUT_FILE);
  ASSERT_TRUE(diagram.has_value());
  EXPECT_EQ(5, diagram->overlaps(OVERLAPS));
}

TEST(HydrothermalVenture, part2_testInput)
{
  const bool diagonal(true);
  auto diagram = HydrothermalVenture::parseFile(TEST_INPUT_FILE, diagonal);
  ASSERT_TRUE(diagram.has_value());
  EXPECT_EQ(12, diagram->overlaps(OVERLAPS));
}

TEST(HydrothermalVenture, part1_input)
{
  auto diagram = HydrothermalVenture::parseFile(INPUT_FILE);
  ASSERT_TRUE(diagram.has_value());
  EXPECT_EQ(4993, diagram->overlaps(OVERLAPS));
}

TEST(HydrothermalVenture, part2_input)
{
  const bool diagonal(true);
  auto diagram = HydrothermalVenture::parseFile(INPUT_FILE, diagonal);
  ASSERT_TRUE(diagram.has_value());
  EXPECT_EQ(21101, diagram->overlaps(OVERLAPS));
}
