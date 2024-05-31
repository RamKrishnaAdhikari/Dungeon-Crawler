#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "terminalui.h"
#include "level.h"
#include "tile.h"
#include "character.h"

class DungeonCrawler
{
public:
    DungeonCrawler(TerminalUI* terminalui, Level* currentLevel);

    ~DungeonCrawler();
    bool turn();

private:
    TerminalUI* terminalui;
    Level* currentLevel;
};

#endif // DUNGEONCRAWLER_H
