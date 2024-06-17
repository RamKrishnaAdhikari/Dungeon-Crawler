#include "portal.h"

Portal::Portal(const std::string& texture, int row, int column,int portaltype) : Tile(texture, row, column), destination(nullptr),portaltype(portaltype)
{}

void Portal::setDestination(Portal* newDestination)
{
    destination = newDestination;
}

std::pair<bool, Tile*> Portal::onEnter(Character* who)
{
    return {true, destination};
}


int Portal:: getportaltype()const{
    return portaltype;
}
