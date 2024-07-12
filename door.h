#ifndef DOOR_H
#define DOOR_H
<<<<<<< HEAD
#include "tile.h"
#include "passive.h"

class Door : public Tile, public Passive
{
public:
    Door(int row, int col, std::string texture);
    ~Door() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool getOpen() const;
    void notify() override;
    QPixmap* getTex_ui() const override;


    void setOpen(bool newOpen);

private:
=======
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
    bool open;
};

#endif // DOOR_H
