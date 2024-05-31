#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractview.h"
#include "level.h"
#include "input.h"
#include"abstractcontroller.h"

class TerminalUI : public AbstractView, public Abstractcontroller
{
public:
    void draw(Level* level) override;
    Input move() override;
};

#endif // TERMINALUI_H
