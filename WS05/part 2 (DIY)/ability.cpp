#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ability.h"

using namespace std;
namespace seneca{
    Ability::Ability(){
        abilityName[0] = '\0';
        abilityStrength = 0;    
    }

    Ability::Ability(const char* aName, int aStrength) : Ability(){
        if(aName) strcpy(abilityName, aName);
        if(aStrength) abilityStrength = aStrength;
    }
    
    int Ability::getAbilStr() const{
        return abilityStrength;
    }

    const char* Ability::getAbilName() const{
        return abilityName;
    }
}