#ifndef GUARDIANCONTROLLER_H
#define GUARDIANCONTROLLER_H

#include "abstractcontroller.h"
#include <string>
#include <vector>

class GuardianController: public AbstractController
{
public:
    GuardianController();
    Input_gui move() override;
    ~GuardianController();

    std::string movem_str;
    std::vector<int> result;
};
#endif // GUARDIANCONTROLLER_H
