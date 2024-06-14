#ifndef RAMP_H
#define RAMP_H
#include "tile.h"

class Ramp : public Tile
{
 public:
    Ramp(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool onLeave(Tile* destTile, Character* who) override;
};

#endif // RAMP_H
