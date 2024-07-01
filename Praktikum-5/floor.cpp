#include "floor.h"

Floor::Floor(const std::string& texture, int row, int column) : Tile(texture, row, column)
{}

std::string Floor::getTexture() const
{
    return Tile::getTexture();
}

bool Floor::onLeave(Tile *destTile, Character *who)
{
    return true;
}

std::pair<bool, Tile *> Floor::onEnter(Character *who)
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













