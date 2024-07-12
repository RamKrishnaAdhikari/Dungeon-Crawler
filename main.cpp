<<<<<<< HEAD
#include "mainwindow.h"
#include "startscreen.h"
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "level.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <istream>

int main(int argc, char* argv[])
{QApplication a(argc, argv);
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#.3.#"
        "#11__#...#"
        "#..SX#...#"
        "#######-##"
        "#O...2...#"
        "#...?....#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O.......#"
        "#......###"
        "#.....4#&#"
        "#S...###.#"
        "#....#...#"
        "######-###"
        "#O......1#"
        "#...2...?#"
        "##########"
    };

    const std::string l_2{
        "##########"
        "#O...#..W#"
        "#...<#...#"
        "#..__#.2.#"
        "#11__#..2#"
        "#..S.#...#"
        "######-###"
        "#O...2...#"
        "#...?...4#"
        "##########"
    };

    std::string tmp_l;
    int rows;
    int cols;
    int level_num_tmp;

        std::ofstream file("/Users/vedantsorout/Desktop/Praktikum6/build/save.txt");
        file << 2 << std::endl;
        file << 10 << std::endl;
        file << 10 << std::endl;
        file << l << std::endl;
        file << 10 << std::endl;
        file << 10 << std::endl;
        file << l_n << std::endl;
        file << 10 << std::endl;
        file << 10 << std::endl;
        file << l_2 << std::endl;
        file << -1 << std::endl;
        file.close();

    std::ifstream infile("/Users/vedantsorout/Desktop/Praktikum6/build/save.txt");
    infile >> level_num_tmp;
    infile >> rows;
    infile >> cols;
    infile >> tmp_l;
    StartScreen s;
    s.show();
    a.exec();
   MainWindow w(rows, cols, tmp_l, nullptr);
    GraphicalUI* UI = new GraphicalUI(&w);
    w.getDc()->setGr_ui(UI);
    while(!infile.eof())
    {
        infile >> rows;
        infile >> cols;
        infile >> tmp_l;
        if(rows<=0 || cols<=0 || tmp_l=="")
        {
            break;
        }
        w.getDc()->push_level_back(new Level(rows, cols, tmp_l));
    }
    infile.close();

    UI->draw();
    w.show();
    a.exec();
    return 0;


=======
#include "startscreen.h"
#include "mainwindow.h"
#include "graphicalui.h"
#include "dungeoncrawler.h"
#include "level.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Example dungeon layout string
    const std::string l = {
        "##########"
        "#O.......#"
        "#...<....#"
        "#..___..C#"
        "#..___...#"
        "#........#"
        "#######X##"
        "#O.......#"
        "#...?....#"
        "##########"
    };

    const int rows = 10;
    const int cols = 10;

    // Create the Level and DungeonCrawler
    Level* level = new Level(rows, cols, l);
    DungeonCrawler* dungeon = new DungeonCrawler(level);

    // Create and initialize the MainWindow
    MainWindow w(dungeon, nullptr);

    // Create and show the StartScreen
    GraphicalUI gui(&w, nullptr); // Set MainWindow now
    StartScreen s(&gui); // Pass the GraphicalUI instance to StartScreen
    gui.setStartScreen(&s); // Set StartScreen in GraphicalUI

    // Draw the initial state of the game
    gui.draw(level);

    // Show the start screen
    s.show();

    // Start the application event loop
    int result = a.exec();

    // Clean up dynamically allocated objects
    delete dungeon;
    delete level;

    return result;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
