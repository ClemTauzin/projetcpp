#include "fruit.h"
#include "vegetables.h"

/**
 * @brief Constructor of fruit
 * @param _name name of fruit
 * @param _dlu   date of peremption
 * @param _origin  origin of the fruit
 */
Fruit::Fruit(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

//! @brief Display fruit information
void Fruit::displayInfo(){
    std::cout << "-> Name : " << name << " - dlu : " << dlu << " - origin : " << origin << std::endl;
}
