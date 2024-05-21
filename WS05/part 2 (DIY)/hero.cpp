#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "hero.h"


using namespace std;
namespace seneca{
    Hero::Hero(){
        m_name[0] = '\0';
        m_abilities = nullptr;
        m_cntAbilities = 0;
        m_level = 1;
    };

    Hero::Hero(const char* name, Ability* abilities, int cntAbilities) : Hero(){
        *this = Hero();
        if(name[0] != '\0' && name) strcpy(m_name, name);
        m_cntAbilities = cntAbilities;
        m_abilities = abilities;
        Ability* newArr = new Ability[cntAbilities];
        for(auto i = 0; i < m_cntAbilities; ++i){
            newArr[i] = m_abilities[i];
        }
        m_abilities = newArr;
        newArr = nullptr;
    };

    Hero::~Hero(){
        delete[] m_abilities;
        m_abilities = nullptr;
        m_name[0] = '\0';
        m_cntAbilities = 0;
    };

    Hero::operator const char*() const{
        return m_name;
    };

    Hero::operator int() const{
        int totalWeight = 0;
        for (auto i = 0; i < m_cntAbilities; ++i) {
            totalWeight += m_abilities[i].getAbilStr();
        }
        // cout << totalWeight << endl;
        return totalWeight * m_level;
    };

    Hero& Hero::operator +=(const Ability& ability){
        Ability* newArr = new Ability[m_cntAbilities + 1];
        for(int i = 0; i < m_cntAbilities; ++i){
            newArr[i] = m_abilities[i];
        }
        newArr[m_cntAbilities] = ability;
        delete[] m_abilities;
        m_abilities = newArr;
        
        ++m_cntAbilities;
        newArr = nullptr;
        return *this;
    };

    
    Hero& Hero::operator +=(int lvlchange){
        // m_level = (lvlchange > 0) ? m_level + lvlchange : (m_level + lvlchange < 1 ? 1 : m_level + lvlchange);
        if(lvlchange > 0){
            m_level += lvlchange;
        }
        else{
            if (m_level + lvlchange < 1)
            {
                m_level = 1;
            }
            else{
                m_level += lvlchange;
            }
        }
        return *this;
    };

    Hero& Hero::operator++(){
        m_level++;
        return *this;
    };

    void Hero::display() const{
        cout << m_name << " (lvl: " << m_level << ", str: " << int(*this) << ')' << endl; // int(*this)
        for(auto i = 0; i < m_cntAbilities; ++i){
            cout << "  - " << m_abilities[i].getAbilName() << " (" << m_abilities[i].getAbilStr() << ')' << endl; 
        }
    };

    bool operator<(const Hero& h1, const Hero& h2){
        if(int(h1) && int(h2) && int(h1) < int(h2)){
            return true;
        }
        else{
            return false;
        }
    }; 
    bool operator>(const Hero& h1, const Hero& h2){
        if(int(h1) && int(h2) && int(h1) > int(h2)){
            return true;
        }
        else{
            return false;
        }
    }; 
    void operator>>(const Ability& ability, Hero& hero){
        if(hero){
            hero += ability;
        }
    }; 
    
    void operator<<(Hero& hero, const Ability& ability){
        if(hero){
            hero += ability;
        }
    }; 


    


}