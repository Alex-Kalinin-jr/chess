#include "figures.h"

#include <map>
#include <stdexcept>

namespace ch {

Figure::Figure(int x, int y) { set_coords(x, y); }

void Figure::set_coords(int x, int y) {
  if (x < 0 || y < 0 || x > 7 || y > 7) {
    throw std::invalid_argument("Invalid coordinates");
  }
  row_ = x;
  col_ = y;
}

////////////////////////////////////////////////////////////////////////////////
std::map<int, char> cols_map{
    {0, 'a'}, {1, 'b'}, {2, 'c'}, {3, 'd'},
    {4, 'e'}, {5, 'f'}, {6, 'g'}, {7, 'h'},
};
////////////////////////////////////////////////////////////////////////////////

std::string King::WhoAmI() const {
  std::string s = cols_map[col_] + std::to_string(row_ + 1);
  return "King: " + s;
}

std::string King::MyAbbreviation() const { return "K"; }

void King::ComputePoints() {
  points_.clear();
  Compute();
}

void King::Compute() {
  if ((row_ - 1) >= 0) {
    points_.insert({row_ - 1, col_});
    if ((col_ - 1) >= 0) {
      points_.insert({row_ - 1, col_ - 1});
    }
    if ((col_ + 1) <= 7) {
      points_.insert({row_ - 1, col_ + 1});
    }
  }
  if (col_ + 1 <= 7) {
    points_.insert({row_, col_ + 1});
  }
  if (col_ - 1 >= 0) {
    points_.insert({row_, col_ - 1});
  }
  if ((row_ + 1) <= 7) {
    points_.insert({row_ + 1, col_});
    if ((col_ - 1) >= 0) {
      points_.insert({row_ + 1, col_ - 1});
    }
    if ((col_ + 1) <= 7) {
      points_.insert({row_ + 1, col_ + 1});
    }
  }
}
////////////////////////////////////////////////////////////////////////////////
std::string Rook::WhoAmI() const {
  std::string s = cols_map[col_] + std::to_string(row_ + 1);
  return "Rook: " + s;
}

std::string Rook::MyAbbreviation() const { return "R"; }

void Rook::ComputePoints() {
  points_.clear();
  Compute();
}

void Rook::Compute() {
  int temp = row_ - 1;
  while (temp >= 0) {
    points_.insert({temp, col_});
    --temp;
  }
  temp = row_ + 1;
  while (temp <= 7) {
    points_.insert({temp, col_});
    ++temp;
  }
  temp = col_ - 1;
  while (temp >= 0) {
    points_.insert({row_, temp});
    --temp;
  }
  temp = col_ + 1;
  while (temp <= 7) {
    points_.insert({row_, temp});
    ++temp;
  }
}
////////////////////////////////////////////////////////////////////////////////
std::string Bishop::WhoAmI() const {
  std::string s = cols_map[col_] + std::to_string(row_ + 1);
  return "Bishop: " + s;
}

std::string Bishop::MyAbbreviation() const { return "B"; }

void Bishop::ComputePoints() {
  points_.clear();
  Compute();
}

void Bishop::Compute() {
  int temp = row_ - 1;
  int temp2 = col_ - 1;
  while (temp >= 0 && temp2 >= 0) {
    points_.insert({temp, temp2});
    --temp;
    --temp2;
  }
  temp = row_ + 1;
  temp2 = col_ + 1;
  while (temp <= 7 && temp2 <= 7) {
    points_.insert({temp, temp2});
    ++temp;
    ++temp2;
  }
  temp = row_ + 1;
  temp2 = col_ - 1;
  while (temp <= 7 && temp2 >= 0) {
    points_.insert({temp, temp2});
    ++temp;
    --temp2;
  }
  temp = row_ - 1;
  temp2 = col_ + 1;
  while (temp >= 0 && temp2 <= 7) {
    points_.insert({temp, temp2});
    --temp;
    ++temp2;
  }
}
////////////////////////////////////////////////////////////////////////////////
std::string Queen::WhoAmI() const {
  std::string s = cols_map[Rook::col_] + std::to_string(Rook::row_);
  return "Queen: " + s;
}

std::string Queen::MyAbbreviation() const { return "Q"; }

void Queen::ComputePoints() {
  Rook::points_.clear();
  Rook::Compute();
  Bishop::Compute();
}
////////////////////////////////////////////////////////////////////////////////
std::string Knight::WhoAmI() const {
  std::string s = cols_map[col_] + std::to_string(row_ + 1);
  return "Knight: " + s;
}

std::string Knight::MyAbbreviation() const { return "N"; }

void Knight::ComputePoints() {
  points_.clear();
  Compute();
}

void Knight::Compute() {
  if ((row_ - 2) >= 0 && (col_ - 1) >= 0) {
    points_.insert({row_ - 2, col_ - 1});
  }
  if ((row_ - 1) >= 0 && (col_ - 2) >= 0) {
    points_.insert({row_ - 1, col_ - 2});
  }
  if ((row_ - 2) >= 0 && (col_ + 1) <= 7) {
    points_.insert({row_ - 2, col_ + 1});
  }
  if ((row_ - 1) >= 0 && (col_ + 2) <= 7) {
    points_.insert({row_ - 1, col_ + 2});
  }
  if ((row_ + 1) <= 7 && (col_ - 2) >= 0) {
    points_.insert({row_ + 1, col_ - 2});
  }
  if ((row_ + 2) <= 7 && (col_ - 1) >= 0) {
    points_.insert({row_ + 2, col_ - 1});
  }
  if ((row_ + 2) <= 7 && (col_ + 1) <= 7) {
    points_.insert({row_ + 2, col_ + 1});
  }
  if ((row_ + 1) <= 7 && (col_ + 2) <= 7) {
    points_.insert({row_ + 1, col_ + 2});
  }
}
////////////////////////////////////////////////////////////////////////////////
}  // namespace ch
