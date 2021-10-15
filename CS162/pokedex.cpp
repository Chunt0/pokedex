#include "pokedex.h"
#include <iostream>
#include <fstream>
#include <string>


void Pokedex::dexOwner(string new_owner){
    owner = new_owner;
}

void Pokedex::setNum(string new_num){
    num_of_pokemon = new_num;
}

string Pokedex::getOwner(){
    return owner;
}

int Pokedex::getNum(){
    int num = stoi(num_of_pokemon);
    return num;
}

