#include <iostream>
#include "dungeoncrawler.h"

int main()
{
    const std::string l = {
        "##########"
        "#O.......#"
        "#........#"
        "#........#"
        "#........#"
        "#........#"
        "##########"
        "#O.......#"
        "#........#"
        "##########"
    };

   

    TerminalUI* terminalui = new TerminalUI();
    Level* level = new Level(10,10, l);

    DungeonCrawler dungeonCrawler(terminalui, level);

    bool continueGame = true;

    while (continueGame)
    {
        continueGame = dungeonCrawler.turn();
    }

    return 0;
}
