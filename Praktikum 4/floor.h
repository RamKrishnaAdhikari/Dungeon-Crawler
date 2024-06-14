#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"

class Floor : virtual public Tile
{
 public:
    Floor(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
};

#endif // FLOOR_H
