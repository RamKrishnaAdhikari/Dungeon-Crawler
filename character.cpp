#include "character.h"

Character::Character(const std::string& texture) : texture(texture),
    currentTile(nullptr)
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

Input Character::move()
{
    if (ui != nullptr)
    {
        return ui->move();
    }
    else
    {
        return Input(0, 0, false);
    }
}
