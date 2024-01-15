#include "readwrite.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "figures.h"

namespace ch {

std::vector<std::shared_ptr<Figure>> Reader::Read(
    const std::string &filename) const {
  auto answ = std::vector<std::shared_ptr<Figure>>();
  auto file = std::ifstream(filename, std::ios::in);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file");
  } else {
    std::string line;
    while (std::getline(file, line)) {
      std::string name;
      int row = -1;
      int col = -1;
      std::istringstream linestream(line);
      if (!(linestream >> name)) {
        continue;
      }
      if (!(linestream >> row) || row < 0 || row > 7) {
        continue;
      }
      if (!(linestream >> col) || col < 0 || col > 7) {
        continue;
      }

      if (name == "king") {
        answ.push_back(std::make_shared<King>(col, row));
      } else if (name == "rook") {
        answ.push_back(std::make_shared<Rook>(col, row));
      } else if (name == "bishop") {
        answ.push_back(std::make_shared<Bishop>(col, row));
      } else if (name == "queen") {
        std::shared_ptr<Rook> rook = std::make_shared<Queen>(col, row);
        answ.push_back(std::static_pointer_cast<Figure>(rook));
      } else if (name == "knight") {
        answ.push_back(std::make_shared<Knight>(col, row));
      }
    }
    file.close();
  }
  return answ;
}

}  // namespace ch
