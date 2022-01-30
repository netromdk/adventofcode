#ifndef _2021_6_LANTERNFISH_H_
#define _2021_6_LANTERNFISH_H_

#include <cstdint>
#include <vector>

#include "utils.h"

namespace Lanternfish {

// Position in vector is fish value [0, 8] and value is the counter.
class Fishes {
public:
  using Counter = std::uintmax_t;
  using Container = std::vector<Counter>;

  Fishes()
  {
    // Create default counters values for 0 to 8.
    data.resize(9);
  }

  static Fishes parseFile(const std::string &path)
  {
    const auto values = utils::readLines<std::size_t>(path, ',');
    Fishes fishes;
    for (const auto fish : values) {
      fishes.add(fish);
    }
    return fishes;
  }

  void add(std::size_t fish)
  {
    data[fish]++;
  }

  void nextDay()
  {
    Counter adds = 0;
    for (std::size_t i = 0; i <= 8; ++i) {
      if (i == 0) {
        if (data[0] > 0) {
          // New 8'ers per value. But add last so they won't get decreased this cycle.
          adds = data[0];

          // Convert 0's to 6'ers (they're added along with `adds` beneath).
          data[0] = 0;
        }
      }
      else {
        // Decrease value by moving down one level.
        data[i - 1] += data[i];
        data[i] = 0;
      }
    }
    if (adds > 0) {
      data[6] += adds;
      data[8] += adds;
    }
  }

  Counter cycle(const int days)
  {
    for (int i = 0; i < days; ++i) {
      nextDay();
    }
    return count();
  }

  Counter count() const
  {
    return utils::accumulate<Container, Counter>(data, 0,
                                                 [](auto acc, auto value) { return acc + value; });
  }

  Counter count(std::size_t fish) const
  {
    if (fish < data.size()) {
      return data[fish];
    }
    return 0;
  }

  void dump() const
  {
    for (std::size_t i = 0; i <= 8; ++i) {
      std::cout << "fish " << i << " #=" << data[i] << "\n";
    }
    std::cout << "\n";
  }

private:
  Container data;
};

} // namespace Lanternfish

#endif // _2021_6_LANTERNFISH_H_
