#include "controller.h"


void Controller::initFrigo() {
    frigo = new Frigo();
    fillFrigo(frigo);
}

void Controller::displayFrigo() {
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE SAUVEGARDE" << std::endl;
    // archivageFrigo(frigo);
}