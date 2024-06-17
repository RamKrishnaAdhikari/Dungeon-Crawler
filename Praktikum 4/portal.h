#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
public:
    Portal(const std::string& texture, int row, int column,int portaltype);
    void setDestination(Portal* newDestination);

    std::pair<bool, Tile*> onEnter(Character* who) override;
    int getportaltype()const ;

private:
    Portal* destination;
    int portaltype ;

};

#endif // PORTAL_H
