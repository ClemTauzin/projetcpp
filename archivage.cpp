#include "archivage.h"
#include "frigo.h"
#include "vegetables.h"
#include "meat.h"
#include "fruit.h"

#include "vegetables.h"
#include "fruit.h"
#include "meat.h"
#include "food.h"

/**
 * @brief archivageFrigo - Write in output file data corresponding to food details
 * @param frigo a pointer of the frigo container
 */
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
}

/**
 * @brief suppressExpiredFood
 * @param i The index of the food to supress from the vector
 * @param frigo a pointer of the frigo container
 */
void suppressExpiredFood(Food* i,Frigo* frigo ){
    if(i->isDluOver()){
        std::cout<<i->getName()<< " DLU is expired -> Put in the garbage"<<std::endl;
        delete i;
    }else{
    frigo->addFood(i);
    }
}

/**
 * @brief fillFrigo Fill the fridge from the input archive file
 * @param frigo a pointer of the frigo container
 */
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
            suppressExpiredFood(i, frigo);
        }else if(in_class == "Meat"){
            Food* i = new Meat(in_name, in_dlu, in_origin);
            suppressExpiredFood(i, frigo);
        }else{
            Food* i = new Fruit(in_name, in_dlu, in_origin);
            suppressExpiredFood(i, frigo);
        }
    }
    stream.close();
    
    std::cout<<"---- Expired foods removed ----"<<std::endl;
    std::cout<<"--- Frigo food successfully filled ---"<<std::endl;
}
