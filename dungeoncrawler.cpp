#include "dungeoncrawler.h"
#include "character.h"
#include "level.h"
//#include <iostream>

DungeonCrawler::DungeonCrawler(Level* currentLevel) :
    currentLevel(currentLevel)
{
    // Test copy constructor
    /*std::cout << "Testing copy constructor" << std::endl;
    auto* tmp = new Level(10, 10, "##########"
                                  "#O.....C.#"
                                  "#...<....#"
                                  "#..___...#"
                                  "#..___...#"
                                  "#........#"
                                  "#######X##"
                                  "#O.......#"
                                  "#...?....#"
                                  "##########");
    std::cout << "Created tmp : " << std::endl;
    terminalui->draw(tmp);

    currentLevel = new Level(*tmp);
    std::cout << "Copy constructor called created new level : " << std::endl;
    terminalui->draw(currentLevel);

    delete tmp;
    std::cout << "Tmp deleted" << std::endl;

    std::cout << std::endl;

    // Test assignment
    tmp = new Level(10, 10, "##########"
                            "#O.......#"
                            "#...<....#"
                            "#..___...#"
                            "#C.___...#"
                            "#........#"
                            "#######X##"
                            "#O.......#"
                            "#...?....#"
                            "##########");
    std::cout << "Created new tmp : " << std::endl;
    terminalui->draw(tmp);

    *currentLevel = *tmp;
    std::cout << "Called assignment operator : " << std::endl;
    terminalui->draw(currentLevel);

    delete tmp;
    std::cout << "Cleaned everything up" << std::endl;*/
}

DungeonCrawler::~DungeonCrawler()
{
    delete currentLevel;
}

bool DungeonCrawler::turn(Input input_terminal)
{
    bool Moved = false;
    for (Character* character : currentLevel->getCharacters())
    {
        if (character != nullptr){
            Tile* current_tile = character->getCurrentTile();
            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getColumn();

            if (input_terminal.getVertical() == -1)
            {
                dest_row -= 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(Input(0, -1, false));
                    Moved = true;
                }
            }

            if (input_terminal.getVertical() == 1)
            {
                dest_row += 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(0, 1, false));
                    Moved = true;
                }
            }

            if (input_terminal.getHorizontal() == 1)
            {
                dest_col += 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(1, 0, false));
                    Moved = true;
                }
            }

            if (input_terminal.getHorizontal() == -1)
            {
                dest_col -= 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(-1, 0, false));
                    Moved = true;
                }
            }

            if (input_terminal.getExit())
            {
                character->setMoveDirection(Input(0, 0, true));
                return false;
            }
        }
    }
    return Moved;
}

Level* DungeonCrawler::getLevel() const
{
    return currentLevel;
}

