#include "active.h"

<<<<<<< HEAD
Active::Active() {}

Active::~Active()
{
    for(auto passive:list_of_passive)
    {
        detach(passive);
    }
}

void Active::attach(Passive* p)
{
    for(auto passive:list_of_passive)
    {
        if(passive==p)
        {
            return;
        }
    }
    list_of_passive.push_back(p);
}

void Active::detach(Passive* p)
{
    for(unsigned int i = 0; i < list_of_passive.size(); i++)
    {
        if(list_of_passive[i] == p)
        {
            list_of_passive.erase(list_of_passive.begin()+i);
        }
    }
=======
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
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

void Active::activate()
{
<<<<<<< HEAD
    for(auto passive:list_of_passive)
    {
        passive->notify();
    }
}

std::vector<Passive *> Active::getList_of_passive() const
{
    return list_of_passive;
=======
    for (auto& passiveobj : passiveObjects)
    {
        passiveobj->notify();
    }
}

std::vector<Passive*> Active::getPassiveObjects() const
{
    return passiveObjects;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}
