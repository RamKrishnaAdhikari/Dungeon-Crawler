#include "switch.h"

<<<<<<< HEAD
Switch::Switch(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/switch.png"));
}

std::string Switch::getTexture() const
{
    return Tile::getTexture();
}

bool Switch::onLeave(Tile* destTile, Character* who)
{
    if(destTile->getTexture()=="_")
    {
        return false;
    }
    return true;
}
=======
Switch::Switch(const std::string& texture, int row, int column) : Tile(texture, row, column), Floor(texture, row, column), Active()
{}
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d

std::pair<bool, Tile*> Switch::onEnter(Character* who)
{
    this->activate();
<<<<<<< HEAD
    return{true, nullptr};
}

QPixmap* Switch::getTex_ui() const
{
    return Tile::getTex_ui();
=======
    return {true, nullptr};
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
