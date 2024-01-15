#include "controller.h"

#include <iostream>
#include <vector>

namespace ch {
void Controller::Start() const {
  std::vector<std::shared_ptr<Figure>> points;
  while (true) {
    try {
      std::string filename = view_->Input();
      if (filename == "0") {
        return;
      }
      points = reader_->Read(filename);
    } catch (...) {
      std::cout << "Input error" << std::endl;
      continue;
    }
    try {
      view_->Output(points);
    } catch (...) {
      std::cout << "Output error" << std::endl;
      continue;
    }
  }
}
} // namespace ch