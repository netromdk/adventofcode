#include "gtest/gtest.h"

#include "Lanternfish.h"
#include "utils.h"

TEST(Lanternfish, part1_testInput)
{
  auto fishes = Lanternfish::Fishes::parseFile(TEST_INPUT_FILE);
  EXPECT_EQ(5, fishes.count());

  // 1 day
  EXPECT_EQ(5, fishes.cycle(1));
  EXPECT_EQ(1, fishes.count(0));
  EXPECT_EQ(1, fishes.count(1));
  EXPECT_EQ(2, fishes.count(2));
  EXPECT_EQ(1, fishes.count(3));
  EXPECT_EQ(0, fishes.count(4));
  EXPECT_EQ(0, fishes.count(5));
  EXPECT_EQ(0, fishes.count(6));
  EXPECT_EQ(0, fishes.count(7));
  EXPECT_EQ(0, fishes.count(8));

  // 2 days
  EXPECT_EQ(6, fishes.cycle(1));
  EXPECT_EQ(1, fishes.count(0));
  EXPECT_EQ(2, fishes.count(1));
  EXPECT_EQ(1, fishes.count(2));
  EXPECT_EQ(0, fishes.count(3));
  EXPECT_EQ(0, fishes.count(4));
  EXPECT_EQ(0, fishes.count(5));
  EXPECT_EQ(1, fishes.count(6));
  EXPECT_EQ(0, fishes.count(7));
  EXPECT_EQ(1, fishes.count(8));

  // 3 days
  EXPECT_EQ(7, fishes.cycle(1));
  EXPECT_EQ(2, fishes.count(0));
  EXPECT_EQ(1, fishes.count(1));
  EXPECT_EQ(0, fishes.count(2));
  EXPECT_EQ(0, fishes.count(3));
  EXPECT_EQ(0, fishes.count(4));
  EXPECT_EQ(1, fishes.count(5));
  EXPECT_EQ(1, fishes.count(6));
  EXPECT_EQ(1, fishes.count(7));
  EXPECT_EQ(1, fishes.count(8));

  // 4 days
  EXPECT_EQ(9, fishes.cycle(1));
  EXPECT_EQ(1, fishes.count(0));
  EXPECT_EQ(0, fishes.count(1));
  EXPECT_EQ(0, fishes.count(2));
  EXPECT_EQ(0, fishes.count(3));
  EXPECT_EQ(1, fishes.count(4));
  EXPECT_EQ(1, fishes.count(5));
  EXPECT_EQ(3, fishes.count(6));
  EXPECT_EQ(1, fishes.count(7));
  EXPECT_EQ(2, fishes.count(8));

  // 5 days
  EXPECT_EQ(10, fishes.cycle(1));
  EXPECT_EQ(0, fishes.count(0));
  EXPECT_EQ(0, fishes.count(1));
  EXPECT_EQ(0, fishes.count(2));
  EXPECT_EQ(1, fishes.count(3));
  EXPECT_EQ(1, fishes.count(4));
  EXPECT_EQ(3, fishes.count(5));
  EXPECT_EQ(2, fishes.count(6));
  EXPECT_EQ(2, fishes.count(7));
  EXPECT_EQ(1, fishes.count(8));

  // 6 days
  EXPECT_EQ(10, fishes.cycle(1));
  EXPECT_EQ(0, fishes.count(0));
  EXPECT_EQ(0, fishes.count(1));
  EXPECT_EQ(1, fishes.count(2));
  EXPECT_EQ(1, fishes.count(3));
  EXPECT_EQ(3, fishes.count(4));
  EXPECT_EQ(2, fishes.count(5));
  EXPECT_EQ(2, fishes.count(6));
  EXPECT_EQ(1, fishes.count(7));
  EXPECT_EQ(0, fishes.count(8));

  // 7 days
  EXPECT_EQ(10, fishes.cycle(1));
  EXPECT_EQ(0, fishes.count(0));
  EXPECT_EQ(1, fishes.count(1));
  EXPECT_EQ(1, fishes.count(2));
  EXPECT_EQ(3, fishes.count(3));
  EXPECT_EQ(2, fishes.count(4));
  EXPECT_EQ(2, fishes.count(5));
  EXPECT_EQ(1, fishes.count(6));
  EXPECT_EQ(0, fishes.count(7));
  EXPECT_EQ(0, fishes.count(8));

  // 8 days
  EXPECT_EQ(10, fishes.cycle(1));
  EXPECT_EQ(1, fishes.count(0));
  EXPECT_EQ(1, fishes.count(1));
  EXPECT_EQ(3, fishes.count(2));
  EXPECT_EQ(2, fishes.count(3));
  EXPECT_EQ(2, fishes.count(4));
  EXPECT_EQ(1, fishes.count(5));
  EXPECT_EQ(0, fishes.count(6));
  EXPECT_EQ(0, fishes.count(7));
  EXPECT_EQ(0, fishes.count(8));

  // 9 days
  EXPECT_EQ(11, fishes.cycle(1));
  EXPECT_EQ(1, fishes.count(0));
  EXPECT_EQ(3, fishes.count(1));
  EXPECT_EQ(2, fishes.count(2));
  EXPECT_EQ(2, fishes.count(3));
  EXPECT_EQ(1, fishes.count(4));
  EXPECT_EQ(0, fishes.count(5));
  EXPECT_EQ(1, fishes.count(6));
  EXPECT_EQ(0, fishes.count(7));
  EXPECT_EQ(1, fishes.count(8));

  // 10 days
  EXPECT_EQ(12, fishes.cycle(1));
  EXPECT_EQ(3, fishes.count(0));
  EXPECT_EQ(2, fishes.count(1));
  EXPECT_EQ(2, fishes.count(2));
  EXPECT_EQ(1, fishes.count(3));
  EXPECT_EQ(0, fishes.count(4));
  EXPECT_EQ(1, fishes.count(5));
  EXPECT_EQ(1, fishes.count(6));
  EXPECT_EQ(1, fishes.count(7));
  EXPECT_EQ(1, fishes.count(8));

  // 11 days
  EXPECT_EQ(15, fishes.cycle(1));
  EXPECT_EQ(2, fishes.count(0));
  EXPECT_EQ(2, fishes.count(1));
  EXPECT_EQ(1, fishes.count(2));
  EXPECT_EQ(0, fishes.count(3));
  EXPECT_EQ(1, fishes.count(4));
  EXPECT_EQ(1, fishes.count(5));
  EXPECT_EQ(4, fishes.count(6));
  EXPECT_EQ(1, fishes.count(7));
  EXPECT_EQ(3, fishes.count(8));
}

TEST(Lanternfish, part1_testInput_18_days)
{
  auto fishes = Lanternfish::Fishes::parseFile(TEST_INPUT_FILE);
  EXPECT_EQ(26, fishes.cycle(18));
}

TEST(Lanternfish, part1_testInput_80_days)
{
  auto fishes = Lanternfish::Fishes::parseFile(TEST_INPUT_FILE);
  EXPECT_EQ(5934, fishes.cycle(80));
}

TEST(Lanternfish, part1_input_80_days)
{
  auto fishes = Lanternfish::Fishes::parseFile(INPUT_FILE);
  EXPECT_EQ(352872, fishes.cycle(80));
}

TEST(Lanternfish, part2_testInput_256_days)
{
  auto fishes = Lanternfish::Fishes::parseFile(TEST_INPUT_FILE);
  EXPECT_EQ(26984457539ULL, fishes.cycle(256));
}

TEST(Lanternfish, part2_input_256_days)
{
  auto fishes = Lanternfish::Fishes::parseFile(INPUT_FILE);
  EXPECT_EQ(1604361182149ULL, fishes.cycle(256));
}
