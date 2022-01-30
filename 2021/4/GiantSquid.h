#ifndef _2021_4_GIANTSQUID_H_
#define _2021_4_GIANTSQUID_H_

#include "utils.h"

#include <algorithm>
#include <cstddef>
#include <memory>
#include <optional>
#include <unordered_set>
#include <vector>

namespace GiantSquid {

struct Field {
  int number = 0;
  bool marked = false;
};

template <int SIDE>
class Board {
public:
  Board()
  {
    fields.resize(SIDE * SIDE);
  }

  void setField(unsigned int row, unsigned int col, int number)
  {
    if (0 <= row <= SIDE && 0 <= col <= SIDE) {
      fields[row * SIDE + col].number = number;
    }
  }

  void markNumber(int number)
  {
    for (auto &field : fields) {
      if (field.number == number) {
        field.marked = true;
      }
    }
  }

  bool checkWon()
  {
    if (won) return true;

    // Check rows.
    for (unsigned int i = 0; i < SIDE; ++i) {
      bool all = true;
      for (unsigned int j = 0; j < SIDE; ++j) {
        all &= rowField(i, j).marked;
      }
      if (all) {
        return (won = true);
      }
    }

    // Check columns.
    for (unsigned int i = 0; i < SIDE; ++i) {
      bool all = true;
      for (unsigned int j = 0; j < SIDE; ++j) {
        all &= colField(j, i).marked;
      }
      if (all) {
        return (won = true);
      }
    }

    return false;
  }

  int unmarkedSum() const
  {
    return utils::accumulate(fields, 0, [](int acc, const auto &field) {
      return acc + (!field.marked ? field.number : 0);
    });
  }

private:
  const Field &rowField(unsigned int row, unsigned int col) const
  {
    return fields[row * SIDE + col];
  }

  const Field &colField(unsigned int col, unsigned int row) const
  {
    return fields[col * SIDE + row];
  }

  std::vector<Field> fields;
  bool won = false;
};

using BingoBoard = Board<5>;

struct ParsedResult {
  std::vector<int> numbers;
  std::vector<BingoBoard> boards;
};

std::optional<ParsedResult> parseFile(const std::string &path);

int part1(std::optional<ParsedResult> &result);
int part2(std::optional<ParsedResult> &result);

} // namespace GiantSquid

#endif // _2021_4_GIANTSQUID_H_
