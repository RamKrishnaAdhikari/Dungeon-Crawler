#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include <algorithm>
#include "passive.h"

class Active
{
public:
    virtual ~Active() = default;
    void attach(Passive* passiveObj);
    void detach(Passive* passiveObj);
    void activate();
    std::vector<Passive*> getPassiveObjects() const;

private:
    std::vector<Passive*> passiveObjects;
};


#endif // ACTIVE_H
