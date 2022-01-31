#ifndef _2021_7_TREACHERYOFWHALES_H_
#define _2021_7_TREACHERYOFWHALES_H_

#include <functional>

#include "utils.h"

namespace TreacheryOfWhales {

using PosType = int;
using Positions = std::vector<PosType>;

namespace detail {

// Fuel cost from pos to go-to pos.
using FuelCostFunc = std::function<PosType(PosType, PosType)>;

PosType calcFuelUse(const Positions &positions, const FuelCostFunc &func);

} // namespace detail

PosType horizontalFuelConstant(const Positions &positions);
PosType horizontalFuel(const Positions &positions);

} // namespace TreacheryOfWhales

#endif // _2021_7_TREACHERYOFWHALES_H_
