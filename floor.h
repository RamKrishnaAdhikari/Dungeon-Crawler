#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"

<<<<<<< HEAD
class Floor : public Tile
{
public:
    Floor(int row, int col, std::string texture);
    virtual ~Floor() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*>onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;

=======
class Floor : virtual public Tile
{
 public:
    Floor(const std::string& texture, int row, int column);
    std::pair<bool, Tile*> onEnter(Character* who) override;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // FLOOR_H
