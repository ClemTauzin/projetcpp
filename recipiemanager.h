#ifndef RECIPIEMANAGER_H
#define RECIPIEMANAGER_H
#include <list>
#include <vector>
#include <map>

#include "food.h"
#include "vegetables.h"
#include "fruit.h"
#include "meat.h"




struct Recipie{
    std::vector<Food*> foodList;
    std::string name;

    Recipie(std::string name, std::vector<Food*> foodList)
        :name(name),foodList(foodList){}

    std::vector<Food*> getFoodList(){
        return foodList;
    }
    std::string getName(){
        return name;
    }
};



//using Recipie = std::vector<Food *>;

class RecipieManager
{
    // std::map<std::string,std::list<Food*>> recipies;
    std::list<Recipie*> recipies;

public:
    RecipieManager();

    void addRecipie(std::string name, std::vector<Food *> recipieListFood);
    // void addRecipies(const Recipie& recipie);

    void findRecipieWithOneFood(std::string food);
};

#endif // RECIPIEMANAGER_H
