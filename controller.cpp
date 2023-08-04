#include "controller.h"


void Controller::createFrigo() {
    frigo = new Frigo();
    fillFrigo(frigo);
}

void Controller::displayFrigo() {
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
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