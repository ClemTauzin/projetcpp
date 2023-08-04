#include "food.h"
#include "frigo.h"

void Frigo::addFood(Food* aFood) {
    foods.push_back(aFood);
}

void Frigo::displayAllFoods() {
    std::cout<<"\nVotre frigo contient les produits suivants :"<<std::endl;
    int i=0;
    for(auto &f : foods) {
        i++;
        std::cout<<i;
        f->displayInfo();
    }
}

    void Frigo::removeFood(int index){
        delete foods[index];
        foods.erase(foods.begin() + index);
    };



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
