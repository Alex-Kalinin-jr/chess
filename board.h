#include <set>
#include <vector>

#include "figures.h"

namespace ch {

class Board {
public:
    Board() = default;
    ~Board() = default;

    void AddFigure(Figure *figure) { figures_.push_back(figure); }
    
private:
    std::vector<Figure *> figures_;

};

} // ch