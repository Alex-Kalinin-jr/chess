#include <set>

namespace ch {

class Figure {
public:
  Figure(int x, int y);
  virtual ~Figure() = default;
  void set_coords(int x, int y);
  virtual void ComputePoints() = 0;
  std::set<std::pair<int, int>> GetPoints() const { return points_; }

protected:
  int row_;
  int col_;
  std::set<std::pair<int, int>> points_;
};

class King : public Figure {
public:
  King(int x, int y) : Figure(x, y) {}
  void ComputePoints() override;

protected:
  void Compute();
};

class Rook : public Figure {
public:
  Rook(int x, int y) : Figure(x, y) {}
  void ComputePoints() override;

protected:
  void Compute();
};

class Bishop : public Figure {
public:
  Bishop(int x, int y) : Figure(x, y) {}
  void ComputePoints() override;

protected:
  void Compute();
};

class Queen : virtual public Rook, public Bishop {
public:
  Queen(int x, int y) : Rook(x, y), Bishop(x, y) {}
  void ComputePoints() override;

protected:
  void Compute();
};

class Knight : public Figure {
public:
  Knight(int x, int y) : Figure(x, y) {}
  void ComputePoints() override;

protected:
  void Compute();
};

} // namespace ch