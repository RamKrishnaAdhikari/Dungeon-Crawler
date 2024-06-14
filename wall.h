#ifndef WALL_H
#define WALL_H
#include "tile.h"

class Wall : virtual public Tile
{
 public:
    Wall(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
};

#endif // WALL_H

