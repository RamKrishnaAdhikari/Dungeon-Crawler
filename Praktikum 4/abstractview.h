#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H
#include "level.h"

class AbstractView
{
 public:
    virtual void draw(Level* level) = 0;
};

#endif // ABSTRACTVIEW_H
