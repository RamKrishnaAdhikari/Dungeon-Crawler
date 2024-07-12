#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
<<<<<<< HEAD
=======
#include <algorithm>
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
#include "passive.h"

class Active
{
<<<<<<< HEAD
public:
    Active();
    ~Active();
    void attach(Passive*);
    void detach(Passive*);
    void activate();
    std::vector<Passive *> getList_of_passive() const;

private:
    std::vector<Passive*>list_of_passive;
=======
 public:
    virtual ~Active() = default;
    void attach(Passive* passiveObj);
    void detach(Passive* passiveObj);
    void activate();
    std::vector<Passive*> getPassiveObjects() const;

private:
    std::vector<Passive*> passiveObjects;
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
};

#endif // ACTIVE_H
