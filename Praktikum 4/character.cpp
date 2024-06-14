#include "character.h"

Character::Character(const std::string& texture) : texture(texture),
    currentTile(nullptr), abController(nullptr), moveDirection(Input(0, 1, false))
{}

std::string Character::getTexture() const
{
    return texture;
}

void Character::setCurrentTile(Tile* tile)
{
    currentTile = tile;
}

Tile* Character::getCurrentTile() const
{
    return currentTile;
}

Input Character::move(char input)
{
    return abController->move(input);
}

Input Character::getMoveDirection() const
{
    return moveDirection;
}

void Character::setMoveDirection(const Input& newMoveDirection)
{
    moveDirection = newMoveDirection;
}
