#ifndef _2021_5_HYDROTHERMALVENTURE_H_
#define _2021_5_HYDROTHERMALVENTURE_H_

#include <iostream>
#include <optional>
#include <vector>

namespace HydrothermalVenture {

class Diagram {
public:
  Diagram(unsigned int width, unsigned int height);

  void markPoint(unsigned int x, unsigned int y);
  long overlaps(int threshold) const;
  void dump() const;

private:
  unsigned int width, height;
  std::vector<int> points;
};

std::optional<Diagram> parseFile(const std::string &path, const bool diagonal = false);

} // namespace HydrothermalVenture

#endif // _2021_5_HYDROTHERMALVENTURE_H_
