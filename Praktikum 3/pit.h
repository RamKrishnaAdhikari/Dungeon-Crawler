#ifndef PIT_H
#define PIT_H
#include"tile.h"

class pit : public Tile
{
public:
    pit(const std::string& texture, int row, int column);
    std::pair<bool,Tile*> onEnter(Character * who)override;
    bool onLeave(Tile* desttile , Character* who)override;
};

#endif // PIT_H
