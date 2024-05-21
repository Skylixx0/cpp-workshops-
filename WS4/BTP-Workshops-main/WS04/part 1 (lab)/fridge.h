// Alikhan Ongdassyn
// 158486225

#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H
#include "food.h"
namespace seneca{
    class Fridge{
        int m_capacity;
        char* m_model;
        Food* m_foods;
        int m_cntFoods;
        
        int getContentWeight() const;

        public:
        Fridge();
        Fridge(const char* model, int capacity);
        void setModel(const char* model, int capacity);
        Fridge(Food* foods, int cntFoods, const char* model, int capacity);
        ~Fridge();
        bool addFood(const Food& aFood);
        bool isFull() const;
        const bool hasFood(const char* theFood = nullptr);
        std::ostream& display(std::ostream& out = std::cout) const;
    };
}
#endif