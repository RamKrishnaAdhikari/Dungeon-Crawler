#include "graphicalui.h"
#include <iostream>
#include "level.h"


GraphicalUI::GraphicalUI(MainWindow* mw):ui_m(mw){}

void GraphicalUI::draw()
{
    ui_m->draw();
}

Input_gui GraphicalUI::move()
{
    Input_gui Last_clicked = ui_m->getLastClicked();
    return Last_clicked;
}
