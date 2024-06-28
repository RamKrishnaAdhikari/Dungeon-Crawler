#ifndef DOOR_H
#define DOOR_H
#include "tile.h"
#include "passive.h"

class Door: public Tile, public Passive
{
public:
    Door(int row, int col,const  std::string &texture);

    std::string getTexture() const override;
    bool onLeave(Tile *destTile, Character *who) override;
    std::pair<bool, Tile *> onEnter(Character *who) override;

    void notify() override;

    bool getOpen() const;


private:
    bool Open;
};

#endif // DOOR_H
