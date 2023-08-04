#include "controller.h"


void Controller::createFrigo() {
    frigo = new Frigo();
    fillFrigo(frigo);
}

void Controller::createRecipieManager() {
    recipieManager = new RecipieManager();
}

void Controller::displayFrigo() {
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::list<Recipie*> possibleRecipies = recipieManager->getPossibleRecipies(frigo->getFoods());

    for( auto r : possibleRecipies){
        std::cout << "Possible recipie : " << r->getName() << std::endl;
    }
}

void Controller::displayFoodNearExpire() {
    std::cout << "ALIMENTS BIENTOT PERIMEE : " << std::endl;
    for(auto f : frigo->getFoods()) {
        if(f->isDluNear()) {
            f->displayInfo();
        }
    }
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE SAUVEGARDE" << std::endl;
    // archivageFrigo(frigo);
}

Controller::~Controller() {
    for(auto f : frigo->getFoods()) {
        delete f;
    }
    frigo->getFoods().clear();
    delete frigo;
}