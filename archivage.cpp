#include "archivage.h"
#include "frigo.h"
#include "vegetables.h"
#include "meat.h"
#include "fruit.h"

#include "vegetables.h"
#include "fruit.h"
#include "meat.h"
#include "food.h"

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
    int i = 0;
    for(auto &f : frigo->getFoods()) {
        i++;
        frigoContainer <<"food"<<i<< ";";
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
    frigoContainer << f->getName() << ";" << f->getDlu()<< ";" << f->getOrigin() << std::endl;
    }
    frigoContainer.close();
    std::cout<<"--- Frigo food successfully saved ---"<<std::endl;
};

// void archivageFrigo(Frigo* frigo){
//     std::ofstream frigoContainer;
//     frigoContainer.open("archive.txt", std::ios::out);
//     int i = 0;
//     for(auto &f : frigo->getFoods()) {
//         i++;
//         frigoContainer <<"Food* food"<<i<< " = new ";
//         Vegetables* vegetable = dynamic_cast<Vegetables*>(f);
//         Meat* meat = dynamic_cast<Meat*>(f);
//         Fruit* fruit = dynamic_cast<Fruit*>(f);
//         if(vegetable){
//             frigoContainer << "Vegetables(";
//         }else if(meat){
//             frigoContainer << "Meat(";
//         }else{
//             frigoContainer << "Fruit(";
//         }
//     frigoContainer <<"\""<< f->getName() <<"\",\""<< f->getDlu()<<"\",\""<< f->getOrigin() << "\");"<<std::endl;
//     }
// };

void fillFrigo(Frigo* frigo){
    std::ifstream stream;
    stream.open("archive.txt", std::ios::in);
    std::vector<std::string> lines;
    std::string line;
    int i=0;
while (std::getline (stream,line,';'))
{
    i++;
    std::string in_class;
    std::getline (stream, in_class, ';');

    std::string in_name;
    std::getline (stream, in_name, ';');

    std::string in_dlu;
    std::getline (stream, in_dlu, ';');

    std::string in_origin;
    std::getline (stream, in_origin);

    if(in_class == "Vegetables"){
        Food* i = new Vegetables(in_name, in_dlu, in_origin);
        frigo->addFood(i);
    }else if(in_class == "Meat"){
        Food* i = new Meat(in_name, in_dlu, in_origin);
        frigo->addFood(i);
    }else{
        Food* i = new Fruit(in_name, in_dlu, in_origin);
        frigo->addFood(i);
    }
}
    stream.close();
    std::cout<<"--- Frigo food successfully filled ---"<<std::endl;
}