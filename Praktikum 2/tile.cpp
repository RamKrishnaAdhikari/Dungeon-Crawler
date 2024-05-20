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
    if (character != nullptr)
    {
        return character->getTexture();
    }
    else
    {
        return texture;
    }
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
    if(destTile->getTexture()!="#"){
        std::pair<bool, Tile *> dest_Pair=destTile->onEnter(who);
        if(onLeave(destTile,who)==true && dest_Pair.first==true) {
            if(dest_Pair.second!=nullptr)
            {
                this->setCharacter(nullptr);
                dest_Pair.second->setCharacter(who);
                who->setCurrentTile(dest_Pair.second);
                return true;

            }
            this->setCharacter(nullptr);
            destTile->setCharacter(who);
            who->setCurrentTile(destTile);
            return true;
        }
    }
    return false;
}

bool Tile::onLeave(Tile* destTile, Character* who)
{
    return true;
}




