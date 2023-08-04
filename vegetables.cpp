#include "vegetables.h"

/**
 * @brief Constructor of Vegetable
 * @param _name name of vegetable
 * @param _dlu   date of peremption
 * @param _origin  origin of the fruit
 */
Vegetables::Vegetables(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

//! @brief Display meat information
void Vegetables::displayInfo(){
    std::cout << "-> Name : " << name << " - dlu : " << dlu << " - origin : " << origin << std::endl;
}
