#ifndef __2021_4_GIANTSQUID_H__
#define __2021_4_GIANTSQUID_H__

#include "Utils.h"

#include <algorithm>
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

  void setField(int row, int col, int number)
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
    for (int i = 0; i < SIDE; ++i) {
      bool all = true;
      for (int j = 0; j < SIDE; ++j) {
        all &= rowField(i, j).marked;
      }
      if (all) {
        return (won = true);
      }
    }

    // Check columns.
    for (int i = 0; i < SIDE; ++i) {
      bool all = true;
      for (int j = 0; j < SIDE; ++j) {
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
    return Utils::accumulate(fields, 0, [](int acc, const auto &field) {
      return acc + (!field.marked ? field.number : 0);
    });
  }

private:
  const Field &rowField(int row, int col) const
  {
    return fields[row * SIDE + col];
  }

  const Field &colField(int col, int row) const
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

std::optional<ParsedResult> parseFile(const std::string &path)
{
  const auto data = Utils::readFile(path);
  if (data.empty()) return {};

  // Parse numbers.
  std::stringstream ss(data);
  std::string line;
  if (!std::getline(ss, line, '\n')) {
    return {};
  }

  ParsedResult res;
  res.numbers = Utils::splitValues<int>(line, ',');
  if (res.numbers.empty()) {
    return {};
  }

  // Parse boards.
  while (!ss.eof()) {
    // Eat empty line.
    if (!std::getline(ss, line, '\n')) {
      break;
    }

    // Read 5 rows of board data.
    BingoBoard board;
    for (int row = 0; row < 5; ++row) {
      if (!std::getline(ss, line, '\n')) {
        return {};
      }
      int n;
      std::stringstream nss(line);
      for (int col = 0; col < 5; ++col) {
        nss >> n;
        board.setField(row, col, n);
      }
    }
    res.boards.push_back(board);
  }

  return res;
}

int part1(std::optional<ParsedResult> &result)
{
  // Find first winner.
  for (auto n : result->numbers) {
    for (auto &board : result->boards) {
      board.markNumber(n);
      if (board.checkWon()) {
        return board.unmarkedSum() * n;
      }
    }
  }
  return 0;
}

int part2(std::optional<ParsedResult> &result)
{
  // Find last winner.
  const auto amount = result->boards.size();
  std::unordered_set<int> wins;
  for (auto n : result->numbers) {
    for (int i = 0; i < amount; ++i) {
      auto &board = result->boards[i];
      board.markNumber(n);
      if (board.checkWon() && !wins.contains(i)) {
        wins.insert(i);
        if (wins.size() == amount) {
          return board.unmarkedSum() * n;
        }
      }
    }
  }
  return 0;
}

} // namespace GiantSquid

#endif // __2021_4_GIANTSQUID_H__
