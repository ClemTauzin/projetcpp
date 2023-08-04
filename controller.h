#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "frigo.h"
#include "food.h"
#include "vegetables.h"
#include "fruit.h"
#include "meat.h"
#include "archivage.h"

class Controller {
private:
    Frigo* frigo;

public:
    Controller(Frigo* _frigo): frigo(_frigo) {}
    Controller() : frigo(nullptr){}
    Frigo* getFrigo() { return frigo;}



    /*
        Initialisation de l'application.
        Chargement des aliments du frigo
    */
    void createFrigo();

    void displayFrigo();
    void displayReceip();
    void displayFoodNearExpire();
    void saveFrigo();

    ~Controller();
};

#endif