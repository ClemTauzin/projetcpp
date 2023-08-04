#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "frigo.h"
#include "food.h"
#include "vegetables.h"
#include "fruit.h"
#include "meat.h"
#include "archivage.h"
#include "recipiemanager.h"

class Controller {
private:
    Frigo* frigo;
    RecipieManager* recipieManager;

public:
    Controller(Frigo* _frigo, RecipieManager* _recipieManager): frigo(_frigo), recipieManager(_recipieManager) {}
    Controller() : frigo(nullptr), recipieManager(nullptr) {}
    Frigo* getFrigo() { return frigo;}
    RecipieManager* getRecipieManager() { return recipieManager;}



    /*
        Initialisation de l'application.
        Chargement des aliments du frigo
    */
    void createFrigo();
    void createRecipieManager();
    void displayFrigo();
    void displayReceip();
    void displayFoodNearExpire();
    void saveFrigo();
    void addMoreFood();
    void addLessFood();

    ~Controller();
};

#endif