#ifndef FRUIT_H
#define FRUIT_H

#include "food.h"

class Fruit : public Food
{
public:
    Fruit(const std::string& _name, std::string _dlu, std::string _origin);

    void displayInfo();
};


#endif // FRUIT_H
