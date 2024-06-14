#include "tile.h"
#include "character.h"

Tile::Tile(const std::string& texture, int row, int column) : texture(texture),
    character(nullptr),
    row(row),
    column(column)
{}

void Tile::setTexture(const std::string& newTexture)
{
    texture = newTexture;
}

void Tile::setCharacter(Character* newCharacter)
{
    character = newCharacter;
}

Character* Tile::getCharacter() const
{
    return character;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getColumn() const
{
    return column;
}

std::string Tile::getTexture() const
{
    return texture;
}

bool Tile::hasCharacter() const
{
    if (character != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Tile::moveTo(Tile* destTile, Character* who)
{
    if (this->onLeave(destTile, who))
    {
        std::pair<bool, Tile*> result = destTile->onEnter(who);
        if (result.first)
        {
            if (result.second == nullptr)
            {
                destTile->setCharacter(who);
                this->setCharacter(nullptr);
                who->setCurrentTile(destTile);
                return true;
            }
            else
            {
                Tile* portalDestination = destTile->onEnter(who).second;
                portalDestination->setCharacter(who);
                this->setCharacter(nullptr);
                who->setCurrentTile(portalDestination);
                return true;
            }
        }
    }
    return false;
}

bool Tile::onLeave(Tile* destTile, Character* who)
{
    return true;
}




