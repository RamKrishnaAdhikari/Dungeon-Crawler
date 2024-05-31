#include <iostream>
#include "dungeoncrawler.h"
#include "terminalui.h"
#include "level.h"

int main()
{
     std::string l = {

        "##########"
        "#O.......#"
        "#...<....#"
        "#..___.C.#"
        "#..___...#"
        "#........#"
        "#######X##"
        "#O.......#"
        "#...?....#"
        "##########"
    };

    constexpr size_t rows = 10;
    constexpr size_t cols = 10;

    TerminalUI* terminalui = new TerminalUI();
    Level* level = new Level(rows, cols, l);

    DungeonCrawler dungeonCrawler(terminalui,level);

    bool continueGame = true;

    while (continueGame)
    {
        continueGame = dungeonCrawler.turn();
    }

    return 0;
}
