#include "archivage.h"
#include "frigo.h"
#include "vegetables.h"
#include "meat.h"
#include "fruit.h"

// std::ofstream& operator <<(std::ofstream& os, const Frigo& frigo)
// {
//     for(auto &f : frigo.foods) {
//     os << f->getName() << " ; " << f->getDlu()<< " ; " << f->getOrigin() << "\n";
//     }
//     return os;
// };

void archivageFrigo(Frigo* frigo){
    std::ofstream frigoContainer;
    frigoContainer.open("archive.txt", std::ios::out);
    for(auto &f : frigo->getFoods()) {
        Vegetables* vegetable = dynamic_cast<Vegetables*>(f);
        Meat* meat = dynamic_cast<Meat*>(f);
        Fruit* fruit = dynamic_cast<Fruit*>(f);
        if(vegetable){
            frigoContainer << "Vegetables;";
        }else if(meat){
            frigoContainer << "Meat;";
        }else{
            frigoContainer << "Fruit;";
        }
    frigoContainer << f->getName() << ";" << f->getDlu()<< ";" << f->getOrigin() << "\n";
    }
};

