#ifndef TILE_H
#define TILE_H
#include <string>

class Character;

class Tile
{
 public:
    virtual ~Tile() = default;
    std::string getTexture() const;
    void setTexture(const std::string& newTexture);

    Character* getCharacter() const;
    void setCharacter(Character* newCharacter);

    int getRow() const;
    int getColumn() const;

    bool hasCharacter() const;
    virtual bool moveTo(Tile* destTile, Character* who);
    virtual bool onLeave(Tile* destTile, Character* who);
    virtual std::pair<bool, Tile*> onEnter(Character* who) = 0;
 protected:
    Tile(const std::string& texture, int row, int column);
 private:
    std::string texture;
    Character* character;
    const int row;
    const int column;
};

#endif // TILE_H
