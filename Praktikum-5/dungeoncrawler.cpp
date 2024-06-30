#include "dungeoncrawler.h"
#include "level.h"
#include "levelchanger.h"
#include "graphicalui.h"


DungeonCrawler::DungeonCrawler()
{

}

DungeonCrawler::DungeonCrawler(Level *level):level(level)
{
    lootchest_found=(false);
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):level(new Level(rows, cols, l))
{
    lootchest_found=(false);
    human_alive = true;

    push_level_back(level);
}

DungeonCrawler::~DungeonCrawler(){
    delete level;
    //delete list_of_levels;
    delete gui;
}

Level *DungeonCrawler::getLevel() const
{
    return level;
}

void DungeonCrawler::push_level_back(Level *level_n)
{
    list_of_levels.push_back(level_n);

    (list_of_levels.begin().operator *())->getLevel_ch()->setDestination(level_n->getLevel_ch());
    (list_of_levels.begin().operator *())->getLevel_ch()->setLevel_dest(level_n);

    level_n->getLevel_ch()->setDestination((list_of_levels.begin().operator *())->getLevel_ch());
    level_n->getLevel_ch()->setLevel_dest((list_of_levels.begin().operator *()));
}

void DungeonCrawler::setGui(GraphicalUI *newGui)
{
    gui = newGui;
}

bool DungeonCrawler::getLootchest_found() const
{
    return lootchest_found;
}

void DungeonCrawler::check_alive()
{
    int ind{};
    for(auto charac: level->getCharacters()){
        if(!(charac->isAlive())){
            if(charac->isHuman()){
                human_alive = false;
            }
            level->removeCharacter(ind);
        }
        ind++;
    }
}

bool DungeonCrawler::isHuman_alive() const
{
    return human_alive;
}

bool DungeonCrawler::turn()
{

    bool Moved = false;
    for(Character* character:level->getCharacters()){

        if(character!=nullptr){
            Tile* current_tile = character->getCurrentTile();

            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            Input_gui input_terminal;

            if(character->isHuman()){
                input_terminal = gui->move();
            }
            else{
                input_terminal = character->move();
            }

            if(input_terminal == up)
            {
                dest_row-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(up);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == upleft)
            {
                dest_row-=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == upright)
            {
                dest_row-=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == down)
            {
                dest_row+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(down);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == downright)
            {
                dest_row+=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == downleft)
            {
                dest_row+=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == right)
            {
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(right);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == left)
            {
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&"){
                    level = level->getLevel_ch()->getLevel_dest();
                    level->addCharacter(character);
                }
                if(dest_tile->getTexture()=="W"){
                    lootchest_found = true;
                }
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(left);
                    Moved = true;
                }
                if(dest_tile->getTexture()=="&"){
                    break;
                }
                continue;
            }
            if(input_terminal == terminate)
            {
                continue;
            }
        }

    }
    check_alive();
    return Moved;
}
