#ifndef DOOR_H
#define DOOR_H
#include"tile.h"
#include"passive.h"

class door: public Tile, public passive
{
public:
    door(const std:: string& texture , int row, int column);
    std:: pair<bool,Tile*> onEnter(Character* who)override;
    void notify()override;
    void settexture();
private :
    bool opened;

};

#endif // DOOR_H
