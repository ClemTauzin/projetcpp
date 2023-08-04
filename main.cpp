#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>


#include "vegetables.h"
#include "fruit.h"
#include "meat.h"

#include "food.h"
#include "frigo.h"

#include "controller.h"

int main(){


    Controller controller;
    controller.initFrigo();

    char choix = '_';
    while(choix != '0') {
        std::string input = "";
        /**********MENU**************/
        std::cout << "Faites votre choix : " << std::endl;
        std::cout << "1 - Afficher le contenu du frigo " << std::endl;
        std::cout << "2 - Afficher les recettes " << std::endl;
        std::cout << "3 -   Montrer les recettes avec les aliments presque périmée" << std::endl;
        std::cout << "4 - Cuisiner une recette" << std::endl;
        std::cout << "5 - Gestion du frigo" << std::endl;
        std::cout << "0 - Quitter" << std::endl;
        std::cin >> input;
        choix = input[0];

        switch(choix) {
            case '0':
                controller.saveFrigo();
                break;
            case '1':
                controller.displayFrigo();
                break;
            case '2':
                controller.displayReceip();
                break;
            case '4':
                //Choisir la recette
                // ET supprimer les ingrédients du frigo
                break;
            case '5':
                // Ajouter un aliment
                // Supprimer un aliment
                break;
            default:
                std::cout << "Choix non reconnu" << std::endl;
        }
    }

    return 0;
}