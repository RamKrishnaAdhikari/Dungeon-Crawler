#include "portal.h"

Portal::Portal(const std::string& texture, int row, int column) : Tile(texture, row, column), destination(nullptr)
{}

void Portal::setDestination(Portal* newDestination)
{
    destination = newDestination;
}

std::pair<bool, Tile*> Portal::onEnter(Character* who)
{
    return {true, destination};
}


