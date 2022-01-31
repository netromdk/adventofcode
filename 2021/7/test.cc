#include "gtest/gtest.h"

#include "TreacheryOfWhales.h"
#include "utils.h"

TEST(TreacheryOfWhales, part1_testInput)
{
  EXPECT_EQ(37, TreacheryOfWhales::horizontalFuelConstant(
                  utils::readLines<TreacheryOfWhales::PosType>(TEST_INPUT_FILE, ',')));
}

TEST(TreacheryOfWhales, part1_input)
{
  EXPECT_EQ(329389, TreacheryOfWhales::horizontalFuelConstant(
                      utils::readLines<TreacheryOfWhales::PosType>(INPUT_FILE, ',')));
}

TEST(TreacheryOfWhales, part2_testInput)
{
  EXPECT_EQ(168, TreacheryOfWhales::horizontalFuel(
                   utils::readLines<TreacheryOfWhales::PosType>(TEST_INPUT_FILE, ',')));
}

TEST(TreacheryOfWhales, part2_input)
{
  EXPECT_EQ(86397080, TreacheryOfWhales::horizontalFuel(
                        utils::readLines<TreacheryOfWhales::PosType>(INPUT_FILE, ',')));
}
