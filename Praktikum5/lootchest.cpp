#include "lootchest.h"

Lootchest::Lootchest(int row, int col, std::string texture): Tile(texture,row, col)
{

}

std::string Lootchest::getTexture() const
{
    return Tile::getTexture();
}

bool Lootchest::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Lootchest::onEnter(Character *who)
{
    return {who->isHuman(), nullptr};
}
