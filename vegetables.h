/**
 * \brief Vegetables class - concretisation of abstract Food pure virtual class
 */

#ifndef VEGETABLES_H
#define VEGETABLES_H

#include "food.h"


class Vegetables : public Food
{
public:
    Vegetables(const std::string& _name, std::string _dlu, std::string _origin);

    void displayInfo();
};

#endif // VEGETABLES_H
