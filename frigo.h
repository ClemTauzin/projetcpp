#ifndef FRIGO_H
#define FRIGO_H

#include <iostream>
#include <vector>
#include <ostream>
#include "food.h"


class Frigo {
    protected:
    std::vector<Food*> foods;

    public:
    Frigo(){}

    void addFood(Food* aFood);

    void displayAllFoods();

    std::vector<Food*> getFoods();

    ~Frigo();

    friend std::ostream& operator <<(std::ostream& os, const Frigo& frigo)
    {

        for(auto &f : frigo.foods) {
            os << f->getName() << " ; " << f->getDlu()<< " ; " << f->getOrigin() << "\n";
        }

        return os;
    }

};



#endif
