#ifndef CHARACTER_H
#define CHARACTER_H
<<<<<<< HEAD
#include <string>
#include "abstractcontroller.h"
=======
#include "abstractcontroller.h"
#include "input.h"
#include <string>
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d

class Tile;

class Character
{
public:
<<<<<<< HEAD
    Character(std::string texture, int strength, int stamina, bool hum = true);

    std::string getTexture() const;
    Input_gui move();
    ~Character();
    Tile* getChar_tile() const;
    void setChar_tile(Tile* newChar_tile);
    void setMoveDirection(Input_gui newMoveDirection);
    Input_gui getMoveDirection() const;
    bool isHuman() const;
    int getMaxHP() const;
    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;
    void setStamina(int newStamina);
    void setHitpoints(int newHitpoints);
    void setStrength(int newStrength);

    bool getAlive() const;
    void setAlive(bool newAlive);

    void setAbstrCon(AbstractController *newAbstrCon);


    AbstractController *getAbstrCon() const;

private:
    std::string texture;
    Tile* char_tile;
    AbstractController* abstrCon;
    Input_gui moveDirection;
    bool human;
    int strength;
    int stamina;
    int hitpoints;
    bool alive;
=======
    Character(const std::string& texture);

    std::string getTexture() const;
    void setCurrentTile(Tile* tile);
    Tile* getCurrentTile() const;
    Input move(char input);
    Input getMoveDirection() const;
    void setMoveDirection(const Input& newMoveDirection);

private:
    std::string texture;
    Tile* currentTile;
    AbstractController* abController;
    Input moveDirection;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // CHARACTER_H
