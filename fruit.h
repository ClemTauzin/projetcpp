/**
 * \brief header of fruit
 * \authors Moi toi
 * \date 2023/08/03
 * Commentaires classiques
 */

#ifndef FRUIT_H
#define FRUIT_H

#include "food.h"


 //! Doxygen command in down @brief The Fruit class
class Fruit : public Food
{
public:

    /**
     * @brief Fruit Constructor of frut ==> Doxygen (in .cpp)
     * @param _name name of fruit description
     * @param _dlu limit time of consumation
     * @param _origin origin
     */
    Fruit(const std::string& _name, std::string _dlu, std::string _origin);

    /**
     * @brief displayInfo
     */
    void displayInfo();   /// doxygen command at left
};


#endif // FRUIT_H
