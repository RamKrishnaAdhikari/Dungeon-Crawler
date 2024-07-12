#ifndef PIT_H
#define PIT_H
#include "tile.h"
<<<<<<< HEAD

class Pit : public Tile
{
public:
    Pit(int row, int col, std::string texture);
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
=======
#include "ramp.h"

class Pit : public Tile
{
 public:
    Pit(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool onLeave(Tile* destTile, Character* who) override;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // PIT_H
