#include "guardiancontroller.h"

bool found = false;

GuardianController::GuardianController()
{
    if (found == false)
    {
        movem_str = "66444466";
        for (char c : movem_str)
        {
            if (isdigit(c)) {
                result.push_back(c - '0');
            }
        }
        found = true;
    }
    else
    {
        movem_str = "828282";
        for (char c : movem_str)
        {
            if (isdigit(c)) {
                result.push_back(c - '0');
            }
        }
    }
}

Input_gui GuardianController::move()
{
   /* int index = result.at(0);
    result.erase(result.begin()+0);
    result.push_back(index);

    while(true){
        switch (index) {
        case 8:
            return up;
            break;
        case 6:
            return right;
            break;
        case 2:
            return down;
            break;
        case 4:
            return left;
            break;
        default:
            return terminate;
            break;
        }
    }
*/
    if (result.empty())
    {
        return terminate;
    }

    int index = result.front();
    result.erase(result.begin());
    result.push_back(index);

    switch (index)
    {
    case 8:
        return up;
    case 6:
        return right;
    case 2:
        return down;
    case 4:
        return left;
    default:
        return terminate;
    }
}

GuardianController::~GuardianController()
{
    result.clear();
}

