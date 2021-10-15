#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pokedex{
private:
   string owner;
   string num_of_pokemon;
   Pokemon *dex;

public:
   
    void dexOwner(string);
    void setNum(string);
    int getNum();
    string getOwner();
};

#endif