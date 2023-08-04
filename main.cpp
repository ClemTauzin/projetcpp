#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>


#include "vegetables.h"
#include "fruit.h"
#include "meat.h"
#include "archivage.h"
#include "food.h"
#include "frigo.h"

#include "recipiemanager.h"

#include "controller.h"

int main(){

    Controller controller;
    controller.createFrigo();
    controller.createRecipieManager();

    char choix = '_';
    char choix2 = '_';
    while(choix != '0') {
        std::string input = "";
        std::string input2 = "";

        /**********MENU**************/
        std::cout << "\nFaites votre choix : " << std::endl;
        std::cout << "1 - Afficher le contenu du frigo " << std::endl;
        std::cout << "2 - Afficher les recettes en fonction du contenu du frigo" << std::endl;
        std::cout << "3 - Afficher les aliments presque périmés" << std::endl;
        std::cout << "4 - Gestion du frigo" << std::endl;
        // std::cout << "5 - Cuisiner une recette" << std::endl; ??
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
            case '3':
                controller.displayFoodNearExpire();
                break;
            case '4':
                std::cout << "\nFaites votre choix : " << std::endl;
                std::cout << "1 - Ajouter un aliment dans le frigo " << std::endl;
                std::cout << "2 - Supprimer un aliment du frigo" << std::endl;
                std::cout << "0 - Abandonner" << std::endl;
                std::cin >> input2;
                choix2 = input2[0];
                    switch(choix2) {
                        case '0':
                            break;
                        case '1':
                        // Ajouter un aliment
                            controller.addMoreFood();
                            break;
                        case '2':
                        // Supprimer un aliment
                            controller.addLessFood();
                            break;
                        default:
                            std::cout << "Choix non reconnu" << std::endl;
                    }
                break;
            // case '5':
            //     Choisir la recette
            //     ET supprimer les ingrédients du frigo
            //     break;
            default:
                std::cout << "Choix non reconnu" << std::endl;
        }
    }

    return 0;
}
