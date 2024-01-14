#include "figures.h"

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
void Queen::ComputePoints() {
  Rook::points_.clear();
  Rook::Compute();
  Bishop::Compute();
}
////////////////////////////////////////////////////////////////////////////////
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
} // namespace ch
