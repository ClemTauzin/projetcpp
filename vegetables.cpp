#include "vegetables.h"

//  name(_name), dlu(_dlu), origin(_origin);

Vegetables::Vegetables(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

void Vegetables::displayInfo(){
    std::cout << "name: " << name << " dlu:" << dlu << " origin " << origin << std::endl;
}
