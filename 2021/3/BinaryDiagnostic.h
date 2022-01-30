#ifndef BINARYDIAGNOSTIC_H
#define BINARYDIAGNOSTIC_H

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

namespace BinaryDiagnostic {

using Counter = std::unordered_map<char, int>;
Counter defaultCounter();

int powerConsumption(const std::vector<std::string> &lines);
int filter(const std::vector<std::string> &lines, bool opposite = false, std::size_t pos = 0);
int lifeSupportRating(const std::vector<std::string> &lines);

} // namespace BinaryDiagnostic

#endif // BINARYDIAGNOSTIC_H
