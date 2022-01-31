#include "TreacheryOfWhales.h"

#include <cmath>
#include <unordered_map>

namespace TreacheryOfWhales {

namespace detail {

PosType calcFuelUse(const Positions &positions, const FuelCostFunc &func)
{
  std::unordered_map<PosType, PosType> fuelUse;
  const auto maxPos = *utils::max_element(positions);
  for (auto gotoPos = 0; gotoPos <= maxPos; ++gotoPos) {
    fuelUse[gotoPos] =
      utils::accumulate(positions, 0, [&](auto acc, auto pos) { return acc + func(pos, gotoPos); });
  }
  return utils::min_element(fuelUse,
                            [](const auto &a, const auto &b) { return a.second < b.second; })
    ->second;
}

} // namespace detail

PosType horizontalFuelConstant(const Positions &positions)
{
  return detail::calcFuelUse(positions,
                             [](PosType pos, PosType gotoPos) { return std::abs(gotoPos - pos); });
}

PosType horizontalFuel(const Positions &positions)
{
  return detail::calcFuelUse(positions, [](PosType pos, PosType gotoPos) {
    const auto dist = std::abs(gotoPos - pos);

    // Gauss summation of 1 to dist.
    return (dist * (dist + 1)) / 2;
  });
}

} // namespace TreacheryOfWhales
