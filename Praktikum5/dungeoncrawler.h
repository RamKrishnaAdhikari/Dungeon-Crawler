#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "level.h"
#include "list.h"

class GraphicalUI;

class DungeonCrawler
{
public:
    DungeonCrawler();
    DungeonCrawler(Level* level);
    DungeonCrawler(int rows, int cols, std::string l);
    bool turn();
    ~DungeonCrawler();

    Level *getLevel() const;
    void push_level_back(Level* level);
    void setGui(GraphicalUI *newGui);
    bool getLootchest_found() const;
    void check_alive();
    bool isHuman_alive() const;

private:
    Level* level;
    myList list_of_levels;
    GraphicalUI* gui;
    bool lootchest_found;
    bool human_alive;

};

#endif // DUNGEONCRAWLER_H
