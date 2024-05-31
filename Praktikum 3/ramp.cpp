#include "ramp.h"

ramp::ramp(const std:: string& texture, int row, int column):
    Tile(texture,row,column)
{}

std::pair<bool, Tile*> ramp:: onEnter(Character* who){
    return {true,nullptr};
}
