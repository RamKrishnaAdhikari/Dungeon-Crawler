#include "floor.h"

    Floor::Floor(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Floor::onEnter(Character *who)
{
    return {true, nullptr};
}

