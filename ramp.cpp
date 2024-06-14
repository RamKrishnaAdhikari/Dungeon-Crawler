#include "ramp.h"

Ramp::Ramp(const std::string &texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Ramp::onEnter(Character* who)
{
    return {true, nullptr};
}

bool Ramp::onLeave(Tile* destTile, Character* who)
{
    return true;
}
