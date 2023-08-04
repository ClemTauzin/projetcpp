/**
 * @brief The main controler of the program
 * manage instances and life cycle of Frigo and RecipeManager
 */
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
    Frigo* frigo;                   //!< Frigo reference
    RecipieManager* recipieManager; //!< RecipieManager reference

public:
    //! Parametrized constructor of Main Controller
    Controller(Frigo* _frigo, RecipieManager* _recipieManager): frigo(_frigo), recipieManager(_recipieManager) {}
    Controller() : frigo(nullptr), recipieManager(nullptr) {}
    Frigo* getFrigo() { return frigo;}  //!< Get the reference to the Frigo
    RecipieManager* getRecipieManager() { return recipieManager;} //!< Get the reference to the RecipieManager


    void createFrigo();             //!< Frigo factory
    void createRecipieManager();    //!< RecipieManager factory
    void displayFrigo();            //!< Display Frigo content
    void displayReceip();           //!< Display all reciepie according to food present in the frigo
    void displayFoodNearExpire();   //!< Display foods near to be expired
    void saveFrigo();               //!< Save the frigo data content in the output file
    void addMoreFood();             //!< Let the user to add a custom food in the fridged
    void addLessFood();             //!< Remove one food from the fridge

    ~Controller();  //!< Controller Destructor
};

#endif
