#include "view.h"

#include <algorithm>
#include <iostream>
#include <map>

#include "../lib/figures.h"

namespace ch {

void View::Output(const std::vector<std::shared_ptr<Figure>>& points) const {
  for (int i = 7; i >= 0; --i) {
    for (int j = 0; j < 8; ++j) {
      if (!OutputFig(i, j, points)) {
        std::cout << "_";
      }
      std::cout << "|";
    }
    std::cout << std::endl;
  }
}

bool View::OutputFig(int i, int j,
                     const std::vector<std::shared_ptr<Figure>>& points) const {
  auto it = std::find_if(points.begin(), points.end(), [&](const auto& figure) {
    return figure->GetCoords() == std::make_pair(i, j);
  });

  if (it != points.end()) {
    std::cout << (*it)->MyAbbreviation();
    return true;
  }

  return false;
}

std::string View::Input() const {
  std::cout << "Enter filename (0 - exit)" << std::endl;
  std::string filename;
  std::cin >> filename;
  return filename;
}

void View::ShowMessage(const std::string& message) const {
  std::cout << message << std::endl;
}

}  // namespace ch