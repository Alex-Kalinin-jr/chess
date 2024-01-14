#include "board.h"

#include <algorithm>
#include <string>
#include <vector>

#include "figures.h"

namespace ch {
std::vector<std::string> Board::GetAllChops() const {
  std::vector<std::string> answ;
  for (const auto &figure : figures_) {
    figure->ComputePoints();
    auto points = figure->GetPoints();
    for (const auto &target : figures_) {
      if (std::find(points.begin(), points.end(), target->GetCoords()) !=
          points.end()) {
        answ.push_back(figure->WhoAmI() + " -> " + target->WhoAmI());
      }
    }
  }
  return answ;
}
} // namespace ch
