#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include "ability.h"

namespace seneca{
    class Hero{
        char m_name[100 + 1];
        Ability* m_abilities;
        int m_cntAbilities;
        int m_level;

        public:
        Hero();
        Hero(const char* name, Ability* abilities, int cntAbilities);
        ~Hero();
        operator const char*() const;
        operator int() const;
        Hero& operator +=(const Ability& ability);
        Hero& operator +=(int lvlchange);
        Hero& operator++();
        void display() const;
    };
    bool operator<(const Hero& h1, const Hero& h2); 
    bool operator>(const Hero& h1, const Hero& h2); 
    void operator>>(const Ability& ability, Hero& hero); 
    void operator<<(Hero& hero, const Ability& ability); 
}
#endif