#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
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
};

#endif // GRAPHICALUI_H
