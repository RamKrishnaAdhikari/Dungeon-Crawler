#include "door.h"

<<<<<<< HEAD
Door::Door(int row, int col, std::string texture):
    Tile(row, col, texture),
    open(false)
{
    setTex_ui(new QPixmap(":/textures/doors/door1.png"));
}

std::string Door::getTexture() const
{
    if(open)
    {
        return "\\";
    }
    return Tile::getTexture();
=======
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

bool Door::onLeave(Tile* destTile, Character* who)
{
<<<<<<< HEAD
    return true;
}

std::pair<bool, Tile*>Door::onEnter(Character* who)
{
    if(open)
    {
        return Tile::onEnter(who);
    }
    return {false,nullptr};
=======
    if (open)
    {
        return true;
    }
    else
    {
        return false;
    }
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

void Door::notify()
{
<<<<<<< HEAD

    open =!(open);
    if(open)
    {
        setTex_ui(new QPixmap(":textures/doors/door2.png"));
    }
    else
    {
        setTex_ui(new QPixmap(":textures/doors/door1.png"));
    }

}

QPixmap* Door::getTex_ui() const
{
    return Tile::getTex_ui();
}

void Door::setOpen(bool newOpen)
{
    open = newOpen;
}

bool Door::getOpen() const
=======
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
{
    return open;
}
