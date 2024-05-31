#include "door.h"

door::door(const std :: string& texture, int row, int column):
    Tile(texture,row, column),passive(),opened(false)
{}

std:: pair<bool,Tile*> door::onEnter(Character* who){
    if(opened){
        return{true,nullptr};
    }
    else{
        return {false ,nullptr};
    }
}
void door:: notify(){
    opened = !opened;
    settexture();
}
void door:: settexture(){
    if(opened){
        setTexture("/");
    }
    else{
        setTexture("X");
    }
}
