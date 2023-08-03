#ifndef MEAT_H
#define MEAT_H

#include "food.h"


class Meat : public Food
{
public:
    Meat(const std::string& _name, std::string _dlu, std::string _origin);

    void displayInfo();
};

#endif // MEAT_H
