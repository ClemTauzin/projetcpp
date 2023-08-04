#ifndef RECIPIEMANAGER_H
#define RECIPIEMANAGER_H
#include <list>
#include <vector>
#include <map>

#include "food.h"
#include "vegetables.h"
#include "fruit.h"
#include "meat.h"



/**
 * @brief The Recipie struct
 */
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

/**
template<typename T>
class VectorNameWrapper{

    std::vector<T*> vector;
    std::string name;

public:
    VectorNameWrapper(std::string name, std::vector<T*> vector)
        :name(name),vector(vector){}

    std::vector<T*> getVector(){return vector;}
    std::string getName(){return name;}
};
*/


//using Recipie = std::vector<Food *>;

class RecipieManager
{
    // std::map<std::string,std::list<Food*>> recipies;
    /**
     * @brief recipies
     */
    std::list<Recipie*> recipies;
    // std::list<VectorNameWrapper<Food>*> recipies; // test with wrapper

public:

    RecipieManager();

    void addRecipie(std::string name, std::vector<Food *> recipieListFood);

    void findRecipieWithOneFood(std::string food);


    friend std::ostream& operator <<(std::ostream& os, const RecipieManager& rm)
    {

        // for each recipie in the list
        for(auto &r : rm.recipies) {
            // I print the recipie name
            os << r->getName() << " :  ";
            // And in the recipie, for each ingredient, I print the food name
            for(auto &f : r->getFoodList()) {
            // for(auto &f : r->getVector()) { // test with wrapper
                os << f->getName()<< " + ";
            }
            os << "\n";
        }

        return os;
    }


    std::list<Recipie*> getPossibleRecipies(std::vector<Food*> foodList) const;
};

#endif // RECIPIEMANAGER_H
