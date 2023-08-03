#include <iostream>
#include <string>
#include <vector>

#include "vegetables.h"
#include "fruit.h"
#include "meat.h"

#include "food.h"

int main(){

    Food* food1 = new Vegetables("Patate","2023/08/15","France");
    Food* food2 = new Fruit("Poire","2023/02/15","Danemark");
    Food* food3 = new Meat("Rumsteak","2023/07/15","Spain");


    std::vector<Food*> table;
    table.push_back(food1);
    table.push_back(food2);
    table.push_back(food3);

    for(auto &f : table){
        f->displayInfo();
    }

    delete(food3);
    delete(food2);
    delete(food1);

    return 0;
}