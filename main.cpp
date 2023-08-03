#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>


#include "vegetables.h"
#include "fruit.h"
#include "meat.h"

#include "food.h"
#include "frigo.h"

int main(){

    // Recup today date
    time_t now = time(0);
    std::tm *localTime = localtime(&now);

    Food* food1 = new Vegetables("Patate","2022/08/15","France");
    Food* food2 = new Fruit("Poire","2023/08/16","Danemark");
    Food* food3 = new Meat("Rumsteak","2023/07/15","Spain");


    // std::vector<Food*> table;
    // table.push_back(food1);
    // table.push_back(food2);
    // table.push_back(food3);

    // for(auto &f : table){
    //     f->displayInfo();
    // }
    // std::cout<<(food1->getDluTM()).tm_yday<<std::endl;
    // std::cout<<(food2->getDluTM()).tm_yday<<std::endl;
    std::cout<<std::boolalpha<<food1->isDluOver()<<std::endl;


    Frigo frigo;
    frigo.addFood(food1);
    frigo.addFood(food2);
    frigo.addFood(food3);

    frigo.displayAllFoods();

    return 0;
}