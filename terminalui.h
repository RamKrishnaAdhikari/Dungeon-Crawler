#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractui.h"
#include "level.h"
#include "input.h"

class TerminalUI : public AbstractUI
{
 public:
    void draw(Level* level) override;
    Input move() override;
};

#endif // TERMINALUI_H
