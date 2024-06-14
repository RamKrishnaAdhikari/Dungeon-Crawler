#include "pit.h"

Pit::Pit(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Pit::onEnter(Character* who)
{
    return {true, nullptr};
}

bool Pit::onLeave(Tile* destTile, Character* who)
{
    Ramp* rampDestination = dynamic_cast<Ramp*>(destTile);
    Pit* pitDestination = dynamic_cast<Pit*>(destTile);

    if (rampDestination != nullptr || pitDestination != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
