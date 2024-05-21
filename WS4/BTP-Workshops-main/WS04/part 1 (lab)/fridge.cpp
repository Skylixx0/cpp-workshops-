// Alikhan Ongdassyn
// 158486225
#include <iostream>
#include <cstring>
#include "fridge.h"
using namespace std;


namespace seneca{
    Fridge::Fridge(){
        m_capacity = 0;
        m_cntFoods = 0;
        m_model = nullptr;
        m_foods = nullptr;
    }
    Fridge::Fridge(const char* model, int capacity){
        *this = Fridge();
        setModel(model, capacity);
    };
    Fridge::Fridge(Food* foods, int cntFoods, const char* model, int capacity){
        *this = Fridge();
        setModel(model, capacity);
        if(m_model != nullptr){
            for(int i = 0; i < cntFoods; i++){
                addFood(foods[i]);
            }
        }
    };

    Fridge::~Fridge(){
        delete[] m_model;
        m_model = nullptr;
        delete[] m_foods;
        m_foods = nullptr;
    };

    void Fridge::setModel(const char* model, int capacity){
        if(model != nullptr && capacity >= 10){
            m_model = new char[strlen(model) + 1];
            strncpy(m_model, model, strlen(model));
            m_capacity = capacity;

        }
    };

    bool Fridge::addFood(const Food& aFood){
        int totalWeight = getContentWeight();
        if(totalWeight + aFood.m_weight <= m_capacity){

            Food* newArrOfFoods = new Food[m_cntFoods + 1];
            for(int i = 0; i < m_cntFoods; i++){ // maybe + 1 for cntFoods
                newArrOfFoods[i] = m_foods[i];
            }
            newArrOfFoods[m_cntFoods] = aFood; // + 1 maybe for cntFoods
            delete[] m_foods;
            m_foods = newArrOfFoods;
            m_cntFoods++;
            return true;
        }
        return false;
    };
    const bool Fridge::hasFood(const char* theFood){

        bool returnVal = false;

    if (theFood == nullptr && m_cntFoods > 0){
         returnVal = true; 
         }
    else {
         for (int i = 0; !returnVal && i < m_cntFoods; i++) {
             returnVal = !(strcmp(m_foods[i].m_name,theFood)); 
             }
        } 
        return returnVal; 
    };
    
    
    int Fridge::getContentWeight() const{
        int totalWeight = 0;
        
        for(int i = 0; i < m_cntFoods; i++){
            totalWeight += m_foods[i].m_weight; 
        }
        return totalWeight;
    };

    bool Fridge::isFull() const {
        if(getContentWeight() >= m_capacity*0.9){
            return true;
        }
        return false;
    };

    
    std::ostream& Fridge::display(std::ostream& out) const{
        if(m_model == nullptr){
            out << "The fridge object is in an empty state.\n";
        }
        else{
            out << "  " << "   " << "Fridge model: " << m_model << endl;
            out << "  " << "Fridge capacity: " << m_capacity << "kg" << endl;
            out << "  " << "Fill percentage: " << ((double)getContentWeight() / (double)m_capacity)*100 << "%" << " full" << endl;
            out << "The list of foods:\n";
            for(int i = 0; i < m_cntFoods; i++){
                out << "  " << "- " << m_foods[i].m_name << ' ' << '(' << m_foods[i].m_weight << "kg" << ')' << endl;
            };
        }
        return out;
    };

}