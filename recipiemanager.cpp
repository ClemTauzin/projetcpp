#include "recipiemanager.h"


/**
 * @brief Constructor for the RecipeManager
 */
RecipieManager::RecipieManager()
{
    std::vector<Food*> kebab{new Vegetables("Salad","2023/08/04","France"),
                new Fruit("Tomato","2023/08/15","France"),
                new Vegetables("Onion","2023/08/15","France"),
                new Meat("Kebab","2023/08/15","France")};


    std::vector<Food*> simplesalad{new Vegetables("Salad","2023/08/04","France"),
                new Fruit("Tomato","2023/08/15","France"),
                new Vegetables("Onion","2023/08/15","France"),
                };


    std::vector<Food*> fruitsalad{new Vegetables("Apple","2023/08/04","France"),
                new Fruit("Peer","2023/08/15","France"),
                new Vegetables("Banana","2023/08/15","France"),
                                  };


    addRecipie("kebab",kebab);
    addRecipie("simple salad",simplesalad);
    addRecipie("fruit salad",fruitsalad);

}

/**
 * @brief Add a new recipe in the recipe book (database)
 * @param name
 * @param recipieListFood
 */
void RecipieManager::addRecipie(std::string name,
                                std::vector<Food*> recipieListFood)
{
    recipies.push_back(new Recipie(name,recipieListFood));
}


/**
 * @brief Test method : find a recipie wich contains at least this food (as a std::string)
 * @param food
 */
void RecipieManager::findRecipieWithOneFood(std::string food){
    for(auto& r : recipies){
        auto foodList = r->getFoodList();
        // auto foodList = r->getVector(); // test with wrapper
        for(auto& f : foodList ){
            if(f->getName() == food){
                std::cout << "With this food " << food
                          << ", you can add this food in the recipie \"" << r->getName() << "\""
                          << std::endl;
            }
        }
    }
}


/**
 * @brief RecipieManager::getPossibleRecipies
 * @param foodListInFridge The list of foods (in the fridge) as a std::vector<Food*>
 * @return The list of possible recipe with the given list of foods
 */
std::list<Recipie*> RecipieManager::getPossibleRecipies(std::vector<Food*> foodListInFridge) const
{
    std::list<Recipie*> possibleRecipies;
    // We test each existing recipie
    for(auto &recipie : recipies){
        // I get the food list for this recipie
        auto foodListInRecipie = recipie->getFoodList();
        // auto foodListInRecipie = recipie->getVector(); // test with wrapper
        // I catch the number of ingredient in this recipie
        int recipieFoodNumber = foodListInRecipie.size();
        int recipieFoodCounter = 0;
        // For each ingredient in the fridge, I test I it exists in this recipie
        bool foundRecipie = false;
        for(auto &foodInFridge : foodListInFridge){
            // For each ingredient in this recipie
            for(auto &foodInRecipie : foodListInRecipie){
                if(foodInFridge->getName() == foodInRecipie->getName()){
                    recipieFoodCounter++;
                }
                // If we have all ingredient from the fridge to complete the recipie OK
                if(recipieFoodCounter == recipieFoodNumber){
                    possibleRecipies.push_back(recipie);
                    foundRecipie = true;
                    break;
                }
            }// end of : For each ingredient in this recipie
            if(foundRecipie) break; // we have found a recipie, pass directly to other possible recipies
        }// end of : For each ingredient in the fridge, I test I it exists in this recipie
    } // end of : We test each existing recipie

    return possibleRecipies;

}
