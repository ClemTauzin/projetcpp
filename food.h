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
    Food(const std::string& _name, std::string _dlu, std::string _origin)
         : name(_name), dlu(_dlu), origin(_origin){}

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

    struct std::tm getDluTM(){
        struct std::tm tm;
        std::istringstream ss(this->dlu);
        ss >> std::get_time(&tm, "%Y/%m/%d");
        return tm;
    }

    /**
     * @brief isDluOver : descrption of the method
     * @return true if the dl is over ; false otherwise
     */
    bool isDluOver()
    {
        time_t now = time(0);
        std::tm *localTime = localtime(&now);
        if (this->getDluTM().tm_year > localTime->tm_year){
            // is ok
            return false;
        } else if(this->getDluTM().tm_year == localTime->tm_year){
            // a vérifier
            if (this->getDluTM().tm_mon > localTime->tm_mon){
                // is ok
                return false;
            } else if (this->getDluTM().tm_mon == localTime->tm_mon){
                // a vérifier
                if (this->getDluTM().tm_mday > localTime->tm_mday){
                    // is ok
                    return false;
                }else{
                    // c'est périmé
                    return true;
            }
            }else{
                // c'est périmé
                return true;
            }
        }else{
            // c'est périmé
            return true;
        }
    }

    bool isDluNear();
};

#endif
