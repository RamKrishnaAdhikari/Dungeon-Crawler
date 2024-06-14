#include "door.h"

Door::Door(const std::string& texture, int row, int column) : Tile(texture, row, column), Floor(texture, row, column),
    Wall(texture, row, column), Passive(), open(false)
{}

std::pair<bool, Tile*> Door::onEnter(Character* who)
{
    if (open)
    {
        return {true, nullptr};
    }
    else
    {
        return {false, nullptr};
    }
}

bool Door::onLeave(Tile* destTile, Character* who)
{
    if (open)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Door::notify()
{
    open = !open;
    if (open)
    {
        setTexture("/");
    }
    else
    {
        setTexture("X");
    }
}

void Door::setOpen(bool open)
{
    this->open = open;
    if (open)
    {
        setTexture("/");
    }
    else
    {
        setTexture("X");
    }
}

bool Door::isOpen() const
{
    return open;
}
