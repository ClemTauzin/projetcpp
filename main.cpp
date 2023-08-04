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

void test() {
        // Recup today date
    // time_t now = time(0);
    // std::tm *localTime = localtime(&now);

    // Food* food1 = new Vegetables("Patate","2022/08/15","France");
    // Food* food2 = new Fruit("Poire","2023/08/16","Danemark");
    // Food* food3 = new Meat("Rumsteak","2023/07/15","Spain");

    // std::cout<<std::boolalpha<<food1->isDluOver()<<std::endl;

    Frigo frigo;

    fillFrigo(&frigo);

    // frigo.addFood(food1);
    // frigo.addFood(food2);
    // frigo.addFood(food3);

    frigo.displayAllFoods();
    std::cout << frigo << std::endl;



    RecipieManager* recipieManager = new RecipieManager();
    std::cout << *recipieManager << std::endl;

    recipieManager->findRecipieWithOneFood("tomat");

    std::vector<Food*> foodInFridge{new Vegetables("salad","2023/08/04","BZH"),
                    new Fruit("tomat","2023/08/15","France"),
                    new Vegetables("onion","2023/08/15","France"),
                    new Fruit("peer","2023/08/15","Panam"),
                    new Meat("kebab","2023/08/15","France"),
                    new Meat("Magret","2023/08/15","Toulouse")
                    };

    std::list<Recipie*> possibleRecipies = recipieManager->getPossibleRecipies(foodInFridge);

    for( auto r : possibleRecipies){
        std::cout << "Possible recipie : " << r->getName() << std::endl;
    }


    delete(recipieManager);
    // archivageFrigo(&frigo);
}

int main(){


    Controller controller;
    controller.initFrigo();

    char choix = '_';
    while(choix != '0') {
        std::string input = "";
        /**********MENU**************/
        std::cout << "\nFaites votre choix : " << std::endl;
        std::cout << "1 - Afficher le contenu du frigo " << std::endl;
        std::cout << "2 - Afficher les recettes " << std::endl;
        std::cout << "3 - Montrer les recettes avec les aliments presque périmée" << std::endl;
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
