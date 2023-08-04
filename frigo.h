/**
 * @brief Declaration of the Frigo calss - Container for Food
 */

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

    //! Add a specific food in the container
    void addFood(Food* aFood);

    void displayAllFoods();

    void removeFood(int index);

    std::vector<Food*> getFoods();  //!< GETTER of foods

    ~Frigo();

    //! operator<<() for the standard output : print all foods present in the fridge
    friend std::ostream& operator <<(std::ostream& os, const Frigo& frigo)
    {
        for(auto &f : frigo.foods) {
            os << f->getName() << " ; " << f->getDlu()<< " ; " << f->getOrigin() << "\n";
        }
        return os;
    }

};

#endif
