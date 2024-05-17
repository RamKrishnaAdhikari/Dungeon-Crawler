#ifndef CHARACTER_H
#define CHARACTER_H
#include "abstractui.h"
#include "input.h"
#include <string>

class Tile;

class Character
{
public:
    Character(const std::string& texture);

    std::string getTexture() const;
    void setCurrentTile(Tile* tile);
    Tile* getCurrentTile() const;
    Input move();

 private:
    std::string texture;
    Tile* currentTile;
    AbstractUI* ui;
};

#endif // CHARACTER_H
