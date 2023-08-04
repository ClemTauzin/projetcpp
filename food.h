#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Food {

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


/*
    Schema des dates : 
    String date => struct tm => time_t (type long)
*/
    struct std::tm getDluTM() {
        // Initialise toutes les valeurs de la structure
        struct std::tm tm = {};
        std::istringstream ss(this->dlu);
        ss >> std::get_time(&tm, "%Y/%m/%d");
        return tm;
    }

    time_t getDluTimeT() {
        tm tm = getDluTM();
        return mktime(&tm);
    }

    time_t getDateSystem(int nbDayBefore = 0) {
        struct std::tm* tm_system = {};
        
        time_t tSystem = time(0);
        tm_system = std::localtime(&tSystem);
        tm_system->tm_hour = 0;
        tm_system->tm_min = 0;
        tm_system->tm_sec = 0;
        tm_system->tm_mday -= nbDayBefore;

        return mktime(tm_system);
    }

    bool isDluOver() {
        // Récupération en tm de la date système
        time_t tnow = getDateSystem();
        
        time_t tfood = getDluTimeT();
        return compareDlu(tfood, tnow);
    }

    bool compareDlu(time_t tfood, time_t tSystem) {
        double diff = difftime(tfood, tSystem);

        if (diff <= 0) {
            std::cout << "Aliment périmé" << std::endl;
            return true;
        }

        std::cout << "Aliment goutu" << std::endl;
        return false;
    }


    bool isDluNear() {
        time_t timeSystem = getDateSystem(3);
        struct std::tm* tSystem = localtime(&timeSystem);   

        return compareDlu(getDluTimeT(), timeSystem);
    };
};

#endif