#ifndef RAMP_H
#define RAMP_H
#include"tile.h"

class ramp : public Tile
{
public:
    ramp(const std :: string& texture, int row, int column );
    std::pair<bool, Tile*> onEnter(Character* who)override;
};

#endif // RAMP_H
