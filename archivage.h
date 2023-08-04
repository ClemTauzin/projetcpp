/**
 * @brief Archivage File - Manage file recording to allow a data base of foods
 */

#ifndef ARCHIVAGE_H
#define ARCHIVAGE_H

#include <iostream>
#include <string>
#include <fstream>
#include "frigo.h"

void archivageFrigo(Frigo* frigo);

void fillFrigo(Frigo* frigo);

#endif // ARCHIVAGE_H
