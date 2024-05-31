#include "switch.h"


Switch:: Switch(const std:: string& texture, int row , int column):
    Tile(texture, row, column), active(){}
std::pair<bool,Tile*> Switch::onEnter(Character* who){
    return {true, nullptr};
}

void Switch :: switchauslösen(){   
        activate();
}
