#include "startscreen.h"
#include "dungeoncrawler.h"
#include "mainwindow.h"
#include "graphicalui.h"
#include "level.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#.2.#"
        "#1.__#.1.#"
        "#...X#...#"
        "######-###"
        "#O.......#"
        "#...?.2..#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O..1.1.1#"
        "#...<..###"
        "#..___.#W#"
        "#&...###.#"
        "#....#.1.#"
        "######-###"
        "#O......1#"
        "#...2...?#"
        "##########"
    };

    const int rows = 10;
    const int cols = 10;

    QApplication a(argc, argv);

    StartScreen s;
    s.showFullScreen();
    a.exec();


    auto* dungeon = new DungeonCrawler(rows, cols, l);

    Level* level_n = new Level(rows, cols, l_n);

    dungeon->push_level_back(level_n);

    MainWindow w(dungeon, nullptr);

    GraphicalUI* UI = new GraphicalUI(&w);

    dungeon->setGui(UI);

    UI->draw();

    w.showFullScreen();
    a.exec();

    //delete level_n;
    delete dungeon;
    return 0;
}
