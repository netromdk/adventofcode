#ifndef BINARYDIAGNOSTIC_H
#define BINARYDIAGNOSTIC_H

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Utils.h"

namespace BinaryDiagnostic {

using Counter = std::unordered_map<char, int>;

Counter defaultCounter()
{
  return {{'0', 0}, {'1', 0}};
}

int powerConsumption(const std::vector<std::string> &lines)
{
  std::vector<Counter> counters(lines[0].size(), defaultCounter());
  for (const auto &line : lines) {
    for (int i = 0; i < line.size(); ++i) {
      const auto ch = line[i];
      counters[i][ch]++;
    }
  }

  std::stringstream gamma, epsilon;
  for (const auto &counter : counters) {
    const bool moreOnes = counter.at('1') > counter.at('0');
    gamma << (moreOnes ? "1" : "0");

    // Epsilon is just the opposite of gamme so no need to calculate twice.
    epsilon << (!moreOnes ? "1" : "0");
  }

  const auto gammaRate = Utils::str2bin(gamma.str());
  const auto epsilonRate = Utils::str2bin(epsilon.str());
  return gammaRate * epsilonRate;
}

int filter(const std::vector<std::string> &lines, bool opposite = false, int pos = 0)
{
  if (lines.size() == 1) {
    return Utils::str2bin(lines[0]);
  }

  auto counter = defaultCounter();
  for (const auto &line : lines) {
    counter[line[pos]]++;
  }

  auto lookFor = (counter.at('1') >= counter.at('0') ? '1' : '0');
  if (opposite) {
    lookFor = (lookFor == '1' ? '0' : '1');
  }

  std::vector<std::string> selected;
  for (const auto &line : lines) {
    if (line[pos] == lookFor) {
      selected.push_back(line);
    }
  }
  return filter(selected, opposite, pos + 1);
}

int lifeSupportRating(const std::vector<std::string> &lines)
{
  const auto oxygenGen = filter(lines);
  const auto co2Scrub = filter(lines, true);
  return oxygenGen * co2Scrub;
}

} // namespace BinaryDiagnostic

#endif // BINARYDIAGNOSTIC_H
