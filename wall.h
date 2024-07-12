#ifndef WALL_H
#define WALL_H
#include "tile.h"

<<<<<<< HEAD
class Wall : public Tile
{
public:
    Wall(int row, int col, std::string texture);
    virtual ~Wall() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character *who) override;
    std::pair<bool, Tile* > onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
};

#endif // WALL_H
=======
class Wall : virtual public Tile
{
 public:
    Wall(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
};

#endif // WALL_H

>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
