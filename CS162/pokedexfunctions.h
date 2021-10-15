#ifndef POKEDEXFUNCTIONS_H
#define POKEDEXFUNCTIONS_H

#include "pokemon.h"
#include "pokedex.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

//#### Function Definitions #####//
vector <string> getFile(char* path){
// Takes in file path, and turns it into an ifstream data type --> checks if there was an error
// if not reads file to a vector, all whitespace and \n characters seperate the strings 
// into distinct elements of vector. Return vector.
    ifstream file(path);

    if(file.fail()){
        std::cerr << "Error Opening File" << std::endl;
        exit(1);
    }

    vector <string> vec;
    string input;
    while(file >> input){
        vec.push_back(input);
    }
    return vec;
};

void signIn(vector <string> vec, string* arr){
 //Assign Pokedex a name and assign number of pokemon
    std::cout << "##### POKEDEX #####" << std::endl;
    std::cout << "Enter name: ";
    string owner;
    string dex_count{vec[0]};
    std::cin >> owner; 
    arr[0] = dex_count;
    arr[1] = owner;
   
};

Pokemon* buildDex(int numberInDex, vector<string> vec){
// Takes in number of pokemon in the pokedex file and the vector of the dex data. 
// Creates a dynamic array of Pokemon data and assigns the values to each element.
// Returns caught pokemon array.
    Pokemon *caught_pokemon = new Pokemon[numberInDex];
    for(int i = 0; i < numberInDex; ++i){
        string new_moves[]{vec[4+(i*7)], vec[5+(i*7)], vec[6+(i*7)], vec[7+(i*7)]};
        caught_pokemon[i].setDexNum(stoi(vec[1+(i*7)]));
        caught_pokemon[i].setName(vec[2+(i*7)]);
        caught_pokemon[i].setType(vec[3+(i*7)]);
        caught_pokemon[i].setMoves(new_moves);
    }

    return caught_pokemon;
};

Pokemon searchDex(Pokemon *poke_array, int size_of_dex){
// Searches pokedex by Dex number, returns pokemon information.    
    std::cout << "\n##### Search by Dex Number ######\nEnter Dex Number: ";
    int num{0};
    std::cin >> num;
    int len = size_of_dex;
    int index{0};
    for(int i = 0; i < len; ++i){
        if(poke_array[i].getDexNum() == num){
            index = i;
        }
    }
    return poke_array[index];  
};

Pokemon searchName(Pokemon *poke_array, int size_of_dex){
// Searches pokedex by pokemon name, returns pokemon information.    
    std::cout << "\n##### Search by Name ######\nEnter Name: ";
    string name{""};
    std::cin >> name;
    int len = size_of_dex;
    int index{0};
    for(int i = 0; i < len; ++i){
        if(poke_array[i].getName() == name){
            index = i;
        }
    }
    return poke_array[index];  
};

Pokemon* searchType(Pokemon *poke_array, int size_of_dex){
// Searches pokemon by type, returns an array of pokemon data type, all of that type.
    std::cout << "\n##### Search by Type ######\nEnter Type: ";
    string type{""};
    std::cin >> type;
    int len = size_of_dex;
    int index{0};
    int num_of_type{0};
    for(int i = 0; i < len; ++i){
        if(poke_array[i].getType() == type){
            ++num_of_type;
        }
    }
// Builds out pokemone type array to be returned to user.    
    Pokemon *type_array = new Pokemon[num_of_type];
    int count{0};
    for(int i = 0; i < len; ++i){
        if(poke_array[i].getType() == type){
            type_array[count] = poke_array[i];
            ++count;
        }
        else{
            ;
        }
    }
    return type_array;
};

Pokemon addPokemon(){
// Returns a new pokemon as defined by the user and returns a pokemon data type containing that info.
    std::cout << "So you caught a new pokemon, huh?\nLet's add it to the DEX!\n";
    Pokemon pokemon;
    int dex_num{0};
    std::cout << "Dex Number: ";
    std::cin >> dex_num;
    pokemon.setDexNum(dex_num);
    string name;
    std::cout << "Name: ";
    std::cin >> name;
    pokemon.setName(name);
    string type;
    std::cout << "Type: ";
    std::cin >> type;
    pokemon.setType(type);
    string moves[4];
    std::cout << "Moves: ";
    std::cin >> moves[0] >> moves[1] >> moves[2] >> moves[3];
    pokemon.setMoves(moves);

    return pokemon;

};

void appendDex(Pokemon new_poke, char* file_path, int size_of_dex){
// Appends pokedex with the new pokemon created, and updates number of pokemon in dex.
// This is not complete, program must be quit and booted again to access this new pokemon.
    std::ifstream infile;
    std::ofstream outfile;
    std::fstream file;
    string* move_list = new_poke.getMoves();

    // Append new pokemon to file
    infile.open(file_path);
    outfile.open(file_path, std::ios::app);
    if (infile.is_open()){
        outfile << "\n" << new_poke.getDexNum() << " " << new_poke.getName() << " " << new_poke.getType() << "\n" << move_list[0] << " " << move_list[1] << " " << move_list[2] << " " << move_list[3];
        std::cout << "\nData has been appended to Pokedex" << std::endl;
    }

    // Update Pokedex number
    int new_dex_size{0};
    new_dex_size = size_of_dex+1;
    string dex_size{to_string(new_dex_size)};
    file.open(file_path);
    if (file.is_open()){
        file << dex_size;
    file.close();
    }
}

void writeToFile(Pokemon new_poke){
    fstream new_file;
    string* moves;

    moves = new_poke.getMoves();
    new_file.open("returnPokemon.txt", std::ios::app | std::ios::out);
    if(new_file.is_open()){
        new_file << new_poke.getDexNum() << " " << new_poke.getName() << " " << new_poke.getType() << "\n" << moves[0] << " " << moves[1] << " " << moves[2] << " " << moves[3] << std::endl;
    }
    new_file.close();
}

void selectionLoop(Pokemon* poke_array, int size, char* path){
// Starts the Pokedex selection loops
// Allows user to trigger various functions related to the Pokedex or quit program
    int selection {0};
    while(selection != 5){
        std::cout << "1. Search by Dex Number.\n" << "2. Search by Name.\n" << "3. Search by Type.\n" << "4. Add a Pokemon.\n" << "5. Quit\n" << ":: ";
        std::cin >> selection;
        switch(selection){
            case 1:{
                Pokemon pokemon = searchDex(poke_array, size);
                std::cout << pokemon.getDexNum() << "    " << pokemon.getName() << "    " << pokemon.getType() << std::endl;
                std::cout << "Would you like to write this to file? [y/n] ";
                string answer;
                std::cin >> answer;
                if(answer == "y"){
                    writeToFile(pokemon);
                }
                break;
            }
            case 2:{
                Pokemon pokemon = searchName(poke_array, size);
                std::cout << pokemon.getDexNum() << "    " << pokemon.getName() << "    " << pokemon.getType() << std::endl;
                std::cout << "Would you like to write this to file? [y/n] ";
                string answer;
                std::cin >> answer;
                if(answer == "y"){
                    writeToFile(pokemon);
                }
               break;
            }
            case 3:{
                Pokemon* pokemon = searchType(poke_array, size);
                std::cout << pokemon[0].getDexNum() << "    " << pokemon[0].getName() << "    " << pokemon[0].getType() << std::endl;
                break;
            }
            case 4:{
                Pokemon pokemon = addPokemon();
                appendDex(pokemon, path, size);
                std::cout << "Please reload Pokedex to access new pokemon." << std::endl;
                selection = 5;
                break;
               ;
            }
            case 5:{
                break;
            }
        }
    }
};

#endif