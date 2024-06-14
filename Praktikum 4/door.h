#ifndef DOOR_H
#define DOOR_H
#include <string>
#include "floor.h"
#include "wall.h"
#include "passive.h"

class Door : public Floor, public Wall, public Passive
{
 public:
    Door(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool onLeave(Tile* destTile, Character* who) override;
    void notify() override;
    void setOpen(bool open);
    bool isOpen() const;

 private:
    bool open;
};

#endif // DOOR_H
