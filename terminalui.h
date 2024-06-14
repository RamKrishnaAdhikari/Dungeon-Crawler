#ifndef TERMINALUI_H
#define TERMINALUI_H
#include "abstractview.h"
#include "abstractcontroller.h"
#include "level.h"
#include "input.h"

class TerminalUI : public AbstractView, public AbstractController
{
 public:
    void draw(Level* level) override;
    Input move(char input) override;
};

#endif // TERMINALUI_H
