#include "food.h"
#include "frigo.h"

void Frigo::addFood(Food* aFood) {
    foods.push_back(aFood);
}

void Frigo::displayAllFoods() {
    for(auto &f : foods) {
        f->displayInfo();
    }
}

Frigo::~Frigo() {
    for(auto &f : foods) {
        delete f;
    }
    foods.clear();
}