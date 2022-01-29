#ifndef DIVE_H
#define DIVE_H

#include <sstream>
#include <string>
#include <vector>

namespace Dive {

int horizontalPosDepth(const std::vector<std::string> &lines)
{
  int pos = 0;
  int depth = 0;
  for (const auto &line : lines) {
    std::stringstream ss(line);
    std::string cmd;
    int mod = 0;
    ss >> cmd >> mod;
    if (cmd == "forward") {
      pos += mod;
    }
    else if (cmd == "down") {
      depth += mod;
    }
    else if (cmd == "up") {
      depth -= mod;
    }
  }
  return pos * depth;
}

int horizontalPosDepthAim(const std::vector<std::string> &lines)
{
  int pos = 0;
  int depth = 0;
  int aim = 0;
  for (const auto &line : lines) {
    std::stringstream ss(line);
    std::string cmd;
    int mod = 0;
    ss >> cmd >> mod;
    if (cmd == "forward") {
      pos += mod;
      depth += aim * mod;
    }
    else if (cmd == "down") {
      aim += mod;
    }
    else if (cmd == "up") {
      aim -= mod;
    }
  }
  return pos * depth;
}

} // namespace Dive

#endif // DIVE_H
