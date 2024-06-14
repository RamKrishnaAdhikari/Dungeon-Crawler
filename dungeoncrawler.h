#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "terminalui.h"
#include "level.h"

class DungeonCrawler
{
public:
    DungeonCrawler(Level* currentLevel);
    ~DungeonCrawler();
    bool turn(Input input_terminal);
    Level* getLevel() const;
private:
    Level* currentLevel;
};

#endif // DUNGEONCRAWLER_H
