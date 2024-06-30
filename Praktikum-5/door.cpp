#include "door.h"

Door::Door( int row, int col,const std::string& texture) : Tile(texture,row,col),Passive()

{
    Open-=false;
}

std::string Door::getTexture() const
{
    if(Open){
        return "\\";
    }
    else{
        return Tile::getTexture();
    }
}

bool Door::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Door::onEnter(Character *who)
{
    if(Open){
        return {true, nullptr};
    }
    return {false, nullptr};
}

void Door::notify()
{
    Open = !(Open);
}

bool Door::getOpen() const
{
    return Open;
}







