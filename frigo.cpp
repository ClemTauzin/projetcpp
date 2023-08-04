#include "food.h"
#include "frigo.h"

void Frigo::addFood(Food* aFood) {
    foods.push_back(aFood);
}

void Frigo::displayAllFoods() {
    std::cout<<"\nVotre frigo contient les produits suivants :"<<std::endl;
    for(auto &f : foods) {
        f->displayInfo();
    }
}
/*
 * std::string getName() const{
        return name;
    }
    std::string getDlu() const{
        return dlu;
    }
    std::string getOrigin() const{
        return origin;
    }

 *
 */

std::vector<Food*> Frigo::getFoods(){
    return foods;
};

Frigo::~Frigo() {
    for(auto &f : foods) {
        delete f;
    }
    foods.clear();
}
