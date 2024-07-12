#include "graphicalui.h"
<<<<<<< HEAD
#include "level.h"
#include <iostream>
#include "mainwindow.h"

GraphicalUI::GraphicalUI(MainWindow* mw):
    ui_m(mw)
{}

void GraphicalUI::draw()
{
    ui_m->draw();
}

GraphicalUI::~GraphicalUI()
{
    ui_m = nullptr;
}

Input_gui GraphicalUI::move()
{
    Input_gui LC = ui_m->getLastClicked();
    return LC;
=======
#include <iostream>

GraphicalUI::GraphicalUI(MainWindow* mw,StartScreen* ss) : ui_m(mw),ui_s(ss)
{
    loadtextures();
}

void GraphicalUI::draw(Level* level)
{
    ui_m->draw(level);
}

void GraphicalUI:: loadtextures(){
    textures["floor 1"]= QPixmap(":/textures/floor/floor1.png");
    textures["floor 2"]= QPixmap(":/textures/floor/floor2.png");
    textures["floor 3"]= QPixmap(":/textures/floor/floor3.png");
    textures["floor 4"]= QPixmap(":/textures/floor/floor4.png");
    textures["floor 5"]= QPixmap(":/textures/floor/floor5.png");
     textures["wall 1"]= QPixmap(":/textures/wall/wall1.png");
     textures["ramp"]= QPixmap(":/textures/ramp.png");
    textures["pit"]= QPixmap(":/textures/pit.png");
    textures["portal 1"]= QPixmap(":/textures/portal/portal1.png");
     textures[" switch"]= QPixmap(":/textures/switch.png");
     textures["door 1"]= QPixmap(":/textures/doors/door1.png");
      textures["door 2"]= QPixmap(":/textures/doors/door2.png");


}
Input GraphicalUI::move(char input)
{
    while (true)
    {
        switch (input)
        {
        case 'A':
        case 'a':
            return Input(-1, 0, false);
        case 'D':
        case 'd':
            return Input(1, 0, false);
        case 'W':
        case 'w':
            return Input(0, -1, false);
        case 'S':
        case 's':
            return Input(0, 1, false);
        case 'X':
        case 'x':
            std::cout << "Program wird beendet." << std::endl;
            return Input(0, 0, true);
        default:
            std::cerr << "Invalid Input. Please enter A, D, W, S, X." << std::endl;
            return Input(0, 0, false);
        }
    }
}
void GraphicalUI::showStartScreen()
{
    if (ui_s)
    {
        ui_s->show();
    }
    if (ui_m)
    {
        ui_m->hide();
    }
}

void GraphicalUI::showGameScreen()
{
    if (ui_s)
    {
        ui_s->hide();
    }
    if (ui_m)
    {
        ui_m->show();
    }
}
void GraphicalUI::setMainWindow(MainWindow* mw)
{
    ui_m = mw;
}

void GraphicalUI::setStartScreen(StartScreen* ss)
{
    ui_s = ss;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
