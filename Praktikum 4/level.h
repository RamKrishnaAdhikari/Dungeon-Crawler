#ifndef LEVEL_H
#define LEVEL_H
#include "tile.h"
#include <array>
#include <vector>

class Level
{
 public:
    Level(int height, int width, const std::string& levelString);
    Level(const Level& other);
    Level& operator=(const Level& rhs);
    ~Level();
    std::vector<std::vector<Tile*> > getMap() const;
    std::vector<Character*> getCharacters() const;

    Tile* getTile(int row, int col);
    const Tile* getTile(int row, int col) const;
    void placeCharacter(Character* c, int row, int col);

    int getHeight() const;
    int getWidth() const;
    std::string getLevelString() const;
 private:
    int height;
    int width;
    std::string levelString;
    std::vector<std::vector<Tile*> > map;
    std::vector<Character*> characters;
};

#endif // LEVEL_H

