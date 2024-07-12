#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
<<<<<<< HEAD
#include "level.h"
#include "list.h"


class GraphicalUI;

class DungeonCrawler : public List<Level*>
{
public:
    DungeonCrawler();
    ~DungeonCrawler();
    DungeonCrawler(Level* level);
    DungeonCrawler(int rows, int cols, std::string l);
    bool turn();
    Level* getCurrentLevel() const;
    void setGr_ui(GraphicalUI* newGr_ui);
    void push_level_back(Level* level);
    void check_alive();
    bool isHuman_alive() const;
    bool getLootchest_found() const;
    void saveGame();
    void loadGame();
    int getLevel_num() const;
    void setLevel_num(int newLevel_num);
private:
    List<Level*> level_list;
    GraphicalUI* gr_ui;
    Level* level;
    bool lootchest_found;
    bool human_alive;
    int level_num;
=======
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // DUNGEONCRAWLER_H
