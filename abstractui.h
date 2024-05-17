#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
#include "level.h"
#include "input.h"

class AbstractUI
{
 public:
    virtual void draw(Level* level) = 0;
    virtual Input move() = 0;
 private:
};

#endif // ABSTRACTUI_H
