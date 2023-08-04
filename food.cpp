#include "food.h"
/*
    Schema des dates : 
    String date => struct tm => time_t (type long)
*/
struct std::tm Food::getDluTM() {
    // Initialise toutes les valeurs de la structure
    struct std::tm tm = {};
    std::istringstream ss(this->dlu);
    ss >> std::get_time(&tm, "%Y/%m/%d");
    return tm;
}

time_t  Food::getDluTimeT() {
    tm tm = getDluTM();
    return mktime(&tm);
}

time_t  Food::getDateSystem(int nbDayBefore) {
    struct std::tm* tm_system = {};
    
    time_t tSystem = time(0);
    tm_system = std::localtime(&tSystem);
    tm_system->tm_hour = 0;
    tm_system->tm_min = 0;
    tm_system->tm_sec = 0;
    tm_system->tm_mday += nbDayBefore;

    return mktime(tm_system);
}

bool  Food::isDluOver() {
    // Récupération en tm de la date système
    time_t tnow = getDateSystem();
    
    time_t tfood = getDluTimeT();
    return isFoodExpired(tfood, tnow);
}

bool  Food::isFoodExpired(time_t tfood, time_t tSystem) {
    double diff = difftime(tfood, tSystem);

    if (diff <= 0) {
        std::cout << "Aliment périmé" << std::endl;
        return true;
    }

    std::cout << "Aliment goutu" << std::endl;
    return false;
}


bool  Food::isDluNear() {
    std::cout << this->getName() << std::endl;
    time_t timeSystem3 = getDateSystem(4);
    time_t timeSystemNow = getDateSystem(); 

    return   !isFoodExpired(getDluTimeT(), timeSystemNow) && isFoodExpired(getDluTimeT(), timeSystem3);
}