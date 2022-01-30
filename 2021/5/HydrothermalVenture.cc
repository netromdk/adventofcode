#include "HydrothermalVenture.h"
#include "utils.h"

#include <array>
#include <sstream>

namespace HydrothermalVenture {

Diagram::Diagram(unsigned int width, unsigned int height) : width(width), height(height)
{
  points.resize(width * height);
}

void Diagram::markPoint(unsigned int x, unsigned int y)
{
  if (x <= width && y <= height) {
    points[y * width + x]++;
  }
}

long Diagram::overlaps(int threshold) const
{
  return utils::count_if(points, [threshold](auto point) { return point >= threshold; });
}

void Diagram::dump() const
{
  for (unsigned int x = 0; x < width; ++x) {
    for (unsigned int y = 0; y < height; ++y) {
      std::cout << points[x * width + y];
    }
    std::cout << "\n";
  }
}

std::optional<Diagram> parseFile(const std::string &path, const bool diagonal)
{
  const auto data = utils::readFile(path);
  if (data.empty()) return {};

  // Parse line segments and expand points.
  std::vector<std::array<unsigned int, 2>> points;
  unsigned int maxX = 0, maxY = 0;
  std::stringstream ss(data);
  std::string line;
  while (std::getline(ss, line, '\n')) {
    if (const auto pos = line.find("->"); pos != line.npos) {
      const auto lhs = utils::splitValues<unsigned int>(line.substr(0, pos), ',');
      const auto rhs = utils::splitValues<unsigned int>(line.substr(pos + 2), ',');

      // Only horizontal.
      if (lhs[0] == rhs[0]) {
        maxX = std::max({maxX, lhs[0], rhs[0]});
        maxY = std::max({maxY, lhs[1], rhs[1]});
        const auto from = std::min(lhs[1], rhs[1]);
        const auto to = std::max(lhs[1], rhs[1]);
        for (unsigned int y = from; y <= to; ++y) {
          points.push_back({lhs[0], y});
        }
      }

      // Or vertical.
      else if (lhs[1] == rhs[1]) {
        maxX = std::max({maxX, lhs[0], rhs[0]});
        maxY = std::max({maxY, lhs[1], rhs[1]});
        const auto from = std::min(lhs[0], rhs[0]);
        const auto to = std::max(lhs[0], rhs[0]);
        for (unsigned int x = from; x <= to; ++x) {
          points.push_back({x, lhs[1]});
        }
      }

      // Or diagonal.
      else if (diagonal) {
        maxX = std::max({maxX, lhs[0], rhs[0]});
        maxY = std::max({maxY, lhs[1], rhs[1]});
        if (lhs[0] < rhs[0]) {
          if (lhs[1] < rhs[1]) {
            for (unsigned int x = lhs[0], y = lhs[1]; x <= rhs[0] && y <= rhs[1]; ++x, ++y) {
              points.push_back({x, y});
            }
          }
          else if (lhs[1] > rhs[1]) {
            for (unsigned int x = lhs[0], y = lhs[1]; x <= rhs[0] && y >= rhs[1]; ++x, --y) {
              points.push_back({x, y});
            }
          }
        }
        else if (lhs[0] > rhs[0]) {
          if (lhs[1] < rhs[1]) {
            for (unsigned int x = lhs[0], y = lhs[1]; x >= rhs[0] && y <= rhs[1]; --x, ++y) {
              points.push_back({x, y});
            }
          }
          else if (lhs[1] > rhs[1]) {
            for (unsigned int x = lhs[0], y = lhs[1]; x >= rhs[0] && y >= rhs[1]; --x, --y) {
              points.push_back({x, y});
            }
          }
        }
      }
    }
  }

  // Build diagram. +1 because we need room for the zero row and column.
  Diagram diagram(maxX + 1, maxY + 1);
  for (const auto &point : points) {
    diagram.markPoint(point[0], point[1]);
  }
  return diagram;
}

} // namespace HydrothermalVenture
