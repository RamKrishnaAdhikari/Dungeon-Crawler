#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"

class Tile
{


public:
    virtual ~Tile() = default;
    virtual std::string getTexture() const;


     virtual Character *getCharacter() const;
     virtual void setCharacter(Character *newCharacter);
     int getRow() const;
     int getCol() const;

    virtual bool hasCharacter() const;
    virtual bool moveTo(Tile* destTile, Character* who);
    virtual bool onLeave(Tile* destTile, Character* who);
    virtual std::pair<bool, Tile*> onEnter(Character* who);

    virtual int getPortaltype() const;
    virtual void setPortaltype(int newPortaltype);
    virtual int getFloor_tiletype() const;
    virtual void setFloor_tiletype(int newFloor_tiletype);
    protected:
              Tile(const std::string& texture, int row, int column);
private:
    int portalType;
    int floor_tileType;

    std::string texture;
    Character* character;
    const int row;
    const int col;
};

#endif // TILE_H



