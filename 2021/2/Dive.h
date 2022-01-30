#ifndef DIVE_H
#define DIVE_H

#include <sstream>
#include <string>
#include <vector>

namespace Dive {

class CommandProcessor {
public:
  virtual ~CommandProcessor();

  int process(const std::vector<std::string> &lines);

protected:
  virtual void forward(int x) = 0;
  virtual void down(int x) = 0;
  virtual void up(int x) = 0;
  virtual int result() const = 0;
};

int horizontalPosDepth(const std::vector<std::string> &lines);
int horizontalPosDepthAim(const std::vector<std::string> &lines);

} // namespace Dive

#endif // DIVE_H
