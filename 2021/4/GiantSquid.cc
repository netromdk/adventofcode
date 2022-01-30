#include "GiantSquid.h"

namespace GiantSquid {

std::optional<ParsedResult> parseFile(const std::string &path)
{
  const auto data = utils::readFile(path);
  if (data.empty()) return {};

  // Parse numbers.
  std::stringstream ss(data);
  std::string line;
  if (!std::getline(ss, line, '\n')) {
    return {};
  }

  ParsedResult res;
  res.numbers = utils::splitValues<int>(line, ',');
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
    for (unsigned int row = 0; row < 5; ++row) {
      if (!std::getline(ss, line, '\n')) {
        return {};
      }
      int n;
      std::stringstream nss(line);
      for (unsigned int col = 0; col < 5; ++col) {
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
  std::unordered_set<std::size_t> wins;
  for (auto n : result->numbers) {
    for (std::size_t i = 0; i < amount; ++i) {
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
