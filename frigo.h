#ifndef FRIGO_H
#define FRIGO_H

#include <iostream>
#include <vector>
#include "food.h"


class Frigo {
    protected:
    std::vector<Food*> foods;

    public:
    Frigo(){}

    void addFood(Food* aFood);

    void displayAllFoods();

    std::vector<Food*> getFoods();

    // friend std::ofstream& operator <<(std::ofstream& os, const Frigo& frigo);

    ~Frigo();


};



#endif