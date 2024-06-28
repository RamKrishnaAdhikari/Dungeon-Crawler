#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
public:
    Portal(int row, int col, std::string texture);
    virtual ~Portal() = default;
    std::string getTexture() const override;
    bool onLeave(Tile *destTile, Character *who) override;
    std::pair<bool, Tile *> onEnter(Character *who) override;
    Portal *getDestination() const;
    void setDestination(Portal *newDestination);
    int getPortaltype() const override;
    void setPortaltype(int newPortaltype) override;

private:
    Portal* destination;
};

#endif // PORTAL_H
