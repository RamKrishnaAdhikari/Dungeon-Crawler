#ifndef PIT_H
#define PIT_H
#include "tile.h"
#include "ramp.h"

class Pit : public Tile
{
 public:
    Pit(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool onLeave(Tile* destTile, Character* who) override;
};

#endif // PIT_H
