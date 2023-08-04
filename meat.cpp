#include "meat.h"
#include "vegetables.h"

/**
 * @brief Constructor of Meat
 * @param _name name of meat
 * @param _dlu   date of peremption
 * @param _origin  origin of the fruit
 */
Meat::Meat(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

//! @brief Display meat information
void Meat::displayInfo(){
    std::cout << "-> Name : " << name << " - dlu : " << dlu << " - origin : " << origin << std::endl;
}
