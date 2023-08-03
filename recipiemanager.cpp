#include "recipiemanager.h"




RecipieManager::RecipieManager()
{

    std::vector<Food*> kebab{new Vegetables("salad","2023/08/04","France"),
                new Fruit("tomat","2023/08/15","France"),
                new Vegetables("onion","2023/08/15","France"),
                new Meat("kebab","2023/08/15","France")};


    std::vector<Food*> simplesalad{new Vegetables("salad","2023/08/04","France"),
                new Fruit("tomat","2023/08/15","France"),
                new Vegetables("onion","2023/08/15","France"),
                };


    std::vector<Food*> fruitsalad{new Vegetables("apple","2023/08/04","France"),
                new Fruit("peer","2023/08/15","France"),
                new Vegetables("banana","2023/08/15","France"),
                                  };

//    std::string recipieKebab{"kebab"};
//    std::string recipieSimpleSalad{"simple salad"};
//    std::string recipieFruitSalad{"fruit salad"};

//    addRecipie(recipieKebab,kebab);
//    addRecipie(recipieSimpleSalad,simplesalad);
//    addRecipie(recipieFruitSalad,fruitsalad);

        addRecipie("kebab",kebab);
        addRecipie("simple salad",simplesalad);
        addRecipie("fruit salad",fruitsalad);


}

void RecipieManager::addRecipie(std::string name,
                                std::vector<Food*> recipieListFood)
{
    recipies.push_back(new Recipie(name,recipieListFood));
}


void RecipieManager::findRecipieWithOneFood(std::string food){
    for(auto& r : recipies){
        auto foodList = r->getFoodList();
        for(auto& f : foodList ){
            if(f->getName() == food){
                std::cout << "With this food " << food
                          << ", you can add this food in the recipie \"" << r->getName() << "\""
                          << std::endl;
            }
        }
    }
}

