#include "fruit.h"
#include "vegetables.h"

//  name(_name), dlu(_dlu), origin(_origin);


/**
 * @brief Fruit::Fruit Constructeor of fruit
 * @param _name name of fruit
 * @param _dlu   datte of permemption
 * @param _origin  origin of the fruit
 */
Fruit::Fruit(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

//!
void Fruit::displayInfo(){
    std::cout << "name: " << name << " dlu:" << dlu << " origin " << origin << std::endl;
}
