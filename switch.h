#ifndef SWITCH_H
#define SWITCH_H
<<<<<<< HEAD
#include "tile.h"
#include "active.h"

class Switch : public Tile, public Active
{
public:
    Switch(int row, int col, std::string texture);
    ~Switch() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
=======
#include "floor.h"
#include "active.h"

class Switch : public Floor, public Active
{
 public:
    Switch(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // SWITCH_H
