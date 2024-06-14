#include "level.h"
#include "floor.h"
#include "wall.h"
#include "portal.h"
#include "character.h"
#include "switch.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"
#include <iostream>
#include <typeinfo>

Level::Level(int height, int width, const std::string& levelString) : height(height),
    width(width), levelString(levelString)
{
    int count = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1found = false;

    Switch* newSwitch = nullptr;
    Door* newDoor = nullptr;
    bool switch1Found = false;
    bool door1Found = false;

    map.resize(height, std::vector<Tile*>(width, nullptr));

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            switch (levelString.at(count))
            {
            case '#':
                map.at(i).at(j) = new Wall("#", i, j);
                count++;
                break;
            case '.':
                map.at(i).at(j) = new Floor(".", i, j);
                count++;
                break;
            case 'O':
                if (portal1found)
                {
                    portal2 = new Portal("O", i, j);
                    map.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1found = false;
                }
                else
                {
                    portal1 = new Portal("O", i, j);
                    map.at(i).at(j) = portal1;
                    portal1found = true;
                }
                count++;
                break;
            case 'X':
                newDoor = new Door("X", i, j);
                map.at(i).at(j) = newDoor;
                door1Found = true;
                count++;
                break;
            case '?':
                newSwitch = new Switch("?", i, j);
                map.at(i).at(j) = newSwitch;
                switch1Found = true;
                count++;
                break;
            case '_':
                map.at(i).at(j) = new Pit("_", i, j);
                count++;
                break;
            case '<':
                map.at(i).at(j) = new Ramp("<", i, j);
                count++;
                break;
            case 'C':
                map.at(i).at(j) = new Floor(".", i, j);
                Character* character = new Character("C");
                placeCharacter(character, i, j);
                character->setCurrentTile(map.at(i).at(j));
                count++;
                break;
            }
        }
    }

    if (door1Found == true || switch1Found == true)
    {
        newSwitch->attach(newDoor);
    }

 /*   for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            auto* switchTile = dynamic_cast<Switch*>(map.at(i).at(j));
            if (switchTile != nullptr)
            {
                for (size_t i = 0; i < height; i++)
                {
                    for (size_t j = 0; j < width; j++)
                    {
                        auto* doorTile = dynamic_cast<Door*>(map.at(i).at(j));
                        if (doorTile != nullptr)
                        {
                            switchTile->attach(doorTile);
                        }
                    }
                }
            }
        }
    }*/
}

Level::Level(const Level& other) : height(other.getHeight()), width(other.getWidth()), levelString(other.getLevelString())
{
    int count = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1found = false;

    Switch* newSwitch = nullptr;
    Door* newDoor = nullptr;
    bool switch1Found = false;
    bool door1Found = false;

    map.resize(height, std::vector<Tile*>(width, nullptr));

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            auto obj = other.getTile(i, j);
            const std::type_info& tileTemp = typeid(*obj);

            if (tileTemp == typeid(Wall))
            {
                map.at(i).at(j) = new Wall("#", i, j);
                continue;
            }
            if (tileTemp == typeid(Floor))
            {
                map.at(i).at(j) = new Floor(".", i, j);
                continue;
            }
            if (tileTemp == typeid(Portal))
            {
                if (portal1found)
                {
                    portal2 = new Portal("O", i, j);
                    map.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1found = false;
                }
                else
                {
                    portal1 = new Portal("O", i, j);
                    map.at(i).at(j) = portal1;
                    portal1found = true;
                }
                continue;
            }
            if (tileTemp == typeid(Door))
            {
                newDoor = new Door("X", i, j);
                map.at(i).at(j) = newDoor;
                door1Found = true;
                continue;
            }
            if (tileTemp == typeid(Switch))
            {
                newSwitch = new Switch("?", i, j);
                map.at(i).at(j) = newSwitch;
                switch1Found = true;
                continue;
            }
            if (tileTemp == typeid(Pit))
            {
                map.at(i).at(j) = new Pit("_", i, j);
                continue;
            }
            if (tileTemp == typeid(Ramp))
            {
                map.at(i).at(j) = new Ramp("<", i, j);
                continue;
            }
        }
    }

    for (const auto& character : other.characters)
    {
        Character* newCharacter = new Character(*character);
        characters.push_back(newCharacter);
        map.at(character->getCurrentTile()->getRow()).at(character->getCurrentTile()->getColumn())->setCharacter(newCharacter);
        newCharacter->setCurrentTile(map.at(character->getCurrentTile()->getRow()).at(character->getCurrentTile()->getColumn()));
    }

    if (door1Found == true || switch1Found == true)
    {
        newSwitch->attach(newDoor);
    }
}

Level& Level::operator=(const Level& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            delete map.at(i).at(j);
        }
    }
    map.clear();

    for (size_t i = 0; i < characters.size(); i++)
    {
        delete characters.at(i);
    }
    characters.clear();

    height = rhs.height;
    width = rhs.width;
    levelString = rhs.levelString;

    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1found = false;

    Switch* newSwitch = nullptr;
    Door* newDoor = nullptr;
    bool switch1Found = false;
    bool door1Found = false;

    map.resize(height, std::vector<Tile*>(width, nullptr));

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            auto obj = rhs.getTile(i, j);
            const std::type_info& tileTemp = typeid(*obj);

            if (tileTemp == typeid(Wall))
            {
                map.at(i).at(j) = new Wall("#", i, j);
                continue;
            }
            if (tileTemp == typeid(Floor))
            {
                map.at(i).at(j) = new Floor(".", i, j);
                continue;
            }
            if (tileTemp == typeid(Portal))
            {
                if (portal1found)
                {
                    portal2 = new Portal("O", i, j);
                    map.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1found = false;
                }
                else
                {
                    portal1 = new Portal("O", i, j);
                    map.at(i).at(j) = portal1;
                    portal1found = true;
                }
                continue;
            }
            if (tileTemp == typeid(Door))
            {
                newDoor = new Door("X", i, j);
                map.at(i).at(j) = newDoor;
                door1Found = true;
                continue;
            }
            if (tileTemp == typeid(Switch))
            {
                newSwitch = new Switch("?", i, j);
                map.at(i).at(j) = newSwitch;
                switch1Found = true;
                continue;
            }
            if (tileTemp == typeid(Pit))
            {
                map.at(i).at(j) = new Pit("_", i, j);
                continue;
            }
            if (tileTemp == typeid(Ramp))
            {
                map.at(i).at(j) = new Ramp("<", i, j);
                continue;
            }
        }
    }

    for (const auto& character : rhs.characters)
    {
        Character* newCharacter = new Character(*character);
        characters.push_back(newCharacter);
        map.at(character->getCurrentTile()->getRow()).at(character->getCurrentTile()->getColumn())->setCharacter(newCharacter);
        newCharacter->setCurrentTile(map.at(character->getCurrentTile()->getRow()).at(character->getCurrentTile()->getColumn()));
    }

    if (door1Found == true || switch1Found == true)
    {
        newSwitch->attach(newDoor);
    }

    return *this;
}

std::vector<Character*> Level::getCharacters() const
{
    return characters;
}

std::vector<std::vector<Tile*>> Level::getMap() const
{
    return map;
}

Level::~Level()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            delete map.at(i).at(j);
        }
    }
    map.clear();

    for (size_t i = 0; i < characters.size(); i++)
    {
        delete characters.at(i);
    }
    characters.clear();
}

Tile* Level::getTile(int row, int col)
{
    if (row >= 0 && row < map.size() && col >= 0 && col < map.at(row).size())
    {
        return map.at(row).at(col);
    }
    else
    {
        return nullptr;
    }
}

const Tile* Level::getTile(int row, int col) const
{
    if (row >= 0 && row < map.size() && col >= 0 && col < map.at(row).size())
    {
        return map.at(row).at(col);
    }
    else
    {
        return nullptr;
    }
}

void Level::placeCharacter(Character* c, int row, int col)
{
    if (row >= 0 && row < map.size() && col >= 0 && col < map.at(row).size())
    {
        Tile* targetTile = map.at(row).at(col);
        targetTile->setCharacter(c);
        characters.push_back(c);
    }
}

int Level::getHeight() const
{
    return height;
}

int Level::getWidth() const
{
    return width;
}

std::string Level::getLevelString() const
{
    return levelString;
}


