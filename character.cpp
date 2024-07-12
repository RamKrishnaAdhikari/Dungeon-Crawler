<<<<<<< HEAD


#include "character.h"
#include "stationarycontroller.h"
#include "guardiancontroller.h"
#include "tile.h"

Character::Character(std::string texture, int strength, int stamina, bool hum):
    texture(texture),
    char_tile(nullptr),
    moveDirection(down),
    human(hum),
    strength(strength),
    stamina(stamina),
    hitpoints(getMaxHP()),
    alive(true)
{
    if(!human)
    {
        if(texture == "1"){
            abstrCon = new StationaryController();
        }
        if(texture == "2"){
            abstrCon = new GuardianController("66444466");
        }
        if(texture == "3"){
            abstrCon = new GuardianController("2288664444668822");
        }
    }
}

Character::~Character()
=======
#include "character.h"

Character::Character(const std::string& texture) : texture(texture),
    currentTile(nullptr), abController(nullptr), moveDirection(Input(0, 1, false))
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
{}

std::string Character::getTexture() const
{
    return texture;
}

<<<<<<< HEAD
Input_gui Character::move()
{
    return abstrCon->move();
}

Tile* Character::getChar_tile() const
{
    return char_tile;
}

void Character::setChar_tile(Tile* newChar_tile)
{
    char_tile = newChar_tile;
}

void Character::setMoveDirection(Input_gui newMoveDirection)
{
    moveDirection = newMoveDirection;
}

Input_gui Character::getMoveDirection() const
=======
void Character::setCurrentTile(Tile* tile)
{
    currentTile = tile;
}

Tile* Character::getCurrentTile() const
{
    return currentTile;
}

Input Character::move(char input)
{
    return abController->move(input);
}

Input Character::getMoveDirection() const
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
{
    return moveDirection;
}

<<<<<<< HEAD
bool Character::isHuman() const
{
    return human;
}

int Character::getMaxHP() const
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

bool Character::getAlive() const
{
    return alive;
}

void Character::setAlive(bool newAlive)
{
    alive = newAlive;
}

void Character::setAbstrCon(AbstractController *newAbstrCon)
{
    abstrCon = newAbstrCon;
}

AbstractController *Character::getAbstrCon() const
{
    return abstrCon;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
=======
void Character::setMoveDirection(const Input& newMoveDirection)
{
    moveDirection = newMoveDirection;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
