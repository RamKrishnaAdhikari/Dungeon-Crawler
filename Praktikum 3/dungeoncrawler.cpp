#include "dungeoncrawler.h"
//#include<iostream>

DungeonCrawler::DungeonCrawler(TerminalUI* terminalui, Level* currentLevel) : terminalui(terminalui),
    currentLevel(currentLevel)
{
    // This is the test for copy constructor and assignment operator
    // if you want to see test uncomment this and see in terminal
    //Test copy constructor

   /* std::cout << "testing copyconstructor" << std::endl << std::endl;
    auto* tmp = new Level(2,5,"##########");
     std::cout << "Created Tmp :" << std::endl << std::endl;
    terminalui->draw(tmp);
    auto* cLevel = new Level(*tmp);
     std::cout << "copyconst called created new level :" << std::endl << std::endl;
    terminalui->draw(cLevel);
    delete tmp;
    std::cout << "deleted tmp " << std::endl << std::endl;
    terminalui->draw(cLevel);
    std::cout<<std::endl;
    //Test assignment
    tmp = new Level(3,5,"##X###########X");
    std::cout << "created new tmp value :" << std::endl << std::endl;
    terminalui->draw(tmp);
    *cLevel =(*tmp);
     std::cout << "called assignment operator :" << std::endl << std::endl;
    terminalui->draw(cLevel);
    delete tmp;
    std::cout << "cleaned everything up" << std::endl << std::endl;
    terminalui->draw(cLevel);
*/
}



DungeonCrawler::~DungeonCrawler()
{
    delete terminalui;
    delete currentLevel;
}

bool DungeonCrawler::turn()
{
    for (auto& character : currentLevel->getCharacters())
    {
        if (character != nullptr)
        {
            Tile* currentTile = character->getCurrentTile();
            bool notMoved = true;

            while (notMoved)
            {
                terminalui->draw(currentLevel);
                Input userInput = terminalui->move();

                if (userInput.getExit()) {
                    return false;
                }

                int desRow = currentTile->getRow();
                int desCol = currentTile->getColumn();

                if (userInput.getVertical() == -1)
                {
                    desRow -= 1;
                }
                else if (userInput.getVertical() == 1)
                {
                    desRow += 1;
                }
                else if (userInput.getHorizontal() == 1)
                {
                    desCol += 1;
                }
                else if (userInput.getHorizontal() == -1)
                {
                    desCol -= 1;
                }
                else
                {
                    continue;
                }

                if (desRow >= 0 && desRow < currentLevel->getHeight() && desCol >= 0 && desCol < currentLevel->getWidth())
                {
                    Tile* desTile = currentLevel->getMap().at(desRow).at(desCol);
                    if (currentTile->moveTo(desTile, character))
                    {
                        notMoved = false;
                    }
                }
            }
        }
    }
    return true;
}
