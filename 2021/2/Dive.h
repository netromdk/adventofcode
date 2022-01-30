#ifndef DIVE_H
#define DIVE_H

#include <sstream>
#include <string>
#include <vector>

namespace Dive {

class CommandProcessor {
public:
  int process(const std::vector<std::string> &lines)
  {
    for (const auto &line : lines) {
      std::stringstream ss(line);
      std::string cmd;
      int mod = 0;
      ss >> cmd >> mod;
      if (cmd == "forward") {
        forward(mod);
      }
      else if (cmd == "down") {
        down(mod);
      }
      else if (cmd == "up") {
        up(mod);
      }
    }
    return result();
  }

protected:
  virtual void forward(int x) = 0;
  virtual void down(int x) = 0;
  virtual void up(int x) = 0;
  virtual int result() const = 0;
};

int horizontalPosDepth(const std::vector<std::string> &lines)
{
  class Proc : public CommandProcessor {
  protected:
    void forward(int x) override
    {
      pos += x;
    }

    void down(int x) override
    {
      depth += x;
    }

    void up(int x) override
    {
      depth -= x;
    }

    int result() const override
    {
      return pos * depth;
    }

    int pos = 0;
    int depth = 0;
  };
  return Proc().process(lines);
}

int horizontalPosDepthAim(const std::vector<std::string> &lines)
{
  class Proc : public CommandProcessor {
  protected:
    void forward(int x) override
    {
      pos += x;
      depth += aim * x;
    }

    void down(int x) override
    {
      aim += x;
    }

    void up(int x) override
    {
      aim -= x;
    }

    int result() const override
    {
      return pos * depth;
    }

    int pos = 0;
    int depth = 0;
    int aim = 0;
  };
  return Proc().process(lines);
}

} // namespace Dive

#endif // DIVE_H
