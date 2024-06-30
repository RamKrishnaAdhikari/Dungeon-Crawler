#include "character.h"
#include "stationerycontroller.h"
#include "guardiancontroller.h"
#include "tile.h"

Character::Character(std::string texture, int strength, int stamina, bool ishuman):texture(texture), currentTile(nullptr), moveDirection(down),  strength(strength), stamina(stamina),hitpoints(getMaxHP()),ishuman(ishuman),alive(true) {
    if (!ishuman)
    {
        if (texture == "1")
        {
            abController = new StationeryController();
        }
        if (texture == "2")
        {
            abController = new GuardianController();
        }
    }
}

Character::~Character()
{

}

std::string Character::getTexture() const
{
    return texture;
}

Input_gui Character::move()
{
    return abController->move();
}

Tile *Character::getCurrentTile() const
{
    return currentTile;
}

void Character::setCurrentTile(Tile *tile)
{
    currentTile = tile;
}

void Character::setMoveDirection(Input_gui newMoveDirection)
{
    moveDirection = newMoveDirection;
}

Input_gui Character::getMoveDirection() const
{
    return moveDirection;
}

bool Character::isHuman() const
{
    return ishuman;
}

int Character::getMaxHP()
{
    return 20+(this->stamina*5);
}

int Character::getStrength() const
{
    return strength;
}

void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

int Character::getStamina() const
{
    return stamina;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}

void Character::setAlive(bool newAlive)
{
    alive = newAlive;
}

bool Character::isAlive() const
{
    return alive;
}
