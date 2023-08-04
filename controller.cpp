#include "controller.h"


void Controller::createFrigo() {
    frigo = new Frigo();
    fillFrigo(frigo);
}

void Controller::createRecipieManager() {
    recipieManager = new RecipieManager();
}

void Controller::displayFrigo() {
    frigo->displayAllFoods();
}

void Controller::displayReceip() {
    std::list<Recipie*> possibleRecipies = recipieManager->getPossibleRecipies(frigo->getFoods());

    for( auto r : possibleRecipies){
        std::cout << "Possible recipie : " << r->getName() << std::endl;
    }
}

void Controller::displayFoodNearExpire() {
    std::cout << "ALIMENTS BIENTOT PERIMEE : " << std::endl;
    for(auto f : frigo->getFoods()) {
        if(f->isDluNear()) {
            f->displayInfo();
        }
    }
}

void Controller::saveFrigo() {
    std::cout << "EN ATTENTE SAUVEGARDE" << std::endl;
    archivageFrigo(frigo);
}

void Controller::addMoreFood(){
     // Saisie de la classe
    std::cout<<"A quelle catégorie appartient l'aliment ?\n"<<"1 -> Vegetables\n"<<"2 -> Meat\n"<<"3 -> Fruit\n"<<std::endl;
    int in_class = 0;
    std::cin>>in_class;
    std::cin.clear();
    std::cin.ignore();

    // Saisie du nom
    std::cout<<"Quel est le nom de l'aliment ?"<<std::endl;
    std::string in_name = "";
    std::getline(std::cin, in_name);

    // Saisie de la DLU
    std::cout<<"Quel est la date de péremption de l'aliment (format aaaa/mm/jj) ?"<<std::endl;
    std::string in_dlu ="";
    std::getline(std::cin, in_dlu);

    // Saisie de la provenance
    std::cout<<"Quel est la provenance de l'aliment ?"<<std::endl;
    std::string in_origin ="";
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

void Controller::addLessFood(){

    displayFrigo();
std::cout<<"\nQuel aliment de la liste souhaitez vous supprimer ?"<<std::endl;
    int index = 0;
    std::cin>>index;
    std::cin.clear();
    std::cin.ignore();
    index-=1;
    frigo->removeFood(index);
}


Controller::~Controller() {
    delete frigo;
}