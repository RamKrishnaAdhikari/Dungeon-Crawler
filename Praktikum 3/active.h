#ifndef ACTIVE_H
#define ACTIVE_H
#include"passive.h"
#include<vector>
class active
{
public:
    active();
    std::vector<passive* > passiveobjects;
    void  attach(passive* passiveobj );
    void  detach(passive* passiveobj);
    void activate();
};

#endif // ACTIVE_H
