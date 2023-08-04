#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Food {

private:
    /*
    Schema des dates : 
    String date => struct tm => time_t (type long)
    */
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

    bool isDluOver();

    bool isFoodExpired(time_t tfood, time_t tSystem);

    bool isDluOver() {
        // Récupération en tm de la date système
        time_t tnow = getDateSystem();
        
        time_t tfood = getDluTimeT();
        return compareDlu(tfood, tnow);
    }

    bool compareDlu(time_t tfood, time_t tSystem) {
        double diff = difftime(tfood, tSystem);
        if (diff <= 0) {
            return true;
        }
        return false;
    }


    bool isDluNear() {
        time_t timeSystem3 = getDateSystem(3);
        time_t timeSystemNow = getDateSystem(); 

        return compareDlu(getDluTimeT(), timeSystemNow) && !compareDlu(getDluTimeT(), timeSystem3);
    };
};

#endif