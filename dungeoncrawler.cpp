#include "dungeoncrawler.h"

DungeonCrawler::DungeonCrawler(TerminalUI* terminalui, Level* currentLevel) : terminalui(terminalui),
    currentLevel(currentLevel)
{}

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
