/**
 * @brief Main firt
 *
 */
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

int main(){

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

    return 0;
}
