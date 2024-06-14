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
}
