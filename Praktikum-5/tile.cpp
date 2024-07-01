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
    if (this->hasCharacter()) {
        Character* defender = this->getCharacter();

        // Combat logic
        int damage_to_defender = std::min(defender->getHitpoints(), who->getStrength());
        int damage_to_attacker = std::min(who->getHitpoints(), defender->getStrength());

        defender->setHitpoints(defender->getHitpoints() - damage_to_defender);
        who->setHitpoints(who->getHitpoints() - damage_to_attacker);

        if (defender->getHitpoints() <= 0) {
            defender->die();
            return {true, nullptr}; // Allow movement if defender dies
        }

        if (who->getHitpoints() <= 0) {
            who->die();
        }
        return {false, nullptr}; // Prevent movement after combat
    }
    return {true, nullptr};
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
void Tile::removeCharacter() {
    character = nullptr;
}
