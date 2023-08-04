#include "meat.h"
#include "vegetables.h"


Meat::Meat(const std::string& _name, std::string _dlu, std::string _origin)
    : Food(_name,_dlu,_origin){}

void Meat::displayInfo(){
    std::cout << "-> Name : " << name << " - dlu : " << dlu << " - origin : " << origin << std::endl;
}
