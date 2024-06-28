#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "level.h"
#include "portal.h"

class Level;

class Levelchanger : public Portal
{
public:
    Levelchanger(int row, int col, std::string texture);

    std::pair<bool, Tile *> onEnter(Character *who) override;

    Levelchanger *getDestination() const;
    void setDestination(Levelchanger *newDestination_level);

    Level* getLevel_dest() const;
    void setLevel_dest(Level *newLevel_dest);

private:
    Level* level_destination;
    Levelchanger *destination_levelchanger;
};

#endif // LEVELCHANGER_H
