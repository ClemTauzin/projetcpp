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

    // archivageFrigo(&frigo);

    return 0;
}