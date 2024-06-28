#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

enum Input_gui{
    up,
    upleft,
    upright,
    down,
    downleft,
    downright,
    left,
    right,
    terminate
};

class AbstractController
{
public:
    AbstractController();
    virtual Input_gui move() = 0;
    virtual ~AbstractController();
};

#endif // ABSTRACTCONTROLLER_H
