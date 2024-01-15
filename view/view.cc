#include "view.h"

#include <iostream>
#include <map>

#include "../lib/figures.h"

namespace ch {

void View::Output(std::vector<std::shared_ptr<Figure>> &points) const {
  for (int i = 7; i >= 0; --i) {
    for (int j = 0; j < 8; ++j) {
      bool flag = false;
      for (auto &figure : points) {
        if (figure->GetCoords() == std::make_pair(i, j)) {
          std::cout << figure->MyAbbreviation();
          flag = true;
        }
      }
      if (!flag) {
        std::cout << "_";
      }
      std::cout << "|";
    }
    std::cout << std::endl;
  }
}

std::string View::Input() const {
  std::cout << "Enter filename (0 - exit)" << std::endl;
  std::string filename;
  std::cin >> filename;
  return filename;
}

} // namespace ch