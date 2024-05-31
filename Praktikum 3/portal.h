#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
public:
    Portal(const std::string& texture, int row, int column);
    void setDestination(Portal* newDestination);

    std::pair<bool, Tile*> onEnter(Character* who) override;

private:
    Portal* destination;
};

#endif // PORTAL_H
