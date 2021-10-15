#include "pokedex.h"
#include "pokemon.h"
#include "pokedexfunctions.h"
#include <vector>
#include <bits/stdc++.h>

//##### Initialize Functions #####//
vector <string> getFile(char*);

Pokemon* buildDex(int, vector<string>);

void signIn(vector <string>, string*);

Pokemon searchDex(Pokemon*, int);

Pokemon searchName(Pokemon*, int);

Pokemon* searchType(Pokemon*, int);

Pokemon addPokemon();

void appendDex(Pokemon, char*, int);

void writeToFile(Pokemon);

void selectionLoop(Pokemon*, int, char*);

//##### Main Function #####//
int main(int argc, char* argv[]){
// Intialization of Pokedex program variables.
    Pokedex newDex;
    Pokemon newPoke;
    vector <string> dex_vec;

// Get dex and place it into a vector data type.
    dex_vec = getFile(argv[1]);

// Login to the pokedex, assign trainer name and number of pokemon in dex. 
// Print name and number of pokemon in dex.
    string num_name[2];
    signIn(dex_vec, num_name);
    newDex.setNum(num_name[0]);
    newDex.dexOwner(num_name[1]);
    int dex_number{newDex.getNum()};
    std::cout << "Welcome, " << newDex.getOwner() << "!" << std::endl;
    std::cout << "You have " << dex_number << " Pokemon." << std::endl;
    std::cout << "What would you like to do?" << std::endl;

// Use dex_vec to build out a dynamic array of pokemon.
    Pokemon *caught_pokemon = buildDex(dex_number, dex_vec);

// Start selection loop.
    selectionLoop(caught_pokemon, dex_number, argv[1]);

    
    return 0;
}