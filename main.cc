#include "controller/controller.h"
#include "lib/board.h"
#include "view/view.h"

int main() {
  auto board = std::make_shared<ch::Board>();
  auto view = std::make_shared<ch::View>();
  auto reader = std::make_shared<ch::Reader>();
  ch::Controller controller{board, view, reader};
  controller.Start();
  return 0;
}