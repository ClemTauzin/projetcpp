#include "food.h"


/**
 * @brief getDluTM Schema des dates
 * @return struct tm => time_t (type long)
 */
struct std::tm Food::getDluTM() {
    // Initialise toutes les valeurs de la structure
    struct std::tm tm = {};
    std::istringstream ss(this->dlu);
    ss >> std::get_time(&tm, "%Y/%m/%d");
    return tm;
}

/**
 * @brief getDluTimeT get the DLU time (conversion from string to time_t)
 * @return time_t TYYhe DLU Time
 */
time_t  Food::getDluTimeT() {
    tm tm = getDluTM();
    return mktime(&tm);
}

/**
 * @brief getDateSystem Get the system date difference wwith a number of days
 * @param nbDayBefore the number of days difference
 * @return the time_t date
 */
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


/**
 * @brief Determine if the food is passed
 * @return true if it's over, false otherwise
 */
bool Food::isDluOver() {
    // Récupération en tm de la date système
    time_t tnow = getDateSystem();
    
    time_t tfood = getDluTimeT();
    return isFoodExpired(tfood, tnow);
}

/**
 * @brief Make the difference between local time and given food expiration time
 * @param tfood food time
 * @param tSystem system time
 * @return true if it's expired, false otherwise
 */
bool  Food::isFoodExpired(time_t tfood, time_t tSystem) {
    double diff = difftime(tfood, tSystem);

    if (diff <= 0) {
        return true;
    }
    return false;
}

/**
 * @brief Determine if the DLU is near to be expired
 * @return
 */
bool  Food::isDluNear() {
    time_t timeSystem3 = getDateSystem(4);
    time_t timeSystemNow = getDateSystem(); 

    return   !isFoodExpired(getDluTimeT(), timeSystemNow) && isFoodExpired(getDluTimeT(), timeSystem3);
}
