#include "pit.h"

Pit::Pit(int row, int col, std::string texture): Tile( texture,row, col)
{

}

std::string Pit::getTexture() const
{
    return Tile::getTexture();
}

bool Pit::onLeave(Tile *destTile, Character *who)
{
    if(destTile->getTexture()=="_" || destTile->getTexture()== "<"){
        return true;
    }
    return false;
}

std::pair<bool, Tile *> Pit::onEnter(Character *who)
{
    return {true, nullptr};
}
