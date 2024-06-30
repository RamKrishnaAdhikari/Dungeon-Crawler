#include "tile.h"
#include "random.h"
Tile::Tile(const std::string& texture, int row, int column):portalType(0), floor_tileType(getRandom(1,5)), texture(texture), character(nullptr), row(row), col(column)
{

}

std::string Tile::getTexture() const
{
    return texture;
}



bool Tile::hasCharacter() const
{
    if(character!=nullptr){
        return true;
    }
    return false;
}

bool Tile::moveTo(Tile *destTile, Character *who)
{
    std::pair<bool, Tile*> tempEnter = destTile->onEnter(who);
    bool tempLeave = this->onLeave(destTile, who);

    if(tempLeave)
    {
        if(tempEnter.first)
        {
            if(tempEnter.second==nullptr){
                destTile->setCharacter(who);
                this->setCharacter(nullptr);
                who->setCurrentTile(destTile);
                return true;
            }
            else{
                if(tempEnter.second->getTexture() == "O"){
                    Tile* por_dest = tempEnter.second;
                    por_dest->setCharacter(who);
                    this->setCharacter(nullptr);
                    who->setCurrentTile(por_dest);
                    return true;
                }
                if(tempEnter.second->getTexture() == "&"){
                    Tile* por_dest = tempEnter.second;
                    por_dest->setCharacter(who);
                    this->setCharacter(nullptr);
                    who->setCurrentTile(por_dest);

                    return true;
                }
            }
        }
    }
    return false;
}

bool Tile::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Tile::onEnter(Character *who)
{
    if(this->hasCharacter()){
        Character* present_char = this->getCharacter();
        if(!who->isHuman() && !present_char->isHuman()){
            return {false, nullptr};
        }
        if(present_char->getHitpoints() - who->getStrength() <= 0){
            present_char->setAlive(false);
        }
        else{
            present_char->setHitpoints(present_char->getHitpoints() - who->getStrength());
            if(who->getHitpoints() - present_char->getStrength() <= 0){
                who->setAlive(false);
            }
            else{
                who->setHitpoints(who->getHitpoints() - present_char->getStrength());
            }
            return {false, nullptr};
        }
    }
    return {true,nullptr};
}

Character *Tile::getCharacter() const
{
    return character;
}

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getCol() const
{
    return col;
}

int Tile::getPortaltype() const
{
    return portalType;
}

void Tile::setPortaltype(int newPortaltype)
{
    portalType = newPortaltype;
}

int Tile::getFloor_tiletype() const
{
    return floor_tileType;
}

void Tile::setFloor_tiletype(int newFloor_tiletype)
{
    floor_tileType = newFloor_tiletype;
}
