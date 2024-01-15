#ifndef READWRITE_H
#define READWRITE_H

#include <memory>
#include <vector>

#include "figures.h"

namespace ch {

class Reader {

public:
  Reader() = default;
  virtual ~Reader() = default;

  std::vector<std::shared_ptr<Figure>> Read(const std::string &filename) const;

protected:
};

} // namespace ch

#endif // READWRITE_H