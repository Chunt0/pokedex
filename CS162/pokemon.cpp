#include "pokemon.h"

// Setters
void Pokemon::setName(string new_name){
    name = new_name;
}

void Pokemon::setDexNum(int new_dex_num){
    dex_number = new_dex_num;
}

void Pokemon::setType(string new_type){
    type = new_type;
}

void Pokemon::setMoves(string new_moves[4]){
    moves[0] = new_moves[0];
    moves[1] = new_moves[1];
    moves[2] = new_moves[2];
    moves[3] = new_moves[3];
}


void Pokemon::printInfo(){
    std::cout << "Dex Number: " << dex_number << "\n" << "Name: " << name << "\n" << "Type: " << type << "\n"; 
    for(int i=0; i < 4; i++){
        std::cout << moves[i] << std::endl;
    }
}

string Pokemon::getName(){
    return name;
}

string Pokemon::getType(){
    return type;
}

int Pokemon::getDexNum(){
    return dex_number;
}

string* Pokemon::getMoves(){
    return moves;

}
