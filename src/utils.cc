#include "utils.h"

#include <fstream>

namespace utils {

std::string readFile(const std::string &path)
{
  std::ifstream is(path, std::ios::binary | std::ios::ate);
  if (!is) return {};

  const auto size = is.tellg();
  std::string data(static_cast<std::size_t>(size), '\0');
  is.seekg(0);
  if (is.read(&data[0], size)) {
    return data;
  }
  return {};
}

int str2bin(const std::string &bin)
{
  return std::stoi(bin, nullptr, 2);
}

} // namespace utils
