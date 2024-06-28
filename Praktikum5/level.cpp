#include "level.h"
#include "portal.h"
#include "wall.h"
#include "floor.h"
#include "switch.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"
#include "levelchanger.h"
#include <typeinfo>
#include "random.h"
#include "levelchanger.h"
#include "lootchest.h"
#include "list.h"

Level::Level(int row, int col, std::string lvl):level_change(nullptr), lvl_string(lvl), rows(row),cols(col) {
    int index = 0;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;

    Door* door1;
    Switch* switch1;

    int  portal_t{};

    bool portal1_found = false;
    bool door1_found = false;
    bool switch1_found = false;

    field.resize(rows);
    for(int i = 0; i < rows; ++i){
        field.at(i).resize(col, nullptr);
    }

    int floor_type;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            switch(lvl_string.at(index)){
            case '#':
                field.at(i).at(j) = new Wall(i, j, "#");
                index++;
                break;

            case '.':
                field.at(i).at(j) = new Floor(".",i, j);
                floor_type = getRandom(1,20);
                field.at(i).at(j)->setFloor_tiletype(floor_type);
                index++;
                break;

            case 'O':
                if(portal1_found)
                {
                    portal2 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                    portal1->setPortaltype(portal_t++);
                }
                else
                {
                    portal1 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal1;
                    portal1_found = true;
                    portal1->setPortaltype(portal_t);
                }
                index++;
                break;

            case '?':
                switch1 = new Switch(i, j, "?");
                field.at(i).at(j) = switch1;
                index++;
                switch1_found = true;
                break;

            case '-':
                door1 = new Door(i, j,"-");
                field.at(i).at(j) = door1;
                door1_found = true;
                index++;
                break;

            case '_':
                field.at(i).at(j) = new Pit(i, j, "_");
                index++;
                break;

            case '<':
                field.at(i).at(j) = new Ramp(i, j, "<");
                index++;
                break;

            case 'X':
            {
                field.at(i).at(j) = new Floor(".",i, j);
                index++;
                Character* new_char1 = new Character("X", 5, 5, true); //just placeholder for stats
                characters.push_back(new_char1);
                field.at(i).at(j)->setCharacter(new_char1);
                new_char1->setCurrentTile(field.at(i).at(j));
                break;
            }
            case '1':
            {
                field.at(i).at(j) = new Floor(".",i, j);
                index++;
                Character* new_char2 = new Character("1", 2, 2, false); //just placeholder for stats
                characters.push_back(new_char2);
                field.at(i).at(j)->setCharacter(new_char2);
                new_char2->setCurrentTile(field.at(i).at(j));
                break;
            }
            case '2':
            {
                field.at(i).at(j) = new Floor(".",i, j);
                index++;
                Character* new_char3 = new Character("2", 1, 1, false); //just placeholder for stats
                characters.push_back(new_char3);
                field.at(i).at(j)->setCharacter(new_char3);
                new_char3->setCurrentTile(field.at(i).at(j));
                break;
            }
            case '&':
            {
                level_change = new Levelchanger(i, j, "&");
                field.at(i).at(j) = level_change;
                level_change->setLevel_dest(this);
                index++;
                break;
            }
            case 'W':
                auto lootchest = new Lootchest(i, j, "W");
                field.at(i).at(j) = lootchest;
                index++;
                break;
            }
        }
    }
    if(door1_found && switch1_found){
        switch1->attach(door1);
    }
}

Level::~Level()
{
    for(auto& x:this->field){
        for(auto y:x){
            delete y;
        }
    }
    this->field.clear();

    for(auto& z:this->characters){
        delete z;
    }
    this->characters.clear();
}

Level::Level(const Level &l):lvl_string(l.getLvl_string()), rows(l.getRows()), cols(l.getCols())
{
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;

    Door* door1;
    Switch* switch1;

    bool portal1_found = false;
    bool door1_found = false;
    bool switch1_found = false;

    field.resize(rows);
    for(int i = 0; i < rows; ++i){
        field.at(i).resize(cols, nullptr);
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            const std::type_info& tile_tmp = typeid(*l.getTile(i, j));
            delete field.at(i).at(j);
            if(tile_tmp == typeid(Wall)){
                field.at(i).at(j) = new Wall(i, j, "#");
                continue;
            }

            if(tile_tmp == typeid(Floor)){
                field.at(i).at(j) = new Floor(".",i, j);
                continue;
            }

            if(tile_tmp == typeid(Portal)){
                if(portal1_found)
                {
                    portal2 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                }
                else
                {
                    portal1 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal1;
                    portal1_found = true;
                }
                continue;
            }

            if(tile_tmp == typeid(Switch)){
                switch1 = new Switch(i, j, "?");
                field.at(i).at(j) = switch1;
                switch1_found = true;
                continue;
            }

            if(tile_tmp == typeid(Door)){
                door1 = new Door(i, j,"-");
                field.at(i).at(j) = door1;
                door1_found = true;
                continue;
            }

            if(tile_tmp == typeid(Pit)){
                field.at(i).at(j) = new Pit(i, j, "_");
                continue;
            }

            if(tile_tmp == typeid(Ramp)){
                field.at(i).at(j) = new Ramp(i, j, "<");
                continue;
            }
            if(tile_tmp == typeid(Levelchanger)){

                level_change = new Levelchanger(i, j, "&");
                field.at(i).at(j) = level_change;
                level_change->setLevel_dest(this);
                continue;
            }
            if(l.getField().at(i).at(j)->hasCharacter()){
                auto charac = l.getField().at(i).at(j)->getCharacter();
                Character* new_char = new Character(charac->getTexture(), charac->getStrength(), charac->getStamina(), charac->isHuman()); //just placeholder for stats
                characters.push_back(new_char);
                field.at(i).at(j)->setCharacter(new_char);
                new_char->setCurrentTile(field.at(i).at(j));
            }
        }
    }
    if(door1_found && switch1_found){
        switch1->attach(door1);
    }
}

Level &Level::operator=(const Level &l)
{
    this->cols = l.cols;
    this->rows = l.rows;
    this->lvl_string = l.lvl_string;
    for(auto& x:this->characters){
        delete x;
    }
    this->characters.clear();

    for(auto& x:this->field){
        for(auto y:x){
            delete y;
        }
    }
    this->field.clear();

    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;

    Door* door1;
    Switch* switch1;

    bool portal1_found = false;
    bool door1_found = false;
    bool switch1_found = false;

    field.resize(rows);
    for(int i = 0; i < rows; ++i){
        field.at(i).resize(cols, nullptr);
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            const std::type_info& tile_tmp = typeid(*l.getTile(i, j));
            delete field.at(i).at(j);
            if(tile_tmp == typeid(Wall)){
                field.at(i).at(j) = new Wall(i, j, "#");
                continue;
            }

            if(tile_tmp == typeid(Floor)){
                field.at(i).at(j) = new Floor( ".",i, j);
                if(l.getField().at(i).at(j)->hasCharacter()){
                    Character* new_char = new Character("X", 5, 5); //just placeholder for stats
                    characters.push_back(new_char);
                    field.at(i).at(j)->setCharacter(new_char);
                    new_char->setCurrentTile(field.at(i).at(j));
                }
                continue;
            }

            if(tile_tmp == typeid(Portal)){
                if(portal1_found)
                {
                    portal2 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                }
                else
                {
                    portal1 = new Portal(i, j, "O");
                    field.at(i).at(j) = portal1;
                    portal1_found = true;
                }
                continue;
            }

            if(tile_tmp == typeid(Switch)){
                switch1 = new Switch(i, j, "?");
                field.at(i).at(j) = switch1;
                switch1_found = true;
                continue;
            }

            if(tile_tmp == typeid(Door)){
                door1 = new Door(i, j,"-");
                field.at(i).at(j) = door1;
                door1_found = true;
                continue;
            }

            if(tile_tmp == typeid(Pit)){
                field.at(i).at(j) = new Pit(i, j, "_");
                continue;
            }

            if(tile_tmp == typeid(Ramp)){
                field.at(i).at(j) = new Ramp(i, j, "<");
                continue;
            }
            if(tile_tmp == typeid(Levelchanger)){
                level_change = new Levelchanger(i, j, "&");
                field.at(i).at(j) = level_change;
                level_change->setLevel_dest(this);
                continue;
            }
            if(l.getField().at(i).at(j)->hasCharacter()){
                auto charac = l.getField().at(i).at(j)->getCharacter();
                Character* new_char = new Character(charac->getTexture(), charac->getStrength(), charac->getStamina(), charac->isHuman()); //just placeholder for stats
                characters.push_back(new_char);
                field.at(i).at(j)->setCharacter(new_char);
                new_char->setCurrentTile(field.at(i).at(j));
            }
        }
    }
    if(door1_found && switch1_found){
        switch1->attach(door1);
    }
    return *this;
}

Tile *Level::getTile(int row, int col)
{
    return field.at(row).at(col);
}

const Tile *Level::getTile(int row, int col) const
{
    return field.at(row).at(col);
}

void Level::placeCharacter(Character *c, int row, int col)
{
    field.at(row).at(col)->setCharacter(c);
}

int Level::getRows() const
{
    return this->rows;
}

int Level::getCols() const
{
    return this->cols;
}

std::vector<Character *> Level::getCharacters() const
{
    return characters;
}

std::string Level::getLvl_string() const
{
    return lvl_string;
}

std::vector<std::vector<Tile *> > Level::getField() const
{
    return field;
}

void Level::setField(const std::vector<std::vector<Tile *> > &newField)
{
    field = newField;
}

void Level::addCharacter(Character *newCharacter)
{
    characters.push_back(newCharacter);
}

void Level::removeCharacter(int ind)
{
    delete characters.at(ind);
    characters.erase(characters.begin()+ind);
}


void Level::setLvl_string(const std::string &newLvl_string)
{
    lvl_string = newLvl_string;
}

void Level::setRows(int newRows)
{
    rows = newRows;
}

void Level::setCols(int newCols)
{
    cols = newCols;
}

bool Level::operator==(Level lhs)
{
    if(this->field == lhs.getField() &&this->characters == lhs.getCharacters() && this->lvl_string == lhs.getLvl_string() && this->rows == lhs.getRows() &&this->cols == lhs.getCols())

       {

        return true;
    }
    return false;
}

bool Level::operator!=(Level lhs)
{
    if(this->field == lhs.getField() &&this->characters == lhs.getCharacters() &&  this->lvl_string == lhs.getLvl_string() &&this->rows == lhs.getRows() &&this->cols == lhs.getCols())
   {
        return false;
    }
    return true;
}

Levelchanger *Level::getLevel_ch() const
{
    return level_change;
}

void Level::setLevel_change(Levelchanger *newLevel_change)
{
    level_change = newLevel_change;
}
