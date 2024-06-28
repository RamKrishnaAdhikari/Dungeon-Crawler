#pragma once
#include "abstractcontroller.h"
#include "abstractview.h"
#include "mainwindow.h"
#include "dungeoncrawler.h"

class MainWindow;

class GraphicalUI : public AbstractController, public AbstractView
{
public:
    GraphicalUI(MainWindow* mw);
    void draw() override;
    virtual ~GraphicalUI() = default;
    Input_gui move() override;

private:
    MainWindow* ui_m;
};
