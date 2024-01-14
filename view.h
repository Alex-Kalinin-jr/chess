#ifndef VIEV_H
#define VIEV_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>

#include "figures.h"

namespace ch {
class View {
public:
  View() {}
  void output(std::vector<std::shared_ptr<Figure>> &points) const;
};
} // namespace ch

#endif // VIEV_H