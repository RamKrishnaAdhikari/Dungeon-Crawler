#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "abstractcontroller.h"

class Tile;

class Character
{
public:
    Character(std::string texture, int strength, int stamina, bool ishuman = true);

    std::string getTexture() const;
    Input_gui move();
    void setCurrentTile(Tile* tile);
    Tile* getCurrentTile() const;
    void setMoveDirection(Input_gui newMoveDirection);
    Input_gui getMoveDirection() const;
     ~Character();
    bool isHuman() const;
     bool isAlive() const;
     void setAlive(bool newAlive);
    int getMaxHP();
     int getHitpoints() const;
     void setHitpoints(int newHitpoints);
    int getStamina() const;
    void setStamina(int newStamina);   
    int getStrength() const;
    void setStrength(int newStrength);
    void die();



private:
    std::string texture;
    Tile* currentTile;
    AbstractController* abController;
    Input_gui moveDirection;
    int strength;
    int stamina;
    int hitpoints;
    bool ishuman;
    bool alive;
};

#endif // CHARACTER_H

