#ifndef CHARACTER_H
#define CHARACTER_H
#include "abstractcontroller.h"
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
    Input move(char input);
    Input getMoveDirection() const;
    void setMoveDirection(const Input& newMoveDirection);

private:
    std::string texture;
    Tile* currentTile;
    AbstractController* abController;
    Input moveDirection;
};

#endif // CHARACTER_H
