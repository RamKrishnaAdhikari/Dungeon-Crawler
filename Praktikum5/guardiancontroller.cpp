#include "guardiancontroller.h"


GuardianController::GuardianController(){
    movem_str = "66444466";
    for (char c : movem_str) {
        if (isdigit(c)) {
            result.push_back(c - '0');
        }
    }
}

Input_gui GuardianController::move()
{
    int index = result.at(0);
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
}

GuardianController::~GuardianController()
{
    result.clear();
}

