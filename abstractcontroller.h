#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H
<<<<<<< HEAD

enum Input_gui
{
    up,
    upleft,
    upright,
    down,
    downleft,
    downright,
    left,
    right,
    terminate,
    stand
};

class AbstractController
{
public:
    AbstractController();
    virtual Input_gui move() = 0;
    virtual ~AbstractController() = default;
=======
#include "input.h"

class AbstractController
{
 public:
    virtual Input move(char input) = 0;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // ABSTRACTCONTROLLER_H
