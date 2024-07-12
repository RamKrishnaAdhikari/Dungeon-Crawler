#include "wall.h"

<<<<<<< HEAD
Wall::Wall(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/wall/wall1.png"));
}

std::string Wall::getTexture() const
{
    if(hasCharacter())
    {
        return "X";
    }
    return Tile::getTexture();
}

bool Wall::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*> Wall::onEnter(Character* who)
{
    return{false,nullptr};
}

QPixmap* Wall::getTex_ui() const
{
    return Tile::getTex_ui();
}
=======
Wall::Wall(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Wall::onEnter(Character* who)
{
    return {false, nullptr};
}


>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
