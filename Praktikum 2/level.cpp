#include "level.h"
#include "floor.h"
#include "wall.h"
#include "portal.h"
#include "character.h"
#include <iostream>

Level::Level(int height, int width, const std::string& l) : height(height),
    width(width)
{
    int count = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    bool portal1found = false;


    map.resize(height, std::vector<Tile*>(width, nullptr));

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (l.at(count) == '#')
            {
                map.at(i).at(j) = new Wall("#", i, j);
            }
            else if (l.at(count) == '.')
            {
                map.at(i).at(j) = new Floor(".", i, j);
            }
            else if (l.at(count) == 'O')
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
            }
            else if (l.at(count) == 'X')
            {
                map.at(i).at(j) = new Floor(".", i, j);
                Character* character = new Character("X");
                placeCharacter(character, i, j);
                character->setCurrentTile(map.at(i).at(j));
            }
            count++;
        }
    }
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


