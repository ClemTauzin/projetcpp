#include "fruit.h"
#include "vegetables.h"

//  name(_name), dlu(_dlu), origin(_origin);
/**
 * \brief Fruit Description of constructeor
 * @param _name name of fruit
 * @param _dlu time
 * @param _origin origin
 */
Fruit::Fruit(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

//!
void Fruit::displayInfo(){
    std::cout << "name: " << name << " dlu:" << dlu << " origin " << origin << std::endl;
}
