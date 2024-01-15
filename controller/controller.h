#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../lib/board.h"
#include "../lib/readwrite.h"
#include "../view/view.h"

namespace ch {

class Controller {
public:
  Controller(std::shared_ptr<ch::Board> board, std::shared_ptr<ch::View> view,
             std::shared_ptr<ch::Reader> reader)
      : board_(board), view_(view), reader_(reader) {}
  ~Controller() = default;

  void Start() const;

private:
  std::shared_ptr<ch::Board> board_;
  std::shared_ptr<ch::View> view_;
  std::shared_ptr<ch::Reader> reader_;
};
} // namespace s21

#endif // CONTROLLER_H