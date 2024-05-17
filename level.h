#ifndef LEVEL_H
#define LEVEL_H
#include "tile.h"
#include <array>
#include <vector>

class Level
{
 public:
    Level(int height, int width, const std::string& l);
    ~Level();
    std::vector<std::vector<Tile*> > getMap() const;
    std::vector<Character*> getCharacters() const;

    Tile* getTile(int row, int col);
    const Tile* getTile(int row, int col) const;
    void placeCharacter(Character* c, int row, int col);

    int getHeight() const;
    int getWidth() const;

 private:
    int height;
    int width;
    std::vector<std::vector<Tile*> > map;
    std::vector<Character*> characters;
};

#endif // LEVEL_H

