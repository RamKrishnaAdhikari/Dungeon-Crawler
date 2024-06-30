#ifndef LEVEL_H
#define LEVEL_H
#include "string"
#include <vector>
#include "tile.h"

class List;

class Levelchanger;

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();
    Level(const Level& l);

    Level& operator=(const Level& l);
    void setRows(int newRows);
    void setCols(int newCols);
    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;
    void addCharacter(Character* newCharacter);
    void removeCharacter(int ind);
    void placeCharacter(Character *c, int row, int col);
    std::vector<std::vector<Tile *> > getField() const;

    void setField(const std::vector<std::vector<Tile *> > &newField);

    void setLvl_string(const std::string &newLvl_string);
    Levelchanger *getLevel_ch() const;
    void setLevel_change(Levelchanger *newLevel_change);
    int getRows() const;
    int getCols() const;
    bool operator==(Level lhs);
    bool operator!=(Level lhs);
    std::vector<Character *> getCharacters() const;
    std::string getLvl_string() const;

private:
    Levelchanger* level_change;
    std::vector<std::vector<Tile*>> field;
    std::vector<Character *> characters;
    std::string lvl_string;
    int rows;
    int cols;
};

#endif // LEVEL_H
