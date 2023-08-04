/**
 * @brief File food Abstract class for concretisation of Vegetables, Fruit, Meat
 */

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Food {

private:

    struct std::tm getDluTM();

    time_t getDluTimeT();


    time_t getDateSystem(int nbDayBefore = 0);

protected:
    std::string name;
    std::string dlu;
    std::string origin;

public:
    Food(const std::string& _name, std::string _dlu, std::string _origin): name(_name), dlu(_dlu), origin(_origin){}
    virtual ~Food() = default;

    std::string getName() const{
        return name;
    }
    std::string getDlu() const{
        return dlu;
    }
    std::string getOrigin() const{
        return origin;
    }

    virtual void displayInfo() = 0;

    bool isFoodExpired(time_t tfood, time_t tSystem);

    bool isDluOver();

    bool isDluNear();
};

#endif
