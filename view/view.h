#ifndef VIEV_H
#define VIEV_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>

#include "../lib/figures.h"

namespace ch {
class View {
 public:
  View() {}
  std::string Input() const;
  void ShowMessage(const std::string &message) const;
  void Output(const std::vector<std::shared_ptr<Figure>> &points) const;

 private:
  bool OutputFig(int i, int j,
                 const std::vector<std::shared_ptr<Figure>> &points) const;
};
}  // namespace ch

#endif  // VIEV_H