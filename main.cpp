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
        std::cout << "Faire votre choix : " << std::endl;
        std::cout << "1 - Afficher le contenu du frigo " << std::endl;
        std::cout << "2 - Afficher les recettes " << std::endl;
        std::cout << "3 -   " << std::endl;
        std::cout << "0 - Quitter" << std::endl;
        std::cin >> input;
        choix = input[0];

        switch(choix) {
            case '0':
                break;
            case '1':
                controller.displayFrigo();
                break;
            case '2':
                controller.displayRecette();
                break;
            default:
                std::cout << "Choix non reconnu" << std::endl;
        }
    }


    return 0;
}