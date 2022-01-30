#include "SonarSweep.h"

#include <cstddef>

namespace SonarSweep {

int timesIncreased(const std::vector<int> &values)
{
  if (values.empty()) return -1;

  auto prev = values[0];
  int increased = 0;
  for (std::size_t i = 1; i < values.size(); ++i) {
    auto value = values[i];
    if (value > prev) {
      increased++;
    }
    prev = value;
  }
  return increased;
}

int sumsLarger(const std::vector<int> &values)
{
  if (values.size() < 3) return -1;

  auto prev = values[0] + values[1] + values[2];
  int increased = 0;
  for (std::size_t i = 1; i < values.size() - 2; ++i) {
    auto value = values[i] + values[i + 1] + values[i + 2];
    if (value > prev) {
      increased++;
    }
    prev = value;
  }
  return increased;
}

} // namespace SonarSweep
