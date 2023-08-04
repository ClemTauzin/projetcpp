#include "controller.h"


void Controller::initFrigo() {
    frigo = new Frigo();
    Food* food1 = new Vegetables("Patate","2022/08/15","France");
    Food* food2 = new Fruit("Poire","2023/08/04","Danemark");
    Food* food3 = new Meat("Rumsteak","2023/07/03","Spain");
    Food* food4 = new Meat("testNear01","2023/08/07","Spain");
    Food* food5 = new Meat("testNear02","2023/08/08","Spain");
    Food* food6 = new Meat("testNear02","2023/08/10","Spain");


    frigo->addFood(food1);
    frigo->addFood(food2);
    frigo->addFood(food3);
    frigo->addFood(food4);
    frigo->addFood(food5);
    frigo->addFood(food6);


    food1->isDluOver();
    food2->isDluOver();
    food3->isDluOver();
    std::cout << "Test near" << std::endl;
    food4->isDluNear();
    food5->isDluNear();
    food6->isDluNear();

}

void Controller::displayFrigo() {
    std::cout << "test" << std::endl;
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE SAUVEGARDE" << std::endl;
}