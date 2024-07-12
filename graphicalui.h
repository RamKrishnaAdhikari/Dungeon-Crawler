#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
<<<<<<< HEAD
#include "abstractcontroller.h"
#include "dungeoncrawler.h"

class MainWindow;

class GraphicalUI : public AbstractController
{
public:
    GraphicalUI(MainWindow* mw);
    void draw();
    virtual ~GraphicalUI();
    Input_gui move() override;

private:
    MainWindow* ui_m;
=======
#include "abstractview.h"
#include "abstractcontroller.h"
#include "mainwindow.h"
#include "dungeoncrawler.h"
#include"startscreen.h"
#include<Qmap>

class GraphicalUI : public AbstractView, public AbstractController
{
public:
    virtual ~GraphicalUI() = default;
    GraphicalUI(MainWindow* mw,StartScreen* ss);
    void loadtextures();
    void draw(Level* level) override;
    Input move(char input) override;
    void showStartScreen();
    void showGameScreen();
    void setMainWindow(MainWindow* mw);
    void setStartScreen(StartScreen* ss);
private:
    MainWindow* ui_m;
     StartScreen* ui_s;
     QMap<QString, QPixmap> textures;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // GRAPHICALUI_H
