#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

namespace Utils {

std::string readFile(const std::string &path)
{
  std::ifstream is(path, std::ios::binary | std::ios::ate);
  if (!is) return {};

  const auto size = is.tellg();
  std::string data(size, '\0');
  is.seekg(0);
  if (is.read(&data[0], size)) {
    return data;
  }
  return {};
}

template <typename T>
std::vector<T> splitValues(const std::string &data, const char delim = '\n')
{
  std::vector<T> values;
  std::stringstream ss(data);
  std::string line;
  while (std::getline(ss, line, delim)) {
    std::stringstream ss2(line);
    T val{};
    ss2 >> val;
    values.push_back(val);
  }
  return values;
}

template <>
std::vector<std::string> splitValues(const std::string &data, const char delim)
{
  std::vector<std::string> values;
  std::stringstream ss(data);
  std::string line;
  while (std::getline(ss, line, delim)) {
    values.push_back(line);
  }
  return values;
}

template <typename T>
std::vector<T> readLines(const std::string &path, const char delim = '\n')
{
  const auto data = readFile(path);
  if (data.empty()) return {};
  return splitValues<T>(data, delim);
}

int str2bin(const std::string &bin)
{
  return std::stoi(bin, 0, 2);
}

template <typename Container, typename UnaryPredicate>
typename std::iterator_traits<typename Container::iterator>::difference_type
count_if(const Container &c, UnaryPredicate p)
{
  return std::count_if(std::begin(c), std::end(c), p);
}

template <typename Container, typename T, typename BinaryOperation>
constexpr T accumulate(const Container &c, T init, BinaryOperation op)
{
  return std::accumulate(std::begin(c), std::end(c), init, op);
}

} // namespace Utils

#endif // UTILS_H
