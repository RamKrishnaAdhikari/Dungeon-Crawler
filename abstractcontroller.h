#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H
#include "input.h"

class AbstractController
{
 public:
    virtual Input move(char input) = 0;
};

#endif // ABSTRACTCONTROLLER_H
