#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include <set>
#include <vector>

#include "figures.h"

namespace ch {

class Board {
public:
  Board() = default;
  ~Board() = default;

  void AddFigure(std::shared_ptr<Figure> figure) { figures_.push_back(figure); }
  std::vector<std::shared_ptr<Figure>> GetFigures() const { return figures_; }
  std::vector<std::string> GetAllChops() const;

private:
  std::vector<std::shared_ptr<Figure>> figures_;
};

} // namespace ch

#endif // BOARD_H