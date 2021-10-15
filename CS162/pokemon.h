#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Pokemon{
private:
    int dex_number;
    string name;
    string type;
    string moves[4];

public:
    //Setters
    void setName(string);
    void setDexNum(int);
    void setType(string);
    void setMoves(string*);
    void printInfo();
    //Getters
    string getName();
    string getType();
    int getDexNum();
    string* getMoves();
};

#endif