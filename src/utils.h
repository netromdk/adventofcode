#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

namespace utils {

std::string readFile(const std::string &path);

template <typename T>
inline std::vector<T> splitValues(const std::string &data, const char delim = '\n')
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
inline std::vector<std::string> splitValues(const std::string &data, const char delim)
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

int str2bin(const std::string &bin);

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

} // namespace utils

#endif // UTILS_H
