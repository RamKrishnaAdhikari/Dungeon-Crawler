#include "pit.h"

<<<<<<< HEAD
Pit::Pit(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/pit.png"));
}

std::string Pit::getTexture() const
{
    return Tile::getTexture();
=======
Pit::Pit(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::pair<bool, Tile*> Pit::onEnter(Character* who)
{
    return {true, nullptr};
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

bool Pit::onLeave(Tile* destTile, Character* who)
{
<<<<<<< HEAD
    auto tmp = destTile->getTexture();
    if(tmp == "_" || tmp == "<")
    {
        return true;
    }
    return false;
}

std::pair<bool, Tile*> Pit::onEnter(Character* who)
{
    return Tile::onEnter(who);
}

QPixmap* Pit::getTex_ui() const
{
    return Tile::getTex_ui();
=======
    Ramp* rampDestination = dynamic_cast<Ramp*>(destTile);
    Pit* pitDestination = dynamic_cast<Pit*>(destTile);

    if (rampDestination != nullptr || pitDestination != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
