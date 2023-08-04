#include "food.h"
#include "frigo.h"

/**
 * @brief Frigo::addFood
 * @param aFood The food to add in the cvector of food
 */
void Frigo::addFood(Food* aFood) {
    foods.push_back(aFood);
}

/**
 * @brief Display all caracteristics of each food in the fridge
 */
void Frigo::displayAllFoods() {
    std::cout<<"\nVotre frigo contient les produits suivants :"<<std::endl;
    int i=0;
    for(auto &f : foods) {
        i++;
        std::cout<<i;
        f->displayInfo();
    }
}

/**
 * @brief Frigo::removeFood remove one food from the fridge
 * @param index the index of the vrctor to remove
 */
void Frigo::removeFood(int index){
    delete foods[index];
    foods.erase(foods.begin() + index);
}


/**
 * @brief Frigo::getFoods
 * @return The vector of foods in the fridge
 */
std::vector<Food*> Frigo::getFoods(){
    return foods;
}

/**
 * @brief Destructor
 */
Frigo::~Frigo() {
    for(auto &f : foods) {
        delete f;
    }
    foods.clear();
}
