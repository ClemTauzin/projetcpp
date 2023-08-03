#include <iostream>
#include "frigo.h"
#include "food.h"
#include "vegetables.h"
#include "Fruit.h"
#include "Meat.h"

class Controller {
private:
    Frigo* frigo;

public:
    Controller(Frigo* _frigo = nullptr): frigo(_frigo) {}

    Frigo* getFrigo() { return frigo;}



    /*
        Initialisation de l'application.
        Chargement des aliments du frigo
    */
    Frigo* initFrigo();

    void displayFrigo();
    void displayRecette();



};