#include "pit.h"
#include"ramp.h"

pit::pit(const std:: string& texture, int row, int column):
    Tile(texture,row,column){}
std:: pair<bool, Tile*> pit::onEnter(Character* who){
    return {true, nullptr};
}
bool pit::onLeave (Tile* desttile , Character* who){
    auto* tile1 = dynamic_cast<pit*>(desttile);
    auto* tile2 = dynamic_cast<ramp*>(desttile);
    if(tile1 != nullptr || tile2 !=nullptr){
        return true;
    }
    else{
        return false;
    }

}
