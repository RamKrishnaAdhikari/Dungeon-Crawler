#include "portal.h"

Portal::Portal(int row, int col, std::string texture) : Tile( texture,row, col), destination(nullptr)
{}

std::string Portal::getTexture() const
{
    return Tile::getTexture();
}

bool Portal::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Portal::onEnter(Character *who)
{
    return {true, destination};
}

Portal *Portal::getDestination() const
{
    return destination;
}

void Portal::setDestination(Portal *newDestination)
{
    destination = newDestination;
}

int Portal::getPortaltype() const
{
    return Tile::getPortaltype();
}

void Portal::setPortaltype(int newPortaltype)
{
    Tile::setPortaltype(newPortaltype);
}
