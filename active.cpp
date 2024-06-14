#include "active.h"

void Active::attach(Passive* passiveObj)
{
    if (std::find(passiveObjects.begin(), passiveObjects.end(), passiveObj) == passiveObjects.end())
    {
        passiveObjects.push_back(passiveObj);
    }
}

void Active::detach(Passive* passiveObj)
{
    passiveObjects.erase(std::remove(passiveObjects.begin(), passiveObjects.end(), passiveObj), passiveObjects.end());
}

void Active::activate()
{
    for (auto& passiveobj : passiveObjects)
    {
        passiveobj->notify();
    }
}

std::vector<Passive*> Active::getPassiveObjects() const
{
    return passiveObjects;
}
