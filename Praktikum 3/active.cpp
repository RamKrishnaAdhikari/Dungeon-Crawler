#include "active.h"

active::active() {}
void active::attach(passive* passivobj){
    if(passiveobjects.size()!=0){
    for(const auto& obj : passiveobjects){
        if(obj == passivobj ){

            return ;
        }
    }
    }
    passiveobjects.push_back(passivobj);

}

void active::detach(passive* passivobj){
    for(int i= 0 ; i<passiveobjects.size();i++){
        if(passiveobjects.at(i)== passivobj){
            passiveobjects.erase(passiveobjects.begin()+i);
        }
    }
}

void active :: activate(){
    for(const auto& obj : passiveobjects){
        obj->notify();
    }
}
