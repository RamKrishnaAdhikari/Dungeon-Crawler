#ifndef SWITCH_H
#define SWITCH_H
#include"tile.h"
#include"active.h"

class Switch : public Tile  , public active
{
public:
    Switch(const std:: string& texture, int row , int column);
    std::pair<bool,Tile*> onEnter(Character* who);
    void switchauslösen();


};

#endif // SWITCH_H
