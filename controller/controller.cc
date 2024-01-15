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
      view_->ShowMessage("Input error");
      continue;
    }

    try {
      view_->Output(points);
    } catch (...) {
      view_->ShowMessage("Output error");
      continue;
    }

    try {
      board_->ArrangeFigures(points);
      for (auto &chop : board_->GetAllChops()) {
        view_->ShowMessage(chop);
      }
    } catch (...) {
      view_->ShowMessage("Internal error");
      continue;
    }
  }
}

}  // namespace ch