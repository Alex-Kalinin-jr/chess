#include "gtest/gtest.h"

#include "lib/board.h"
#include "lib/readwrite.h"
#include "view/view.h"

namespace ch {

TEST(figure, create2) { EXPECT_ANY_THROW(King k(8, 8)); }

TEST(figure, create3) { EXPECT_ANY_THROW(King k(-1, 8)); }

TEST(figure, create4) { EXPECT_ANY_THROW(King k(1, -1)); }

TEST(figure, create5) { EXPECT_ANY_THROW(King k(1, -1)); }

TEST(king, compute1) {
  King k(0, 0);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{1, 0}, {1, 1}, {0, 1}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(king, compute2) {
  King k(1, 0);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{2, 0}, {2, 1}, {1, 1}, {0, 1}, {0, 0}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(king, compute3) {
  King k(7, 7);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{6, 7}, {6, 6}, {7, 6}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(king, compute4) {
  King k(5, 5);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{4, 5}, {4, 4}, {5, 4}, {6, 4},
                                     {6, 5}, {6, 6}, {5, 6}, {4, 6}};
  ASSERT_EQ(k.GetPoints(), answ);
  ASSERT_EQ(k.WhoAmI(), "King: f6");
}

TEST(rook, compute1) {
  Rook k(0, 1);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6},
                                     {0, 7}, {0, 0}, {1, 1}, {2, 1}, {3, 1},
                                     {4, 1}, {5, 1}, {6, 1}, {7, 1}};
  ASSERT_EQ(k.GetPoints(), answ);
  ASSERT_EQ(k.WhoAmI(), "Rook: b1");
}

TEST(rook, compute2) {
  Rook k(4, 4);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{
      {5, 4}, {6, 4}, {7, 4}, {3, 4}, {2, 4}, {3, 4}, {2, 4}, {1, 4},
      {0, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 5}, {4, 6}, {4, 7}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(bishop, compute) {
  Bishop k(4, 4);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{3, 3}, {2, 2}, {1, 1}, {0, 0}, {5, 5},
                                     {6, 6}, {7, 7}, {5, 3}, {6, 2}, {7, 1},
                                     {3, 5}, {2, 6}, {1, 7}};
  ASSERT_EQ(k.GetPoints(), answ);
  ASSERT_EQ(k.WhoAmI(), "Bishop: e5");
}

TEST(bishop, compute2) {
  Bishop k(1, 2);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{0, 1}, {0, 3}, {2, 1}, {3, 0}, {2, 3},
                                     {3, 4}, {4, 5}, {5, 6}, {6, 7}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(knight, compute) {
  Knight k(1, 2);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{0, 0}, {2, 0}, {3, 1},
                                     {3, 3}, {2, 4}, {0, 4}};
  ASSERT_EQ(k.GetPoints(), answ);
  ASSERT_EQ(k.WhoAmI(), "Knight: c2");
}

TEST(knight, compute2) {
  Knight k(5, 5);
  k.ComputePoints();
  std::set<std::pair<int, int>> answ{{3, 4}, {3, 6}, {4, 3}, {4, 7},
                                     {6, 3}, {6, 7}, {7, 4}, {7, 6}};
  ASSERT_EQ(k.GetPoints(), answ);
}

TEST(board, create) {
  Board b;
  std::shared_ptr<Figure> king = std::make_shared<King>(0, 0);
  b.AddFigure(king);
}

TEST(board, compute1) {
  Board b;
  std::shared_ptr<Figure> king = std::make_shared<King>(0, 0);
  b.AddFigure(king);
  std::shared_ptr<Figure> rook = std::make_shared<Rook>(1, 0);
  b.AddFigure(rook);
  std::shared_ptr<Figure> knight = std::make_shared<Knight>(4, 4);
  b.AddFigure(knight);
  std::vector<std::string> answs = b.GetAllChops();
}

} // namespace ch

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
