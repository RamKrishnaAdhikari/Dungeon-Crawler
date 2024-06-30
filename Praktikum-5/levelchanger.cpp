#include "levelchanger.h"
#include "level.h"

Levelchanger::Levelchanger(int row, int col, std::string texture):Portal(row, col, texture)
{

}

std::pair<bool, Tile *> Levelchanger::onEnter(Character *who)
{
    return {true, destination_levelchanger};
}

Levelchanger *Levelchanger::getDestination() const
{
    return destination_levelchanger;
}

void Levelchanger::setDestination(Levelchanger *newDestination_level)
{
    destination_levelchanger = newDestination_level;
}

Level *Levelchanger::getLevel_dest() const
{
    return level_destination;
}

void Levelchanger::setLevel_dest(Level *newLevel_dest)
{
    level_destination = newLevel_dest;
}
