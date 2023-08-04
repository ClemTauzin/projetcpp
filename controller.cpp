#include "controller.h"


void Controller::createFrigo() {
    frigo = new Frigo();
    fillFrigo(frigo);
}

void Controller::displayFrigo() {
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::cout << "EN ATTENTE DES RECETTES" << std::endl;
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE SAUVEGARDE" << std::endl;
    // archivageFrigo(frigo);
}

void Controller::addMoreFood(){
     // Saisie de la classe
    std::cout<<"A quelle catégorie appartient l'aliment ?\n"<<"1 -> Vegetables\n"<<"2 -> Meat\n"<<"3 -> Fruit\n"<<std::endl;
    int in_class = 0;
    std::cin>>in_class;

    // Saisie du nom
    std::cout<<"Quel est le nom de l'aliment ?"<<std::endl;
    std::string in_name;
    std::getline(std::cin, in_name);

    // Saisie de la DLU
    std::cout<<"Quel est la date de péremption de l'aliment (format aaa/mm/jj) ?"<<std::endl;
    std::string in_dlu;
    std::getline(std::cin, in_dlu);

    // Saisie de la provenance
    std::cout<<"Quel est la provenance de l'aliment ?"<<std::endl;
    std::string in_origin;
    std::getline(std::cin, in_origin);

    // Création de l'objet
    Food* food = nullptr;
    if (in_class==1){
        food = new Vegetables(in_name, in_dlu, in_origin);    
    }else if(in_class==2){
        food = new Meat(in_name, in_dlu, in_origin);    
    }else if(in_class==3){
        food = new Fruit(in_name, in_dlu, in_origin);    
    }else{
        std::cout<<"ERREUR DE SAISIE"<<std::endl;
    }
    frigo->addFood(food);
}