#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H
#include "input.h"
class Abstractcontroller
{
public:
    Abstractcontroller();
     virtual Input move() = 0;
};

#endif // ABSTRACTCONTROLLER_H
