#ifndef SENECA_ABILITY_H
#define SENECA_ABILITY_H

namespace seneca{
    class Ability{
        char abilityName[100 + 1];
        int abilityStrength;

        public:
        Ability();
        Ability(const char* aName, int aStrength);
        int getAbilStr() const;
        const char* getAbilName() const;
    };
}

#endif