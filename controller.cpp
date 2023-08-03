#include "controller.h"

void Controller::initFrigo() {
    frigo = new Frigo();
    Food* food1 = new Vegetables("Patate","2022/08/15","France");
    Food* food2 = new Fruit("Poire","2023/08/16","Danemark");
    Food* food3 = new Meat("Rumsteak","2023/07/15","Spain");

    frigo->addFood(food1);
    frigo->addFood(food2);
    frigo->addFood(food3);
}

void Controller::displayFrigo() {
    std::cout << "test" << std::endl;
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
}