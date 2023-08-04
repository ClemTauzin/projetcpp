/**
 * \brief Fruit class - concretisation of abstract Food pure virtual class
 */

#ifndef FRUIT_H
#define FRUIT_H

#include "food.h"


/**
 * @brief Definition of the fruit class
 */
class Fruit : public Food
{
public:


    Fruit(const std::string& _name, std::string _dlu, std::string _origin);

    /**
     * @brief displayInfo
     */
    void displayInfo();   /// doxygen command at left
};


#endif // FRUIT_H
