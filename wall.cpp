#include "wall.h"

Wall::Wall(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Wall::onEnter(Character* who)
{
    return {false, nullptr};
}


